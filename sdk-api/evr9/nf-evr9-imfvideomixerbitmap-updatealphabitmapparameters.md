# IMFVideoMixerBitmap::UpdateAlphaBitmapParameters

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Updates the current alpha-blending settings, including the source and destination rectangles, the color key, and other information. You can update some or all of the blending parameters.

## Parameters

### `pBmpParms` [in]

Pointer to an [MFVideoAlphaBitmapParams](https://learn.microsoft.com/windows/desktop/api/evr9/ns-evr9-mfvideoalphabitmapparams) structure that contains the blending parameters.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The blending parameters defined in the *pBmpParms* structure are not valid. |
| **MF_E_NOT_INITIALIZED** | No bitmap is currently set. You must call [IMFVideoMixerBitmap::SetAlphaBitmap](https://learn.microsoft.com/windows/desktop/api/evr9/nf-evr9-imfvideomixerbitmap-setalphabitmap) to set a bitmap. |

## Remarks

The video must be playing for the changes to take effect.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoMixerBitmap](https://learn.microsoft.com/windows/desktop/api/evr9/nn-evr9-imfvideomixerbitmap)