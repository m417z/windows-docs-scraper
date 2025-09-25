# IInkRectangle::SetRectangle

## Description

Sets the elements of the [InkRectangle](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class) object in a single call.

## Parameters

### `Top` [in]

The top of the rectangle.

### `Left` [in]

The left of the rectangle.

### `Bottom` [in]

The bottom of the rectangle.

### `Right` [in]

The right of the rectangle.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

**Note** The order of the parameters in this method (*Top*, *Left*, *Bottom*, and *Right*) is different from the expected order (*Left*, *Top*, *Right*, and *Bottom*).

## See also

[Bottom Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrectangle-get_bottom)

[IInkRectangle](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrectangle)

[InkRectangle Class](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class)

[Left Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrectangle-get_left)

[Right Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrectangle-get_right)

[Top Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrectangle-get_top)