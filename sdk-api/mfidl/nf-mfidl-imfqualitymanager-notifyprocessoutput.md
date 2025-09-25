# IMFQualityManager::NotifyProcessOutput

## Description

Called after the media processor gets an output sample from a pipeline component.

## Parameters

### `pNode` [in]

Pointer to the [IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode) interface of the topology node that represents the pipeline component.

### `lOutputIndex` [in]

Index of the output stream on the topology node.

### `pSample` [in]

Pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface of the output sample.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is called for every sample passing through every pipeline component. Therefore, the method must return quickly to avoid introducing too much latency into the pipeline.

## See also

[IMFQualityManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualitymanager)