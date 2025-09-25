# GetTebAddress function

## Description

The **GetTebAddress** function returns the address of the thread environment block (TEB) for the current operating system thread.

## Parameters

### `Address`

Receives the address of the TEB for the current operating system thread.

## Remarks

In user-mode debugging, the TEB for the current thread is returned. In kernel-mode debugging, the TEB for the operating system thread that was running on the current processor when the last event occurred is returned.

## See also

[GetPebAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nf-wdbgexts-getpebaddress)