# VMRALLOCATIONINFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `VMRALLOCATIONINFO` structure is used in the VMR-7 filter's [IVMRSurfaceAllocator::AllocateSurface](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrsurfaceallocator-allocatesurface) method.

## Members

### `dwFlags`

A bitwise **OR** of flags from the [VMRSurfaceAllocationFlags](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-vmrsurfaceallocationflags) enumeration.

### `lpHdr`

Pointer to the **BITMAPINFOHEADER** structure associated with the surface.

### `lpPixFmt`

Pointer to the **DDPIXELFORMAT** structure associated with the surface.

### `szAspectRatio`

A [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that specifies the aspect ratio of the new surface.

### `dwMinBuffers`

The minimum number of buffers to create for this surface.

### `dwMaxBuffers`

The maximum number of buffers to create for this surface.

### `dwInterlaceFlags`

A bitwise **OR** of flags that indicate the interlacing. For a list of flags, see the **dwInterlaceFlags** member of the [VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2) structure.

### `szNativeSize`

The size of the native video rectangle.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)