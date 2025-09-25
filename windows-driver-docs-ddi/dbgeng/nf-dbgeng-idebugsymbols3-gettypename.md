# IDebugSymbols3::GetTypeName

## Description

The **GetTypeName** method returns the name of the type symbol specified by its type ID and module.

## Parameters

### `Module` [in]

Specifies the base address of the module to which the type belongs. For more information, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules).

### `TypeId` [in]

Specifies the type ID of the type.

### `NameBuffer` [out, optional]

Receives the name of the type. If *NameBuffer* is **NULL**, this information is not returned.

### `NameBufferSize` [in]

Specifies the size in characters of the buffer *NameBuffer*. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

Receives the size in characters of the type's name. This size includes the space for the '\0' terminating character. If *NameSize* is **NULL**, this information is not returned.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer was not large enough to hold the name of the type and it was truncated. |
| **E_FAIL** | The specified type could not be found in the specified module. |

## Remarks

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetTypeSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-gettypesize)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)