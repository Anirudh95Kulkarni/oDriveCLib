/* 
* Header file declaring the public functions which can be used for the 
* control of the motors over serial. 
* Author: Anirudh
*/

/* ODRIVE struc, for storing all the parameters from a given motor */
struct ODRIVE
{
    char motor[5];
    int positionSetpoint;
    int velocitySetpoint;
    int currentSetpoint;
    int state;
    int velocityLim;
    int currentLim;
    int velocityFF;
    int currentFF;
    int vbusVoltage;
    char output[50];
};

/* enum, definition of the different states we can request */
enum AxisState_t
{
    AXIS_STATE_UNDEFINED = 0,                  //<! will fall through to idle
    AXIS_STATE_IDLE = 1,                       //<! disable PWM and do nothing
    AXIS_STATE_STARTUP_SEQUENCE = 2,           //<! the actual sequence is defined by the config.startup_... flags
    AXIS_STATE_FULL_CALIBRATION_SEQUENCE = 3,  //<! run all calibration procedures, then idle
    AXIS_STATE_MOTOR_CALIBRATION = 4,          //<! run motor calibration
    AXIS_STATE_SENSORLESS_CONTROL = 5,         //<! run sensorless control
    AXIS_STATE_ENCODER_INDEX_SEARCH = 6,       //<! run encoder index search
    AXIS_STATE_ENCODER_OFFSET_CALIBRATION = 7, //<! run encoder offset calibration
    AXIS_STATE_CLOSED_LOOP_CONTROL = 8         //<! run closed loop control
};

enum setValueID{

    POSITION = 0, 
    VELOCITY = 1
};

/**
 * @brief  Initialize the odrive struct with the appropriate motor number, vel lim and current lim
 * @param  
 * @param  
 * @retval void
 */
void odriveINIT(struct ODRIVE *odrv, char *motorNR, float velocityLim, float currentLim);

/**
 * @brief  Set the trajectory for a given motor and set point
 * @param  
 * @param  
 * @retval void
 */
void setTrajectory(struct ODRIVE *odrv);

/**
 * @brief  Sets the position of the motor, basic
 * @param  
 * @param  
 * @retval void
 */
void setPositionBasic(struct ODRIVE *odrv);

/**
 * @brief  Sets the position, this is the function we should use. The ff commands can be set to 0. 
 * @param  
 * @param  
 * @retval void
 */
void setPositionReal(struct ODRIVE *odrv);

/**
 * @brief  Set the velocity of the given motor, feedforward current optional
 * @param  
 * @param  
 * @retval 
 */
void setVelocity(struct ODRIVE *odrv);

/**
 * @brief  Set the current for the given motor. 
 * @param  
 * @param  
 * @retval 
 */
void setCurrent(struct ODRIVE *odrv);

/**
 * @brief  Request feedback from the ODRIVE, for the given motor. The return from ODRIVE is [pos, vel] 
 * @param  
 * @param  
 * @retval 
 */
void requestFeedback(struct ODRIVE *odrv); //ensure that this is able to split and return the values

/**
 * @brief  Update the watchdog timer.  
 * @param  
 * @param  
 * @retval 
 */
void updateTimer(struct ODRIVE *odrv);

/**
 * @brief  Read the state of the motor, for a given parameter
 * @param  
 * @param  
 * @retval 
 */
void readState(struct ODRIVE *odrv); //ensure that this is able to split and return the values

/**
 * @brief  Change parameters of the ODRIVE, for a given parameter 
 * @param  
 * @param  
 * @retval 
 */
void writeState(struct ODRIVE *odrv);


/**
 * @brief  Change parameters of the ODRIVE, for a given parameter 
 * @param  
 * @param  
 * @retval 
 */
char* mystrcat( char* dest, char* src );
