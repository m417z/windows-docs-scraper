# ID2D1Ink::GetSegments

## Description

Retrieves the specified subset of segments stored in this ink object.

## Parameters

### `startSegment`

Type: **UINT32**

The index of the first segment in this ink object to retrieve.

### `segments` [out]

Type: **[D2D1_INK_BEZIER_SEGMENT](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ns-d2d1_3-d2d1_ink_bezier_segment)***

When this method returns, contains a pointer to an array of retrieved segments.

### `segmentsCount`

Type: **UINT32**

The number of segments to retrieve. Note that segmentsCount must be less than or equal to the number of segments in the ink object minus startSegment.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1Ink](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1ink)