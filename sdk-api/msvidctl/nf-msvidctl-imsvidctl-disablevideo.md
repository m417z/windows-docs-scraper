# IMSVidCtl::DisableVideo

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **DisableVideo** method disables the video renderer.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method sets the active video renderer device to **NULL**.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::put_VideoRendererActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_videorendereractive)