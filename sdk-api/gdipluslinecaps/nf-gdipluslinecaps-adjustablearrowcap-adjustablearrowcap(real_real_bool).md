## Description

Creates an adjustable arrow line cap with the specified height and width. The arrow line cap can be filled or nonfilled. The middle inset defaults to zero.

## Parameters

### `height` [in]

Type: **REAL**

Real number that specifies the length, in units, of the arrow from its base to its point.

### `width` [in]

Type: **REAL**

Real number that specifies the distance, in units, between the corners of the base of the arrow.

### `isFilled` [in]

Type: **BOOL**

Boolean value that specifies whether the arrow is filled. The default value is **TRUE**.

## Remarks

The middle inset is the number of units that the midpoint of the base shifts towards the vertex. A middle inset of zero results in no shift — the base is a straight line, giving the arrow a triangular shape. A positive (greater than zero) middle inset results in a shift the specified number of units toward the vertex — the base is an arrow shape that points toward the vertex, giving the arrow cap a V-shape. A negative (less than zero) middle inset results in a shift the specified number of units away from the vertex — the base becomes an arrow shape that points away from the vertex, giving the arrow either a diamond shape (if the absolute value of the middle inset is equal to the height) or distorted diamond shape. If the middle inset is equal to or greater than the height of the arrow cap, the cap does not appear at all. The value of the middle inset affects the arrow cap only if the arrow cap is filled. The middle inset defaults to zero when an **AdjustableArrowCap::AdjustableArrowCap** object is constructed.

## See also

[AdjustableArrowCap](https://learn.microsoft.com/windows/desktop/api/gdipluslinecaps/nl-gdipluslinecaps-adjustablearrowcap)

[AdjustableArrowCap::GetMiddleInset](https://learn.microsoft.com/windows/desktop/api/gdipluslinecaps/nf-gdipluslinecaps-adjustablearrowcap-getmiddleinset)

[AdjustableArrowCap::SetMiddleInset](https://learn.microsoft.com/windows/desktop/api/gdipluslinecaps/nf-gdipluslinecaps-adjustablearrowcap-setmiddleinset)