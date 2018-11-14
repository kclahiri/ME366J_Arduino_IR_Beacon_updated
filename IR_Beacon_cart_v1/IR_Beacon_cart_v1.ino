#define motor1_en 12
#define motor1_fwd 46
#define motor1_rev 47
#define motor2_en 13
#define motor2_fwd 48
#define motor2_rev 49
#define beacon_front_north 50
#define beacon_back_south 51
#define beacon_right_east 52
#define beacon_left_west 53

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1_en, OUTPUT);
  pinMode(motor1_fwd, OUTPUT);
  pinMode(motor1_rev, OUTPUT);
  pinMode(motor2_en, OUTPUT);
  pinMode(motor2_fwd, OUTPUT);
  pinMode(motor2_rev, OUTPUT);
  pinMode(beacon_front_north, INPUT);
  pinMode(beacon_back_south, INPUT);
  pinMode(beacon_right_east, INPUT);
  pinMode(beacon_left_west, INPUT);
  digitalWrite(motor1_en, 255);
  digitalWrite(motor2_en, 255);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  int beacon_f_status = digitalRead(beacon_front_north);
  int beacon_r_status = digitalRead(beacon_right_east);
  int beacon_b_status = digitalRead(beacon_back_south);
  int beacon_l_status = digitalRead(beacon_left_west);
  
  int beacon_status[4] = {beacon_f_status, beacon_r_status, beacon_b_status, beacon_l_status};

  int case_1[4] = {0, 1, 1, 1}; //N
  int case_2[4] = {0, 0, 1, 1}; //NE
  int case_3[4] = {1, 0, 1, 1}; //E
  int case_4[4] = {1, 0, 0, 1}; //SE
  int case_5[4] = {1, 1, 0, 1}; //S
  int case_6[4] = {1, 1, 0, 0}; // SW
  int case_7[4] = {1, 1, 1, 0}; //W
  int case_8[4] = {0, 1, 1, 0}; //NW

  while (memcmp(beacon_status,case_1, sizeof(beacon_status)) == 1){
    digitalWrite(motor1_fwd, HIGH);
    digitalWrite(motor2_fwd, HIGH);
    Serial.println("Detected North");
  }

  while (memcmp(beacon_status,case_2, sizeof(beacon_status)) == 1){
    digitalWrite(motor1_fwd, HIGH);
    digitalWrite(motor2_rev, HIGH);
    Serial.println("Detected Northeast");
  }

  while (memcmp(beacon_status,case_3, sizeof(beacon_status)) == 1){
    digitalWrite(motor1_fwd, HIGH);
    digitalWrite(motor2_rev, HIGH);
    Serial.println("Detected East");
  }

  while (memcmp(beacon_status,case_4, sizeof(beacon_status)) == 1){
    digitalWrite(motor1_fwd, HIGH);
    digitalWrite(motor2_rev, HIGH);
    Serial.println("Detected Southeast");
  }

  while (memcmp(beacon_status,case_5, sizeof(beacon_status)) == 1){
    digitalWrite(motor1_fwd, HIGH);
    digitalWrite(motor2_rev, HIGH);
    Serial.println("Detected South");
  }

  while (memcmp(beacon_status,case_6, sizeof(beacon_status)) == 1){
    digitalWrite(motor1_rev, HIGH);
    digitalWrite(motor2_fwd, HIGH);
    Serial.println("Detected Southwest");
  }

  while (memcmp(beacon_status,case_7, sizeof(beacon_status)) == 1){
    digitalWrite(motor1_rev, HIGH);
    digitalWrite(motor2_fwd, HIGH);
    Serial.println("Detected West");
  }

  while (memcmp(beacon_status,case_8, sizeof(beacon_status)) == 1){
    digitalWrite(motor1_rev, HIGH);
    digitalWrite(motor2_fwd, HIGH);
    Serial.println("Detected Northwest");
  }

  delay(100);
}
  
