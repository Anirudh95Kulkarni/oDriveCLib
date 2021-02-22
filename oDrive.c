/*includes*/
#include "odrive.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"


/* Function Definitions */
void odriveINIT(struct ODRIVE *odrv, char *motorNR, float velocityLim, float currentLim)
{
	strcpy(odrv->motor, motorNR);
	strcat(odrv->motor, " "); /* We add a space to ease it later */
	
	odrv->velocityLim = velocityLim;
	odrv->currentLim = currentLim;
	odrv->state = AXIS_STATE_UNDEFINED;
}

void setTrajectory(struct ODRIVE *odrv)
{
	char* datastring;
	datastring = (char*) malloc(50);
	char* p = datastring;
	char temp[50];

	p = mystrcat(p, "t ");
	p = mystrcat(p, odrv->motor); //Add the motor number

	sprintf(temp, "%d", odrv->positionSetpoint);
	p = mystrcat(p, temp);				  //Add the pos

	p = mystrcat(p, "\n"); //new line
	strcpy(odrv->output, datastring);
	free(datastring);
}

void setPositionBasic(struct ODRIVE *odrv)
{
	char* datastring;
	datastring = (char*) malloc(50);
	char* p = datastring;
	char temp[50];
	
	p = mystrcat(p, "q ");
	p = mystrcat(p, odrv->motor);
	
	sprintf(temp, "%d", odrv->positionSetpoint);
	p = mystrcat(p, temp);
    p = mystrcat(p, " ");
	
	sprintf(temp, "%d", odrv->positionSetpoint);
	p = mystrcat(p, temp);
	p = mystrcat(p, " ");

	sprintf(temp, "%d", odrv->currentLim);
	p = mystrcat(p, temp);

	p = mystrcat(p, "\n");
	strcpy(odrv->output, p);

	free(datastring);
}

void setSetpoint(struct ODRIVE *odrv, int id, float value){

	switch(id){

		case POSITION:
			
			break;
		
		case VELOCITY:

			break;
	
	
	}


}

void setPositionReal(struct ODRIVE *odrv)
{
	sprintf(odrv->output, "p %s %d %d %d\n", odrv->motor, odrv->positionSetpoint, odrv->velocityFF, odrv->currentFF);
	/*
	char* datastring;
	datastring = (char*) malloc(50);
	char* p = datastring;
	char temp[50];
	
	p = mystrcat(p, "p ");
	p = mystrcat(p, odrv->motor);
	sprintf(temp, "%d", odrv->positionSetpoint);
	p = mystrcat(p, temp);
	p = mystrcat(p, " ");
	sprintf(temp, "%d", odrv->velocityFF);
	p = mystrcat(p, temp);
	p = mystrcat(p, " ");
	sprintf(temp, "%d", odrv->currentFF);
	p = mystrcat(p, temp);
	p = mystrcat(p, "\n");
	strcpy(odrv->output, datastring);
	free(datastring);
	*/
}

void setVelocity(struct ODRIVE *odrv)
{
	char* datastring;
	datastring = (char*) malloc(50);
	char* p = datastring;
	char temp[50];

	p = mystrcat(p, "v ");
	p = mystrcat(p, odrv->motor);

	sprintf(temp, "%d", odrv->velocitySetpoint);

	p = mystrcat(p, temp);

	sprintf(temp, "%d", odrv->currentFF);
	p = mystrcat(p, temp);

	p = mystrcat(p, "\n");
	
	strcpy(odrv->output, datastring);
	free(datastring);
}

void setCurrent(struct ODRIVE *odrv)
{
	char* datastring;
	datastring = (char*) malloc(50);
	char* p = datastring;
	char temp[50];
	
	p = mystrcat(p, "c ");

	p = mystrcat(p, odrv->motor);

	sprintf(temp, "%d", odrv->currentSetpoint);
	p = mystrcat(p, temp);

	p = mystrcat(p, "\n");
	strcpy(odrv->output, datastring);
	free(datastring);
}

void requestFeedback(struct ODRIVE *odrv)
{
	char temp;
	char *out;
	mystrcat(odrv->output, "f ");

	mystrcat(odrv->output, odrv->motor);

	mystrcat(odrv->output, "\n");
}

void updateTimer(struct ODRIVE *odrv)
{
	char temp;
	char *out;

	mystrcat(odrv->output, "u ");
	mystrcat(odrv->output, odrv->motor);
	mystrcat(odrv->output, "\n");
}

void readState(struct ODRIVE *odrv)
{
	char temp;
	char *out;

	mystrcat(odrv->output, "r ");
	mystrcat(odrv->output, odrv->motor);

	/*code the state machine for reading different properties here */

	mystrcat(odrv->output, "\n");
}

void writeState(struct ODRIVE *odrv)
{
	char temp;
	char *out;
	mystrcat(odrv->output, "w ");

	mystrcat(odrv->output, odrv->motor);

	/*Write the state machine if necessary here */

	mystrcat(odrv->output, "\n");
}

char* mystrcat( char* dest, char* src )
{
     while (*dest) dest++;
     while (*dest++ = *src++);
     return --dest;
}
