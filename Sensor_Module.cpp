

#include <string.h>
#include "Sensor_Node.h"
#include "math.h"
#include "Arduino.h"
#include "SFE_BMP180.h"






int main()
{
	//	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(Dist_Snsr_Frnt_Echo_Pin, INPUT);
	pinMode(Dist_Snsr_Rear_Echo_Pin, INPUT);
	pinMode(Dist_Snsr_Right_Echo_Pin, INPUT);
	pinMode(Dist_Snsr_Left_Echo_Pin, INPUT);
	pinMode(Dist_Snsr_Frnt_Trgr_Pin, OUTPUT);
	pinMode(Dist_Snsr_Left_Trgr_Pin, OUTPUT);
	pinMode(Dist_Snsr_Rear_Trgr_Pin, OUTPUT);
	pinMode(Dist_Snsr_Right_Trgr_Pin, OUTPUT);

	float Dist_Snsr_Frnt_Duration = 0;
	float Dist_Snsr_Frnt_Distance = 0;
	float Dist_Snsr_Rear_Duration = 0;
	float Dist_Snsr_Rear_Distance = 0;
	float Dist_Snsr_Right_Duration = 0;
	float Dist_Snsr_Right_Distance = 0;
	float Dist_Snsr_Left_Duration = 0;
	float Dist_Snsr_Left_Distance = 0;
	init();  // initialize timers
	Serial.begin(9600);
	


	while (1) {

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

