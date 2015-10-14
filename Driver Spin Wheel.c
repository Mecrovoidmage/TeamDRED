#pragma config(Sensor, dgtl1,  SpeedBump,      sensorTouch)
#pragma config(Motor,  port2,           leftSpin,      tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           rightSpin,     tmotorVex393HighSpeed_MC29, openLoop)
//Canada

task main()
{
	bool newSpinState=false;
	bool oldSpinState=true;
	bool SpinState=false;
	int speed;
	const int lowSpeed=64;
	const int highSpeed=127;
	repeat(forever)
	{
		if(vexRT[Btn5D]==1 || SensorValue(SpeedBump)==true)
		{
			speed=lowSpeed;
		}
		else
		{
			speed=highSpeed;
		}
		if(vexRT[Btn5U]==1)
		{
			if(newSpinState==false)
				newSpinState=true;
			else
				newSpinState=false;
		}
		if(newSpinState==true && oldSpinState==false)
		{
			SpinState=true;
			oldSpinState=true;
			wait1Msec(250);
		}
		if(newSpinState==false && oldSpinState==true)
		{
			SpinState=false;
			oldSpinState=false;
			wait1Msec(250);
		}
		if(SpinState==true)
		{
			setMultipleMotors(speed,leftSpin,rightSpin);
		}
		else
		{
			stopMultipleMotors(leftSpin,rightSpin);
		}
	}

}
