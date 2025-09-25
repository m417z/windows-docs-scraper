# MmGetSystemRoutineAddressEx function

## Description

The **MmGetSystemRoutineAddressEx** function returns the address of the specified function in the specified system module.

## Parameters

### `ModuleName`

Supplies a pointer to a **UNICODE_STRING** that describes the system module.

### `FunctionName`

Supplies a pointer to the name of the desired function.

## Return value

If the specified module is not in the loaded module list, the specified loaded module is the kernel or the HAL, or the specified function cannot be located, then NULL is returned. Otherwise, the appropriate bit is set in the CFG bitmap and a pointer to the specified function is returned.

## Remarks

## See also