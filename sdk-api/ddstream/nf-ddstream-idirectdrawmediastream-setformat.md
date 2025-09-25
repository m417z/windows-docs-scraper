# IDirectDrawMediaStream::SetFormat

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Sets the format of the current media stream.

## Parameters

### `pDDSurfaceDesc` [in]

Pointer to a DirectDraw surface description that contains the new format.

### `pDirectDrawPalette` [in]

Optional parameter that is a pointer to an **IDirectDrawPalette** interface.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **DDERR_INVALIDSURFACETYPE** | The specified format is incompatible with the current stream. |
| **MS_E_SAMPLEALLOC** | Can't change the format because one or more stream samples are already allocated for this stream. |
| **S_OK** | Success. |

## Remarks

If the stream already has allocated samples and the sample format doesn't match the specified format, this method fails. This method always succeeds if the specified format matches the current format.

## See also

[IDirectDrawMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/ddstream/nn-ddstream-idirectdrawmediastream)