# IDebugSystemObjects4::GetImplicitProcessDataOffset

## Description

The **GetImplicitProcessDataOffset** method returns the implicit process for the current target.

## Parameters

### `Offset` [out]

Receives the location in the target's memory address space of the data structure of the system process that is the implicit process for the current target.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

In kernel-mode debugging, the data structure is the KPROCESS structure for the process.

In user-mode debugging, the data structure is the process environment block (PEB) for the process.

For more information about the implicit process, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes). For details on the KPROCESS and PEB structures, see *Microsoft Windows Internals* by David Solomon and Mark Russinovich.