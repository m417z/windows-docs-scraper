# IDebugSymbolGroup2::WriteSymbolWide

## Description

The **WriteSymbolWide** method sets the value of the specified symbol.

## Parameters

### `Index` [in]

The index of the symbol whose value will be changed. The index of a symbol is an identification number. The index ranges from zero through the number of symbols in the symbol group minus one.

### `Value` [in]

A C++ expression that is evaluated to give the symbol's new value.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

This method can change symbols only if the symbols are stored in a register or memory location that the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) knowns and if they have not had their type changed to an extension by using the [OutputAsType](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-outputastype) method.

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[GetNumberSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getnumbersymbols)

[GetSymbolValueText](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getsymbolvaluetext)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)