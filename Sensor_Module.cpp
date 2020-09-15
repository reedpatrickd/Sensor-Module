

#include <string.h>
#include "Sensor_Node.h"
#include "math.h"
#include "Arduino.h"
#include "SFE_BMP180.h"
#include "Wire.h"







int main()
{
	//	pinMode(LED_BUILTIN, OUTPUT);

	SFE_BMP180 BMP180;

	pinMode(Dist_Snsr_Frnt_Echo_Pin, INPUT);
	pinMode(Dist_Snsr_Rear_Echo_Pin, INPUT);
	pinMode(Dist_Snsr_Right_Echo_Pin, INPUT);
	pinMode(Dist_Snsr_Left_Echo_Pin, INPUT);
	pinMode(Dist_Snsr_Frnt_Trgr_Pin, OUTPUT);
	pinMode(Dist_Snsr_Left_Trgr_Pin, OUTPUT);
	pinMode(Dist_Snsr_Rear_Trgr_Pin, OUTPUT);
	pinMode(Dist_Snsr_Right_Trgr_Pin, OUTPUT);
	pinMode(Sound_Snsr_Gate_Pin, INPUT);

	float Dist_Snsr_Frnt_Duration = 0;
	float Dist_Snsr_Frnt_Distance = 0;
	float Dist_Snsr_Rear_Duration = 0;
	float Dist_Snsr_Rear_Distance = 0;
	float Dist_Snsr_Right_Duration = 0;
	float Dist_Snsr_Right_Distance = 0;
	float Dist_Snsr_Left_Duration = 0;
	float Dist_Snsr_Left_Distance = 0;

	double Temperature = 0;
	double Absolute_Pressure = 0;
	double Relative_Pressure = 0;
	double Altitude = 0;
	int	   Wait_Time = 0;
	bool   Sound_Detected = 0;
	int	   Sound_Level = 0;




	init();  // initialize timers
	Serial.begin(9600);
	bool success = BMP180.begin();
	
	if (success) {
		Serial.println("BMP180 has successfully initialized");
	}


	while (1) {

		Wait_Time = BMP180.startTemperature();
		if (Wait_Time != 0) {
			delay(Wait_Time);
		}
		BMP180.getTemperature(Temperature);
		Serial.print("Temperature (degC) is: ");
		Serial.println(Temperature);

		Wait_Time = BMP180.startPressure(2);
		if (Wait_Time != 0) {
			delay(Wait_Time);
		}
		BMP180.getPressure(Absolute_Pressure, Temperature);
		Serial.print("Absolute Pressure is (mBar): ");
		Serial.println(Absolute_Pressure);

		Relative_Pressure = BMP180.sealevel(Absolute_Pressure, Home_Altitude);
		Serial.print("Relative Pressure is (mBar): ");
		Serial.println(Relative_Pressure);

		Altitude = BMP180.altitude(Absolute_Pressure, Sea_Level_Pressure);
		Serial.print("Altitude (m) is: ");
		Serial.println(Altitude);

		if (Sound_Detected = 1) {
			Sound_Level = analogRead(Sound_Snsr_Envelope_Pin);
		}

		Serial.print("Sound Level: ");
		Serial.println(Sound_Level);

				digitalWrite(Dist_Snsr_Frnt_Trgr_Pin, LOW);
				_delay_us(2);
				digitalWrite(Dist_Snsr_Frnt_Trgr_Pin, HIGH);
				_delay_us(10);
				digitalWrite(Dist_Snsr_Frnt_Trgr_Pin, LOW);
				Dist_Snsr_Frnt_Duration = pulseIn(Dist_Snsr_Frnt_Echo_Pin, HIGH);
				Dist_Snsr_Frnt_Distance = Dist_Snsr_Frnt_Duration / 58;
				digitalWrite(Dist_Snsr_Rear_Trgr_Pin, LOW);
				_delay_us(2);
				digitalWrite(Dist_Snsr_Rear_Trgr_Pin, HIGH);
				_delay_us(10);
				digitalWrite(Dist_Snsr_Rear_Trgr_Pin, LOW);
				Dist_Snsr_Rear_Duration = pulseIn(Dist_Snsr_Rear_Echo_Pin, HIGH);
				Dist_Snsr_Rear_Distance = Dist_Snsr_Rear_Duration / 58;
				digitalWrite(Dist_Snsr_Right_Trgr_Pin, LOW);
				_delay_us(2);
				digitalWrite(Dist_Snsr_Right_Trgr_Pin, HIGH);
				_delay_us(10);
				digitalWrite(Dist_Snsr_Right_Trgr_Pin, LOW);
				Dist_Snsr_Right_Duration = pulseIn(Dist_Snsr_Right_Echo_Pin, HIGH);
				Dist_Snsr_Right_Distance = Dist_Snsr_Right_Duration / 58;
				digitalWrite(Dist_Snsr_Left_Trgr_Pin, LOW);
				_delay_us(2);
				digitalWrite(Dist_Snsr_Left_Trgr_Pin, HIGH);
				_delay_us(10);
				digitalWrite(Dist_Snsr_Left_Trgr_Pin, LOW);
				Dist_Snsr_Left_Duration = pulseIn(Dist_Snsr_Left_Echo_Pin, HIGH);
				Dist_Snsr_Left_Distance = Dist_Snsr_Left_Duration / 58;
				Serial.println(Dist_Snsr_Frnt_Distance);
				Serial.println(Dist_Snsr_Rear_Distance);
				Serial.println(Dist_Snsr_Right_Distance);
				Serial.println(Dist_Snsr_Left_Distance);








				delay(1000);

	}
return 0;
}

