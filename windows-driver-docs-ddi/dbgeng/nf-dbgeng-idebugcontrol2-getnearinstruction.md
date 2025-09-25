# IDebugControl2::GetNearInstruction

## Description

The **GetNearInstruction** method returns the location of a processor instruction relative to a given location.

## Parameters

### `Offset` [in]

Specifies the location in the process's virtual address space from which to start looking for the desired instruction.

### `Delta` [in]

Specifies the number of instructions from *Offset* of the desired instruction. If *Delta* is negative, the returned offset is before *Offset* (see the Remarks section for more information).

### `NearOffset` [out]

Receives the location in the process's virtual address space of the instruction that is *Delta* instructions away from *Offset*.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

On some architectures, like x86 and x64, the size of an instruction may vary. On these architectures, when *Delta* is negative, the desired instruction location might not be uniquely defined. In this case, the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) will search backward from *Offset* until it encounters a location such that there are the *Delta* number of instructions between that location and *Offset*.