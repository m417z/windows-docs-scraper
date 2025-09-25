# IInkRectangle::GetRectangle

## Description

Gets the elements of the [InkRectangle](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class) object in a single call.

## Parameters

### `Top` [out]

The top of the rectangle.

### `Left` [out]

The left edge of the rectangle.

### `Bottom` [out]

The bottom of the rectangle.

### `Right` [out]

The right edge of the rectangle.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## See also

[Bottom Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrectangle-get_bottom)

[IInkRectangle](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrectangle)

[InkRectangle Class](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class)

[Left Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrectangle-get_left)

[Right Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrectangle-get_right)

[Top Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrectangle-get_top)