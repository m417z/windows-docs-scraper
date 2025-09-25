# IDebugSystemObjects2::SetImplicitThreadDataOffset

## Description

The **SetImplicitThreadDataOffset** method sets the implicit thread for the current process.

## Parameters

### `Offset` [in]

Specifies the location in the target's memory address space of the data structure of the system thread that is to become the implicit thread for the current process. If this is zero, the implicit thread for the current process is set to the default implicit thread.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In kernel-mode debugging, the data structure is the KTHREAD structure for the process.

In user-mode debugging, the data structure is the thread environment block (TEB) for the process.

**Warning** Because it is possible to use [SetImplicitProcessDataOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsystemobjects4-setimplicitprocessdataoffset) to set the implicit process independently of the implicit thread, the implicit thread might not belong to the implicit process. This can cause errors if you attempt to access any of the user state for the implicit thread, because it will be incompatible with the virtual address space (specified by the implicit process).

For more information about the current implicit thread, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details on the KTHREAD structure and TEB, see *Microsoft Windows Internals* by David Solomon and Mark Russinovich.