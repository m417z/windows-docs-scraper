# ID2D1SvgPathData::UpdateSegmentData

## Description

Updates the segment data array. Existing segment data not updated by this method are preserved.
The array is resized larger if necessary to accommodate the new segment data.

## Parameters

### `data` [in]

Type: **const FLOAT***

The data array.

### `dataCount`

Type: **UINT32**

The number of data to update.

### `startIndex`

Type: **UINT32**

The index at which to begin updating segment data. Must be less than or equal to the size of the segment data array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgPathData](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgpathdata)