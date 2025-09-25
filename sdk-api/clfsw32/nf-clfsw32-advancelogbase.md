# AdvanceLogBase function

## Description

 Advances the base log sequence number (LSN) of a log stream to the specified LSN.

## Parameters

### `pvMarshal` [in, out]

A pointer to the marshaling context that a successful call to [CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea) returns.

### `plsnBase` [in]

The new base LSN for the log that is specified in *pvMarshal*.

This LSN must be in the range between the current base LSN and the last LSN of the log, inclusively.

### `fFlags` [in]

This parameter is not implemented at this time, and must be zero.

### `pOverlapped` [in, out, optional]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that is required for asynchronous operation.

If asynchronous operation is not used, this parameter can be **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes:

## Remarks

**AdvanceLogBase** might flush data and metadata when it is called.

## See also

[Obtaining the Next LSN](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/obtaining-the-next-lsn)