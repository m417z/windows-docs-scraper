# IDebugSymbols::GetSourcePath

## Description

The **GetSourcePath** method returns the source path.

## Parameters

### `Buffer` [out, optional]

Receives the source path. This is a string that contains source path elements separated by semicolons (**;**). Each source path element can specify either a directory or a source server. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in characters, of the *Buffer* buffer.

### `PathSize` [out, optional]

Receives the size, in characters, of the source path.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer was not large enough to hold the source path and the path was truncated. |

## Remarks

The source path is used by the engine when searching for source files.

For more information about manipulating the source path, see [Using Source Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-source-files). For an overview of the source path and its syntax, see [Source Path](https://learn.microsoft.com/windows-hardware/drivers/debugger/source-path).

## See also

[AppendSourcePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-appendsourcepath)

[GetSourcePathElement](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsourcepathelement)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[SetSourcePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setsourcepath)