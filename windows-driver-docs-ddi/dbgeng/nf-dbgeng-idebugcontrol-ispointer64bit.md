# IDebugControl::IsPointer64Bit

## Description

The **IsPointer64Bit** method determines if the effective processor uses 64-bit pointers.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The effective processor uses 64-bit pointers. |
| **S_FALSE** | The effective processor does not use 64-bit pointers. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.