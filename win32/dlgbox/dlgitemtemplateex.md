# DLGITEMTEMPLATEEX structure

A block of text used by an extended dialog box template to describe the extended dialog box. For a description of the format of an extended dialog box template, see [**DLGTEMPLATEEX**](https://learn.microsoft.com/windows/win32/dlgbox/dlgtemplateex).

## Members

**helpID**

Type: **DWORD**

The help context identifier for the control. When the system sends a [**WM\_HELP**](https://learn.microsoft.com/windows/win32/shell/wm-help) message, it passes the **helpID** value in the **dwContextId** member of the [**HELPINFO**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-helpinfo) structure.

**exStyle**

Type: **DWORD**

The extended styles for a window. This member is not used to create controls in dialog boxes, but applications that use dialog box templates can use it to create other types of windows. For a list of values, see [**Extended Window Styles**](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles).

**style**

Type: **DWORD**

The style of the control. This member can be a combination of [window style values](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) (such as **WS\_BORDER**) and one or more of the [control style values](https://learn.microsoft.com/windows/desktop/Controls/common-control-styles) (such as **BS\_PUSHBUTTON** and **ES\_LEFT**).

**x**

Type: **short**

The x-coordinate, in dialog box units, of the upper-left corner of the control. This coordinate is always relative to the upper-left corner of the dialog box's client area.

**y**

Type: **short**

The y-coordinate, in dialog box units, of the upper-left corner of the control. This coordinate is always relative to the upper-left corner of the dialog box's client area.

**cx**

Type: **short**

The width, in dialog box units, of the control.

**cy**

Type: **short**

The height, in dialog box units, of the control.

**id**

Type: **DWORD**

The control identifier.

**windowClass**

Type: **sz\_Or\_Ord**

A variable-length array of 16-bit elements that specifies the window class of the control. If the first element of this array is any value other than 0xFFFF, the system treats the array as a null-terminated Unicode string that specifies the name of a registered window class.

If the first element is 0xFFFF, the array has one additional element that specifies the ordinal value of a predefined system class. The ordinal can be one of the following atom values.

| Value | Meaning |
|-----------------------------------------------------------------------------------|-----------------------|
| 0x0080 | Button<br> |
| 0x0081 | Edit<br> |
| 0x0082 | Static<br> |
| 0x0083 | List box<br> |
| 0x0084 | Scroll bar<br> |
| 0x0085 | Combo box<br> |

**title**

Type: **sz\_Or\_Ord**

A variable-length array of 16-bit elements that contains the initial text or resource identifier of the control. If the first element of this array is 0xFFFF, the array has one additional element that specifies the ordinal value of a resource, such as an icon, in an executable file. You can use a resource identifier for controls, such as static icon controls, that load and display an icon or other resource rather than text. If the first element is any value other than 0xFFFF, the system treats the array as a null-terminated Unicode string that specifies the initial text.

**extraCount**

Type: **WORD**

The number of bytes of creation data that follow this member. If this value is greater than zero, the creation data begins at the next **WORD** boundary. This creation data can be of any size and format. The control's window procedure must be able to interpret the data. When the system creates the control, it passes a pointer to this data in the *lParam* parameter of the [**WM\_CREATE**](https://learn.microsoft.com/windows/desktop/winmsg/wm-create) message that it sends to the control.

## Remarks

An extended template for a dialog box consists of a [**DLGTEMPLATEEX**](https://learn.microsoft.com/windows/win32/dlgbox/dlgtemplateex) header followed by a **DLGITEMTEMPLATEEX** structure for each control in the dialog box.

Each **DLGITEMTEMPLATEEX** structure must be aligned on a **DWORD** boundary. The variable-length **windowClass** and **title** arrays must be aligned on **WORD** boundaries. The creation data array, if any, must be aligned on a **WORD** boundary.

If you specify character strings in the **windowClass** and **title** arrays, you must use Unicode strings. Use the [**MultiByteToWideChar**](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) function to generate Unicode strings from ANSI strings.

The **x**, **y**, **cx**, and **cy** members specify values in dialog box units. You can convert these values to screen units (pixels) by using the [**MapDialogRect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-mapdialogrect) function.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**CreateDialogIndirect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-createdialogindirecta)

[**CreateDialogIndirectParam**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-createdialogindirectparama)

[**CreateWindowEx**](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

[**DialogBoxIndirect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-dialogboxindirecta)

[**DialogBoxIndirectParam**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-dialogboxindirectparama)

[**DLGTEMPLATEEX**](https://learn.microsoft.com/windows/win32/dlgbox/dlgtemplateex)

[**MapDialogRect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-mapdialogrect)

[**WM\_CREATE**](https://learn.microsoft.com/windows/desktop/winmsg/wm-create)

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/win32/dlgbox/dialog-boxes)

**Other Resources**

[**MultiByteToWideChar**](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)

[**WM\_HELP**](https://learn.microsoft.com/windows/win32/shell/wm-help)

