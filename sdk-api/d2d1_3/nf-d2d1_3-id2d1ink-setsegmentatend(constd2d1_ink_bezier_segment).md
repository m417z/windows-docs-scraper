# ID2D1Ink::SetSegmentAtEnd

## Description

Updates the last segment in this ink object with new control points.

## Parameters

### `segment` [in]

Type: **const [D2D1_INK_BEZIER_SEGMENT](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_ink_bezier_segment)***

A pointer to the segment data with which to overwrite this ink object's last segment. Note that if there are currently no segments in the ink object, SetSegmentsAtEnd will return an error.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1Ink](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1ink)