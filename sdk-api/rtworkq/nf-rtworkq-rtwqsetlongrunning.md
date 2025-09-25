# RtwqSetLongRunning function

## Description

Indicates that the app will be submitting a hint that long running work will occur on this work queue.

## Parameters

### `workQueueId` [in]

The ID of the work queue.

### `enable` [in]

**true** if the app will be submitting the hint; otherwise, **false**. The default is **false**.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.