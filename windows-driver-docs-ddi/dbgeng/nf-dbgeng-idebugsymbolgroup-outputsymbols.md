# IDebugSymbolGroup::OutputSymbols

## Description

The **OutputSymbols** method prints the specified [symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4) to the debugger console.

## Parameters

### `OutputControl` [in]

The output control to use when printing the symbols' information. For more information about possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx). For more information about output, see [Input and Output](https://learn.microsoft.com/windows-hardware/drivers/debugger/input-and-output).

### `Flags` [in]

The flags that determine what information is printed for each symbol. By default, the output includes the symbol's name, offset, value, and type. The format for the output is as follows:

`Name**NAME**Offset**OFF**Value**VALUE**Type**TYPE**`

You can use the following bit flags to suppress the output of one of these pieces of information together with the corresponding marker.

| Value | Description |
| --- | --- |
| DEBUG_OUTPUT_SYMBOLS_NO_NAMES | Suppress output of the symbol's name. |
| DEBUG_OUTPUT_SYMBOLS_NO_OFFSETS | Suppress output of the symbol's offset. |
| DEBUG_OUTPUT_SYMBOLS_NO_VALUES | Suppress output of the symbol's value. |
| DEBUG_OUTPUT_SYMBOLS_NO_TYPES | Suppress output of the symbol's type. |

### `Start` [in]

The index of the first symbol in the symbol group to print. The index of a symbol is an identification number. This number ranges from zero through the number of symbols in the symbol group minus one.

### `Count` [in]

The number of symbols to print.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).

## See also

[GetNumberSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getnumbersymbols)

[IDebugSymbolGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup)

[IDebugSymbolGroup2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbolgroup2)