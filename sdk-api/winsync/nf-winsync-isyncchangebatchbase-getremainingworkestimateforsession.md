# ISyncChangeBatchBase::GetRemainingWorkEstimateForSession

## Description

Gets the estimate of the remaining work for the session.

## Parameters

### `pdwRemainingWorkForSession` [out]

The estimated remaining work for the session. The default value is 0.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

The work estimate is determined by the provider and is typically understood as the remaining work estimated for a session.

This value is reported in the [OnProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isynccallback-onprogress) event.

## See also

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)