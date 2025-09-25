# IMixerOCX::SetDrawRegion

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDrawRegion` method specifies the location and dimensions of the video and clipping rectangles in screen coordinates.

## Parameters

### `lpptTopLeftSC` [in]

Specifies the top left of the video rectangle in screen coordinates. (The Overlay Mixer filter ignores this parameter. This parameter should be set to **NULL**.)

### `prcDrawCC` [in]

Specifies the video rectangle in screen coordinates. This parameter cannot be **NULL**.

### `lprcClip` [in]

Specifies the clipping rectangle in screen coordinates. This parameter cannot be **NULL**.

## Return value

The method returns an **HRESULT** value. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Either *prcDrawCC* or *lprcClip* are **NULL**. |

## See also

[IMixerOCX Interface](https://learn.microsoft.com/windows/desktop/api/mixerocx/nn-mixerocx-imixerocx)

[Overlay Mixer](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter)