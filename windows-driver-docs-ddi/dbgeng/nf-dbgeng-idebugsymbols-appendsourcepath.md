# IDebugSymbols::AppendSourcePath

## Description

The **AppendSourcePath** method appends directories to the source path.

## Parameters

### `Addition` [in]

Specifies the directories to append to the source path. This is a string that contains source path elements separated by semicolons (;). Each source path element can specify either a directory or a source server.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

The source path is used by the engine when searching for source files.

For more information about manipulating the source path, see [Using Source Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-source-files). For an overview of the source path and its syntax, see [Source Path](https://learn.microsoft.com/windows-hardware/drivers/debugger/source-path).

## See also

[GetSourcePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsourcepath)

[GetSourcePathElement](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsourcepathelement)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)

[SetSourcePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-setsourcepath)