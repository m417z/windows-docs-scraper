# ILog::GetLogLimits

## Description

Retrieves information about the current bounds of the log.

## Parameters

### `plsnFirst` [in, out]

A pointer to the LSN of the first record in the log. This parameter can be **NULL** if the LSN of the first record is not needed.

### `plsnLast` [in, out]

A pointer to the LSN of the last record in the log. This parameter can be **NULL** if the LSN of the last record is not needed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The limits returned by this method may include records that have not yet been written to disk.

## See also

[ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog)