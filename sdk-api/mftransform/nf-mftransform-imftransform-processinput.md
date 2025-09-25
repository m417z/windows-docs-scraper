# IMFTransform::ProcessInput

## Description

Delivers data to an input stream on this Media Foundation transform (MFT).

## Parameters

### `dwInputStreamID` [in]

Input stream identifier. To get the list of stream identifiers, call [IMFTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamids).

### `pSample` [in]

Pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface of the input sample. The sample must contain at least one media buffer that contains valid input data.

### `dwFlags` [in]

Reserved. Must be zero.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream identifier. |
| **MF_E_NO_SAMPLE_DURATION** | The input sample requires a valid sample duration. To set the duration, call [IMFSample::SetSampleDuration](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfsample-setsampleduration). <br><br>Some MFTs require that input samples have valid durations. Some MFTs do not require sample durations. |
| **MF_E_NO_SAMPLE_TIMESTAMP** | The input sample requires a time stamp. To set the time stamp, call [IMFSample::SetSampleTime](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfsample-setsampletime). <br><br>Some MFTs require that input samples have valid time stamps. Some MFTs do not require time stamps. |
| **MF_E_NOTACCEPTING** | The transform cannot process more input at this time. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | The media type is not set on one or more streams. |
| **MF_E_UNSUPPORTED_D3D_TYPE** | The media type is not supported for DirectX Video Acceleration (DXVA). A DXVA-enabled decoder might return this error code. |

**Note** If you are converting a DirectX Media Object (DMO) to an MFT, be aware that **S_FALSE** is not a valid return code for **IMFTransform::ProcessInput**, unlike the **IMediaObject::ProcessInput** method.

## Remarks

In most cases, if the method succeeds, the MFT stores the sample and holds a reference count on the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) pointer. Do not re-use the sample until the MFT releases the sample. Instead of storing the sample, however, an MFT might copy the sample data into a new buffer. In that case, the MFT should set the **MFT_INPUT_STREAM_DOES_NOT_ADDREF** flag in the [IMFTransform::GetInputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getinputstreaminfo) method.

If the MFT already has enough input data to produce an output sample, it does not accept new input data, and **ProcessInput** returns **MF_E_NOTACCEPTING**. At that point, the client should clear the pending input data by doing one of the following:

* Generate new output by calling [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput).
* Flush the input data by calling [IMFTransform::ProcessMessage](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processmessage) with the MFT_**MESSAGE_COMMAND_FLUSH** message.

An exception to this rule is the **MFT_OUTPUT_STREAM_LAZY_READ** flag. When this flag is present, the transform will discard stored samples if you give it more input. For more information, see [IMFTransform::GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstreaminfo). A transform should never queue any more input data than is required to produce the correct output.

An MFT can process the input data in the **ProcessInput** method. However, most MFTs wait until the client calls [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput).

After the client has set valid media types on all of the streams, the MFT should always be in one of two states: Able to accept more input, or able to produce more output. It should never be in both states or neither state. An MFT should only accept as much input as it needs to generate at least one output sample, at which point **ProcessInput** returns **MF_E_NOTACCEPTING**. When **ProcessInput** returns **MF_E_NOTACCEPTING**, the client can assume that the MFT is ready to produce output.

If an MFT encounters a non-fatal error in the input data, it can simply drop the data and attempt to recover when it gets the more input data. To request more input data, the MFT returns **MF_E_TRANSFORM_NEED_MORE_INPUT** from the [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) method. If the MFT drops any data, it should set the [MFSampleExtension_Discontinuity](https://learn.microsoft.com/windows/desktop/medfound/mfsampleextension-discontinuity-attribute) attribute attribute on the next output sample, to notify the caller that there is a gap in the data stream.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTProcessInput**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

### Asynchronous Processing

The previous remarks describe the *synchronous* processing model. To support asynchronous processing, see [Asynchronous MFTs](https://learn.microsoft.com/windows/desktop/medfound/asynchronous-mfts).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)