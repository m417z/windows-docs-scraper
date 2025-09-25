# ID2D1SvgStrokeDashArray::UpdateDashes(const D2D1_SVG_LENGTH,UINT32,UINT32)

## Description

Updates the array. Existing dashes not updated by this method are preserved. The array is resized larger if necessary to accommodate the new dashes.

## Parameters

### `dashes` [in]

Type: **const FLOAT***

The dashes array.

### `dashesCount`

Type: **UINT32**

The number of dashes to update.

### `startIndex`

Type: **UINT32**

The index at which to begin updating dashes. Must be less than or equal to the size of the array.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## See also

[ID2D1SvgStrokeDashArray](https://learn.microsoft.com/windows/desktop/api/d2d1svg/nn-d2d1svg-id2d1svgstrokedasharray)