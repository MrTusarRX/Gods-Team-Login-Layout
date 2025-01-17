package uk.lgl.modmenu;

import android.app.Activity;
import android.os.Bundle;
import android.content.Context;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;
import android.view.View;
import android.widget.VideoView;
import android.net.Uri;
import android.media.MediaPlayer;

public class MainActivity extends Activity {
    private Button stopbtn;
    private Button startbtn;
    private TextView homeTextView;
    private TextView expiryStatusTextView;
    private TextView bottomTextView;
    private VideoView videoBackground;
    private MediaPlayer mediaPlayer;
    static native void setDarkStop(Context ctx);
    static native void setDarkStart(Context ctx);

    public static void Start(Context ctx) {
        setDarkStart(ctx);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Load native library
        System.loadLibrary("Alexandre");

        startbtn = findViewById(R.id.startbtn);
        stopbtn = findViewById(R.id.stopbtn);
        homeTextView = findViewById(R.id.home);
        expiryStatusTextView = findViewById(R.id.expirystatus);
        bottomTextView = findViewById(R.id.textView3);
        videoBackground = findViewById(R.id.videoBackground);
        mediaPlayer = MediaPlayer.create(this, R.raw.music);
        mediaPlayer.setLooping(true);
        mediaPlayer.start();
        try {
            Uri videoUri = Uri.parse("android.resource://" + getPackageName() + "/" + R.raw.back);
            videoBackground.setVideoURI(videoUri);
            videoBackground.setOnPreparedListener(new MediaPlayer.OnPreparedListener() {
					@Override
					public void onPrepared(MediaPlayer mp) {
						mp.setLooping(true);
						mp.start();
					}
				});
        } catch (Exception e) {
            e.printStackTrace();
        }
        startbtn.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View v) {
					setDarkStart(MainActivity.this);
				}
			});

        stopbtn.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View v) {
					setDarkStop(MainActivity.this);
				}
			});
        homeTextView.setText("Welcome to the Injector Mod Menu!");
        expiryStatusTextView.setText("Status: Active");
        bottomTextView.setText("Powered by MrTurTsarRX");
    }

	@Override
	protected void onPause() {
		super.onPause();
		if (mediaPlayer != null && mediaPlayer.isPlaying()) {
			mediaPlayer.stop();
			mediaPlayer.release();
			mediaPlayer = null;
		}
	}

	@Override
	protected void onResume() {
		super.onResume();
		if (mediaPlayer == null) {
			mediaPlayer = MediaPlayer.create(this, R.raw.music);
			mediaPlayer.setLooping(true);
			mediaPlayer.start();
		}
	}

    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (mediaPlayer != null) {
            mediaPlayer.release();
            mediaPlayer = null;
        }
    }

    private void showToast(String text) {
        Toast.makeText(this, text, Toast.LENGTH_LONG).show();
    }
}
