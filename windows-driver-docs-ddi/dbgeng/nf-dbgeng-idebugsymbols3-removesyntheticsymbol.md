# IDebugSymbols3::RemoveSyntheticSymbol

## Description

The **RemoveSyntheticSymbol** method removes a synthetic symbol from a module in the current process.

## Parameters

### `Id` [in]

Specifies the synthetic symbol to remove. This must be the same value returned in the *Id* parameter of [AddSyntheticSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-addsyntheticsymbol). See [DEBUG_MODULE_AND_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_and_id) for details about the type of this parameter.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | No synthetic symbol was found at the specified location. This is returned if a synthetic symbol at this location was previously removed or discarded. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

If the module containing a synthetic symbol is reloaded - for example, by calling [Reload](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-reload) with the *Module* parameter set to the name of the module - the synthetic symbol will be discarded.

For more information about synthetic symbols, see Synthetic Symbols.

## See also

[AddSyntheticSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-addsyntheticsymbol)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[RemoveSyntheticModule](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-removesyntheticmodule)