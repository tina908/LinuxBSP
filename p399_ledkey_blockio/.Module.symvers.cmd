cmd_/home/ubuntu/pi_bsp/drivers/p399_ledkey_blockio/Module.symvers :=  sed 's/ko$$/o/'  /home/ubuntu/pi_bsp/drivers/p399_ledkey_blockio/modules.order | scripts/mod/modpost -m -a    -o /home/ubuntu/pi_bsp/drivers/p399_ledkey_blockio/Module.symvers -e -i Module.symvers -T - 
