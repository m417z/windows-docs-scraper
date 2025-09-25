# IDebugSymbols3::GetLineByOffsetWide

## Description

The **GetLineByOffsetWide** method returns the source filename and the line number within the source file of an instruction in the target.

## Parameters

### `Offset` [in]

Specifies the location in the target's virtual address space of the instruction for which to return the source file and line number.

### `Line` [out, optional]

Receives the line number within the source file of the instruction specified by *Offset*. If *Line* is **NULL**, this information is not returned.

### `FileBuffer` [out, optional]

Receives the file name of the file that contains the instruction specified by *Offset*. If *FileBuffer* is **NULL**, this information is not returned.

### `FileBufferSize` [in]

Specifies the size, in characters, of the *FileBuffer* buffer.

### `FileSize` [out, optional]

Specifies the size, in characters, of the source filename. If *FileSize* is **NULL**, this information is not returned.

### `Displacement` [out, optional]

Receives the difference between the location specified in *Offset* and the location of the first instruction of the returned line. If *Displacement* is **NULL**, this information is not returned.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer was not large enough to hold the name of the source file and the name was truncated. |

## Remarks

For more information about source files, see [Using Source Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-source-files).

## See also

[GetOffsetByLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getoffsetbyline)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)