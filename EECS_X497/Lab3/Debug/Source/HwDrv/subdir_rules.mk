################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Source/HwDrv/F2806x_DelayUs.obj: ../Source/HwDrv/F2806x_DelayUs.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --vcu_support=vcu0 --float_support=fpu32 --include_path="//VMWARE-HOST/Shared Folders/Documents/GitHub/UCI/EECS_X497/Lab3/Header/HwDrv" --include_path="C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="Source/HwDrv/F2806x_DelayUs.d" --obj_directory="Source/HwDrv" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/HwDrv/F2806x_Gpio.obj: ../Source/HwDrv/F2806x_Gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --vcu_support=vcu0 --float_support=fpu32 --include_path="//VMWARE-HOST/Shared Folders/Documents/GitHub/UCI/EECS_X497/Lab3/Header/HwDrv" --include_path="C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="Source/HwDrv/F2806x_Gpio.d" --obj_directory="Source/HwDrv" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/HwDrv/F2806x_Startup.obj: ../Source/HwDrv/F2806x_Startup.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --vcu_support=vcu0 --float_support=fpu32 --include_path="//VMWARE-HOST/Shared Folders/Documents/GitHub/UCI/EECS_X497/Lab3/Header/HwDrv" --include_path="C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="Source/HwDrv/F2806x_Startup.d" --obj_directory="Source/HwDrv" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/HwDrv/F2806x_SysCtrl.obj: ../Source/HwDrv/F2806x_SysCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --vcu_support=vcu0 --float_support=fpu32 --include_path="//VMWARE-HOST/Shared Folders/Documents/GitHub/UCI/EECS_X497/Lab3/Header/HwDrv" --include_path="C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="Source/HwDrv/F2806x_SysCtrl.d" --obj_directory="Source/HwDrv" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/HwDrv/LedDrv.obj: ../Source/HwDrv/LedDrv.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --vcu_support=vcu0 --float_support=fpu32 --include_path="//VMWARE-HOST/Shared Folders/Documents/GitHub/UCI/EECS_X497/Lab3/Header/HwDrv" --include_path="C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="Source/HwDrv/LedDrv.d" --obj_directory="Source/HwDrv" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


