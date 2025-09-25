# IDirectDrawMediaStream::CreateSample

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

Creates a stream sample using the specified DirectDraw surface object.

## Parameters

### `pSurface` [in]

Pointer to an existing DirectDraw surface. Use **QueryInterface** to obtain the **IDirectDrawSurface** interface from an **IDirectDrawSurface7** interface pointer.

### `pRect` [in]

Pointer to the clipping rectangle you want to use with the specified surface. Set this parameter to **NULL** if you want to use the entire surface.

### `dwFlags` [in]

Specifies miscellaneous flags. The following flag is defined:

| Value | Description |
| --- | --- |
| DDSFF_PROGRESSIVERENDER | If this flag is set, sample updates are performed directly on the surface. When this flag is absent, if the decoder uses delta frames, an extra copy is performed internally. Setting this flag can improve performance but can also introduce tearing. |

### `ppSample` [out]

Address of a pointer to an [IDirectDrawStreamSample](https://learn.microsoft.com/windows/desktop/api/ddstream/nn-ddstream-idirectdrawstreamsample) interface that will point to the newly created sample.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **DDERR_INVALIDPIXELFORMAT** | The specified pixel format is incompatible with the stream format. |
| **DDERR_INVALIDRECT** | The specified clipping rectangle is invalid. |
| **DDERR_INVALIDSURFACETYPE** | The specified surface is incompatible with the stream format. |
| **E_POINTER** | One or more of the required parameters is invalid. |
| **MS_E_SAMPLEALLOC** | The stream already has allocated samples and the surface doesn't match the sample format. |
| **S_OK** | Success. |

## Remarks

This method creates a sample from the current stream and attaches the sample to this surface.

If the stream doesn't have an allocated surface and the specified surface doesn't match the stream's format, this method calls the [IDirectDrawMediaStream::SetFormat](https://learn.microsoft.com/windows/desktop/api/ddstream/nf-ddstream-idirectdrawmediastream-setformat) method on the stream so the two will match.

To perform a progressive render, create a single sample and repeatedly use that sample for successive frames of video. Video decompressors use this technique to do partial updates to the previous frame.

The *pRect* parameter should match the format of the stream (see [IDirectDrawMediaStream::GetFormat](https://learn.microsoft.com/windows/desktop/api/ddstream/nf-ddstream-idirectdrawmediastream-getformat)). If the wrong clip rectangle is set or no clip rectangle is set, and the surface size does not match the movie size, the movie might not play. If a primary surface is used, it is advisable to use a clipping rectangle because the primary surface size can change if the user changes display settings.

## See also

[IDirectDrawMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/ddstream/nn-ddstream-idirectdrawmediastream)