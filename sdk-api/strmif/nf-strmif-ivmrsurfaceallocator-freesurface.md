# IVMRSurfaceAllocator::FreeSurface

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `FreeSurface` method frees the allocated DirectDraw surface.

## Parameters

### `dwID` [in]

An application-defined DWORD_PTR cookie that uniquely identifies this instance of the VMR for use in scenarios when one instance of the allocator-presenter is used with multiple VMR instances.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IVMRSurfaceAllocator Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrsurfaceallocator)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)