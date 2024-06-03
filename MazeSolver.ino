
const int trigPinFront = 8;
const int echoPinFront = 7;
const int trigPinLeft = 10;
const int echoPinLeft = 9;
const int trigPinRight = 6;
const int echoPinRight = 5;

// Motor control pins
const int motor1Pin1 = 28;
const int motor1Pin2 = 29;
const int motor2Pin1 = 26;
const int motor2Pin2 = 27;
 
int ena=23,enb = 25;

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  pinMode(trigPinFront, OUTPUT);
  pinMode(echoPinFront, INPUT);
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);

  // Motor pins setup
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);

  digitalWrite(ena,HIGH);
  digitalWrite(enb,HIGH);
}

float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2; // Speed of sound is 0.034 cm/microsecond
  return distance;
}

void moveForward() {
  float leftDistance = getDistance(trigPinLeft, echoPinLeft);
  float rightDistance = getDistance(trigPinRight, echoPinRight);
  if(rightDistance <8 && leftDistance >10){
    turnLeft();
    delay(75);
    stopMotors();
    delay(50);
    // Serial1.print("Front Distance: ");
    // Serial1.print(frontDistance);
    Serial1.print(" cm, Left Distance: ");
    Serial1.print(leftDistance);
    Serial1.print(" cm, Right Distance: ");
    Serial1.print(rightDistance);
    Serial1.println(" cm");
  }
  else if(leftDistance <8 && rightDistance >10){
    turnRight();
    delay(75);
    stopMotors();
    delay(50);
    Serial1.print(" cm, Left Distance: ");
    Serial1.print(leftDistance);
    Serial1.print(" cm, Right Distance: ");
    Serial1.print(rightDistance);
    Serial1.println(" cm");
  }else {
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    // Serial1.print("Front Distance: ");
    // Serial1.print(frontDistance);
    Serial1.print(" cm, Left Distance: ");
    Serial1.print(leftDistance);
    Serial1.print(" cm, Right Distance: ");
    Serial1.print(rightDistance);
    Serial1.println(" cm");
  }
} 


