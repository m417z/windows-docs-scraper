# IVMRSurfaceAllocatorNotify::SetDDrawDevice

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDDrawDevice` method sets the initial DirectDraw device and monitor to be used for video playback.

## Parameters

### `lpDDrawDevice` [in]

Specifies the DirectDraw device.

### `hMonitor` [in]

Handle to the monitor associated with the DirectDraw device.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The VMR needs to know which DirectDraw device is being used at any given time in order to associate the Direct3D surfaces being created in the mixer component with that device.

## See also

[IVMRSurfaceAllocatorNotify Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrsurfaceallocatornotify)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)