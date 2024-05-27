#ifndef __IOCTL_H__
#define __IOCTL_H__

#define IOCTLTEST_MAGIC '6' 
typedef struct
{
	unsigned long timer_val;
	unsigned long size;
	unsigned char buff[128];
} __attribute__((packed)) keyled_data;

#define TIMER_STOP		_IO(IOCTLTEST_MAGIC, 0) 
#define TIMER_VALUE		_IOW(IOCTLTEST_MAGIC, 1,keyled_data)
#define IOCTLTEST_IO	_IO(IOCTLTEST_MAGIC, 2)
#define TIMER_START		_IO(IOCTLTEST_MAGIC, 3)
#define IOCTLTEST_MAXNR	4
#endif
