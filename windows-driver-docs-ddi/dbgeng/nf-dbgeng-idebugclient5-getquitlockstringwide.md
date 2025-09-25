# IDebugClient5::GetQuitLockStringWide

## Description

Gets a Unicode character quit lock string.

## Parameters

### `Buffer` [out]

The buffer in which to write the Unicode character string.

### `BufferSize` [in]

The size of the buffer.

### `StringSize` [out, optional]

A pointer to the string size.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 A quit lock string provides control to lock the session against
undesired quits.

The quit lock string
cannot be retrieved from a secure session.

## See also

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)