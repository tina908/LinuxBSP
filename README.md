# LinuxBSP

![image](https://github.com/tina908/LinuxBSP/assets/68736697/a096c230-a6c2-4543-8bb9-16bb36c750d0)


## 리눅스 드라이버


* insmod - 해당 모듈 적재

* rmmod - 적재된 모듈 제거

* dmesg - 시스템 부팅 메세지 확인

* mkmod - 드라이브에 대한 특수 파일 작성

* modinfo - 리눅스 모듈 조회

* cat /proc/misc - 연결 되어 있는 장치 확인


![image](https://github.com/tina908/LinuxBSP/assets/68736697/a23e285b-cbfd-4408-828c-b650e72a6c76)

![image](https://github.com/tina908/LinuxBSP/assets/68736697/e4775690-4fda-475b-98f5-05594a3048f4)

![image](https://github.com/tina908/LinuxBSP/assets/68736697/e5806b41-087f-4009-8b38-f4b040363209)

![image](https://github.com/tina908/LinuxBSP/assets/68736697/01897e9f-fc18-4f4c-86c8-c889be447d5c)


## p87

### 디바이스 노드 만들기

![image](https://github.com/tina908/LinuxBSP/assets/68736697/7def1d10-9ebd-4f05-8d70-a924f2a9da64)

```
pi@pi06:/mnt/ubuntu_nfs $ cat /proc/devices
```

![image](https://github.com/tina908/LinuxBSP/assets/68736697/d8302475-739f-46a9-9307-e554b3b8adf4)

>주번호 장치이름   
>주번호는 디바이스를 구분하기 위해 사용   
>부번호는 동일한 디바이스가 여러 개 있을 때 이를 구분하기 위해 사용 (채널, 파티션개념)   

```
ubuntu@ubuntu06:~/pi_bsp/drivers/p87$ gcc mknod.c -o testmknod

ubuntu@ubuntu06:~/pi_bsp/drivers/p87$ sudo ./testmknod
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/e2b2f254-4ac8-4bba-a57c-d216fa60d6d9)


## p106_hello

```
ubuntu@ubuntu06:~/pi_bsp/drivers/p106_hello$ make

pi@pi06:/mnt/ubuntu_nfs $ insmod hello.ko

pi@pi06:/mnt/ubuntu_nfs $ dmesg
```

![image](https://github.com/tina908/LinuxBSP/assets/68736697/a3da9ba2-69e9-4296-b874-0ecb49719e80)
```
pi@pi06:/mnt/ubuntu_nfs $ sudo rmmod hello
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/c124a5cd-8eb2-4094-ba8e-bead055a20b8)


## 106_led
```
ubuntu@ubuntu06:~/pi_bsp/drivers/p106_led$ make

pi@pi06:/mnt/ubuntu_nfs $ sudo insmod led.ko
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/0b91e19b-d2ac-4d49-bd3d-8c00fbf4ed25)
```
pi@pi06:/mnt/ubuntu_nfs $ sudo rmmod led.ko
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/65078503-b084-4421-9c2f-61058b6ca3b1)

![image](https://github.com/tina908/LinuxBSP/assets/68736697/9acf0c5e-5172-4963-964b-c062243c393c)


## p122_led
```
ubuntu@ubuntu06:~/pi_bsp/drivers/p122_led$ make

pi@pi06:/mnt/ubuntu_nfs $ sudo insmod led.ko onevalue=255
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/cf47f46e-0c83-418a-a708-05fddac18f3d)
```
pi@pi06:/mnt/ubuntu_nfs $ sudo rmmod led

pi@pi06:/mnt/ubuntu_nfs $ sudo insmod led.ko onevalue=255 twostring="abcd 1234"
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/5ce10170-a216-4837-b834-6c5d8e9d5c70)
```
pi@pi06:/mnt/ubuntu_nfs $ sudo rmmod led
```

## p184_led
```
ubuntu@ubuntu06:~/pi_bsp/drivers/p184_led$ make

pi@pi06:/mnt/ubuntu_nfs $ sudo insmod call_dev.ko

pi@pi06:/mnt/ubuntu_nfs $ ./call_app
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/0d8d160a-d363-4bd0-ae4f-c8b07f2adc50)

>에러 발생 시
```
pi@pi06:/mnt/ubuntu_nfs $ sudo mknod /dev/calldev c 230 0

pi@pi06:/mnt/ubuntu_nfs $ sudo chmod 777 /dev/calldev

pi@pi06:/mnt/ubuntu_nfs $ ./call_app
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/293b1d36-fb04-4f8a-acbe-73c4830123d8)
![image](https://github.com/tina908/LinuxBSP/assets/68736697/6fd02a82-2558-4595-9cf8-88950c632c4f)

>8번 키를 누르면 종료

```
pi@pi06:/mnt/ubuntu_nfs $ sudo rmmod call_dev
```

## struct
```
ubuntu@ubuntu06:~/pi_bsp/drivers$ gcc struct.c -o struct

ubuntu@ubuntu06:~/pi_bsp/drivers$ ./struct
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/30917333-6479-4db6-80df-f0599d794d9b)


## p238_ledkey
```
ubuntu@ubuntu06:~/pi_bsp/drivers/p238_ledkey$ make

pi@pi06:/mnt/ubuntu_nfs $ sudo mknod /dev/ledkey c 230 0

pi@pi06:/mnt/ubuntu_nfs $ sudo chmod 666 /dev/ledkey

pi@pi06:/mnt/ubuntu_nfs $ sudo insmod ledkey_dev.ko

pi@pi06:/mnt/ubuntu_nfs $ ./ledkey_app 0x55
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/e48cda21-3b72-4078-96f1-a48d5f647eef)

![image](https://github.com/tina908/LinuxBSP/assets/68736697/639a1527-c55a-4b23-b9a3-62c58dd4b544)

>1번 키 누르면 firefox 웹 브라우저 오픈

![image](https://github.com/tina908/LinuxBSP/assets/68736697/e3d3b7d0-cf8a-4c2b-82f9-849a44d5cfe4)

>2번 키 누르면 firefox 웹 브라우저 kill
```
pi@pi06:/mnt/ubuntu_nfs $ sudo rmmod ledkey_dev
```

## p238_ledkey_blockio
```
ubuntu@ubuntu06:~/pi_bsp/drivers/p238_ledkey_blockio$ make

pi@pi06:/mnt/ubuntu_nfs $ sudo mknod /dev/calldev c 230 0

pi@pi06:/mnt/ubuntu_nfs $ sudo insmod ledkey_dev.ko

pi@pi06:/mnt/ubuntu_nfs $ sudo chmod 666 /dev/calldev

pi@pi06:/mnt/ubuntu_nfs $ ./ledKey_app
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/d4da8bc0-3c71-4ec9-b214-78a059431ae9)
```
pi@pi06:/mnt/ubuntu_nfs $ sudo rmmod ledkey_dev
```

## p270_minor_ledkey
```
ubuntu@ubuntu06:~/pi_bsp/drivers/p270_minor_ledkey$ make

pi@pi06:/mnt/ubuntu_nfs $ sudo mknod /dev/minor_led c 230 0

pi@pi06:/mnt/ubuntu_nfs $ sudo mknod /dev/minor_key c 230 0

pi@pi06:/mnt/ubuntu_nfs $ sudo insmod minor_dev.ko

pi@pi06:/mnt/ubuntu_nfs $ sudo chmod 666 /dev/minor_led

pi@pi06:/mnt/ubuntu_nfs $ sudo chmod 666 /dev/minor_key

pi@pi06:/mnt/ubuntu_nfs $ ./minor_app
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/48e71294-280d-4d32-8b16-1ab7006adbca)


## p306_ledkey_ioctl_rw
```
ubuntu@ubuntu06:~/pi_bsp/drivers/p306_ledkey_ioctl_rw$ make
```


## p335_kerneltimer_ledkey_dev
```
ubuntu@ubuntu06:~/pi_bsp/drivers/p335_kerneltimer_ledkey_dev$ make

pi@pi06:/mnt/ubuntu_nfs $ sudo insmod kerneltimer.ko timerVal=50 ledVal=0X55

pi@pi06:/mnt/ubuntu_nfs $ sudo mknod /dev/kerneltimer c 230 0

pi@pi06:/mnt/ubuntu_nfs $ sudo chmod 666 /dev/kerneltimer

pi@pi06:/mnt/ubuntu_nfs $ sudo insmod kerneltimer_dev.ko

pi@pi06:/mnt/ubuntu_nfs $ ./kerneltimer_app 0x55
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/19b9b7a8-84ce-441e-9b1b-731c1ec82dbe)
```
pi@pi06:/mnt/ubuntu_nfs $ sudo rmmod kerneltimer
```

>키를 누르면 해당 번호의 LED가 켜지고 나머지는 꺼졌다가, 그 후 나머지 LED는 켜지고 눌린 키의 LED는 꺼집니다.   
>이 상태가 반복하면서 껐다켰다 반복, 8번 키를 눌렀을 때 종료   
>led on/off 속도 : timerVal=50   
>초기 상태 : ledVal=0X55    

## p432_ledkey_poll
```
ubuntu@ubuntu06:~/pi_bsp/drivers/p432_ledkey_poll$ make

pi@pi06:/mnt/ubuntu_nfs $ sudo mknod /dev/ledkey c 230 0

pi@pi06:/mnt/ubuntu_nfs $ sudo chmod 666 /dev/ledkey

pi@pi06:/mnt/ubuntu_nfs $ sudo insmod ledkey_dev.ko

pi@pi06:/mnt/ubuntu_nfs $ ./ledkey_app 0xff
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/e07cf8f3-8e44-4105-9228-4659494951ca)

![image](https://github.com/tina908/LinuxBSP/assets/68736697/5f79f7c0-3695-47e9-9ab5-70f5a01b1f9e)

![image](https://github.com/tina908/LinuxBSP/assets/68736697/80f18dad-cc07-41a8-8004-5b9e6998d54a)

>poll time out 대기시간은 2초   
>키를 누르면 해당 번호의 LED가 켜짐   
>스위치 255 하면 다 켜짐 0은 다꺼짐 (2진수)
>8번 키를 누르거나 q스위치를 눌렸을 때 종료   
```
pi@pi06:/mnt/ubuntu_nfs $ sudo rmmod ledkey
```
## p399_ledkey_poll_new
```
ubuntu@ubuntu06:~/pi_bsp/drivers/p399_ledkey_poll_new$ make

pi@pi06:/mnt/ubuntu_nfs $ sudo mknod /dev/ledkey c 230 0

pi@pi06:/mnt/ubuntu_nfs $ sudo chmod 666 /dev/ledkey

pi@pi06:/mnt/ubuntu_nfs $ sudo insmod ledkey_dev.ko

pi@pi06:/mnt/ubuntu_nfs $ ./ledkey_app 0xff
```
![image](https://github.com/tina908/LinuxBSP/assets/68736697/ff9dfb82-18ba-41d7-b1d1-5082afa99ed6)

>poll time out 대기시간은 2초   
>키를 누르면 해당 번호의 LED가 켜짐   
>스위치 255 하면 다 켜짐 0은 다꺼짐 (2진수)
>8번 키를 누르거나 q스위치를 눌렸을 때 종료   
```
pi@pi06:/mnt/ubuntu_nfs $ sudo rmmod ledkey
```

