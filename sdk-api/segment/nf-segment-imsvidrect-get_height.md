# IMSVidRect::get_Height

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Height** method retrieves the height of the rectangle.

## Parameters

### `HeightVal` [out]

Pointer to a variable that receives the height, in pixels.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Calling the [IMSVidRect::put_Top](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidrect-put_top) method changes the height of the rectangle. For example, if the y-coordinate is zero and the height is 100, setting the y-coordinate to 10 changes the height to 90.

## See also

[IMSVidRect Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidrect)

[IMSVidRect::put_Height](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidrect-put_height)