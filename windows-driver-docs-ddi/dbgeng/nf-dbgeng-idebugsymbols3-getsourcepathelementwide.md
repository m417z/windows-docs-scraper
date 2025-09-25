# IDebugSymbols3::GetSourcePathElementWide

## Description

The **GetSourcePathElementWide** method returns an element from the source path.

## Parameters

### `Index` [in]

Specifies the index of the element in the source path that will be returned. The source path is a string that contains elements separated by semicolons (;). The index of the first element is zero.

### `Buffer` [out, optional]

Receives the source path element. Each source path element can be a directory or a source server. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in characters, of the *Buffer* buffer.

### `ElementSize` [out, optional]

Receives the size, in characters, of the source path element.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | The source path contains fewer than *Index* elements. |

## Remarks

The source path is used by the engine when searching for source files.

For more information about manipulating the source path, see [Using Source Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-source-files). For an overview of the source path and its syntax, see [Source Path](https://learn.microsoft.com/windows-hardware/drivers/debugger/source-path).

## See also

[AppendSourcePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-appendsourcepath)

[GetSourcePath](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getsourcepath)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)