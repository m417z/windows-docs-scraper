# IMFQualityManager::NotifyTopology

## Description

Called when the Media Session is about to start playing a new topology.

## Parameters

### `pTopology` [in]

Pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface of the new topology. If this parameter is **NULL**, the quality manager should release any references to the previous topology.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

In a typical quality manager this method does the following:

1. Enumerates the nodes in the topology.
2. Calls [IMFTopologyNode::GetObject](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynode-getobject) to get the node's underlying object.
3. Queries for the [IMFQualityAdvise](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualityadvise) interface.

The quality manager can then use the [IMFQualityAdvise](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualityadvise) pointers to adjust audio-video quality as needed.

## See also

[IMFQualityManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualitymanager)