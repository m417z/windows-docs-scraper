# DLGITEMTEMPLATE structure

## Description

Defines the dimensions and style of a control in a dialog box. One or more of these structures are combined with a [DLGTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgtemplate) structure to form a standard template for a dialog box.

## Members

### `style`

Type: **DWORD**

The style of the control. This member can be a combination of [window style values](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) (such as **WS_BORDER**) and one or more of the [control style values](https://learn.microsoft.com/windows/desktop/Controls/common-control-styles) (such as **BS_PUSHBUTTON** and **ES_LEFT**).

### `dwExtendedStyle`

Type: **DWORD**

The extended styles for a window. This member is not used to create controls in dialog boxes, but applications that use dialog box templates can use it to create other types of windows. For a list of values, see [Extended Window Styles](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles).

### `x`

Type: **short**

The
*x*-coordinate, in dialog box units, of the upper-left corner of the control. This coordinate is always relative to the upper-left corner of the dialog box's client area.

### `y`

Type: **short**

The
*y*-coordinate, in dialog box units, of the upper-left corner of the control. This coordinate is always relative to the upper-left corner of the dialog box's client area.

### `cx`

Type: **short**

The width, in dialog box units, of the control.

### `cy`

Type: **short**

The height, in dialog box units, of the control.

### `id`

Type: **WORD**

The control identifier.

## Remarks

In a standard template for a dialog box, the **DLGITEMTEMPLATE** structure is always immediately followed by three variable-length arrays specifying the class, title, and creation data for the control. Each array consists of one or more 16-bit elements.

Each **DLGITEMTEMPLATE** structure in the template must be aligned on a
**DWORD** boundary. The class and title arrays must be aligned on
**WORD** boundaries. The creation data array must be aligned on a
**WORD** boundary.

Immediately following each **DLGITEMTEMPLATE** structure is a class array that specifies the window class of the control. If the first element of this array is any value other than 0xFFFF, the system treats the array as a null-terminated Unicode string that specifies the name of a registered window class. If the first element is 0xFFFF, the array has one additional element that specifies the ordinal value of a predefined system class. The ordinal can be one of the following atom values.

| Value | Meaning |
| --- | --- |
| 0x0080 | Button |
| 0x0081 | Edit |
| 0x0082 | Static |
| 0x0083 | List box |
| 0x0084 | Scroll bar |
| 0x0085 | Combo box |

Following the class array is a title array that contains the initial text or resource identifier of the control. If the first element of this array is 0xFFFF, the array has one additional element that specifies an ordinal value of a resource, such as an icon, in an executable file. You can use a resource identifier for controls, such as static icon controls, that load and display an icon or other resource rather than text. If the first element is any value other than 0xFFFF, the system treats the array as a null-terminated Unicode string that specifies the initial text.

The creation data array begins at the next
**WORD** boundary after the title array. This creation data can be of any size and format. If the first word of the creation data array is nonzero, it indicates the size, in bytes, of the creation data (including the size word). The control's window procedure must be able to interpret the data. When the system creates the control, it passes a pointer to this data in the
*lParam* parameter of the [WM_CREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-create) message that it sends to the control.

If you specify character strings in the class and title arrays, you must use Unicode strings. Use the
[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) function to generate Unicode strings from ANSI strings.

The
**x**,
**y**,
**cx**, and
**cy** members specify values in dialog box units. You can convert these values to screen units (pixels) by using the [MapDialogRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapdialogrect) function.

## See also

**Conceptual**

[CreateDialogIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialogindirecta)

[CreateDialogIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createdialogindirectparama)

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

[DLGITEMTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgitemtemplateex)

[DLGTEMPLATE](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-dlgtemplate)

[DLGTEMPLATEEX](https://learn.microsoft.com/windows/desktop/dlgbox/dlgtemplateex)

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[DialogBoxIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirecta)

[DialogBoxIndirectParam](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxindirectparama)

[MapDialogRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapdialogrect)

[MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)

**Other Resources**

**Reference**

[WM_CREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-create)