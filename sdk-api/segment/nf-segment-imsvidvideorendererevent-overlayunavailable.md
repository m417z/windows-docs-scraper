# IMSVidVideoRendererEvent::OverlayUnavailable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows XP or later.

The **OverlayUnavailable** method is called when the overlay surface on the graphics card is not available.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The dispatch identifier (dispid) of this method is **eventidOverlayUnavailable**.

## See also

[IMSVidVideoRendererEvent Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidvideorendererevent)