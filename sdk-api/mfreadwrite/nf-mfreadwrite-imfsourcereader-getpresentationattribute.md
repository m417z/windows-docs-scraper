# IMFSourceReader::GetPresentationAttribute

## Description

Gets an attribute from the underlying media source.

## Parameters

### `dwStreamIndex` [in]

The stream or object to query. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. |
| ****MF_SOURCE_READER_FIRST_VIDEO_STREAM****<br><br>0xFFFFFFFC | The first video stream. |
| ****MF_SOURCE_READER_FIRST_AUDIO_STREAM****<br><br>0xFFFFFFFD | The first audio stream. |
| ****MF_SOURCE_READER_MEDIASOURCE****<br><br>0xFFFFFFFF | The media source. |

### `guidAttribute` [in]

A GUID that identifies the attribute to retrieve. If the *dwStreamIndex* parameter equals **MF_SOURCE_READER_MEDIASOURCE**, *guidAttribute* can specify one of the following:

* A presentation descriptor attribute. For a list of values, see [Presentation Descriptor Attributes](https://learn.microsoft.com/windows/desktop/medfound/presentation-descriptor-attributes).
* [MF_SOURCE_READER_MEDIASOURCE_CHARACTERISTICS](https://learn.microsoft.com/windows/desktop/medfound/mf-source-reader-mediasource-characteristics). Use this value to get characteristics flags from the media source.

Otherwise, if the *dwStreamIndex* parameter specifies a stream, *guidAttribute* specifies a stream descriptor attribute. For a list of values, see [Stream Descriptor Attributes](https://learn.microsoft.com/windows/desktop/medfound/stream-descriptor-attributes).

### `pvarAttribute` [out]

A pointer to a **PROPVARIANT** that receives the value of the attribute. Call the **PropVariantClear** function to free the **PROPVARIANT**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader)

[Media Foundation Attributes](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-attributes)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)