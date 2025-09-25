# IDebugSymbolGroup2::GetSymbolRegister

## Description

The **GetSymbolRegister** method returns the register that contains the value or a pointer to the value of a symbol in a symbol group.

## Parameters

### `Index` [in]

The index of the symbol to return the register for. The index of a symbol is an identification number. The index ranges from zero through the number of symbols in the symbol group minus one.

### `Register` [out]

The index of the register that contains the value or a pointer to the value of the symbol.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | The symbol's value and a pointer to it are not contained in a register, or the register is not known. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups). For more information about registers and the register index, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## See also

[GetNumberSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getnumbersymbols)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)