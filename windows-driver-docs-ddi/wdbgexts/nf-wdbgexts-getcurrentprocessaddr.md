# GetCurrentProcessAddr function

## Description

The **GetCurrentProcessAddr** function returns the location of the system data that describes the current process.

## Parameters

### `Processor`

Specifies the index of the processor or virtual thread that was running the current thread when the last event occurred. *Processor* is only used in kernel-mode debugging; and, only if *CurrentThread* is **NULL**.

### `CurrentThread`

Specifies the location of the system data for the current thread. This is the location returned by [GetCurrentThreadAddr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-getcurrentthreadaddr).

In kernel-mode debugging, *CurrentThread* can be **NULL**, in which case *Processor* is used instead.

### `Address`

Receives the location of the system data that describes the current process.

## Remarks

In user-mode debugging, **GetCurrentProcessAddr** returns the location of the process's Process Environment Block (PEB). This is the same location that [GetPebAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-getpebaddress) returns.

In kernel-mode debugging, **GetCurrentProcessAddr** returns the location of the KPROCESS structure of the current process.

For details on the KPROCESS and PEB structures, see *Microsoft Windows Internals* by David Solomon and Mark Russinovich.

## See also

[GetCurrentThreadAddr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-getcurrentthreadaddr)

[GetPebAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-getpebaddress)