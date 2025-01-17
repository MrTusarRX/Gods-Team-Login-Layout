<?php
header('Content-Type: application/json');

// Check if the request uses GET or POST
if ($_SERVER['REQUEST_METHOD'] === 'GET') {
    $username = $_GET['username'] ?? null;
    $password = $_GET['password'] ?? null;
} else if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $json_data = file_get_contents('php://input');
    $data = json_decode($json_data, true);
    if (json_last_error() !== JSON_ERROR_NONE) {
        echo json_encode([
            "status" => "error",
            "message" => "Invalid JSON data",
            "error_details" => json_last_error_msg()
        ]);
        exit;
    }
    $username = $data['username'] ?? null;
    $password = $data['password'] ?? null;
} else {
    echo json_encode(["status" => "error", "message" => "Invalid request method"]);
    exit;
}
if (!$username || !$password) {
    echo json_encode(["status" => "error", "message" => "Username and password are required"]);
    exit;
}


$valid_username = "tusar"; //put your username here
$valid_password = "123"; //put your password here



if ($username === $valid_username && $password === $valid_password) {
    echo json_encode(["status" => "success", "message" => "Login successful"]);
} else {
    echo json_encode(["status" => "error", "message" => "Invalid username or password"]);
}
?>
