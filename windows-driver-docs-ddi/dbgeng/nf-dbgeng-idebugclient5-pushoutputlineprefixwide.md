# IDebugClient5::PushOutputLinePrefixWide

## Description

 Saves a wide string output line prefix.

## Parameters

### `NewPrefix` [in, optional]

A pointer to the new output line Unicode character prefix.

### `Handle` [out]

The handle of the previous output line prefix.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)