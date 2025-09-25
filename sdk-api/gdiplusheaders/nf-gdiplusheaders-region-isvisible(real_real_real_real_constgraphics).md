# Region::IsVisible(IN REAL,IN REAL,IN REAL,IN REAL,IN const Graphics)

## Description

The **Region::IsVisible** method determines whether a rectangle intersects this region.

## Parameters

### `x` [in]

Type: **REAL**

Real number that specifies the x-coordinate of the upper-left corner of the rectangle to test.

### `y` [in]

Type: **REAL**

Real number that specifies the y-coordinate of the upper-left corner of the rectangle to test.

### `width` [in]

Type: **REAL**

Real number that specifies the width of the rectangle to test.

### `height` [in]

Type: **REAL**

Real number that specifies the height of the rectangle to test.

### `g` [in]

Type: **const [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)***

Optional. Pointer to a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object that contains the world and page transformations required to calculate the device coordinates of this region and the rectangle. The default value is **NULL**.

## Return value

Type: **BOOL**

If the rectangle intersects this region, this method returns **TRUE**; otherwise, it returns **FALSE**.

## Remarks

**Note** A region contains its border.

## See also

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Region](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-region)