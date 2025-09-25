# IVMRMixerBitmap9::SetAlphaBitmap

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetAlphaBitmap` method specifies a new bitmap image and the source location of the bitmap and how and where it should be rendered on the destination rectangle.

## Parameters

### `pBmpParms` [in]

Pointer to a [VMR9AlphaBitmap](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9alphabitmap) structure that contains information about the bitmap.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pBmpParms* is **NULL**. |
| **E_INVALIDARG** | Invalid argument. See Remarks. |
| **E_OUTOFMEMORY** | Could not create a destination DC or DIBSection for the bitmap. |
| **E_FAIL** | BitBlt to bitmap surface failed. |

## Remarks

To remove the bitmap, set the VMR9AlphaBitmap_Disable flag in the **VMR9AlphaBitmap** structure and call `SetAlphaBitmap` again.

The application can provide the bitmap either as a Direct3D surface or as a GDI bitmap. To use a Direct3D surface, set the **pDDS** member of the [VMR9AlphaBitmap](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9alphabitmap) structure. To use a GDI bitmap, set the **hdc** member of the structure.

The bitmap is mixed onto the video frame by the VMR's mixer component. The mixer draws the bitmap once per frame. If you change the bitmap while the filter graph is paused or stopped, the mixer does not use the new bitmap until the graph restarts. You can work around this limitation by calling [IMediaControl::StopWhenReady](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-stopwhenready), although a better solution is to write a custom allocator-presenter to draw the bitmap. For more information, see [Supplying a Custom Allocator-Presenter for VMR-9](https://learn.microsoft.com/windows/desktop/DirectShow/supplying-a-custom-allocator-presenter-for-vmr-9).

If the method returns E_INVALIDARG, possible reasons include the following:

* The Direct3D surface was not allocated from the D3DPOOL_SYSTEMMEM pool.
* Invalid surface format. If a Direct3D surface is used, the surface format must be D3DFMT_X8R8G8B8 or D3DFMT_A8R8G8B8. If the surface format is D3DFMT_A8R8G8B8, the VMR9AlphaBitmap_SrcColorKey flag cannot be used.
* The source rectangle (rSrc) exceeds the boundaries of the Direct3D surface.
* The source rectangle is empty.
* The source rectangle exceeds the maximum texture width or maximum texture height for the Direct3D device. To find the maximum texture size, call **IDirect3DDevice9::GetDeviceCaps**.
* The **dwFilterMode** member contains an invalid combination of flags.

Include DShow.h and D3d9.h before Vmr9.h.

## See also

[GetAlphaBitmapParameters](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrmixerbitmap9-getalphabitmapparameters)

[IVMRMixerBitmap9 Interface](https://learn.microsoft.com/windows/desktop/api/vmr9/nn-vmr9-ivmrmixerbitmap9)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)