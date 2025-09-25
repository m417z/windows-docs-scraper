# GetCurrentThreadAddr function

## Description

The **GetCurrentThreadAddr** function returns the location of the system data that describes the current thread.

## Parameters

### `Processor`

Specifies the index of the thread whose system data will be returned.

In kernel-mode debugging, this is the index of a virtual thread, which is the index of a processor on the target computer.

### `Address`

Receives the location of the system data for the thread.

## Remarks

In user-mode debugging, **GetCurrentThreadAddr** returns the location of the thread's Thread Environment Block (TEB). This is the same location that [GetTebAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-gettebaddress) returns.

In kernel-mode debugging, **GetCurrentThreadAddr** returns the location of the KTHREAD structure of the operating system thread that was executing on the processor when the last event occurred.

For details on the KTHREAD and TEB structures, see *Microsoft Windows Internals* by David Solomon and Mark Russinovich.

## See also

[GetTebAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-gettebaddress)