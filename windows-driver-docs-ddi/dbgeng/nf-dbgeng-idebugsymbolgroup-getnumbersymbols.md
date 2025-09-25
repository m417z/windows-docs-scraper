# IDebugSymbolGroup::GetNumberSymbols

## Description

The **GetNumberSymbols** method returns the number of [symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4) that are contained in a symbol group.

## Parameters

### `Number` [out]

The number of symbols that are contained in this symbol group.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

Each symbol in a symbol group is identified by an *index*. This index is a number between zero and the number that is returned to *Number* minus one. Every time that a symbol is added or removed from the symbol group, the index of all of the symbols in the group might change.

For more information about symbol groups, see [Scopes and Symbol Groups](https://learn.microsoft.com/windows-hardware/drivers/debugger/scopes-and-symbol-groups).