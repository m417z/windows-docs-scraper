# ID2D1StrokeStyle::GetDashes

## Description

Copies the dash pattern to the specified array.

## Parameters

### `dashes` [out]

Type: **FLOAT***

A pointer to an array that will receive the dash pattern. The array must be able to contain at least as many elements as specified by *dashesCount*. You must allocate storage for this array.

### `dashesCount`

Type: **UINT**

The number of dashes to copy. If this value is less than the number of dashes in the stroke style's dashes array, the returned dashes are truncated to *dashesCount*. If this value is greater than the number of dashes in the stroke style's dashes array, the extra dashes are set to 0.0f. To obtain the actual number of dashes in the stroke style's dashes array, use the [GetDashesCount](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1strokestyle-getdashescount) method.

## Remarks

The dashes are specified in units that are a multiple of the stroke width, with subsequent members of the array indicating the dashes and gaps between dashes: the first entry indicates a filled dash, the second a gap, and so on.

## See also

[ID2D1StrokeStyle](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1strokestyle)