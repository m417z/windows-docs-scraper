# IDebugSymbols3::SetSourcePath

## Description

The **SetSourcePath** method sets the source path.

## Parameters

### `Path` [in]

Specifies the new source path. This is a string that contains source path elements separated by semicolons (**;**). Each source path element can specify either a directory or a source server.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The source path is used by the engine when searching for source files.

For more information about manipulating the source path, see [Using Source Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-source-files). For an overview of the source path and its syntax, see [Source Path](https://learn.microsoft.com/windows-hardware/drivers/debugger/source-path).

## See also

[AppendSourcePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-appendsourcepath)

[GetSourcePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsourcepath)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)