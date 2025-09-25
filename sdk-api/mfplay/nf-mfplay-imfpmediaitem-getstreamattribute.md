# IMFPMediaItem::GetStreamAttribute

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Queries the media item for a stream attribute.

## Parameters

### `dwStreamIndex` [in]

Zero-based index of the stream. To get the number of streams, call [IMFPMediaItem::GetNumberOfStreams](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-getnumberofstreams).

### `guidMFAttribute` [in]

GUID that identifies the attribute value to query. Possible values are listed in the following topics:

* [Stream Descriptor Attributes](https://learn.microsoft.com/windows/desktop/medfound/stream-descriptor-attributes)
* [Media Type Attributes](https://learn.microsoft.com/windows/desktop/medfound/media-type-attributes)

### `pvValue` [out]

Pointer to a **PROPVARIANT** that receives the value. The method fills the **PROPVARIANT** with a copy of the stored value. Call **PropVariantClear** to free the memory allocated by this method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Stream attributes describe an individual stream (audio, video, or other) within the presentation. To get an attribute that applies to the entire presentation, call [IMFPMediaItem::GetPresentationAttribute](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-getpresentationattribute).

## See also

[IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)