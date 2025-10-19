# IMFSourceReader::SetCurrentMediaType

## Description

Sets the media type for a stream.

This media type defines that format that the [Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader) produces as output. It can differ from the native format provided by the media source. See Remarks for more information.

## Parameters

### `dwStreamIndex` [in]

The stream to configure. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. |
| **MF_SOURCE_READER_FIRST_VIDEO_STREAM**<br><br>0xFFFFFFFC | The first video stream. |
| **MF_SOURCE_READER_FIRST_AUDIO_STREAM**<br><br>0xFFFFFFFD | The first audio stream. |

### `pdwReserved` [in, out]

Reserved. Set to **NULL**.

### `pMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDMEDIATYPE** | At least one decoder was found for the native stream type, but the type specified by *pMediaType* was rejected. |
| **MF_E_INVALIDREQUEST** | One or more sample requests are still pending. |
| **MF_E_INVALIDSTREAMNUMBER** | The *dwStreamIndex* parameter is invalid. |
| **MF_E_TOPO_CODEC_NOT_FOUND** | Could not find a decoder for the native stream type. |

## Remarks

For each stream, you can set the media type to any of the following:

* One of the native types offered by the media source. To enumerate the native types, call [IMFSourceReader::GetNativeMediaType](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-getnativemediatype).
* If the native media type is compressed, you can specify a corresponding uncompressed format. The Source Reader will search for a decoder that can decode from the native format to the specified uncompressed format.

Audio resampling support was added to the source reader with Windows 8. In versions of Windows prior to Windows 8, the source reader does not support audio resampling. If you need to resample the audio in versions of Windows earlier than Windows 8, you can use the [Audio Resampler DSP](https://learn.microsoft.com/windows/desktop/medfound/audioresampler).

If you set the [MF_SOURCE_READER_ENABLE_VIDEO_PROCESSING](https://learn.microsoft.com/windows/desktop/medfound/mf-source-reader-enable-video-processing) attribute to **TRUE** when you create the Source Reader, the Source Reader will convert YUV video to RGB-32. This conversion is not optimized for real-time video playback.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)