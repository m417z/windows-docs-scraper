# IMFDeviceTransform::ProcessEvent

## Description

The **ProcessEvent** method sends an event to an input stream on this Media Foundation transform (MFT).

## Parameters

### `dwInputStreamID` [in]

Stream identifier. To get the list of stream identifiers, call [IMFDeviceTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imfdevicetransform-getstreamids).

### `pEvent` [in]

Pointer to the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface of an event object.

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The event processed successfully. The event will be propagated down stream. |
| **MF_E_INVALIDSTREAMNUMBER** | An invalid stream ID was passed. |
| **MF_S_TRANSFORM_DO_NO_PROPOGATE_EVENT** | Indicates that the Device MFT does not want the event to be propagated further. |
| **E_NOTIMPL** | The function is not implemented. |

## Remarks

An MFT can handle sending the event downstream, or it can let the DTM do this, as indicated by the return value:

* **E_NOTIMPL:** The MFT ignores all events, and the DTM should send all events downstream. After the pipeline receives this return value
* **S_OK:** The MFT has examined this event, but the DTM should send the event downstream. Internally, the MFT might respond to the event in some way, or it might ignore the event.
* **MF_S_TRANSFORM_DO_NOT_PROPAGATE_EVENT:** The DTM should not propagate this event downstream. Either the MFT will send the event downstream, or else the MFT will consume the event and not send it downstream. The MFT should only consume the event if the event should stop at this MFT and not travel any further downstream. But in most cases, the event should travel downstream.

To send the event downstream, the MFT adds the event to the collection object that is provided by the client in the pEvents member of the **MFT_OUTPUT_DATA_BUFFER** structure, when the client calls [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imfdevicetransform-processoutput).

Events must be serialized with the samples that come before and after them. Attach the event to the output sample that follows the event. (The pipeline will process the event first, and then the sample.) If an MFT holds back one or more samples between calls to [IMFTransform::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imfdevicetransform-processinput) and [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imfdevicetransform-processoutput), the MFT should handle sending all events downstream, because in this situation the pipeline cannot correlate input samples with output samples.

If an MFT does not hold back samples and does not need to examine any events, it can return **E_NOTIMPL**.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)