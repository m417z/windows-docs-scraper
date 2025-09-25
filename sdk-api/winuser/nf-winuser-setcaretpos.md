# SetCaretPos function

## Description

Moves the caret to the specified coordinates. If the window that owns the caret was created with the **CS_OWNDC** class style, then the specified coordinates are subject to the mapping mode of the device context associated with that window.

## Parameters

### `X` [in]

Type: **int**

The new x-coordinate of the caret.

### `Y` [in]

Type: **int**

The new y-coordinate of the caret.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**SetCaretPos** moves the caret whether the caret is hidden.

The system provides one caret per queue. A window should create a caret only when it has the keyboard focus or is active. The window should destroy the caret before losing the keyboard focus or becoming inactive. A window can set the caret position only if it owns the caret.

### DPI Virtualization

This API does not participate in DPI virtualization. The provided position is interpreted as logical coordinates in terms of the window associated with the caret. The calling thread is not taken into consideration.

#### Examples

For an example, see [Creating and Displaying a Caret](https://learn.microsoft.com/windows/desktop/menurc/using-carets).

## See also

[Carets](https://learn.microsoft.com/windows/desktop/menurc/carets)

**Conceptual**

[GetCaretPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getcaretpos)

[HideCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-hidecaret)

**Reference**

[ShowCaret](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showcaret)