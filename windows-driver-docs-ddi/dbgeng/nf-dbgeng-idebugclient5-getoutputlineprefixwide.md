# IDebugClient5::GetOutputLinePrefixWide

## Description

Gets a Unicode character string prefix for output lines.

## Parameters

### `Buffer` [out]

The pointer to the buffer of the prefix.

### `BufferSize` [in]

The length of the buffer.

### `PrefixSize` [out, optional]

A pointer to the length of the prefix.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)