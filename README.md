# LinuxBSP

![image](https://github.com/tina908/LinuxBSP/assets/68736697/a096c230-a6c2-4543-8bb9-16bb36c750d0)


## 리눅스 드라이버


insmod - 해당 모듈 적재

rmmod - 적재된 모듈 제거

dmesg - 시스템 부팅 메세지 확인

mkmod - 드라이브에 대한 특수 파일 작성

디바이스 노드 만들기

![image](https://github.com/tina908/LinuxBSP/assets/68736697/7def1d10-9ebd-4f05-8d70-a924f2a9da64)

![image](https://github.com/tina908/LinuxBSP/assets/68736697/e4775690-4fda-475b-98f5-05594a3048f4)

![image](https://github.com/tina908/LinuxBSP/assets/68736697/e5806b41-087f-4009-8b38-f4b040363209)

![image](https://github.com/tina908/LinuxBSP/assets/68736697/01897e9f-fc18-4f4c-86c8-c889be447d5c)


## p106_hello

ubuntu@ubuntu06:~/pi_bsp/drivers/p106_hello$ make

pi@pi06:/mnt/ubuntu_nfs $ insmod hello.ko

pi@pi06:/mnt/ubuntu_nfs $ dmesg

![image](https://github.com/tina908/LinuxBSP/assets/68736697/a3da9ba2-69e9-4296-b874-0ecb49719e80)

pi@pi06:/mnt/ubuntu_nfs $ sudo rmmod hello

![image](https://github.com/tina908/LinuxBSP/assets/68736697/c124a5cd-8eb2-4094-ba8e-bead055a20b8)


##106_led

ubuntu@ubuntu06:~/pi_bsp/drivers/p106_led$ make

pi@pi06:/mnt/ubuntu_nfs $ sudo insmod led.ko









