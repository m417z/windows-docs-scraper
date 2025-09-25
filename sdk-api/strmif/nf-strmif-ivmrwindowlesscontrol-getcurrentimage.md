# IVMRWindowlessControl::GetCurrentImage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurrentImage` method retrieves a copy of the current image being displayed by the VMR.

## Parameters

### `lpDib` [out]

Address of a pointer to a BYTE array.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

| Return code | Description |
| --- | --- |
| **VFW_E_WRONG_STATE** | The VMR is not in windowless mode. |

## Remarks

This method returns the current image being displayed. The image is returned in the form of packed Windows DIB. The image starts with a **BITMAPINFOHEADER** structure, possibly including palette entries and/or color masks, followed by the image data.

The VMR allocates the memory for the image and returns a pointer to it in the *lpDib* variable. The caller must free the memory by calling **CoTaskMemFree**.

This method can be called at any time, no matter what state the filter is in, whether running, stopped or paused. However, frequent calls to this method will degrade video playback performance.

#### Examples

| C++ |
| --- |
| ``` BYTE *lpDib = NULL; hr = pWindowlessControl->GetCurrentImage(&lpDib); if (SUCCEEDED(hr)) {     BITMAPINFOHEADER *pBMIH = (BITMAPINFOHEADER*)lpDib;     /* .... */     CoTaskMemFree(lpDib); } ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRWindowlessControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ivmrwindowlesscontrol)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)