# IMFPMediaItem::GetDuration

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Gets the duration of the media item.

## Parameters

### `guidPositionType` [in]

Specifies the unit of time for the duration value. The following value is defined.

| Value | Meaning |
| --- | --- |
| **MFP_POSITIONTYPE_100NS** | 100-nanosecond units.<br><br>The value returned in *pvDurationValue* is a **LARGE_INTEGER**.<br><br>* Variant type (**vt**): VT_I8<br>* Variant member: **hVal** |

### `pvDurationValue` [out]

Pointer to a **PROPVARIANT** that receives the duration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The method returns the total duration of the content, regardless of any values set through [IMFPMediaItem::SetStartStopPosition](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-setstartstopposition).

#### Examples

```cpp
#include <propvarutil.h>

HRESULT GetPlaybackDuration(IMFPMediaItem *pItem, ULONGLONG *phnsDuration)
{
    PROPVARIANT var;

    HRESULT hr = pItem->GetDuration(MFP_POSITIONTYPE_100NS, &var);

    if (SUCCEEDED(hr))
    {
        hr = PropVariantToUInt64(var, phnsDuration);
        PropVariantClear(&var);
    }

    return hr;
}

```

## See also

[How to Get the Playback Duration](https://learn.microsoft.com/windows/desktop/medfound/how-to-get-the-playback-duration)

[IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)