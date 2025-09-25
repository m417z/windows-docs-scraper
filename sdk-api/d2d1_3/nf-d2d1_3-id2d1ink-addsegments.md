# ID2D1Ink::AddSegments

## Description

Adds the given segments to the end of this ink object.

## Parameters

### `segments` [in]

Type: **const [D2D1_INK_BEZIER_SEGMENT](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_ink_bezier_segment)***

A pointer to an array of segments to be added to this ink object.

### `segmentsCount`

Type: **UINT32**

The number of segments to be added to this ink object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1Ink](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1ink)