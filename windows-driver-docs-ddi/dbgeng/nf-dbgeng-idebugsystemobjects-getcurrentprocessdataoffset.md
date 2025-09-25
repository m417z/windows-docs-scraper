# IDebugSystemObjects::GetCurrentProcessDataOffset

## Description

The **GetCurrentProcessDataOffset** method returns the location of the system data structure describing the current process.

## Parameters

### `Offset` [out]

Receives the location in the target's virtual address space of the system data structure describing the current process.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In user-mode debugging, the location returned is of the process environment block (PEB) for the current process. This is the same location returned by [GetCurrentProcessPeb](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsystemobjects4-getcurrentprocesspeb).

In kernel-mode debugging, the location returned is of the KPROCESS structure for the system process in which the last event occurred.

**Note** In kernel mode, the current process of the target is always the single virtual process the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) created for the kernel. However, because events may occur in different system processes, the KPROCESS location returned by this method may change.

For more information about processes, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details about the PEB and KPROCESS structures, see *Microsoft Windows Internals* by David Solomon and Mark Russinovich.