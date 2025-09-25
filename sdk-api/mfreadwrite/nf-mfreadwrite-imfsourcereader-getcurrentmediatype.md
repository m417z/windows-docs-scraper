# IMFSourceReader::GetCurrentMediaType

## Description

Gets the current media type for a stream.

## Parameters

### `dwStreamIndex` [in]

The stream to query. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. |
| ****MF_SOURCE_READER_FIRST_VIDEO_STREAM****<br><br>0xFFFFFFFC | The first video stream. |
| ****MF_SOURCE_READER_FIRST_AUDIO_STREAM****<br><br>0xFFFFFFFD | The first audio stream. |

### `ppMediaType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_INVALIDSTREAMNUMBER**** | The *dwStreamIndex* parameter is invalid. |

## Remarks

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)