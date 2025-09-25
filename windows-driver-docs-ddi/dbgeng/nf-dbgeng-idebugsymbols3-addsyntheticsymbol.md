# IDebugSymbols3::AddSyntheticSymbol

## Description

The **AddSyntheticSymbol** method adds a synthetic symbol to a module in the [current process](https://learn.microsoft.com/windows-hardware/drivers/debugger/c).

## Parameters

### `Offset` [in]

Specifies the location in the process's virtual address space of the synthetic symbol.

### `Size` [in]

Specifies the size in bytes of the synthetic symbol.

### `Name` [in]

Specifies the name of the synthetic symbol.

### `Flags` [in]

Set to DEBUG_ADDSYNTHSYM_DEFAULT.

### `Id` [out, optional]

Receives the [DEBUG_MODULE_AND_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_module_and_id) structure that identifies the synthetic symbol. If *Id* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

The location of the synthetic symbol must not be the same as the location of another symbol.

If the module containing a synthetic symbol is reloaded - for example, by calling [Reload](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-reload) with the *Module* parameter set to the name of the module - the synthetic symbol will be discarded.

For more information about synthetic symbols, see [Synthetic Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-symbols).

## See also

[AddSyntheticModule](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-addsyntheticmodule)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[RemoveSyntheticSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-removesyntheticsymbol)