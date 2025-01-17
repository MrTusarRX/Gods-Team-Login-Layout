package uk.lgl.modmenu;

import android.app.ProgressDialog;
import android.content.Context;
import android.widget.Toast;

import org.json.JSONObject;

import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;
import android.os.AsyncTask;
import android.content.Intent;
import android.util.Log;
import android.app.Activity;

public class Auth extends AsyncTask<String, Void, String> {

    private final Context context;
    private ProgressDialog progressDialog;

    // Declare the native method
    public native void nativeLoginSuccess(String response);

    public Auth(Context context) {
        this.context = context;
		System.loadLibrary("Alexandre");
    }

    @Override
    protected void onPreExecute() {
        super.onPreExecute();
        progressDialog = new ProgressDialog(context);
        progressDialog.setMessage("Logging in, please wait...");
        progressDialog.setCancelable(false);
        progressDialog.show();
    }

    @Override
    protected String doInBackground(String... params) {
        String response = "";
        HttpURLConnection connection = null;
        OutputStreamWriter writer = null;
        Scanner scanner = null;

        try {
            String urlString = "YOUR LOGIN PHP LINK HERE";
            String username = params[0];
            String password = params[1];
            JSONObject jsonPayload = new JSONObject();
            jsonPayload.put("username", username);
            jsonPayload.put("password", password);

       
            URL url = new URL(urlString);
            connection = (HttpURLConnection) url.openConnection();
            connection.setRequestMethod("POST");
            connection.setRequestProperty("Content-Type", "application/json; charset=UTF-8");
            connection.setConnectTimeout(10000); 
            connection.setReadTimeout(10000);    
            connection.setDoOutput(true);
            writer = new OutputStreamWriter(connection.getOutputStream());
            writer.write(jsonPayload.toString());
            writer.flush();
            int responseCode = connection.getResponseCode();
            scanner = new Scanner(connection.getInputStream());
            StringBuilder jsonResponse = new StringBuilder();
            while (scanner.hasNext()) {
                jsonResponse.append(scanner.nextLine());
            }
            String responseBody = jsonResponse.toString();

            if (responseCode == HttpURLConnection.HTTP_OK) {
                JSONObject jsonResponseObject = new JSONObject(responseBody);
                response = jsonResponseObject.optString("message", "Unknown response");
            } else {
                response = "Login failed. HTTP Code: " + responseCode;
            }

        } catch (Exception e) {
            response = "Error: " + e.getMessage();
        } finally {
            // Close resources
            try {
                if (writer != null) writer.close();
                if (scanner != null) scanner.close();
                if (connection != null) connection.disconnect();
            } catch (Exception ignored) {
            }
        }

        return response;
    }
	@Override
	protected void onPostExecute(String result) {
		super.onPostExecute(result);
		if (progressDialog.isShowing()) {
			progressDialog.dismiss();
		}
		if (result.equalsIgnoreCase("Login successful")) {
			Toast.makeText(context, result, Toast.LENGTH_LONG).show();
			nativeLoginSuccess(result);
			Intent intent = new Intent(context, MainActivity.class);
			intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK); 
			context.startActivity(intent);
		} else {
			/* Show the error message if login fails */
		
			
			
			Toast.makeText(context, result, Toast.LENGTH_LONG).show();
		}
	}
	}
