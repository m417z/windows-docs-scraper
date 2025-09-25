# IDebugSystemObjects2::SetImplicitProcessDataOffset

## Description

The **SetImplicitProcessDataOffset** method sets the implicit process for the current target.

## Parameters

### `Offset` [in]

Specifies the location in the target's memory address space of the data structure of the system process that is to become the implicit process for the current target. If this is zero, the implicit process for the current target is set to the default implicit process.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In kernel-mode debugging, the data structure is the KPROCESS structure for the process.

In user-mode debugging, the data structure is the process environment block (PEB) for the process.

**Warning** Because it is possible to use [SetImplicitThreadDataOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsystemobjects4-setimplicitthreaddataoffset) to set the implicit thread independently of the implicit process, the implicit thread might not belong to the implicit process. This can cause errors if you attempt to access any of the user state for the implicit thread, because it will be incompatible with the virtual address space (specified by the implicit process).

For more information about the current implicit process, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details on the KPROCESS and PEB structures, see *Microsoft Windows Internals* by David Solomon and Mark Russinovich.