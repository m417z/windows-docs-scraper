# IDebugSymbols2::AddSymbolOptions

## Description

The **AddSymbolOptions** method turns on some of the engine's global symbol options.

## Parameters

### `Options` [in]

Specifies the symbol options to turns on. *Options* is a bit-set that will be ORed with the existing symbol options. For a description of the bit flags, see [Setting Symbol Options](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbol-options).

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

After the symbol options have been changed, for each client the engine sends out notification to that client's [IDebugEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugeventcallbacks) by passing the DEBUG_CES_SYMBOL_OPTIONS flag to the [IDebugEventCallbacks::ChangeSymbolState](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugeventcallbacks-changesymbolstate) method.

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetSymbolOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsymboloptions)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[RemoveSymbolOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-removesymboloptions)

[SetSymbolOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setsymboloptions)