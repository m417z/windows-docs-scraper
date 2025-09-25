# IDebugSystemObjects3::GetCurrentProcessPeb

## Description

The **GetCurrentProcessPeb** method returns the process environment block (PEB) of the current process.

## Parameters

### `Offset` [out]

Receives the location in the target's virtual address space of the PEB of the current process.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In user-mode debugging, this method provides the same information as [GetCurrentProcessDataOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsystemobjects4-getcurrentprocessdataoffset).

In kernel-mode debugging, the location returned is that of the PEB structure for the system process in which the last event occurred.

**Note** In kernel mode, the current process of the target is always the single virtual process the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) created for the kernel. However, because events may occur in different system processes, the PEB location returned by this method may change.

For more information about processes, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).