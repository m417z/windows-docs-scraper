# ILog::TruncatePrefix

## Description

Throws away the specified prefix of the log, making it no longer retrievable.

## Parameters

### `lsnFirstToKeep` [in]

The LSN of the first record not to be thrown away. If this parameter is 0, the entire log is emptied.

## Return value

This method can return the following values, as well as other **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The log was successfully truncated. |
| **E_INVALIDARG** | *lsnFirstToKeep* is outside the current limits of the log. See [ILog::GetLogLimits](https://learn.microsoft.com/windows/desktop/api/txlogpub/nf-txlogpub-ilog-getloglimits). |

## Remarks

This request is only a hint to the log implementation. The log is free to ignore the request, or to retain more than was strictly requested. Many [ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog) implementations will follow this latter option.

## See also

[ILog](https://learn.microsoft.com/windows/desktop/api/txlogpub/nn-txlogpub-ilog)