# IDebugSymbolGroup2::AddSymbolWide

## Description

The **AddSymbolWide** method adds a symbol to a [symbol group](https://learn.microsoft.com/windows-hardware/drivers/debugger/s).

## Parameters

### `Name` [in]

The symbol's name. *Name* is examined as an expression to determine the symbol's [type](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdtf/nf-wdtf-iwdtftarget2-get_type). This expression can include pointer, array, and structure dereferencing (for example, ***my_pointer**, **my_array[1]**, or **my_struct.some_field**).

### `Index` [in, out]

The index of the entry in the symbol group. When you are calling [AddSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-addsymbol) or **AddSymbolWide**, *Index* should point to the index of the symbol that you want. Or, if *Index* points to DEBUG_ANY_ID, the symbol is appended to the end of the list.

When this method returns, *Index* points to the actual index of the symbol. The index of a symbol is an identification number. The index ranges from zero through the number of symbols in the symbol group minus one.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

The symbol name in *Name* is evaluated by the [C++ expression evaluator](https://learn.microsoft.com/windows-hardware/drivers/debugger/c---numbers-and-operators) and can contain any C++ expression (for example, **x+y**).

If the index that you want is less than the size of the symbol group, the new symbol is added at the desired index. If the desired index is larger than the size of the symbol group, the new symbol is added to the end of the list (as in the case of DEBUG_ANY_ID).

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[GetNumberSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getnumbersymbols)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)

[RemoveSymbolByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-removesymbolbyindex)

[RemoveSymbolByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-removesymbolbyname)