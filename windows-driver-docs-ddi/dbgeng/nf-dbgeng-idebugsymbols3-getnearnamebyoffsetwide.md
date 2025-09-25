# IDebugSymbols3::GetNearNameByOffsetWide

## Description

The **GetNearNameByOffsetWide** method returns the name of a symbol that is located near the specified location.

## Parameters

### `Offset` [in]

Specifies the location in the target's virtual address space of the symbol from which the desired symbol is determined.

### `Delta` [in]

Specifies the relationship between the desired symbol and the symbol located at *Offset*. If positive, the engine will return the symbol that is *Delta* symbols after the symbol located at *Offset*. If negative, the engine will return the symbol that is *Delta* symbols before the symbol located at *Offset*.

### `NameBuffer` [out, optional]

Receives the symbol's name. The name is qualified by the module to which the symbol belongs (for example, **mymodule!main**). If *NameBuffer* is **NULL**, this information is not returned.

### `NameBufferSize` [in]

Specifies the size in characters of the buffer *NameBuffer*. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

Receives the size in characters of the symbol's name. This size includes the space for the '\0' terminating character. If *NameSize* is **NULL**, this information is not returned.

### `Displacement` [out, optional]

Receives the difference between the value of *Offset* and the location in the target's memory address space of the symbol. If *Displacement* is **NULL**, this information is not returned.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer was not large enough to hold the symbol's name so it was truncated. |
| **E_NOINTERFACE** | No symbol matching the specifications of *Offset* and *Delta* was found. |

## Remarks

By increasing or decreasing the value of *Delta*, these methods can be used to iterate over the target's symbols starting at a particular location.

If *Delta* is zero, these methods behave the same way as [GetNameByOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getnamebyoffset).

For more information about symbols and symbol names, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetNameByOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getnamebyoffset)

[GetOffsetByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getoffsetbyname)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)