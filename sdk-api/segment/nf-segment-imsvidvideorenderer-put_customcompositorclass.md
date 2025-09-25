# IMSVidVideoRenderer::put_CustomCompositorClass

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_CustomCompositorClass** method specifies the class identifier (CLSID) of a custom image compositor, as a **BSTR**.

## Parameters

### `CompositorCLSID` [in]

Specifies the CLSID as a string.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method is provided for Automation clients. C++ applications can use the [IMSVidVideoRenderer::put__CustomCompositorClass](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put__customcompositorclass) method, which specifies a **GUID** rather than a **BSTR**.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::get_CustomCompositorClass](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get_customcompositorclass)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)