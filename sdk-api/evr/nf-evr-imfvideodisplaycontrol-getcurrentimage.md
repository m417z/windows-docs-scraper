# IMFVideoDisplayControl::GetCurrentImage

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Gets a copy of the current image being displayed by the video renderer.

## Parameters

### `pBih` [in, out]

Pointer to a **BITMAPINFOHEADER** structure that receives a description of the bitmap. Set the **biSize** member of the structure to `sizeof(BITMAPINFOHEADER)` before calling the method.

### `pDib` [out]

Receives a pointer to a buffer that contains a packed Windows device-independent bitmap (DIB). The caller must free the memory for the bitmap by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pcbDib` [out]

Receives the size of the buffer returned in *pDib*, in bytes.

### `pTimeStamp` [in, out]

Receives the time stamp of the captured image.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_LICENSE_INCORRECT_RIGHTS** | The content is protected and the license does not permit capturing the image. |
| **MF_E_SHUTDOWN** | The video renderer has been shut down. |

## Remarks

This method can be called at any time. However, calling the method too frequently degrades the video playback performance.

This method retrieves a copy of the final composited image, which includes any substreams, alpha-blended bitmap, aspect ratio correction, background color, and so forth.

In windowed mode, the bitmap is the size of the destination rectangle specified in [IMFVideoDisplayControl::SetVideoPosition](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideodisplaycontrol-setvideoposition). In full-screen mode, the bitmap is the size of the display.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoDisplayControl](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideodisplaycontrol)

[Using the Video Display Controls](https://learn.microsoft.com/windows/desktop/medfound/using-the-video-display-controls)