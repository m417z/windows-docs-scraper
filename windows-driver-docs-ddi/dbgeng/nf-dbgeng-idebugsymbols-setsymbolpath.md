# IDebugSymbols::SetSymbolPath

## Description

The **SetSymbolPath** method sets the symbol path.

## Parameters

### `Path` [in]

Specifies the new symbol path. This is a string that contains symbol path elements separated by semicolons (;). Each symbol path element can specify either a directory or a symbol server.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about manipulating the symbol path, see [Using Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-symbols). For an overview of the symbol path and its syntax, see [Symbol Path](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbol-path).

## See also

[AppendSymbolPath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-appendsymbolpath)

[GetSymbolPath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsymbolpath)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)