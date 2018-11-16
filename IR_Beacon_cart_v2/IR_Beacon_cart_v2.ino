#define motor1_en 12
#define motor1_fwd 46
#define motor1_rev 47
#define motor2_en 13
#define motor2_fwd 48
#define motor2_rev 49
#define beacon_front_north 50
#define beacon_right_east 51
#define beacon_back_south 52
#define beacon_left_west 53
#define beacon_en 11

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
  //digitalWrite(beacon_en, HIGH);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int beacon_f_status = digitalRead(beacon_front_north);
  int beacon_r_status = digitalRead(beacon_right_east);
  int beacon_b_status = digitalRead(beacon_back_south);
  int beacon_l_status = digitalRead(beacon_left_west);

  int beacon_status[4] = {beacon_f_status, beacon_r_status, beacon_b_status, beacon_l_status};

  Serial.print("Detected at: ");
  for(int i = 0; i < sizeof(beacon_status); i++)
{
  Serial.println(beacon_status[i]);
}

  
  while (beacon_f_status == LOW){
    digitalWrite(motor1_fwd, HIGH);
    digitalWrite(motor2_fwd, HIGH);
    
    while(beacon_r_status == LOW){
      digitalWrite(motor1_fwd, HIGH);
      digitalWrite(motor2_rev, HIGH);
      Serial.println("hard to starboard!");
    }
  }

  
}
  
