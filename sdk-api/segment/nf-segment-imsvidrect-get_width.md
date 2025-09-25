# IMSVidRect::get_Width

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Width** method retrieves the width of the rectangle.

## Parameters

### `WidthVal` [out]

Pointer to a variable that receives the width, in pixels.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Calling the [IMSVidRect::put_Left](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidrect-put_left) method changes the width of the rectangle. For example, if the x-coordinate is zero and the width is 100, setting the x-coordinate to 10 changes the width to 90.

## See also

[IMSVidRect Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect)

[IMSVidRect::put_Width](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidrect-put_width)