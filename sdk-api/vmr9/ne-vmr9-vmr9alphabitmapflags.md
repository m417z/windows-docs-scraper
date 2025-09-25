# VMR9AlphaBitmapFlags enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMR9AlphaBitmapFlags** enumeration type defines the possible values for the **dwFlags** member of the [VMR9AlphaBitmap](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9alphabitmap) structure.

## Constants

### `VMR9AlphaBitmap_Disable:0x1`

Disable the alpha bitmap. This flag cannot be combined with any other flags.

### `VMR9AlphaBitmap_hDC:0x2`

The bitmap is specified as a GDI device context (HDC) in the **hdc** member of the [VMR9AlphaBitmap](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9alphabitmap) structure. If this flag is not present, the bitmap is specified as a Direct3D **IDirect3DSurface9** pointer in the **pDDS** member of the structure.

### `VMR9AlphaBitmap_EntireDDS:0x4`

Use the entire Direct3D surface. The **rSrc** member of the [VMR9AlphaBitmap](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9alphabitmap) structure is ignored. This flag cannot be combined with the VMR9AlphaBitmap_hDC flag.

### `VMR9AlphaBitmap_SrcColorKey:0x8`

Indicates that the **srcClrKey** member is valid and should be used when blending. This flag cannot be used with a Direct3D surface that contains per-pixel alpha (D3DFMT_A8R8G8B8 format).

### `VMR9AlphaBitmap_SrcRect:0x10`

Indicates that the **rSrc** member is valid and specifies a sub-rectangle of the original image to be blended. This flag is only valid for the [IVMRMixerBitmap9::UpdateAlphaBitmapParameters](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrmixerbitmap9-updatealphabitmapparameters) method.

### `VMR9AlphaBitmap_FilterMode:0x20`

Indicates that the **dwFilterMode** member is valid and should be used to override the VMR filter's default filtering method.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)