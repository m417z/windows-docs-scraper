# IMSVidVideoRenderer::get_CustomCompositorClass

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_CustomCompositorClass** method retrieves the class identifier (CLSID) of the Video Mixing Renderer's current image compositor, as a **BSTR**.

## Parameters

### `CompositorCLSID` [out]

Receives a string representation of the CLSID.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method is provided for Automation clients. C++ applications can use the [IMSVidVideoRenderer::get__CustomCompositorClass](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-get__customcompositorclass) method, which returns a **GUID** rather than a **BSTR**.

The caller must free the returned string, using the **SysFreeString** function.

## See also

[IMSVidVideoRenderer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer)

[IMSVidVideoRenderer::put_CustomCompositorClass](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_customcompositorclass)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)