# IAMTimecodeDisplay::SetTCDisplay

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetTCDisplay` method sets the timecode character generator output characteristics.

## Parameters

### `Param` [in]

Timecode display characteristic. Specify one of the following properties you want to set properties for.

| Value | Description |
| --- | --- |
| ED_TCD_BORDER | White border for black characters, black border for white characters |
| ED_TCD_INTENSITY | Intensity (brightness) of characters |
| ED_TCD_INVERT | Black characters on white background or white characters on black background |
| ED_TCD_POSITION | Position of characters |
| ED_TCD_SIZE | Size of characters |
| ED_TCD_SOURCE | Source of the display's data |
| ED_TCD_TRANSPARENCY | Transparency of characters |

### `Value` [in]

Setting of the parameter specified in *Param*. Must be one of the following:

If ED_TCD_SOURCE specified in *Param*, set one of the following.

| Value | Description |
| --- | --- |
| ED_TCG | Timecode generator |
| ED_TCR | Timecode reader |

If ED_TCD_SIZE is specified in *Param*, set one of the following.

| Value | Description |
| --- | --- |
| ED_LARGE | Large |
| ED_MED | Medium |
| ED_SMALL | Small |

If ED_TCD_POSITION specified in *Param*, set one of the following.

| Value | Description |
| --- | --- |
| ED_BOTTOM | Bottom |
| ED_MIDDLE | Middle |
| ED_TOP | Top |

in combination with one of the following.

| Value | Description |
| --- | --- |
| ED_CENTER | Center |
| ED_LEFT | Left |
| ED_RIGHT | Right |

If ED_TCD_INTENSITY is specified in *Param*, set one of the following.

| Value | Description |
| --- | --- |
| ED_HIGH | High |
| ED_LOW | Low |

If ED_TCD_TRANSPARENCY is specified in *Param*, set a value from 0 to 4, 0 being completely opaque, 4 being as dark as possible.

If ED_TCD_INVERT is specified in *Param*, set one of the following.

| Value | Description |
| --- | --- |
| OAFALSE | Black on white |
| OATRUE | White on black |

If ED_TCD_BORDER is specified in *Param*, set one of the following.

| Value | Description |
| --- | --- |
| OAFALSE | Black characters for white border |
| OATRUE | White border for black characters |

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTimecodeDisplay Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtimecodedisplay)

[IAMTimecodeDisplay::GetTCDisplay](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtimecodedisplay-gettcdisplay)