void turnRight() {
  // analogWrite(ena, 150);
  // analogWrite(enb, 150);
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void turnLeft() {
  // analogWrite(ena, 150);
  // analogWrite(enb, 150);
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void loop() {
  float frontDistance = getDistance(trigPinFront, echoPinFront);
  float leftDistance = getDistance(trigPinLeft, echoPinLeft);
  float rightDistance = getDistance(trigPinRight, echoPinRight);

  Serial.print("Front Distance: ");
  Serial.print(frontDistance);
  Serial.print(" cm, Left Distance: ");
  Serial.print(leftDistance);
  Serial.print(" cm, Right Distance: ");
  Serial.print(rightDistance);
  Serial.println(" cm");
  
  if (leftDistance > 10 && frontDistance < 15){
    turnLeft();
    delay(250);
    stopMotors();
    delay(500);
  }else if(rightDistance > 10 && frontDistance < 15){
    turnRight();
    delay(250);
    stopMotors();
    delay(500);
    // delay(15);
  }else{
    moveForward();
    delay(400);
    stopMotors();
    delay(500);
    // delay(15);
  }
}




// ............................................................................................................................................................



// #include <Encoder.h>


// const double MY_PI = 3.14159265359; // Value of Pi
// const double GEAR_RATIO = 100;   // Gear ratio
// const double VOLTAGE = 6;        // Voltage (V)
// const double DIAMETER = 6;      // Diameter of the wheel (mm)


// class Node {
// public:
//   int dist;
//   char direction;
//   Node *next;
// };
// Node *head = new Node;

// // int data;
// // char direction;

// // void creation(int size) {
// //   // cin >> head->val;
// //   head->next = NULL;
// //   Node *temp = head;
// //   for (int i = 1; i < size; i++) {
// //     Node *newNode = new Node;
// //     // cin >> newNode->val;
// //     newNode->next = NULL;
// //     temp->next = newNode;
// //     temp = temp->next;
// //   }
// // }

// // void Insert(int data, char direction) {
// //   if(head==NULL){
// //     head->next = NULL;
// //     Node *temp = head;
// //     while(temp!=NULL) {
// //       Node *newNode = new Node;
// //       // cin >> newNode->val;
// //       newNode->next = NULL;
// //       temp->next = newNode;
// //       temp = temp->next;
// //     }
// //   }
// //   else{
// //     Node *newNode = new Node;
// //     Node *temp = head;
// //     // cout << "Enter Vlaue to Insert : ";
// //     while (temp->next != NULL)
// //       temp = temp->next;
// //     // cin >> newNode->val;
// //     temp->next = newNode;
// //   }
// // }

// void Insert(int data, char direction) {
//   if(head == NULL){
//     head = new Node; // Allocate memory for head if it's NULL
//     head->dist = data;
//     head->direction = direction;
//     head->next = NULL;
//   }
//   else{
//     Node *temp = head;
//     while (temp->next != NULL)
//       temp = temp->next;
//     Node *newNode = new Node;
//     newNode->dist = data;
//     newNode->direction = direction;
//     newNode->next = NULL;
//     temp->next = newNode;
//   }
// }


// const int trigPinFront = 8;
// const int echoPinFront = 7;
// const int trigPinLeft = 10;
// const int echoPinLeft = 9;
// const int trigPinRight = 6;
// const int echoPinRight = 5;

// // Motor control pins
// const int motor1Pin1 = 28;
// const int motor1Pin2 = 29;
// const int motor2Pin1 = 26;
// const int motor2Pin2 = 27;
 
// int ena=23,enb = 25;


// // Pins for the encoder
// const int encoder1PinA = 49;
// const int encoder1PinB = 11;

// Encoder encoder(encoder1PinA, encoder1PinB);

// void setup() {
//   Serial1.begin(9600);
//   Serial.begin(9600);
//   pinMode(trigPinFront, OUTPUT);
//   pinMode(echoPinFront, INPUT);
//   pinMode(trigPinLeft, OUTPUT);
//   pinMode(echoPinLeft, INPUT);
//   pinMode(trigPinRight, OUTPUT);
//   pinMode(echoPinRight, INPUT);

//   // Motor pins setup
//   pinMode(motor1Pin1, OUTPUT);
//   pinMode(motor1Pin2, OUTPUT);
//   pinMode(motor2Pin1, OUTPUT);
//   pinMode(motor2Pin2, OUTPUT);
//   pinMode(ena,OUTPUT);
//   pinMode(enb,OUTPUT);

//   digitalWrite(ena,HIGH);
//   digitalWrite(enb,HIGH);
// }

// float getDistance(int trigPin, int echoPin) {
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);
//   float duration = pulseIn(echoPin, HIGH);
//   float distance = duration * 0.034 / 2; // Speed of sound is 0.034 cm/microsecond
//   return distance;
// }

// // void Move(){
// //   digitalWrite(motor1Pin1, HIGH);
// //   digitalWrite(motor1Pin2, LOW);
// //   digitalWrite(motor2Pin1, HIGH);
// //   digitalWrite(motor2Pin2, LOW);
// // }

// void moveForward() {
//   float leftDistance = getDistance(trigPinLeft, echoPinLeft);
//   float rightDistance = getDistance(trigPinRight, echoPinRight);
//   if(rightDistance <6 && leftDistance >12){
//     AutoLeft();
//     delay(75);
//     stopMotors();
//     delay(50);
//     // Serial1.print("Front Distance: ");
//     // Serial1.print(frontDistance);
//     // Serial1.print(" cm, Left Distance: ");
//     // Serial1.print(leftDistance);
//     // Serial1.print(" cm, Right Distance: ");
//     // Serial1.print(rightDistance);
//     // Serial1.println(" cm");
//   }
//   else if(leftDistance <6 && rightDistance >12){
//     AutoRight();
//     delay(75);
//     stopMotors();
//     delay(50);
//     // Serial1.print(" cm, Left Distance: ");
//     // Serial1.print(leftDistance);
//     // Serial1.print(" cm, Right Distance: ");
//     // Serial1.print(rightDistance);
//     // Serial1.println(" cm");
//   }else {
//     digitalWrite(motor1Pin1, HIGH);
//     digitalWrite(motor1Pin2, LOW);
//     digitalWrite(motor2Pin1, HIGH);
//     digitalWrite(motor2Pin2, LOW);
//     // Serial1.print(" cm, Left Distance: ");
//     // Serial1.print(leftDistance);
//     // Serial1.print(" cm, Right Distance: ");
//     // Serial1.print(rightDistance);
//     // Serial1.println(" cm");
//   }
// } 


// void turnRight() {
//   // analogWrite(ena, 150);
//   // analogWrite(enb, 150);
//   digitalWrite(motor1Pin1, LOW);
//   digitalWrite(motor1Pin2, HIGH);
//   digitalWrite(motor2Pin1, HIGH);
//   digitalWrite(motor2Pin2, LOW);
// }

// void turnLeft() {
//   // analogWrite(ena, 150);
//   // analogWrite(enb, 150);
//   digitalWrite(motor1Pin1, HIGH);
//   digitalWrite(motor1Pin2, LOW);
//   digitalWrite(motor2Pin1, LOW);
//   digitalWrite(motor2Pin2, HIGH);
// }

// void AutoRight() {
//   // analogWrite(ena, 150);
//   // analogWrite(enb, 150);
//   digitalWrite(motor1Pin1, LOW);
//   digitalWrite(motor1Pin2, HIGH);
//   digitalWrite(motor2Pin1, HIGH);
//   digitalWrite(motor2Pin2, LOW);
// }

// void AutoLeft() {
//   // analogWrite(ena, 150);
//   // analogWrite(enb, 150);
//   digitalWrite(motor1Pin1, HIGH);
//   digitalWrite(motor1Pin2, LOW);
//   digitalWrite(motor2Pin1, LOW);
//   digitalWrite(motor2Pin2, HIGH);
// }

// void stopMotors() {
//   digitalWrite(motor1Pin1, LOW);
//   digitalWrite(motor1Pin2, LOW);
//   digitalWrite(motor2Pin1, LOW);
//   digitalWrite(motor2Pin2, LOW);
// }


// double calculateDistance(long pulses) {
//   double pulsesPerRevolution = 360 * GEAR_RATIO; // Assuming 360 pulses per revolution
//   double circumference = MY_PI * DIAMETER;         // Calculate circumference of the wheel
//   double distance = (static_cast<double>(pulses) / pulsesPerRevolution) * circumference;
//   return distance;
// }


// void loop() {
//   float frontDistance = getDistance(trigPinFront, echoPinFront);
//   float leftDistance = getDistance(trigPinLeft, echoPinLeft);
//   float rightDistance = getDistance(trigPinRight, echoPinRight);

//   long pulses = encoder.read();

//   // Calculate distance traveled
//   double encodedDistance = calculateDistance(pulses);

//   // Output distance
//   Serial.print("Distance traveled: ");
//   Serial.print(encodedDistance);
//   Serial.println(" mm");

//   Serial.print("Front Distance: ");
//   Serial.print(frontDistance);
//   Serial.print(" cm, Left Distance: ");
//   Serial.print(leftDistance);
//   Serial.print(" cm, Right Distance: ");
//   Serial.print(rightDistance);
//   Serial.println(" cm");
  
//   if (leftDistance > 10 && frontDistance < 15){
//     turnLeft();
//     Insert(encodedDistance, "L");
//     delay(250);
//     stopMotors();
//     delay(500);
//   }else if(rightDistance > 10 && frontDistance < 15){
//     turnRight();
//     Insert(encodedDistance, "R");
//     delay(250);
//     stopMotors();
//     delay(500);
//     // delay(15);
//   }else{
//     moveForward();
//     Insert(encodedDistance, "F");
//     delay(400);
//     stopMotors();
//     delay(500);
//     // delay(15);
//   }
//   transmitLinkedListData();
// }

// void transmitLinkedListData() {
//   Node *temp = head;
//   String dataToSend = "";

//   // Create a string representation of the linked list data
//   while (temp != NULL) {
//     dataToSend += String(temp->dist) + "," + temp->direction + ";";
//     temp = temp->next;
//   }

//   // Transmit the string over Bluetooth
//   Serial1.println(dataToSend);

//   // Clear the linked list for next iteration
//   // clearLinkedList();
// }

// // void clearLinkedList() {
// //   while (head != NULL) {
// //     Node *temp = head;
// //     head = head->next;
// //     delete temp;
// //   }
// // }

