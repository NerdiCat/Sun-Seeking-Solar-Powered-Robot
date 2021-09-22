  int m1p=13; //motor 1 positive
  int m1n=12; //motor 1 negative
  int m2p=11;
  int m2n=10;
  int m3p=9;
  int m3n=8;
  int m4p=7;
  int m4n=6;
void setup() {
  // put your setup code here, to run once:
  pinMode(m1p,OUTPUT);
  pinMode(m1n,OUTPUT);
  pinMode(m2p,OUTPUT);
  pinMode(m2n,OUTPUT);
  pinMode(m3p,OUTPUT);
  pinMode(m3n,OUTPUT);
  pinMode(m4p,OUTPUT);
  pinMode(m4n,OUTPUT);
  Serial.begin(9600);
  //test();
  Forward(10000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
