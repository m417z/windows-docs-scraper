# ITextRange::SetPoint

## Description

Changes the range based on a specified point at or up through (depending on *Extend*) the point (*x*, *y*) aligned according to *Type*.

## Parameters

### `x` [in]

Type: **long**

Horizontal coordinate of the specified point, in absolute screen coordinates.

### `y` [in]

Type: **long**

Vertical coordinate of the specified point, in absolute screen coordinates.

### `Type` [in]

Type: **long**

The end to move to the specified point. It can be one of the following.

|  |  |
| --- | --- |
| **tomStart** | Move the start of range. |
| **tomEnd** | Move the end of range. |

### `Extend` [in]

Type: **long**

How to set the endpoints of the range. If *Extend* is zero (the default), the range is an insertion point at the specified point (or at the nearest point with selectable text). If *Extend* is 1, the end specified by *Type* is moved to the point and the other end is left alone.

## Return value

Type: **HRESULT**

The method returns **S_OK**.

## Remarks

An application can use the specified point in the [WindowFromPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-windowfrompoint) function to get the handle of the window, which usually can be used to find the client-rectangle coordinates (although a notable exception is with [Windowless Controls](https://learn.microsoft.com/windows/desktop/Controls/windowless-rich-edit-controls)).

## See also

**Conceptual**

[GetPoint](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getpoint)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)