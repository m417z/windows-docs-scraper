# IMFPMediaPlayer::GetPosition

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Gets the current playback position.

## Parameters

### `guidPositionType` [in]

Specifies the unit of time for the playback position. The following value is defined.

| Value | Meaning |
| --- | --- |
| **MFP_POSITIONTYPE_100NS** | 100-nanosecond units. <br><br>The value returned in *pvPositionValue* is a **LARGE_INTEGER**.<br><br>* Variant type (**vt**): **VT_I8**<br>* Variant member: **hVal** |

### `pvPositionValue` [out]

Pointer to a **PROPVARIANT** that receives the playback position.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **MF_E_INVALIDREQUEST** | No media item has been queued. |
| **MF_E_SHUTDOWN** | The object's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-shutdown) method was called. |

## Remarks

The playback position is calculated relative to the start time of the media item, which can be specified by calling [IMFPMediaItem::SetStartStopPosition](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-setstartstopposition). For example, if you set the start time to 20 seconds and the source duration is 60 seconds, the range of values returned by **GetPosition** is 0–40 seconds.

#### Examples

The following code gets the current position, in 100-nanosecond units, as a **LONGLONG** value.

```
HRESULT GetPositionHNS(
    IMFPMediaPlayer *pPlayer,
    LONGLONG *phnsPosition    // Receives the position in hns.
)
{
    HRESULT hr = S_OK;

    PROPVARIANT var;
    PropVariantInit(&var);

    *phnsPosition = 0;

    hr = pPlayer->GetPosition(MFP_POSITIONTYPE_100NS, &var);

    if (SUCCEEDED(hr))
    {
        *phnsPosition = var.hVal.QuadPart;
    }

    PropVariantClear(&var);
    return hr;
}

```

## See also

[IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)