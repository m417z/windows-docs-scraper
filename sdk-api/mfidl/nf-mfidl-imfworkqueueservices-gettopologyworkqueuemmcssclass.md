# IMFWorkQueueServices::GetTopologyWorkQueueMMCSSClass

## Description

Retrieves the Multimedia Class Scheduler Service (MMCSS) class for a specified branch of the current topology.

## Parameters

### `dwTopologyWorkQueueId` [in]

Identifies the work queue assigned to this topology branch. The application defines this value by setting the [MF_TOPONODE_WORKQUEUE_ID](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-workqueue-id-attribute) attribute on the source node for the branch.

### `pwszClass` [out]

Pointer to a buffer that receives the name of the MMCSS class. This parameter can be **NULL**.

### `pcchClass` [in, out]

On input, specifies the size of the *pwszClass* buffer, in characters. On output, receives the required size of the buffer, in characters. The size includes the terminating null character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | There is no work queue with the specified identifier. |
| **MF_E_BUFFERTOOSMALL** | The *pwszClass* buffer is too small to receive the class name. |

## See also

[IMFWorkQueueServices](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfworkqueueservices)