<?php
$hostname = "localhost";
$username = "root";
$password = "";
$database = "gas_sensor_data"; //For this example, it is "gas_sensor_data"
// Database name-->  "gas_sensor_data"
// Table name in the database--> "ppm_data"
// variable that is storing the ppm value in this table--> "ppm_val"

$conn = mysqli_connect($hostname, $username, $password, $database);
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

echo "Database connection is OK<br>";
echo "outside of the if condition :)";
// echo "Received ppm_val: " . $_POST["ppm_val"] . "<br>";
if(isset($_POST["ppm_val"])) {
    echo "we are in the if condition :)";
    $ppm_val = $_POST["ppm_val"];
    $sql = "INSERT INTO ppm_data(ppm_val) VALUES (".$ppm_val.")";
    
    if (mysqli_query($conn, $sql)) {
    echo "\n New ppm value from the ESP32 saved into the database successfully";
    } else {
    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
    }
    }
    
?>

