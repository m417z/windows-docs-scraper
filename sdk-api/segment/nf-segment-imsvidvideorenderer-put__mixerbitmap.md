# IMSVidVideoRenderer::put__MixerBitmap

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put__MixerBitmap** method specifies the static bitmap image.

## Parameters

### `MixerPicture` [in]

A pointer to a [VMRALPHABITMAP](https://learn.microsoft.com/previous-versions/ms788081(v=vs.85)) structure that contains information about the bitmap.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::get__MixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get__mixerbitmap)

[IMSVidVideoRenderer::put_MixerBitmap](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_mixerbitmap)

[Mixing an Image Onto the Video Window in C++](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/mixing-an-image-onto-the-video-window-in-c-)