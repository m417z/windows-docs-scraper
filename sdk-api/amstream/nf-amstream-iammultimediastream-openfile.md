# IAMMultiMediaStream::OpenFile

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `OpenFile` method opens and automatically creates a filter graph for the specified media file. If DirectShow doesn't support the file format, this method does nothing.

## Parameters

### `pszFileName` [in]

Pointer to the name of the file you want to open.

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

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *dwFlags* parameter is invalid. |
| **E_POINTER** | This method tried to access an invalid pointer. |
| **S_OK** | Success. |

## Remarks

The AMMSF_RENDERALLSTREAMS flag will create default rendering filters for video and audio if they do not exist. However, these default filters cannot be accessed by the [IStreamSample::GetMediaStream](https://learn.microsoft.com/windows/desktop/api/mmstream/nf-mmstream-istreamsample-getmediastream) method.

## See also

[IAMMultiMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammultimediastream)