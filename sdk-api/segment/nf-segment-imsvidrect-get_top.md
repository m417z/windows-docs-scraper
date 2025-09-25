# IMSVidRect::get_Top

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Top** method retrieves the top y-coordinate of the rectangle. This coordinate is relative to the rectangle's associated window.

## Parameters

### `TopVal` [out]

Pointer to a variable that receives the top y-coordinate, in pixels.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidRect Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect)

[IMSVidRect::get_HWnd](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidrect-get_hwnd)

[IMSVidRect::put_Top](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidrect-put_top)