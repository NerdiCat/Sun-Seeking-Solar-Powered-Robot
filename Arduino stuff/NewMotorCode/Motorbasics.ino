void Motor(int M, char D){  //input which motor (1-4) and direction (f:forward || b:backwards || s:stop )
  int P;
  int N;
//set the positive and negative to the corrisponding motor
if (M==1){ 
  P=m1p;  
  N=m1n;
 }
 if (M==2){
  P=m2p;
  N=m2n;
 }
 if (M==3){
  P=m3p;
  N=m3n;
 }
 if (M==4){
  P=m4p;
  N=m4n;
 }
//
//set the direction
 if (D=='f'){
  digitalWrite(P,HIGH);
  digitalWrite(N,LOW);
 }
 if (D=='b'){
  digitalWrite(P,LOW);
  digitalWrite(N,HIGH);
 }
 if (D=='s'){
  digitalWrite(P,LOW);
  digitalWrite(N,LOW);
 }
}
