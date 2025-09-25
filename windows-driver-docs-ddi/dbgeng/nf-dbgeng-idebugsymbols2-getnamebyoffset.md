# IDebugSymbols2::GetNameByOffset

## Description

The **GetNameByOffset** method returns the name of the symbol at the specified location in the target's virtual address space.

## Parameters

### `Offset` [in]

Specifies the location in the target's virtual address space of the symbol whose name is requested. *Offset* does not need to specify the base location of the symbol; it only needs to specify a location within the symbol's memory allocation.

### `NameBuffer` [out, optional]

Receives the symbol's name. The name is qualified by the module to which the symbol belongs (for example, **mymodule!main**). If *NameBuffer* is **NULL**, this information is not returned.

### `NameBufferSize` [in]

Specifies the size in characters of the buffer *NameBuffer*. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

Receives the size in characters of the symbol's name. This size includes the space for the '\0' terminating character. If *NameSize* is **NULL**, this information is not returned.

### `Displacement` [out, optional]

Receives the difference between the value of *Offset* and the base location of the symbol. If *Displacement* is **NULL**, this information is not returned.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer was not large enough to hold the symbol's name, so it was truncated. |
| **E_FAIL** | No symbol could be found at the specified location. |

## Remarks

For more information about symbols and symbol names, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetNearNameByOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getnearnamebyoffset)

[GetOffsetByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getoffsetbyname)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)