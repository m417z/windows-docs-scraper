# IMFPMediaItem::GetPresentationAttribute

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Queries the media item for a presentation attribute.

## Parameters

### `guidMFAttribute` [in]

GUID that identifies the attribute value to query.

For a list of presentation attributes, see [Presentation Descriptor Attributes](https://learn.microsoft.com/windows/desktop/medfound/presentation-descriptor-attributes).

### `pvValue` [out]

Pointer to a **PROPVARIANT** that receives the value. The method fills the **PROPVARIANT** with a copy of the stored value. Call **PropVariantClear** to free the memory allocated by the method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Presentation attributes describe the presentation as a whole. To get an attribute that applies to an individual stream within the presentation, call [IMFPMediaItem::GetStreamAttribute](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-getstreamattribute).

## See also

[IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)