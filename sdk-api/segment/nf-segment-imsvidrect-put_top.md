# IMSVidRect::put_Top

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Top** method specifies the top y-coordinate of the rectangle. This coordinate is relative to the rectangle's associated window.

## Parameters

### `TopVal` [in]

Specifies the top y-coordinate, in pixels.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Setting the top y-coordinate also changes the height of the rectangle. For example, if the y-coordinate is zero and the height is 100, setting the y-coordinate to 10 changes the height to 90.

## See also

[IMSVidRect Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect)

[IMSVidRect::get_HWnd](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidrect-get_hwnd)

[IMSVidRect::get_Top](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidrect-get_top)