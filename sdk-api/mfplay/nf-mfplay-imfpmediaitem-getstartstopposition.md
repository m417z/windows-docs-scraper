# IMFPMediaItem::GetStartStopPosition

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Gets the start and stop times for the media item.

## Parameters

### `pguidStartPositionType` [out]

Receives the unit of time for the start position. See Remarks. This parameter can be **NULL**.

### `pvStartValue` [out]

Receives the start position. The meaning and data type of this parameter are indicated by the *pguidStartPositionType* parameter. The *pvStartValue* parameter must be **NULL** if *pguidStartPositionType* is **NULL**, and cannot be **NULL** otherwise.

### `pguidStopPositionType` [out]

Receives the unit of time for the stop position. See Remarks. This parameter can be **NULL**.

### `pvStopValue` [out]

Stop position. The meaning and data type of this parameter are indicated by the *pguidStopPositionType* parameter. The *pvStopValue* parameter must be **NULL** if *pguidStopPositionType* is **NULL**, and cannot be **NULL** otherwise.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *pguidStartPositionType* and *pguidStopPositionType* parameters receive the units of time that are used. Currently, the only supported value is **MFP_POSITIONTYPE_100NS**.

| Value | Description |
| --- | --- |
| MFP_POSITIONTYPE_100NS | 100-nanosecond units. The time parameter (*pvStartValue* or *pvStopValue*) uses the following data type:<br><br>* Variant type (**vt**): VT_I8<br>* Variant member: **hVal** |

## See also

[How to Play a File Clip](https://learn.microsoft.com/windows/desktop/medfound/how-to-play-a-file-clip)

[IMFPMediaItem](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaitem)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)