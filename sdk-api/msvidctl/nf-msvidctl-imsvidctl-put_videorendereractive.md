# IMSVidCtl::put_VideoRendererActive

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_VideoRendererActive** method specifies the active video renderer.

## Parameters

### `pVal` [in]

Specifies a pointer to the [IMSVidVideoRenderer](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorenderer) interface of the video renderer device.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Currently the only supported video renderer is the Video Mixing Renderer (VMR) filter. The VMR is used by default, so it is not necessary to call this method.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_VideoRendererActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_videorendereractive)