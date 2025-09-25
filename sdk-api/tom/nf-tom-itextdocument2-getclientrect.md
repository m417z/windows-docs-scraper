# ITextDocument2::GetClientRect

## Description

Retrieves the client rectangle of the rich edit control.

## Parameters

### `Type` [in]

Type: **long**

The client rectangle retrieval options. It can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **tomClientCoord** | Retrieve the rectangle in client coordinates. If this value isn't specified, the function retrieves screen coordinates. |
| **tomIncludeInset** | Add left and top insets to the left and top coordinates of the client rectangle, and subtract right and bottom insets from the right and bottom coordinates. |
| **tomTransform** | Use a world transform (XFORM) provided by the host application to transform the retrieved rectangle coordinates. |

### `pLeft` [out]

Type: **long***

The x-coordinate of the upper-left corner of the rectangle.

### `pTop` [out]

Type: **long***

The y-coordinate of the upper-left corner of the rectangle.

### `pRight` [out]

Type: **long***

The x-coordinate of the lower-right corner of the rectangle.

### `pBottom` [out]

Type: **long***

The y-coordinate of the lower-right corner of the rectangle.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the method succeeds, it returns **NOERROR**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITextDocument2](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument2)