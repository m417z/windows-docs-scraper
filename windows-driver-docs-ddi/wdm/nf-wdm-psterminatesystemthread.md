# PsTerminateSystemThread function

## Description

The **PsTerminateSystemThread** routine terminates the current system thread.

## Parameters

### `ExitStatus` [in]

Specifies the status of the terminating system thread.

## Return value

**PsTerminateSystemThread** does not return if it successfully terminates the calling thread. If the routine cannot terminate the thread (for example, if the thread is not a system thread), the routine returns an error NTSTATUS value.

## Remarks

A system thread calls **PsTerminateSystemThread** to terminate itself. A driver that creates its own threads must ensure that each such thread terminates. The driver must not terminate any threads that the system or other drivers created.

## See also

[PsCreateSystemThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pscreatesystemthread)