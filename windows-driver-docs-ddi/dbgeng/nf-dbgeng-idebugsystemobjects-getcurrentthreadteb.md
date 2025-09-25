# IDebugSystemObjects::GetCurrentThreadTeb

## Description

The **GetCurrentThreadTeb** method returns the location of the thread environment block (TEB) for the current thread.

## Parameters

### `Offset` [out]

Receives the location in the target's virtual address space of the TEB for the current thread.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In user-mode debugging, this method provides the same information as [GetCurrentThreadDataOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsystemobjects4-getcurrentthreaddataoffset).

In kernel-mode debugging, the location returned is of the TEB structure of the system thread that was executing on the processor represented by the current thread when the last event occurred.

**Note** In kernel mode, the current thread is always a virtual thread the debugger created for a processor in the target computer. Because events may occur in different system threads, the TEB location for a virtual thread may change.

For more information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details on the TEB structure, see *Microsoft Windows Internals* by David Solomon and Mark Russinovich.