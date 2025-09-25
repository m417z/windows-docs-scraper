# MFT_OUTPUT_DATA_BUFFER structure

## Description

Contains information about an output buffer for a Media Foundation transform. This structure is used in the [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) method.

## Members

### `dwStreamID`

Output stream identifier. Before calling [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput), set this member to a valid stream identifier.

Exception: If the [IMFTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamids) method returns E_NOTIMPL, the MFT ignores this member and uses the indexes of the *pOutputSamples* array in the [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) method as the stream identifiers. In other words, it uses the first element in the array for stream 0, the second for stream 1, and so forth. It is recommended (but not required) that the caller set **dwStreamID** equal to the array index in this case.

### `pSample`

Pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface. Before calling [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput), set this member equal to a valid **IMFSample** pointer or **NULL**. See Remarks for more information.

### `dwStatus`

Before calling [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput), set this member to zero. When the method returns, the MFT might set the member equal to a value from the [_MFT_OUTPUT_DATA_BUFFER_FLAGS](https://learn.microsoft.com/windows/win32/api/mftransform/ne-mftransform-_mft_output_data_buffer_flags) enumeration. Otherwise, the MFT leaves this member equal to zero.

### `pEvents`

Before calling [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput), set this member to **NULL**. On output, the MFT might set this member to a valid [IMFCollection](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfcollection) interface pointer. The pointer represents a collecton that contains zero or more events. To get each event, call [IMFCollection::GetElement](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfcollection-getelement) and query the returned **IUnknown** pointer for the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface. When the **ProcessOutput** method returns, the caller is responsible for releasing the **IMFCollection** pointer if the pointer is not **NULL**.

## Remarks

You must provide an **MFT_OUTPUT_DATA_BUFFER** structure for each selected output stream.

MFTs can support two different allocation models for output samples:

* The MFT allocates the output sample.
* The client allocates the output sample.

To find which model the MFT supports for a given output stream, call [IMFTransform::GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstreaminfo) and check the value of **dwFlags**.

| Flag | Allocation Model |
| --- | --- |
| MFT_OUTPUT_STREAM_PROVIDES_SAMPLES | The MFT allocates the output samples for the stream. Set **pSample** to **NULL** for this stream. |
| MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES | The MFT supports both allocation models. |
| Neither (default) | The client must allocate the output samples for the stream. |

The behavior of [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) depends on the initial value of **pSample** and the value of the *dwFlags* parameter in the **ProcessOutput** method.

* If **pSample** is **NULL** and *dwFlags* contains the MFT_PROCESS_OUTPUT_DISCARD_WHEN_NO_BUFFER flag, the MFT discards the output data.

  Restriction: This output stream must have the MFT_OUTPUT_STREAM_DISCARDABLE or MFT_OUTPUT_STREAM_LAZY_READ flag. (To get the flags for the output stream, call the [IMFTransform::GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstreaminfo) method.)
* If **pSample** is **NULL** and *dwFlags* does not contain the MFT_PROCESS_OUTPUT_DISCARD_WHEN_NO_BUFFER, the MFT provides a sample for the output data. The MFT sets **pSample** to point to the sample that it provides. The MFT can either allocate a new sample or re-use an input sample.

  Restriction: This output stream must have the MFT_OUTPUT_STREAM_PROVIDES_SAMPLES or MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES flag.
* If **pSample** is non-**NULL**, the MFT uses the sample provided by the caller.

  Restriction: This output stream must not have the MFT_OUTPUT_STREAM_PROVIDES_SAMPLES flag.

Any other combinations are invalid and cause [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) to return E_INVALIDARG.

Each call to [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) can produce zero or more events and up to one sample per output stream.

## See also

[IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)