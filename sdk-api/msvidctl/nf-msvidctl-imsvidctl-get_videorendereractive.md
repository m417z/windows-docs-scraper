# IMSVidCtl::get_VideoRendererActive

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_VideoRendererActive** method retrieves the currently active video renderer.

## Parameters

### `pVal` [out]

Receives an [IMSVidVideoRenderer](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer) interface pointer. The caller must release the interface. If no video renderer is active, this parameter receives the value **NULL**.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::put_VideoRendererActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_videorendereractive)