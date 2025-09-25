# IMFWorkQueueServices::GetTopologyWorkQueueMMCSSTaskId

## Description

Retrieves the Multimedia Class Scheduler Service (MMCSS) task identifier for a specified branch of the current topology.

## Parameters

### `dwTopologyWorkQueueId` [in]

Identifies the work queue assigned to this topology branch. The application defines this value by setting the [MF_TOPONODE_WORKQUEUE_ID](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-workqueue-id-attribute) attribute on the source node for the branch.

### `pdwTaskId` [out]

Receives the task identifier.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFWorkQueueServices](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfworkqueueservices)