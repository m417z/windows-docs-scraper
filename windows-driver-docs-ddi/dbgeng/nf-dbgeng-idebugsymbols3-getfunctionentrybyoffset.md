# IDebugSymbols3::GetFunctionEntryByOffset

## Description

The **GetFunctionEntryByOffset** method returns the function entry information for a function.

## Parameters

### `Offset` [in]

Specifies a location in the current process's virtual address space of the function's implementation. This is the value returned in the *Offset* parameter of [GetNextSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getnextsymbolmatch) and [IDebugSymbolGroup::GetSymbolOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getsymboloffset), and the value of the **Offset** field in the [DEBUG_SYMBOL_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_entry) structure.

### `Flags` [in]

Specifies a bit-flag which alters the behavior of this method. If the bit DEBUG_GETFNENT_RAW_ENTRY_ONLY is not set, the engine will provide artificial entries for well known cases. If this bit is set the artificial entries are not used.

### `Buffer` [out, optional]

Receives the function entry information. If the effective processor is an x86, this is the FPO_DATA structure for the function. For all other architectures, this is the IMAGE_FUNCTION_ENTRY structure for that architecture.

### `BufferSize` [in]

Specifies the size of the buffer *Buffer*.

### `BufferNeeded` [out, optional]

Specifies the size of the function entry information.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful, but the buffer was not large enough to hold the function entry information and so the information was truncated to fit. |
| **E_NOINTERFACE** | No function entry information was found for the location *Offset*. |

## Remarks

The structures FPO_DATA and IMAGE_FUNCTION_ENTRY are documented in "Image Help Library" which is included in Debugging Tools For Windows in the DbgHelp.chm file.

**Note** The functions in "Image Help Library" and "Debug Help Library", documented in DbgHelp.chm, should not be called by any extension or debugger engine application.

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[DEBUG_SYMBOL_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_entry)

[GetNextSymbolMatch](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getnextsymbolmatch)

[IDebugSymbolGroup::GetSymbolOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbolgroup2-getsymboloffset)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)