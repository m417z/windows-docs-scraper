# IDebugSymbols3::GetSourceFileLineOffsets

## Description

The **GetSourceFileLineOffsets** method maps each line in a source file to a location in the target's memory.

## Parameters

### `File` [in]

Specifies the name of the file whose lines will be turned into locations in the target's memory. The symbols for each module in the target are queried for this file. If the file is not located, the path is dropped and the symbols are queried again.

### `Buffer` [out, optional]

Receives the locations in the target's memory that correspond to the lines of the source code. The first entry returned to this array corresponds to the first line of the file, so that `Buffer[i]` contains the location for line `i+1`. If no symbol information is available for a line, the corresponding entry in *Buffer* is set to DEBUG_INVALID_OFFSET. If *Buffer* is **NULL**, this information is not returned.

### `BufferLines` [in]

Specifies the number of PULONG64 objects that the *Buffer* array can hold.

### `FileLines` [out, optional]

Receives the number of lines in the source file specified by *File*.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the number of lines in the source file exceeded the number of entries in the *Buffer* array and some of the results were discarded. |

## Remarks

For more information about using the source path, see [Using Source Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-source-files).

## See also

[FindSourceFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-findsourcefile)

[GetSourceEntriesByLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsourceentriesbyline)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)