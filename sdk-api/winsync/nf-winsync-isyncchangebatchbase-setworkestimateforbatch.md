# ISyncChangeBatchBase::SetWorkEstimateForBatch

## Description

Sets the work estimate for the batch.

## Parameters

### `dwWorkForBatch` [in]

The work estimate for the batch.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The work estimate is determined by the provider and typically is understood as the total work for all changes in a single batch and as a portion of the total work estimated for the session.

This value is reported in the [OnProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isynccallback-onprogress) event.

## See also

[ISyncCallback Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isynccallback)

[ISyncChangeBatchBase Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncchangebatchbase)