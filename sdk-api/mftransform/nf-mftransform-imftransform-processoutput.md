# IMFTransform::ProcessOutput

## Description

Generates output from the current input data.

## Parameters

### `dwFlags` [in]

Bitwise **OR** of zero or more flags from the [_MFT_PROCESS_OUTPUT_FLAGS](https://learn.microsoft.com/windows/win32/api/mftransform/ne-mftransform-_mft_process_output_flags) enumeration.

### `cOutputBufferCount` [in]

Number of elements in the *pOutputSamples* array. The value must be at least 1.

### `pOutputSamples` [in, out]

Pointer to an array of [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structures, allocated by the caller. The MFT uses this array to return output data to the caller.

### `pdwStatus` [out]

Receives a bitwise **OR** of zero or more flags from the [_MFT_PROCESS_OUTPUT_STATUS](https://learn.microsoft.com/windows/win32/api/mftransform/ne-mftransform-_mft_process_output_status) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) method was called on an asynchronous MFT that was not expecting this method call. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream identifier in the **dwStreamID** member of one or more [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structures. |
| **MF_E_TRANSFORM_NEED_MORE_INPUT** | The transform cannot produce output data until it receives more input data. |
| **MF_E_TRANSFORM_STREAM_CHANGE** | The format has changed on an output stream, or there is a new preferred format, or there is a new output stream. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | You must set the media type on one or more streams of the MFT. |

**Note** If you are converting a DirectX Media Object (DMO) to an MFT, be aware that **S_FALSE** is not a valid return code for **IMFTransform::ProcessOutput**, unlike the **IMediaObject::ProcessOutput** method.

## Remarks

The size of the *pOutputSamples* array must be equal to or greater than the number of *selected* output streams. The number of selected output streams equals the total number of output streams minus the number of *deselected* streams. A stream is deselected if it has the **MFT_OUTPUT_STREAM_OPTIONAL** flag and the caller does not set a media type (or sets the media type to **NULL**). For more information, see [_MFT_OUTPUT_STREAM_INFO_FLAGS](https://learn.microsoft.com/windows/win32/api/mftransform/ne-mftransform-_mft_output_stream_info_flags) enumeration.

This method generates output samples and can also generate events. If the method succeeds, at least one of the following conditions is true:

* One or more samples in the *pOutputSamples* array contains output data.
* One or more members of the *pOutputSamples* array contains a non-empty collection of events.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including Mftransform.h, this method is renamed **MFTProcessOutput**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

### Output Buffers

The MFT returns output data for a stream through the **pSample** member of the [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structure. This structure member is a pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface of a media sample. (See [Media Samples](https://learn.microsoft.com/windows/desktop/medfound/media-samples).) The media sample is allocated either by the caller or by the MFT, depending on the MFT's allocation model. To find the allocation model, call [IMFTransform::GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstreaminfo) and examine the **dwFlags** member of the [MFT_OUTPUT_STREAM_INFO](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_stream_info) structure:

* If the **MFT_OUTPUT_STREAM_PROVIDES_SAMPLES** flag is present, the MFT allocates the media sample.
* If the **MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES** flag is present, the caller can optionally provide a media sample. If **pSample** is **NULL**, the MFT will allocate the media sample.
* If neither of these two flags is present, the caller must allocate the media sample.

These flags remain constant unless the media type for the output stream changes.

If the caller allocates the media sample, the media sample must contain a buffer that is large enough to hold the output data. To find the buffer requirements, call [GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstreaminfo). The MFT writes the output data to the start of the buffer, overwriting any data that already exists in the buffer.

If the MFT allocates the sample, the MFT also allocates the buffers for the sample.

If the MFT has multiple output streams, the streams might produce output at different rates, so some streams might have output while other streams do not. If a stream did not any produce output, the MFT sets the **MFT_OUTPUT_DATA_BUFFER_NO_SAMPLE** flag in the **dwStatus** member of the [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structure for that stream. In that case, if the caller allocated **pSample**, the buffers in the sample do not contain any valid data. If the caller did not allocate **pSample**, the **MFT_OUTPUT_DATA_BUFFER_NO_SAMPLE** flag indicates that **pSample** still equals **NULL** after the method returns.

If no output streams have data, and the MFT has no events to return, then **ProcessOutput** returns **MF_E_TRANSFORM_NEED_MORE_INPUT**.

The MFT cannot return more than one sample per stream in a single call to **ProcessOutput**. If there is more output data available for a stream after **ProcessOutput** returns, the MFT sets the **MFT_OUTPUT_DATA_BUFFER_INCOMPLETE** flag in the **dwStatus** member of the [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structure for that stream.

If the MFT has enough data to produce output, it should refuse to accept any more input until **ProcessOutput** has been called enough times to pull all of the available output. (An exception is when the [IMFTransform::GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstreaminfo) method returns the **MFT_OUTPUT_STREAM_LAZY_READ** flag.) Generally, an MFT with multiple output streams should produce output for a stream as soon as possible, and not wait for all of the streams to have output.

### In-Band Events

The MFT can return a collection of event objects in the **pEvents** member of each [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structure. The MFT allocates both the collection object and the events.

To send an event to the caller, the MFT performs the following steps inside **ProcessOutput**:

1. Create a new collection object by calling [MFCreateCollection](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatecollection).
2. Add one or more events to the collection by calling [IMFCollection::AddElement](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfcollection-addelement).
3. Set the **pEvents** member of the [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structure equal to the [IMFCollection](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfcollection) pointer. The MFT leaves a reference count on this interface; the caller must release the pointer.

Events do not have time stamps. The caller should process the events before processing the output samples. In other words, events occur at the point in the stream immediately after the previous call to **ProcessOutput**, and prior to any output samples returned from the current **ProcessOutput** call.

It is valid for the **ProcessOutput** method to return one or more events and zero output samples.

The caller is responsible for releasing any events that the MFT allocates. When the method returns, check the **pEvents** member of each [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structure. If the value is not **NULL**, the caller must release the [IMFCollection](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfcollection) interface pointer:

```cpp
// Release the events that an MFT might allocate in IMFTransform::ProcessOutput().
void ReleaseEventCollection(DWORD cOutputBuffers, MFT_OUTPUT_DATA_BUFFER* pBuffers)
{
    for (DWORD i = 0; i < cOutputBuffers; i++)
    {
        if (pBuffers[i].pEvents)
        {
            pBuffers[i].pEvents->Release();
            pBuffers[i].pEvents = NULL;
        }
    }
}

```

An MFT should not use the [IMFMediaEventGenerator](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventgenerator) interface to send in-band events.

### Stream Changes

The **ProcessOutput** method can cause any of the following changes in an output stream:

* The deletion of an output stream. To signal a stream deletion, the MFT sets the **MFT_OUTPUT_DATA_BUFFER_STREAM_END** flag in the **dwStatus** member of the [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structure for that stream.
* The creation of a new output stream. To signal a new output stream, the MFT sets the **MFT_PROCESS_OUTPUT_STATUS_NEW_STREAMS** flag in the *pdwStatus* parameter. A new stream can have the same stream identifier as a deleted stream.
* A format change on an output stream. To signal a format change, the MFT sets the **MFT_OUTPUT_DATA_BUFFER_FORMAT_CHANGE** flag in the **dwStatus** member of the [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structure for that stream.

It is possible that all three of these actions will result from a single call to **ProcessOutput**. The caller must respond to them in the order listed here—first deletions, then additions, then format changes.

The **MFT_OUTPUT_DATA_BUFFER_FORMAT_CHANGE** flag signals a format change on an output stream. This might mean the current media type has become invalid, or the preference order has changed and a more efficient format is available. In the latter case, it is possible that the client will re-set the original media type. To guard against endless loops, the MFT should not set the **MFT_OUTPUT_DATA_BUFFER_FORMAT_CHANGE** flag again until there is another change. Also, avoid setting this flag if the preference order changes but the current media type is still the most preferred type.

### Sample Attributes

An input sample might have attributes, which are accessed through the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. Unless a specific attribute no longer applies, all attributes should be copied into the corresponding output sample. The responsibility for copying attributes is determined as follows:

* If the value of the [MFPKEY_EXATTRIBUTE_SUPPORTED](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-exattribute-supported-property) property on the MFT is **VARIANT_TRUE**, the MFT copies the attributes.
* If the value of [MFPKEY_EXATTRIBUTE_SUPPORTED](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-exattribute-supported-property) is **VARIANT_FALSE**, or the property is not set, the client must copy the sample attributes. Do not overwrite any attributes that the MFT sets on the output sample.

For a list of sample attributes, see [Sample Attributes](https://learn.microsoft.com/windows/desktop/medfound/sample-attributes).

### Asynchronous Processing

The previous remarks describe the *synchronous* processing model. To support asynchronous processing, see [Asynchronous MFTs](https://learn.microsoft.com/windows/desktop/medfound/asynchronous-mfts).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)