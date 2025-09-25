# MmGetSystemRoutineAddress function

## Description

The **MmGetSystemRoutineAddress** routine returns a pointer to a function specified by *SystemRoutineName*.

## Parameters

### `SystemRoutineName` [in]

Specifies the name of the system routine to resolve.

## Return value

If the function name can be resolved, the routine returns a pointer to the function. Otherwise, the routine returns **NULL**.

## Remarks

Drivers can use this routine to determine if a routine is available on a specific version of Windows. It can only be used for routines exported by the kernel or HAL, not for any driver-defined routine.

## See also

[IoIsWdmVersionAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioiswdmversionavailable)