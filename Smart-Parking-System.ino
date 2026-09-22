const int NUM_SLOTS = 4;
int trigPins[NUM_SLOTS] = {2, 4, 6, 8};
int echoPins[NUM_SLOTS] = {3, 5, 7, 9};

const int OCCUPIED_THRESHOLD_CM = 10;

bool slotOccupied[NUM_SLOTS];

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < NUM_SLOTS; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
    digitalWrite(trigPins[i], LOW);
  }

  Serial.println("Smart Parking System Initialized...");
}

void loop() {
  int occupiedCount = 0;

  for (int i = 0; i < NUM_SLOTS; i++) {
    long distance = readDistanceCM(trigPins[i], echoPins[i]);
    slotOccupied[i] = (distance > 0 && distance <= OCCUPIED_THRESHOLD_CM);

    Serial.print("Slot ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(slotOccupied[i] ? "OCCUPIED" : "FREE");
    Serial.print(" (");
    Serial.print(distance);
    Serial.println(" cm)");

    if (slotOccupied[i]) occupiedCount++;
    delay(50); 
  }

  Serial.print("Total Occupied: ");
  Serial.print(occupiedCount);
  Serial.print(" / ");
  Serial.println(NUM_SLOTS);
  Serial.println("------------------------");

  delay(1000); // Refresh interval
}

long readDistanceCM(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
  if (duration == 0) return -1; // No echo received (out of range/error)

  long distance = duration * 0.034 / 2; // Speed of sound conversion
  return distance;
}
