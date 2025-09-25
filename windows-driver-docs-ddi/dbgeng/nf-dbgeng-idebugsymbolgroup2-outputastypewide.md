# IDebugSymbolGroup2::OutputAsTypeWide

## Description

The **OutputAsTypeWide** method changes the type of a symbol in a symbol group. The symbol's entry is updated to represent the new type.

## Parameters

### `Index` [in]

The index of the entry in this symbol group. The *index* of a symbol is an identification number. The index ranges from zero through the number of symbols in the symbol group minus one.

### `Type` [in]

The name of the type of the symbol that you want. If the name begins with an exclamation mark (**!**), the name is treated as an extension. For more information about how to use an extension as a type, see the Remarks section.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

Because the children of the new entry type might differ from the children of the old entry type, the **OutputAsTypeWide** method removes all of the children of the entry from the symbol group. You can add the children back by using the [ExpandSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-expandsymbol) method.

If *Type* is an extension, the address of the symbol is passed to the extension. Every line of output from the extension becomes a child symbol of the specified symbol. These child symbols are text and you cannot manipulate them in any way. For example, if the name of a variable is **@$teb**, you can change its type to **!teb**.

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[ExpandSymbol](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-expandsymbol)

[GetNumberSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getnumbersymbols)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)