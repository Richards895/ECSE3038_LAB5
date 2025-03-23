Setup Function:
Initializes serial communication and LCD display
Connects to WiFi network 
Displays connection status on both serial monitor and LCD

Loop Function:
Checks if WiFi is connected
Sends an HTTP GET request to a specified endpoint with an API key
Processes the HTTP response:
Checks for errors in the HTTP request
Retrieves the response body
Parses the JSON response using ArduinoJson library
Extracts two lines of text from the parsed JSON
Displays these two lines on the LCD screen

The purpose of this lab is for an assignment.


RIDDLE ME THIS
RIDDLE ME THAT

I CAN INCREASE BUT NOT DECREASE HOWEVER I RESTART WHEN TIME HAS ENDED