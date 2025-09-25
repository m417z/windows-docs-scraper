# IDebugControl2::GetReturnOffset

## Description

The **GetReturnOffset** method returns the return address for the current function.

## Parameters

### `Offset` [out]

Receives the return address.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The return address is the location in the process's virtual address space of the instruction that will be executed when the current function returns.