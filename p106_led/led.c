#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>

#define OFF 0
#define ON 1
#define GPIOLEDCNT 8
#define GPIOKEYCNT 8

int gpioLed[GPIOLEDCNT] = {6,7,8,9,10,11,12,13};
int gpioKey[GPIOKEYCNT] = {16,17,18,19,20,21,22,23};

int gpioLedInit(void);
void gpioLedSet(long);
void gpioLedFree(void);
int gpioKeyInit(void);
int gpioKeyGet(void);
void gpioKeyFree(void);

static int hello_init(void)
{
    int ret;
    ret=gpioLedInit();
    if(ret < 0)
        return ret;
    gpioLedSet(0xff);
/*  gpioLedFree();

    ret=gpioKeyInit();
    if(ret < 0)
        return ret;
    val=gpioKeyGet();
    gpioKeyFree();

    printk("Hello, world \n ");*/
    return 0;
}
static void hello_exit(void)
{
    printk("Goodbye , world\n");
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("Dual BSD/GPL");

int gpioLedInit(void)
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
void gpioLedSet(long val)
{
    int i;
    for(i=0;i<GPIOLEDCNT;i++)
    {
//      gpio_set_value(gpioLed[i],(val>>i) & 0x1);
        gpio_set_value(gpioLed[i],(val & (0x01<<i)));
    }
}
void gpioLedFree(void)
{
    int i;
    for(i=0;i<GPIOLEDCNT;i++)
    {
        gpio_free(gpioLed[i]);
    }
}
int gpioKeyInit(void)
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
int gpioKeyGet(void)
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
void gpioKeyFree(void)
{
    int i;
    for(i=0;i<GPIOKEYCNT;i++)
    {
        gpio_free(gpioKey[i]);
    }
}
