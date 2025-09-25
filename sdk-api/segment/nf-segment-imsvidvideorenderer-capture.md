# IMSVidVideoRenderer::Capture

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Capture** method captures the video frame that is currently being rendered by the Video Mixing Renderer (VMR).

## Parameters

### `currentImage` [out]

Receives an **IPictureDisp** interface pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The returned **IPictureDisp** interface has an outstanding reference count. The caller must release the interface.

For information about the **IPictureDisp** interface, see the Microsoft Platform SDK documentation.

#### Examples

```cpp

CComPtr<IMSVidCtl> m_pVideoControl; // Pointer to the Video Control.

/* Build and run the filter graph (not shown). */

// Find the video renderer
CComPtr<IMSVidVideoRenderer> pVideo;
hr = m_pVideoControl->get_VideoRendererActive(&pVideo);
if (SUCCEEDED(hr))
{
    // Capture the image.
    CComPtr<IPictureDisp> pPic;
    hr = pVideo->Capture(&pPic);
}

```

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)