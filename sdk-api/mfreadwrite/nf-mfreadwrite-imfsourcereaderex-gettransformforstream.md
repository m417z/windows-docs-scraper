# IMFSourceReaderEx::GetTransformForStream

## Description

Gets a pointer to a Media Foundation transform (MFT) for a specified stream.

## Parameters

### `dwStreamIndex` [in]

The stream to query for the MFT. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. |
| **MF_SOURCE_READER_FIRST_VIDEO_STREAM**<br><br>0xFFFFFFFC | The first video stream. |
| **MF_SOURCE_READER_FIRST_AUDIO_STREAM**<br><br>0xFFFFFFFD | The first audio stream. |

### `dwTransformIndex` [in]

The zero-based index of the MFT to retrieve.

### `pGuidCategory` [out]

Receives a GUID that specifies the category of the MFT. For a list of possible values, see [MFT_CATEGORY](https://learn.microsoft.com/windows/desktop/medfound/mft-category).

### `ppTransform` [out]

Receives a pointer to the [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) interface of the MFT. The caller must release the interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **MF_E_INVALIDINDEX** | The *dwTransformIndex* parameter is out of range. |
| **MF_E_INVALIDSTREAMNUMBER** | The *dwStreamIndex* parameter is invalid. |

## Remarks

You can use this method to configure an MFT after it is inserted into the processing chain. Do not use the pointer returned in *ppTransform* to set media types on the MFT or to process data. In particular, calling any of the following [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) methods could have unexpected results.

* [AddInputStreams](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-addinputstreams)
* [DeleteInputStream](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-deleteinputstream)
* [ProcessEvent](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processevent)
* [ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput)
* [ProcessMessage](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processmessage)
* [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput)
* [SetInputType](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-setinputtype)
* [SetOutputType](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-setoutputtype)

If a decoder is present, it appears at index position zero.

To avoid losing any data, you should drain the source reader before calling this method. For more information, see [Draining the Data Pipeline](https://learn.microsoft.com/windows/desktop/medfound/processing-media-data-with-the-source-reader).

## See also

[IMFSourceReaderEx](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereaderex)