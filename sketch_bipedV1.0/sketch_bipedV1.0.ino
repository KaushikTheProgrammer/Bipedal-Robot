int pot1 = 0;
int pot2 = 0;
int pot3 = 0;
int pot4 = 0;
int pot5 = 0;
int pot6 = 0;
int pot7 = 0;
int pot8 = 0;

int offsetA = 1;

unsigned long prevMillis = 0;

double Setpoint1, Input1, Output1;
PID PID1(&Input1, &Output1, &Setpoint1, 2, 0, 0, DIRECT);

double Setpoint2, Input2, Output2;
PID PID2(&Input2, &Output2, &Setpoint2, 2, 0, 0, DIRECT);

double Setpoint3, Input3, Output3;
PID PID3(&Input3, &Output3, &Setpoint3, 2, 0, 0, REVERSE);

double Setpoint4, Input4, Output4;
PID PID4(&Input4, &Output4, &Setpoint4, 2, 0, 0, REVERSE);

double Setpoint5, Input5, Output5;
PID PID5(&Input5, &Output5, &Setpoint5, 2, 0, 0, REVERSE);

double Setpoint6, Input6, Output6;
PID PID6(&Input6, &Output6, &Setpoint6, 2, 0, 0, REVERSE);

double Setpoint7, Input7, Output7;
PID PID7(&Input7, &Output7, &Setpoint7, 2, 0, 0, REVERSE);

double Setpoint8, Input8, Output8;
PID PID8(&Input8, &Output8, &Setpoint8, 2, 0, 0, REVERSE);

double Setpoint9, Input9, Output9;
PID PID9(&Input9, &Output9, &Setpoint9, 2, 0, 0, REVERSE);

Motor motor1 = Motor(rfAIN1, rfAIN2, rfPWMA, offsetA, STBY1);
Motor motor2 = Motor(rllBIN1, rllBIN2, rllPWMB, offsetA, STBY1);
Motor motor3 = Motor(rulAIN1, rulAIN2, rulPWMA, offsetA, STBY2);
Motor motor4 = Motor(rjBIN1, rjBIN2, rjPWMB, offsetA, STBY2);
Motor motor5 = Motor(lfAIN1, lfAIN2, lfPWMA, offsetA, STBY3);
Motor motor6 = Motor(lllBIN1, lllBIN2, lllPWMB, offsetA, STBY3);
Motor motor7 = Motor(lulAIN1, lulAIN2, lulPWMA, offsetA, STBY4);
Motor motor8 = Motor(ljBIN1, ljBIN2, ljPWMB, offsetA, STBY4);


void setup() {

  Serial.begin(115200);

  Setpoint1 = 0;
  Setpoint2 = 0;
  Setpoint3 = 0;
  Setpoint4 = 0;
  Setpoint5 = 0;
  Setpoint6 = 0;
  Setpoint7 = 0;
  Setpoint8 = 0;
  Setpoint9 = 0;

  Input1 = analogRead(A0);
  Input2 = analogRead(A1);
  Input3 = analogRead(A2);
  Input4 = analogRead(A3);
  Input5 = analogRead(A4);
  Input6 = analogRead(A5);
  Input7 = analogRead(A6);
  Input8 = analogRead(A7);

  PID1.SetMode(AUTOMATIC);
  PID1.SetOutputLimits(-255, 255);
  PID1.SetSampleTime(10);

  PID2.SetMode(AUTOMATIC);
  PID2.SetOutputLimits(-255, 255);
  PID2.SetSampleTime(10);

  PID3.SetMode(AUTOMATIC);
  PID3.SetOutputLimits(-255, 255);
  PID3.SetSampleTime(10);

  PID4.SetMode(AUTOMATIC);
  PID4.SetOutputLimits(-255, 255);
  PID4.SetSampleTime(10);

  PID5.SetMode(AUTOMATIC);
  PID5.SetOutputLimits(-255, 255);
  PID5.SetSampleTime(10);

  PID6.SetMode(AUTOMATIC);
  PID6.SetOutputLimits(-255, 255);
  PID6.SetSampleTime(10);

  PID7.SetMode(AUTOMATIC);
  PID7.SetOutputLimits(-255, 255);
  PID7.SetSampleTime(10);

  PID8.SetMode(AUTOMATIC);
  PID8.SetOutputLimits(-255, 255);
  PID8.SetSampleTime(10);

  PID9.SetMode(AUTOMATIC);
  PID9.SetOutputLimits(-506, 517);
  PID9.SetSampleTime(10);
}


void loop() {

    unsigned long currentMillis = millis();

    if ((currentMillis - prevMillis) > 10) {
      prevMillis = currentMillis;

      readPots();


      Input1 = pot1;
      PID1.Compute();
      Serial.println(Output1);
      motor1.drive(Output1);

      Input2 = pot2;
      PID2.Compute();
      Serial.println(Output2);
      motor2.drive(Output2);

      Input3 = pot3;
      PID3.Compute();
      Serial.println(Output3);
      motor3.drive(Output3);

      Input4 = pot4;
      PID4.Compute();
      Serial.println(Output4);
      motor4.drive(Output4);

      Input5 = pot5;
      PID5.Compute();
      Serial.println(Output5);
      motor5.drive(Output5);

      Input6 = pot6;
      PID6.Compute();
      Serial.println(Output6);
      motor6.drive(Output6);

      Input7 = pot7;
      PID7.Compute();
      Serial.println(Output7);
      motor7.drive(Output7);

      Input8 = pot8;
      PID8.Compute();
      Serial.println(Output8);
      motor8.drive(Output8);
    }
  }
}


void readPots() {
  pot1 = analogRead(A0) - offSet1;
  pot2 = analogRead(A1) - offSet2;
  pot3 = analogRead(A2) - offSet3;
  pot4 = analogRead(A3) - offSet4;
  pot5 = analogRead(A4) - offSet5;
  pot6 = analogRead(A5) - offSet6;
  pot7 = analogRead(A6) - offSet7;
  pot8 = analogRead(A7) - offSet8;
}

void printPots() {
  Serial.print("RF: ");
  Serial.print(pot1);
  Serial.print("\t");
  Serial.print("RLL: ");
  Serial.print(pot2);
  Serial.print("\t");
  Serial.print("RUL: ");
  Serial.print(pot3);
  Serial.print("\t");
  Serial.print("RH: ");
  Serial.print(pot4);
  Serial.print("\t");
  Serial.print("LF: ");
  Serial.print(pot5);
  Serial.print("\t");
  Serial.print("LLL: ");
  Serial.print(pot6);
  Serial.print("\t");
  Serial.print("LUL: ");
  Serial.print(pot7);
  Serial.print("\t");
  Serial.print("LH: ");
  Serial.println(pot8);
}

void printOutputs() {
  Serial.print(Output1);
  Serial.print("\t");
  Serial.print(Output2);
  Serial.print("\t");
  Serial.print(Output3);
  Serial.print("\t");
  Serial.print(Output4);
  Serial.print("\t");
  Serial.print(Output5);
  Serial.print("\t");
  Serial.print(Output6);
  Serial.print("\t");
  Serial.print(Output7);
  Serial.print("\t");
  Serial.println(Output8);
}
