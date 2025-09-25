# IMFPMediaItem::SetStartStopPosition

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Sets the start and stop time for the media item.

## Parameters

### `pguidStartPositionType` [in]

Unit of time for the start position. See Remarks. This parameter can be **NULL**.

### `pvStartValue` [in]

Start position. The meaning and data type of this parameter are indicated by the *pguidStartPositionType* parameter. The *pvStartValue* parameter must be **NULL** if *pguidStartPositionType* is **NULL**, and cannot be **NULL** otherwise.

### `pguidStopPositionType` [in]

Unit of time for the stop position. See Remarks. This parameter can be **NULL**.

### `pvStopValue` [in]

Stop position. The meaning and data type of this parameter are indicated by the *pguidStopPositionType* parameter. The *pvStopValue* parameter must be **NULL** if *pguidStopPositionType* is **NULL**, and cannot be **NULL** otherwise.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **MF_E_OUT_OF_RANGE** | Invalid start or stop time. Any of the following can cause this error:<br><br>* Time less than zero.<br>* Time greater than the total duration of the media item.<br>* Stop time less than start time. |

## Remarks

By default, a media item plays from the beginning to the end of the file. This method adjusts the start time and/or the stop time:

* To set the start time, pass non-**NULL** values for *pguidStartPositionType* and *pvStartValue*.
* To set the stop time, pass non-**NULL** values for *pguidStopPositionType* and *pvStopValue*.

The *pguidStartPositionType* and *pguidStopPositionType* parameters give the units of time that are used. Currently, the only supported value is **MFP_POSITIONTYPE_100NS**.

| Value | Description |
| --- | --- |
| **MFP_POSITIONTYPE_100NS** | 100-nanosecond units. The time parameter (*pvStartValue* or *pvStopValue*) uses the following data type:<br><br>* Variant type (**vt**): **VT_I8**<br>* Variant member: **hVal**<br><br>To clear a previously set time, use an empty **PROPVARIANT** (**VT_EMPTY**). |

The adjusted start and stop times are used the next time that [IMFPMediaPlayer::SetMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-setmediaitem) is called with this media item. If the media item is already set on the player, the change does not happen unless you call **SetMediaItem** again.

#### Examples

```cpp
HRESULT PlayMediaClip(
    IMFPMediaPlayer *pPlayer,
    PCWSTR pszURL,
    LONGLONG    hnsStart,
    LONGLONG    hnsEnd
    )
{
    IMFPMediaItem *pItem = NULL;
    PROPVARIANT varStart, varEnd;

    ULONGLONG hnsDuration = 0;

    HRESULT hr = pPlayer->CreateMediaItemFromURL(pszURL, TRUE, 0, &pItem);
    if (FAILED(hr))
    {
        goto done;
    }

    hr = GetPlaybackDuration(pItem, &hnsDuration);
    if (FAILED(hr))
    {
        goto done;
    }

    if ((ULONGLONG)hnsEnd > hnsDuration)
    {
        hnsEnd = hnsDuration;
    }

    hr = InitPropVariantFromInt64(hnsStart, &varStart);
    if (FAILED(hr))
    {
        goto done;
    }

    hr = InitPropVariantFromInt64(hnsEnd, &varEnd);
    if (FAILED(hr))
    {
        goto done;
    }

    hr = pItem->SetStartStopPosition(
        &MFP_POSITIONTYPE_100NS,
        &varStart,
        &MFP_POSITIONTYPE_100NS,
        &varEnd
        );
    if (FAILED(hr))
    {
        goto done;
    }

    hr = pPlayer->SetMediaItem(pItem);

done:
    SafeRelease(&pItem);
    return hr;
}

```

## See also

[How to Play a File Clip](https://learn.microsoft.com/windows/desktop/medfound/how-to-play-a-file-clip)

[IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)