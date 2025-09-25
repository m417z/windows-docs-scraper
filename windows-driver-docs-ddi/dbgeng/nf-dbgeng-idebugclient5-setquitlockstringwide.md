# IDebugClient5::SetQuitLockStringWide

## Description

Sets a quit lock Unicode character string.

## Parameters

### `String` [in]

A pointer to the quit lock Unicode character string.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 This function provides control over locking the session against
undesired quits.

## See also

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)