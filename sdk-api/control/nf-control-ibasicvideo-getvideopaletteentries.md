# IBasicVideo::GetVideoPaletteEntries

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetVideoPaletteEntries` method retrieves the palette colors for the video.

## Parameters

### `StartIndex` [in]

Start index for the palette.

### `Entries` [in]

Number of palette entries to retrieve.

### `pRetrieved` [out]

Pointer to a variable that receives the number of entries returned in *pPallette*.

### `pPalette` [out]

Pointer to an array of [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures of size *Entries*. Cast the pointer to a long pointer type. The method fills the array.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer argument. |
| **VFW_E_NO_PALETTE_AVAILABLE** | No palette is available. |
| **VFW_E_NOT_CONNECTED** | The Video Renderer's input pin is not connected. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IBasicVideo Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ibasicvideo)