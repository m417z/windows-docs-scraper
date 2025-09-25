# IAMTimecodeDisplay::GetTCDisplay

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetTCDisplay` method retrieves current settings of the timecode character generator output.

## Parameters

### `Param` [in]

Timecode display characteristic. Specify one of the following items you want to get settings for.

| Value | Description |
| --- | --- |
| ED_TCD_BORDER | White border for black characters, black border for white characters. |
| ED_TCD_INTENSITY | Intensity (brightness) of characters. |
| ED_TCD_INVERT | Black characters on white background or white characters on black background. |
| ED_TCD_POSITION | Position of characters. |
| ED_TCD_SIZE | Size of characters. |
| ED_TCD_SOURCE | Source of display's data. |
| ED_TCD_TRANSPARENCY | Transparency of characters. |

### `pValue` [out]

Pointer to the current setting of the parameter specified in *Param*. This parameter retrieves one of the following values.

If ED_TCD_SOURCE specified in *Param*, will return one of the following.

| Value | Description |
| --- | --- |
| ED_TCG | Timecode generator |
| ED_TCR | Timecode reader |

If ED_TCD_SIZE specified in *Param*, will return one of the following.

| Value | Description |
| --- | --- |
| ED_LARGE | Large |
| ED_MED | Medium |
| ED_SMALL | Small |

If ED_TCD_POSITION specified in *Param*, will return one of the following.

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

If ED_TCD_INTENSITY specified in *Param*, will return one of the following.

| Value | Description |
| --- | --- |
| ED_HIGH | High |
| ED_LOW | Low |

If ED_TCD_TRANSPARENCY is specified in *Param*, will return a value from 0 to 4, 0 being completely opaque.

If ED_TCD_INVERT is specified in *Param*, will return one of the following.

| Value | Description |
| --- | --- |
| OAFALSE | Black characters on white background |
| OATRUE | White characters on black background |

If ED_TCD_BORDER specified in *Param*, will return one of the following.

| Value | Description |
| --- | --- |
| OAFALSE | Black characters for white border |
| OATRUE | White border for black characters |

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMTimecodeDisplay Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtimecodedisplay)

[IAMTimecodeDisplay::SetTCDisplay](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtimecodedisplay-settcdisplay)