# IAMMultiMediaStream::OpenMoniker

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `OpenMoniker` method opens a file or device moniker; you can read media data from this moniker if DirectShow supports the moniker.

## Parameters

### `pCtx` [in]

Pointer to the bind context associated with the moniker.

### `pMoniker` [in]

Pointer to an **IMoniker** interface that specifies the moniker you want to open.

### `dwFlags` [in]

Value that modifies how the filter graph will render the specified file. This value is a combination of one or more of the following flags.

| Value | Description |
| --- | --- |
| AMMSF_NOCLOCK | Run the stream with no clock. |
| AMMSF_NORENDER | Open the file, but do not render any streams. This flag should always be accompanied with the AMMSF_RUN flag. |
| AMMSF_RENDERALLSTREAMS | Render all streams, including those that do not have an existing media stream. |
| AMMSF_RENDERTOEXISTING | Only render to existing streams. |
| AMMSF_RUN | Set the stream into the run state. |

## Return value

Returns S_OK if successful or E_INVALIDARG if the *dwFlags* parameter is invalid.

## See also

[IAMMultiMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammultimediastream)