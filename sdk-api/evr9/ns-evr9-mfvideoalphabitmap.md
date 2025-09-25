# MFVideoAlphaBitmap structure

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Specifies a bitmap for the enhanced video renderer (EVR) to alpha-blend with the video.

## Members

### `GetBitmapFromDC`

If **TRUE**, the **hdc** member is used. Otherwise, the **pDDs** member is used.

### `bitmap`

A union that contains the following members.

#### pDDs

Pointer to the **IDirect3DSurface9** interface of a Direct3D surface that contains the bitmap. If **GetBitmapFromDC** is **TRUE**, this member is ignored.

### `bitmap.hdc`

Handle to the device context (DC) of a GDI bitmap. If **GetBitmapFromDC** is **FALSE**, this member is ignored.

### `bitmap.pDDS`

### `params`

[MFVideoAlphaBitmapParams](https://learn.microsoft.com/windows/desktop/api/evr9/ns-evr9-mfvideoalphabitmapparams) structure that specifies the parameters for the alpha-blending operation.

## Remarks

To specify a GDI bitmap, create a device context and call **SelectObject** to select the bitmap into the DC. Then set the **hdc** member of the structure equal to the handle to the DC and set the **GetBitmapFromDC** member to **TRUE**.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoMixerBitmap::SetAlphaBitmap](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideomixerbitmap-setalphabitmap)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)