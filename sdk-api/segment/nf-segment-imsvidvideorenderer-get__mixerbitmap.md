# IMSVidVideoRenderer::get__MixerBitmap

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get__MixerBitmap** method retrieves the Video Mixing Renderer's [IVMRMixerBitmap](https://learn.microsoft.com/windows/win32/api/strmif/nn-strmif-ivmrmixerbitmap) interface, which controls how the VMR mixes a static bitmap.

## Parameters

### `MixerPicture` [out]

Receives an [IVMRMixerBitmap](https://learn.microsoft.com/windows/win32/api/strmif/nn-strmif-ivmrmixerbitmap) interface pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The returned [IVMRMixerBitmap](https://learn.microsoft.com/windows/win32/api/strmif/nn-strmif-ivmrmixerbitmap) interface has an outstanding reference count. The caller must release the interface.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::get_MixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_mixerbitmap)

[IMSVidVideoRenderer::put__MixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put__mixerbitmap)

[Mixing an Image Onto the Video Window in C++](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/mixing-an-image-onto-the-video-window-in-c-)