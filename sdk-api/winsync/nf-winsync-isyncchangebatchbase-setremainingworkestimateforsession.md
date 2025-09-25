# ISyncChangeBatchBase::SetRemainingWorkEstimateForSession

## Description

Sets the estimate of the remaining work for the session.

## Parameters

### `dwRemainingWorkForSession` [in]

The estimate of the remaining work for the session.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The work estimate is determined by the provider.

This value is reported in the [OnProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isynccallback-onprogress) event. If this value is set to zero, the [OnProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isynccallback-onprogress) event will fire for each change that is applied during the session. It will pass zero for the completed work and total work.

## See also

[ISyncCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynccallback)

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)