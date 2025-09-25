# IInkPicture::GetWindowInputRectangle

## Description

Retrieves the window rectangle, in pixels, within which ink is drawn.

## Parameters

### `WindowInputRectangle` [out]

Gets the rectangle, of type [InkRectangle](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class), on which ink is drawn.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contains an invalid pointer. |
| **REGDB_CLASSNOTREG** | The InkRectangle object is not registered. |
| **E_INK_EXCEPTION** | An exception occurs inside the method. |

## Remarks

You must first allocate the rectangle before passing it on to this method.

By default, the window input rectangle is set to {0,0,0,0}. This default rectangle maps to the size of the entire window.

If you call **GetWindowInputRectangle** before you call the [SetWindowInputRectangle](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-setwindowinputrectangle) method, this method gets a rectangle with the default coordinates.

## See also

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)

[SetWindowInputRectangle Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-setwindowinputrectangle)