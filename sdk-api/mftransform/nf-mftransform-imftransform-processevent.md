# IMFTransform::ProcessEvent

## Description

Sends an event to an input stream on this Media Foundation transform (MFT).

## Parameters

### `dwInputStreamID` [in]

Input stream identifier. To get the list of stream identifiers, call [IMFTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamids).

### `pEvent` [in]

Pointer to the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface of an event object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream number. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | The media type is not set on one or more streams. |
| **MF_S_TRANSFORM_DO_NOT_PROPAGATE_EVENT** | The pipeline should not propagate the event. |

## Remarks

An MFT can handle sending the event downstream, or it can let the pipeline do this, as indicated by the return value:

* **E_NOTIMPL**: The MFT ignores all events, and the pipeline should send all events downstream. After the pipeline receives this return value, it might not call **ProcessEvent** again.
* **S_OK**: The MFT has examined this event, but the pipeline should send the event downstream. Internally, the MFT might respond to the event in some way, or it might ignore the event.
* **MF_S_TRANSFORM_DO_NOT_PROPAGATE_EVENT**: The pipeline should not propagate this event downstream. Either the MFT will send the event downstream, or else the MFT will consume the event and not send it downstream. The MFT should only consume the event if the event should stop at this MFT and not travel any further downstream. But in most cases, the event should travel downstream.

To send the event downstream, the MFT adds the event to the collection object that is provided by the client in the **pEvents** member of the [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structure, when the client calls [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput).

Events must be serialized with the samples that come before and after them. Attach the event to the output sample that follows the event. (The pipeline will process the event first, and then the sample.) If an MFT holds back one or more samples between calls to [IMFTransform::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput) and [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput), the MFT should handle sending all events downstream, because in this situation the pipeline cannot correlate input samples with output samples.

If an MFT does not hold back samples and does not need to examine any events, it can return **E_NOTIMPL**.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTProcessEvent**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)