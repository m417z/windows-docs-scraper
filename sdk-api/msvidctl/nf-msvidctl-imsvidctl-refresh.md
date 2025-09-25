# IMSVidCtl::Refresh

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Refresh** method immediately updates the Video Control's appearance.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method is a stock ActiveX control method. It forces the Video Control window to repaint itself. Before repainting, the Video Control ensures that the video rectangle is up to date and that all Video Mixing Renderer settings are correct.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)