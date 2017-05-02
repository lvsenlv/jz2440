/*************************************************************************
	> File Name: s3c2440a.h
	> Author: 
	> Mail: 
	> Created Time: 2017年01月21日 星期六 22时48分52秒
 ************************************************************************/

#ifndef     __S3C2440A_H
#define     __S3C2440A_H

typedef     char                            int8_t;
typedef     short                           int16_t;
typedef     int                             int32_t;
typedef     long                            int64_t;
typedef     unsigned char                   uint8_t;
typedef     unsigned short                  uint16_t;
typedef     unsigned int                    uint32_t;
typedef     unsigned long                   uint64_t;

//#define     _I                              volatile const
#define     _O                              const
#define     _IO                             volatile

typedef struct {
    _IO uint32_t conf;
    _IO uint32_t dat;
    _IO uint32_t up;
}regis_gpio_t, *regis_gpio_pt;

#define     GPIO_BASE_ADDR                  ((uint32_t)0x56000000)
#define     GPIOA_ADDR                      (GPIO_BASE_ADDR + 0x0)
#define     GPIOB_ADDR                      (GPIO_BASE_ADDR + 0x20)
#define     GPIOC_ADDR                      (GPIO_BASE_ADDR + 0x20)
#define     GPIOD_ADDR                      (GPIO_BASE_ADDR + 0x30)
#define     GPIOE_ADDR                      (GPIO_BASE_ADDR + 0x40)
#define     GPIOF_ADDR                      (GPIO_BASE_ADDR + 0x50)
#define     GPIOG_ADDR                      (GPIO_BASE_ADDR + 0x60)
#define     GPIOH_ADDR                      (GPIO_BASE_ADDR + 0x70)
#define     GPIOJ_ADDR                      (GPIO_BASE_ADDR + 0xd0)

#define     GPIOA                           ((regis_gpio_pt)GPIOA_ADDR)
#define     GPIOB                           ((regis_gpio_pt)GPIOB_ADDR)
#define     GPIOC                           ((regis_gpio_pt)GPIOC_ADDR)
#define     GPIOD                           ((regis_gpio_pt)GPIOD_ADDR)
#define     GPIOE                           ((regis_gpio_pt)GPIOE_ADDR)
#define     GPIOF                           ((regis_gpio_pt)GPIOF_ADDR)
#define     GPIOG                           ((regis_gpio_pt)GPIOG_ADDR)
#define     GPIOH                           ((regis_gpio_pt)GPIOH_ADDR)
#define     GPIOJ                           ((regis_gpio_pt)GPIOJ_ADDR)

#endif      //__S3C2440A_H

