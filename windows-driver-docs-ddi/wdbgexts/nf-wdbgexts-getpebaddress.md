# GetPebAddress function

## Description

The **GetPebAddress** function returns the address of the process environment block (PEB) for a system process.

## Parameters

### `CurrentThread`

Specifies an operating system thread whose PEB's address will be returned.

In kernel-mode debugging, this is the location of the KTHREAD structure, which is returned by [GetCurrentThreadAddr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-getcurrentthreadaddr). If *CurrentThread* is **NULL**, the PEB for the current process is returned.

In user-mode debugging, *CurrentThread* is ignored.

### `Address`

Receives the address of the PEB for the current operating system process or, in kernel-mode debugging, when *CurrentThread* is not **NULL**, for the system process that contains the thread that is specified by *CurrentThread*.

## Remarks

In user-mode debugging, the PEB for the current thread is returned.

In kernel-mode debugging, if *CurrentThread* is **NULL**, the PEB for the operating system process in which the last event occurred is returned.

## See also

[GetCurrentThreadAddr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-getcurrentthreadaddr)

[GetTebAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-gettebaddress)