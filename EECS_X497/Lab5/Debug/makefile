################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./Source/Apps/TempMonitor.obj" \
"./Source/Apps/lab5.obj" \
"./Source/HwDrv/F2806x_Adc.obj" \
"./Source/HwDrv/F2806x_DelayUs.obj" \
"./Source/HwDrv/F2806x_Gpio.obj" \
"./Source/HwDrv/F2806x_PieCtrl.obj" \
"./Source/HwDrv/F2806x_PieVect.obj" \
"./Source/HwDrv/F2806x_Startup.obj" \
"./Source/HwDrv/F2806x_SysCtrl.obj" \
"./Source/HwDrv/F2806x_Xint1.obj" \
"./Source/HwDrv/LedDrv.obj" \
"../F2806x-controlSTICK-RAM-1.cmd" \
"../F2806x_Headers_nonBIOS.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Source/Apps/subdir_vars.mk
-include Source/HwDrv/subdir_vars.mk
-include subdir_rules.mk
-include Source/Apps/subdir_rules.mk
-include Source/HwDrv/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Lab5.out \

EXE_OUTPUTS__QUOTED += \
"Lab5.out" \

BIN_OUTPUTS += \
Lab5.hex \

BIN_OUTPUTS__QUOTED += \
"Lab5.hex" \


# All Target
all: Lab5.out

# Tool invocations
Lab5.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --vcu_support=vcu0 --float_support=fpu32 -g --display_error_number --diag_warning=225 --diag_wrap=off -z -m"Lab5.map" --stack_size=0x300 --warn_sections -i"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/lib" -i"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="Lab5_linkInfo.xml" --entry_point=_code_start --rom_model -o "Lab5.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

Lab5.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C2000 Hex Utility'
	"C:/ti/ccsv6/tools/compiler/c2000_15.12.3.LTS/bin/hex2000"  -o "Lab5.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "Source\Apps\TempMonitor.d" "Source\Apps\lab5.d" "Source\HwDrv\F2806x_Adc.d" "Source\HwDrv\F2806x_Gpio.d" "Source\HwDrv\F2806x_PieCtrl.d" "Source\HwDrv\F2806x_PieVect.d" "Source\HwDrv\F2806x_SysCtrl.d" "Source\HwDrv\F2806x_Xint1.d" "Source\HwDrv\LedDrv.d" 
	-$(RM) "Source\Apps\TempMonitor.obj" "Source\Apps\lab5.obj" "Source\HwDrv\F2806x_Adc.obj" "Source\HwDrv\F2806x_DelayUs.obj" "Source\HwDrv\F2806x_Gpio.obj" "Source\HwDrv\F2806x_PieCtrl.obj" "Source\HwDrv\F2806x_PieVect.obj" "Source\HwDrv\F2806x_Startup.obj" "Source\HwDrv\F2806x_SysCtrl.obj" "Source\HwDrv\F2806x_Xint1.obj" "Source\HwDrv\LedDrv.obj" 
	-$(RM) "Source\HwDrv\F2806x_DelayUs.d" "Source\HwDrv\F2806x_Startup.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

