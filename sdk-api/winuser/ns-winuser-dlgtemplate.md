# DLGTEMPLATE structure

## Description

Defines the dimensions and style of a dialog box. This structure, always the first in a standard template for a dialog box, also specifies the number of controls in the dialog box and therefore specifies the number of subsequent [DLGITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgitemtemplate) structures in the template.

## Members

### `style`

Type: **DWORD**

The style of the dialog box. This member can be a combination of [window style values](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) (such as **WS_CAPTION** and **WS_SYSMENU**) and [dialog box style values](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-box-styles) (such as **DS_CENTER**).

If the style member includes the **DS_SETFONT** style, the header of the dialog box template contains additional data specifying the font to use for text in the client area and controls of the dialog box. The font data begins on the
**WORD** boundary that follows the title array. The font data specifies a 16-bit point size value and a Unicode font name string. If possible, the system creates a font according to the specified values. Then the system sends a [WM_SETFONT](https://learn.microsoft.com/windows/desktop/winmsg/wm-setfont) message to the dialog box and to each control to provide a handle to the font. If **DS_SETFONT** is not specified, the dialog box template does not include the font data.

The **DS_SHELLFONT** style is not supported in the **DLGTEMPLATE** header.

### `dwExtendedStyle`

Type: **DWORD**

The extended styles for a window. This member is not used to create dialog boxes, but applications that use dialog box templates can use it to create other types of windows. For a list of values, see [Extended Window Styles](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles).

### `cdit`

Type: **WORD**

The number of items in the dialog box.

### `x`

Type: **short**

The x-coordinate, in dialog box units, of the upper-left corner of the dialog box.

### `y`

Type: **short**

The y-coordinate, in dialog box units, of the upper-left corner of the dialog box.

### `cx`

Type: **short**

The width, in dialog box units, of the dialog box.

### `cy`

Type: **short**

The height, in dialog box units, of the dialog box.

## Remarks

In a standard template for a dialog box, the **DLGTEMPLATE** structure is always immediately followed by three variable-length arrays that specify the menu, class, and title for the dialog box. When the DS_SETFONT style is specified, these arrays are also followed by a 16-bit value specifying point size and another variable-length array specifying a typeface name. Each array consists of one or more 16-bit elements. The menu, class, title, and font arrays must be aligned on
**WORD** boundaries.

Immediately following the **DLGTEMPLATE** structure is a menu array that identifies a menu resource for the dialog box. If the first element of this array is 0x0000, the dialog box has no menu and the array has no other elements. If the first element is 0xFFFF, the array has one additional element that specifies the ordinal value of a menu resource in an executable file. If the first element has any other value, the system treats the array as a null-terminated Unicode string that specifies the name of a menu resource in an executable file.

Following the menu array is a class array that identifies the window class of the dialog box. If the first element of the array is 0x0000, the system uses the predefined dialog box class for the dialog box and the array has no other elements. If the first element is 0xFFFF, the array has one additional element that specifies the ordinal value of a predefined system window class. If the first element has any other value, the system treats the array as a null-terminated Unicode string that specifies the name of a registered window class.

Following the class array is a title array that specifies a null-terminated Unicode string that contains the title of the dialog box. If the first element of this array is 0x0000, the dialog box has no title and the array has no other elements.

The 16-bit point size value and the typeface array follow the title array, but only if the
**style** member specifies the DS_SETFONT style. The point size value
specifies the point size of the font to use for the text in the dialog box and its controls. The typeface array is a null-terminated Unicode string specifying the name of the typeface for the font. When these values are specified, the system creates a font having the specified size and typeface (if possible) and sends a [WM_SETFONT](https://learn.microsoft.com/windows/desktop/winmsg/wm-setfont) message to the dialog box procedure and the control window procedures as it creates the dialog box and controls.

Following the **DLGTEMPLATE** header in a standard dialog box template are one or more [DLGITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgitemtemplate) structures that define the dimensions and style of the controls in the dialog box. The
**cdit** member specifies the number of **DLGITEMTEMPLATE** structures in the template. These **DLGITEMTEMPLATE** structures must be aligned on
**DWORD** boundaries.

If you specify character strings in the menu, class, title, or typeface arrays, you must use Unicode strings.

The
**x**,
**y**,
**cx**, and
**cy** members specify values in dialog box units. You can convert these values to screen units (pixels) by using the [MapDialogRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapdialogrect) function.

## See also

**Conceptual**

[CreateDialogIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialogindirecta)

[CreateDialogIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialogindirectparama)

[DLGITEMTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgitemtemplate)

[DLGITEMTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgitemtemplateex)

[DLGTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgtemplateex)

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[DialogBoxIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirecta)

[DialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirectparama)

[MapDialogRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapdialogrect)

[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)

**Other Resources**

**Reference**