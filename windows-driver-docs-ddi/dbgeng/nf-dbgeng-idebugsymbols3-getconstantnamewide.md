# IDebugSymbols3::GetConstantNameWide

## Description

The **GetConstantNameWide** method returns the name of the specified constant.

## Parameters

### `Module` [in]

Specifies the base address of the module in which the constant was defined.

### `TypeId` [in]

Specifies the type ID of the constant.

### `Value` [in]

Specifies the value of the constant.

### `NameBuffer` [out, optional]

Receives the constant's name. If *NameBuffer* is **NULL**, this information is not returned.

### `NameBufferSize` [in]

Specifies the size in characters of the buffer *NameBuffer*. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

Receives the size in characters of the constant's name. This size includes the space for the '\0' terminating character.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer was not large enough for the constant's name and it was truncated. |

## Remarks

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).