# Header_SetHotDivider macro

## Syntax

```cpp
int Header_SetHotDivider(
   HWND  hwnd,
   BOOL  fPos,
   DWORD dw
);
```

## Return value

Type: **int**

Returns the index of the divider that the control highlighted.

## Description

Changes the color of a divider between header items to indicate the destination of an external drag-and-drop operation. You can use this macro or send the [HDM_SETHOTDIVIDER](https://learn.microsoft.com/windows/desktop/Controls/hdm-sethotdivider) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to a header control.

### `fPos`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value specifying how *dw* is to be interpreted. The value in this field can be one of the following:

| Value | Meaning |
| --- | --- |
| ****TRUE**** | Indicates that *dw* holds client coordinates of the pointer. |
| ****FALSE**** | Indicates that *dw* holds a divider index value. |

### `dw`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The value held here is interpreted depending on the value of *fPos*.

If *fPos* is **TRUE**, *dw* represents the x- and y- client coordinates of the pointer. The x-coordinate is in the low word, and the y-coordinate is in the high word. Upon receiving the message, the header control highlights the appropriate divider based on the *dw* coordinates.

If *fPos* is **FALSE**, *dw* represents the integer index of the divider that will be highlighted.

## Remarks

A header control set to the [HDS_DRAGDROP](https://learn.microsoft.com/windows/desktop/Controls/header-control-styles) style produces this effect automatically. This message is intended to be used when the owner of the control handles drag-and-drop operations manually.