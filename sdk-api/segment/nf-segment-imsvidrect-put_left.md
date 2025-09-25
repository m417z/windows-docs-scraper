# IMSVidRect::put_Left

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Left** method specifies the left x-coordinate of the rectangle. This coordinate is relative to the rectangle's associated window.

## Parameters

### `LeftVal` [in]

Specifies the left x-coordinate, in pixels.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Setting the left x-coordinate also changes the width of the rectangle. For example, if the x-coordinate is zero and the width is 100, setting the x-coordinate to 10 changes the width to 90.

## See also

[IMSVidRect Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect)

[IMSVidRect::get_HWnd](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidrect-get_hwnd)

[IMSVidRect::get_Left](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidrect-get_left)