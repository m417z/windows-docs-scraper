# IDebugSymbols3::GetSourceEntriesByLineWide

## Description

The **GetSourceEntriesByLineWide** method queries symbol information and returns locations in the target's memory that correspond to lines in a source file.

## Parameters

### `Line` [in]

Specifies the line in the source file for which to query. The number for the first line is **1**.

### `File` [in]

Specifies the source file. The symbols for each module in the target are queried for this file.

### `Flags` [in]

Specifies bit flags that control the behavior of this method. *Flags* can be any combination of values from the following table.

| Value | Description |
| --- | --- |
| DEBUG_GSEL_NO_SYMBOL_LOADS | The [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) will only search for the file among the modules whose symbols have already been loaded. Symbols for the other modules will not be loaded.<br><br>If this option is not set, the debugger engine will load the symbols for all modules until it finds the file specified in *File*. |
| DEBUG_GSEL_ALLOW_LOWER | Include all the lines in *File* before *Line* in the result. |
| DEBUG_GSEL_ALLOW_HIGHER | Include all the lines in *File* after *Line* in the result. |
| DEBUG_GSEL_NEAREST_ONLY | Only return at most one result. If DEBUG_GSEL_ALLOW_LOWER or DEBUG_GSEL_ALLOW_HIGHER are set, the returned result will be for a line close to *Line* but cannot be *Line* if there is no symbol information for that line. |

To use the default set of flags, set *Flags* to DEBUG_GSEL_DEFAULT. This has all the flags in the previous table turned off.

### `Entries` [out, optional]

Receives the locations in the target's memory that correspond to the source lines queried for. Each entry in this array is of type [DEBUG_SYMBOL_SOURCE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_source_entry) and contains the source line number along with a location in the target's memory.

### `EntriesCount` [in]

Specifies the number of entries in the *Entries* array.

### `EntriesAvail` [out, optional]

Receives the number of locations that match the query found in the target's memory.

## Return value

These methods can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the *Entries* array was not large enough to hold all the results that matched the query and the extra results were discarded. |
| **E_NOINTERFACE** | The query yielded no results. This includes the case where the symbol information was not available for the specified file. |

## Remarks

These methods can be used by debugger applications to fetch locations in the target's memory for setting breakpoints or matching source code with disassembled instructions. For example, setting the flags DEBUG_GSEL_ALLOW_HIGHER and DEBUG_GSEL_NEAREST_ONLY will return the target's memory location for the first piece of code starting at the specified line.

For more information about source files, see [Using Source Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-source-files).

## See also

[DEBUG_SYMBOL_SOURCE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_symbol_source_entry)

[GetSourceFileLineOffsets](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsourcefilelineoffsets)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)