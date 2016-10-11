################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Source/Apps/TempMonitor.obj: ../Source/Apps/TempMonitor.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --vcu_support=vcu0 --float_support=fpu32 --include_path="C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="//VMWARE-HOST/Shared Folders/Documents/GitHub/UCI/EECS_X497/Lab5/Header/HwDrv" --include_path="//VMWARE-HOST/Shared Folders/Documents/GitHub/UCI/EECS_X497/Lab5/Header/Apps" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="Source/Apps/TempMonitor.d" --obj_directory="Source/Apps" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/Apps/lab5.obj: ../Source/Apps/lab5.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --vcu_support=vcu0 --float_support=fpu32 --include_path="C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --include_path="//VMWARE-HOST/Shared Folders/Documents/GitHub/UCI/EECS_X497/Lab5/Header/HwDrv" --include_path="//VMWARE-HOST/Shared Folders/Documents/GitHub/UCI/EECS_X497/Lab5/Header/Apps" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="Source/Apps/lab5.d" --obj_directory="Source/Apps" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


