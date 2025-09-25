# RxGetRDBSSProcess function

## Description

**RxGetRDBSSProcess** returns a pointer to the process of the main thread used by the RDBSS kernel process.

## Return value

**RxGetRDBSSProcess** returns a pointer to the kernel process of the main thread used by RDBSS.

## Remarks

When **RxDriverEntry** is called to initialize RDBSS, a pointer to the kernel process that is running is retrieved by calling **PsGetCurrentProcess** and stored in an internal RDBSS data structure. This value is returned when **RxGetRDBSSProcess** is called. This value is sometimes called the file system process.

## See also

[PsGetCurrentProcess](https://learn.microsoft.com/windows-hardware/drivers/kernel/mm-bad-pointer#psgetcurrentprocess)

[RxDriverEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxdriverentry)