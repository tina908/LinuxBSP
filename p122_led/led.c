#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/moduleparam.h>

#define OFF 0
#define ON 1
#define GPIOLEDCNT 8
#define GPIOKEYCNT 8

static int onevalue = 1;
static char *twostring = NULL;
module_param(onevalue, int, 0);
module_param(twostring, charp, 0);

static int gpioLed[GPIOLEDCNT] = {6,7,8,9,10,11,12,13};
static int gpioKey[GPIOKEYCNT] = {16,17,18,19,20,21,22,23};

static int gpioLedInit(void);
static void gpioLedSet(long);
static void gpioLedFree(void);
static int gpioKeyInit(void);
static int gpioKeyGet(void);
static void gpioKeyFree(void);

static int led_init(void)
{
    int ret;
	printk(KERN_DEBUG "Hello , world [ onevalue=%d, twostring=%s]\n" ,onevalue,twostring);
    ret=gpioLedInit();
    if(ret < 0)
        return ret;
    gpioLedSet(onevalue);
/*  gpioLedFree();

    ret=gpioKeyInit();
    if(ret < 0)
        return ret;
    val=gpioKeyGet();
    gpioKeyFree();

    printk("Hello, world \n ");*/
    return 0;
}
static void led_exit(void)
{
    printk("Goodbye , world\n");
	gpioLedSet(0x00);
	gpioLedFree();
}
module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("Dual BSD/GPL");

static int gpioLedInit(void)
{
    int i;
    int ret=0;
    char gpioName[10];
    for(i=0;i<GPIOLEDCNT;i++)
    {
        sprintf(gpioName,"led%d",i);
        ret = gpio_request(gpioLed[i],gpioName);
        if(ret < 0) {
            printk("Failed gpio_request() gpio%d error \n",gpioLed[i]);
            return ret;
        }

        ret = gpio_direction_output(gpioLed[i],OFF);
        if(ret < 0) {
            printk("Failed gpio_direction_output() gpio%d error \n",gpioLed[i]);
            return ret;
        }
             }
    return ret;
}
static void gpioLedSet(long val)
{
    int i;
    for(i=0;i<GPIOLEDCNT;i++)
    {
//      gpio_set_value(gpioLed[i],(val>>i) & 0x1);
        gpio_set_value(gpioLed[i],(val & (0x01<<i)));
    }
}
static void gpioLedFree(void)
{
    int i;
    for(i=0;i<GPIOLEDCNT;i++)
    {
        gpio_free(gpioLed[i]);
    }
}
static int gpioKeyInit(void)
{
    int i;
    int ret=0;
    char gpioName[10];
    for(i=0;i<GPIOKEYCNT;i++)
    {
        sprintf(gpioName,"key%d",i);
        ret = gpio_request(gpioKey[i], gpioName);
        if(ret < 0) {
            printk("Failed Request gpio%d error\n", gpioKey[i]);
            return ret;
        }
    }
    for(i=0;i<GPIOKEYCNT;i++)
    {
        ret = gpio_direction_input(gpioKey[i]);
        if(ret < 0) {
            printk("Failed direction_output gpio%d error\n", gpioKey[i]);
            return ret;
        }
    }
    return ret;
}
static int gpioKeyGet(void)
{
    int i;
    int ret;
    int keyData=0;
    for(i=0;i<GPIOKEYCNT;i++)
    {
//      ret=gpio_get_value(gpioKey[i]) << i;
//      keyData |= ret;
        ret=gpio_get_value(gpioKey[i]);
        keyData = keyData | ( ret << i );
    }
    return keyData;
}
static void gpioKeyFree(void)
{
    int i;
    for(i=0;i<GPIOKEYCNT;i++)
    {
        gpio_free(gpioKey[i]);
    }
}
