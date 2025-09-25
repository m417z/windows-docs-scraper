# IDebugSymbols3::GetFieldName

## Description

The **GetFieldName** method returns the name of a field within a structure.

## Parameters

### `Module` [in]

Specifies the base address of the module in which the structure was defined.

### `TypeId` [in]

Specifies the type ID of the structure.

### `FieldIndex` [in]

Specifies the index of the desired field within the structure.

### `NameBuffer` [out, optional]

Receives the field's name. If *NameBuffer* is **NULL**, this information is not returned.

### `NameBufferSize` [in]

Specifies the size in characters of the buffer *NameBuffer*. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

Receives the size in characters of the field's name. This size includes the space for the '\0' terminating character. If *NameSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, *NameBuffer* was not large enough to hold the field's name and it was truncated. |

## Remarks

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).