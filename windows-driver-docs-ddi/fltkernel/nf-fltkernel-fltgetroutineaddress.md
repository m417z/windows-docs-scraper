# FltGetRoutineAddress function

## Description

The **FltGetRoutineAddress** routine returns a pointer to a routine specified by the *FltMgrRoutineName* parameter.

## Parameters

### `FltMgrRoutineName` [in]

Name of the filter manager routine to resolve.

## Return value

If the routine name can be resolved, **FltGetRoutineAddress** returns a pointer to the routine. Otherwise, it returns **NULL**.

## Remarks

**FltGetRoutineAddress** searches the filter manager's export table for the requested routine name.

To get the addresses of other routines that are exported by the kernel or hardware abstraction layer (HAL), use [MmGetSystemRoutineAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemroutineaddress).

Note that in Windows 2000 and Windows XP, before FltGetRoutineAddress is called at least one minifilter on the system must call FltRegisterFilter. The call to FltRegisterFilter is necessary to initialize global data structures.

## See also

[MmGetSystemRoutineAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemroutineaddress)