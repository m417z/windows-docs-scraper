# IDebugSymbols3::OutputSymbolByOffset

## Description

The **OutputSymbolByOffset** method looks up a symbol by address and prints the symbol name and other symbol information to the debugger console.

## Parameters

### `OutputControl` [in]

Specifies where to send the output. For possible values, see [DEBUG_OUTCTL_XXX](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-outctl-xxx).

### `Flags` [in]

Specifies the flags used to determine what information is printed with the symbol.

The following flags can be present:

| Bit-flag | Effect |
| --- | --- |
| DEBUG_OUTSYM_FORCE_OFFSET | Include the location of the symbol. |
| DEBUG_OUTSYM_SOURCE_LINE | Include the file name and line number of the source file where the symbol is defined. |
| DEBUG_OUTSYM_ALLOW_DISPLACEMENT | Do not require an exact match for the symbols location.<br><br>This allows the *Offset* parameter to specify any address within the symbol's memory allocation - not just the base address. |

### `Offset` [in]

Specifies the location in the process's virtual address space of the symbol to be printed.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | No symbol was found at the specified location. |

## Remarks

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetNameByOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getnamebyoffset)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)