# IDebugSymbols4::GetNameByInlineContextWide

## Description

Gets a name by inline context.

## Parameters

### `Offset` [in]

An offset for the inline context.

### `InlineContext` [in]

The inline context.

### `NameBuffer` [out]

A pointer an output buffer for a Unicode character string.

### `NameBufferSize` [in]

The size of the name buffer. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

A pointer to the length of the name. This size includes the space for the '\0' terminating character.

### `Displacement` [out, optional]

A pointer to the displacement value of the name.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDebugSymbols4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols4)