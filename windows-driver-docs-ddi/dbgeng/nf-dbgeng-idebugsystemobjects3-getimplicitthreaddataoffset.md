# IDebugSystemObjects3::GetImplicitThreadDataOffset

## Description

The **GetImplicitThreadDataOffset** method returns the implicit thread for the current process.

## Parameters

### `Offset` [out]

Receives the location in the target's memory address space of the data structure of the system thread that is the implicit thread for the current process.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In kernel-mode debugging, the data structure is the KTHREAD structure for the process.

In user-mode debugging, the data structure is the thread environment block (TEB) for the process.

For more information about the implicit thread, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details on the KTHREAD structure and TEB, see *Microsoft Windows Internals* by David Solomon and Mark Russinovich.