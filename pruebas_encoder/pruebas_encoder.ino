#define LEFT_ENCODER_A 37
#define LEFT_ENCODER_B 36
#define RIGHT_ENCODER_A 26
#define RIGHT_ENCODER_B 25

volatile long a = 0;
volatile long b = 0;
volatile long c = 0;
volatile long d = 0;

void IRAM_ATTR callback_1(){
  a = digitalRead(RIGHT_ENCODER_A);
  b = digitalRead(RIGHT_ENCODER_B);
}

void IRAM_ATTR callback_2(){
  c = digitalRead(LEFT_ENCODER_A);
  d = digitalRead(LEFT_ENCODER_B);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(RIGHT_ENCODER_A, INPUT_PULLUP);
  pinMode(RIGHT_ENCODER_B, INPUT_PULLUP);
  pinMode(LEFT_ENCODER_A, INPUT_PULLUP);
  pinMode(LEFT_ENCODER_B, INPUT_PULLUP);
  attachInterrupt(RIGHT_ENCODER_A, callback_1, RISING);
  attachInterrupt(LEFT_ENCODER_A, callback_2, RISING);
  Serial.begin(115200);
}

void loop() {
  Serial.print(a);
  Serial.print(", ");
  Serial.print(b);
  Serial.print(", ");
  Serial.print(c);
  Serial.print(", ");
  Serial.println(d);
}
