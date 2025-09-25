# _MFP_MEDIAITEM_CHARACTERISTICS enumeration

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains flags that describe a media item.

## Constants

### `MFP_MEDIAITEM_IS_LIVE:0x1`

The media item represents a live data source, such as video camera. If playback is stopped and then restarted, there will be a gap in the content.

### `MFP_MEDIAITEM_CAN_SEEK:0x2`

The media item supports seeking. If this flag is absent, the [IMFPMediaPlayer::SetPosition](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-setposition) method will fail.

### `MFP_MEDIAITEM_CAN_PAUSE:0x4`

The media item can pause. If this flag is absent, the [IMFPMediaPlayer::Pause](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-pause) method will likely fail.

### `MFP_MEDIAITEM_HAS_SLOW_SEEK:0x8`

Seeking can take a long time. For example, the source might download content through HTTP.

## Remarks

The following **typedef** is defined for combining flags from this enumeration.

``` syntax
typedef UINT32 MFP_MEDIAITEM_CHARACTERISTICS;
```

## See also

[IMFPMediaItem::GetCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaitem-getcharacteristics)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)