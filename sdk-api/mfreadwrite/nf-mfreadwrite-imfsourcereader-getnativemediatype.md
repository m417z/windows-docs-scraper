# IMFSourceReader::GetNativeMediaType

## Description

Gets a format that is supported natively by the media source.

## Parameters

### `dwStreamIndex` [in]

Specifies which stream to query. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. |
| ****MF_SOURCE_READER_FIRST_VIDEO_STREAM****<br><br>0xFFFFFFFC | The first video stream. |
| ****MF_SOURCE_READER_FIRST_AUDIO_STREAM****<br><br>0xFFFFFFFD | The first audio stream. |

### `dwMediaTypeIndex` [in]

Specifies which media type to query. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFE | The zero-based index of a media type |
| ****MF_SOURCE_READER_CURRENT_TYPE_INDEX****<br><br>0xFFFFFFFF | The current native media type. |

### `ppMediaType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_INVALIDSTREAMNUMBER**** | The *dwStreamIndex* parameter is invalid. |
| ****MF_E_NO_MORE_TYPES**** | The *dwMediaTypeIndex* parameter is out of range. |

## Remarks

This method queries the underlying media source for its native output format. Potentially, each source stream can produce more than one output format. Use the *dwMediaTypeIndex* parameter to loop through the available formats. Generally, file sources offer just one format per stream, but capture devices might offer several formats.

 The method returns a copy of the media type, so it is safe to modify the object received in the  *ppMediaType* parameter.

To set the output type for a stream, call the [IMFSourceReader::SetCurrentMediaType](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-setcurrentmediatype) method.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)