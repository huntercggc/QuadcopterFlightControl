/*==============================================================================================*/
/*==============================================================================================*/
#include "QuadCopterConfig.h"
/*==============================================================================================*/
/*==============================================================================================*
**函數 : MPU6050_Init
**功能 : 初始化MPU6050
**輸入 : None
**輸出 : None
**使用 : MPU6050_Init();
**==============================================================================================*/
/*==============================================================================================*/
void MPU6050_Init(void)
{
	u8 i = 0;
	u8 MPU6050_Init_Data[6][2] = {
		{0x01, MPU6050_PWR_MGMT_1},   // Reset device
		{0x03, MPU6050_CONFIG},       //
		{0x18, MPU6050_GYRO_CONFIG},  // +-2000dps
		{0x08, MPU6050_ACCEL_CONFIG}, // +-4G
		{0x32, MPU6050_INT_PIN_CFG},  //
		{0x00, MPU6050_USER_CTRL}     //
	};

	for (i = 0; i < 6; i++) {
		I2C_DMA_WriteReg(MPU6050_I2C_ADDR, MPU6050_Init_Data[i][1], MPU6050_Init_Data[i], 1);
		Delay_1ms(10);
	}
}
/*==============================================================================================*/
/*==============================================================================================*/
