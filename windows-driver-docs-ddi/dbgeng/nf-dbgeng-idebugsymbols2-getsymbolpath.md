# IDebugSymbols2::GetSymbolPath

## Description

The **GetSymbolPath** method returns the symbol path.

## Parameters

### `Buffer` [out, optional]

Receives the symbol path. This is a string that contains symbol path elements separated by semicolons (**;**). Each symbol path element can specify either a directory or a symbol server. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in characters, of the *Buffer* buffer.

### `PathSize` [out, optional]

Receives the size, in characters, of the symbol path.

## Return value

These methods can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer was not large enough to hold the symbol path and the path was truncated. |

## Remarks

For more information about manipulating the symbol path, see [Using Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-symbols). For an overview of the symbol path and its syntax, see [Symbol Path](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbol-path).

## See also

[AppendSymbolPath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-appendsymbolpath)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[SetSymbolPath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setsymbolpath)