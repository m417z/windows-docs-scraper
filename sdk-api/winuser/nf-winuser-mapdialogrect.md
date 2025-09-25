# MapDialogRect function

## Description

Converts the specified dialog box units to screen units (pixels). The function replaces the coordinates in the specified [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure with the converted coordinates, which allows the structure to be used to create a dialog box or position a control within a dialog box.

## Parameters

### `hDlg` [in]

Type: **HWND**

A handle to a dialog box. This function accepts only handles returned by one of the dialog box creation functions; handles for other windows are not valid.

### `lpRect` [in, out]

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the dialog box coordinates to be converted.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **MapDialogRect** function assumes that the initial coordinates in the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure represent dialog box units. To convert these coordinates from dialog box units to pixels, the function retrieves the current horizontal and vertical base units for the dialog box, then applies the following formulas:

``` syntax

left   = MulDiv(left,   baseunitX, 4);
right  = MulDiv(right,  baseunitX, 4);
top    = MulDiv(top,    baseunitY, 8);
bottom = MulDiv(bottom, baseunitY, 8);
```

If the dialog box template has the [DS_SETFONT](https://learn.microsoft.com/windows/desktop/dlgbox/about-dialog-boxes) or **DS_SHELLFONT** style, the base units are the average width and height, in pixels, of the characters in the font specified by the template.

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[GetDialogBaseUnits](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdialogbaseunits)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**