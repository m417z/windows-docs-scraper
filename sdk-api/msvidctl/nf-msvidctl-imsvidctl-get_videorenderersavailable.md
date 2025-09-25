# IMSVidCtl::get_VideoRenderersAvailable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_VideoRenderersAvailable** method retrieves a collection of video renderers available on the local system.

## Parameters

### `pVal` [out]

Receives an [IMSVidVideoRendererDevices](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorendererdevices) interface pointer. The caller must release the interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method returns a collection of video renderer devices. Use the returned [IMSVidVideoRendererDevices](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvideorendererdevices) pointer to enumerate the collection.

**Note**In the current implementation, the collection always contains exactly one item: an [MSVidVideoRenderer](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd695138(v=vs.85)) object that represents the Video Mixing Renderer filter.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_VideoRendererActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_videorendereractive)