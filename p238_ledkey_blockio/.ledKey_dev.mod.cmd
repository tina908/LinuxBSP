cmd_/home/ubuntu/pi_bsp/drivers/p238_ledkey_blockio/ledKey_dev.mod := printf '%s\n'   ledKey_dev.o | awk '!x[$$0]++ { print("/home/ubuntu/pi_bsp/drivers/p238_ledkey_blockio/"$$0) }' > /home/ubuntu/pi_bsp/drivers/p238_ledkey_blockio/ledKey_dev.mod
