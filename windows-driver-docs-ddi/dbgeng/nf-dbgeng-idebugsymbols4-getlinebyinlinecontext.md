# IDebugSymbols4::GetLineByInlineContext

## Description

Gets a line by inline context.

## Parameters

### `Offset` [in]

An offset for the line.

### `InlineContext` [in]

The inline context.

### `Line` [out, optional]

A pointer to the returned line.

### `FileBuffer` [out]

A pointer to an output buffer.

### `FileBufferSize` [in]

The size of the file buffer.

### `FileSize` [out, optional]

A pointer to the length of the file.

### `Displacement` [out, optional]

A pointer to the displacement value of the file.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDebugSymbols4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols4)