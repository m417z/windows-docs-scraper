## Description

Contains information about a button in a toolbar.

## Members

### `iBitmap`

Type: **int**

Zero-based index of the button image. Set this member to I_IMAGECALLBACK, and the toolbar will send the [TBN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/tbn-getdispinfo) notification code to retrieve the image index when it is needed.

[Version 5.81](https://learn.microsoft.com/windows/desktop/Controls/common-control-versions). Set this member to I_IMAGENONE to indicate that the button does not have an image. The button layout will not include any space for a bitmap, only text.

If the button is a separator, that is, if **fsStyle** is set to [BTNS_SEP](https://learn.microsoft.com/windows/desktop/Controls/toolbar-control-and-button-styles), **iBitmap** determines the width of the separator, in pixels. For information on selecting button images from image lists, see [TB_SETIMAGELIST](https://learn.microsoft.com/windows/desktop/Controls/tb-setimagelist) message.

### `idCommand`

Type: **int**

Command identifier associated with the button. This identifier is used in a [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) message when the button is chosen.

### `fsState`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Button state flags. This member can be a combination of the values listed in [Toolbar Button States](https://learn.microsoft.com/windows/desktop/Controls/toolbar-button-states).

### `fsStyle`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Button style. This member can be a combination of the button style values listed in [Toolbar Control and Button Styles](https://learn.microsoft.com/windows/desktop/Controls/toolbar-control-and-button-styles).

### `bReserved`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved.

### `dwData`

Type: **[DWORD_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Application-defined value.

### `iString`

Type: **[INT_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index of the button string, or a pointer to a string buffer that contains text for the button.

## Remarks

The **iString** member can return either a string pointer or an index. You can use the [IS_INTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-is_intresource) macro to determine which is returned.