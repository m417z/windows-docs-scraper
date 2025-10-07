# DLGTEMPLATEEX structure

An extended dialog box template begins with a **DLGTEMPLATEEX** header that describes the dialog box and specifies the number of controls in the dialog box. For each control in a dialog box, an extended dialog box template has a block of data that uses the [**DLGITEMTEMPLATEEX**](https://learn.microsoft.com/windows/win32/dlgbox/dlgitemtemplateex) format to describe the control.

The **DLGTEMPLATEEX** structure is not defined in any standard header file. The structure definition is provided here to explain the format of an extended template for a dialog box.

## Members

**dlgVer**

Type: **WORD**

The version number of the extended dialog box template. This member must be set to 1.

**signature**

Type: **WORD**

Indicates whether a template is an extended dialog box template. If **signature** is 0xFFFF, this is an extended dialog box template. In this case, the **dlgVer** member specifies the template version number. If **signature** is any value other than 0xFFFF, this is a standard dialog box template that uses the [**DLGTEMPLATE**](https://learn.microsoft.com/windows/desktop/api/Winuser/ns-winuser-dlgtemplate) and [**DLGITEMTEMPLATE**](https://learn.microsoft.com/windows/desktop/api/Winuser/ns-winuser-dlgitemtemplate) structures.

**helpID**

Type: **DWORD**

The help context identifier for the dialog box window. When the system sends a [**WM\_HELP**](https://learn.microsoft.com/windows/win32/shell/wm-help) message, it passes this value in the **wContextId** member of the [**HELPINFO**](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-helpinfo) structure.

**exStyle**

Type: **DWORD**

The extended windows styles. This member is not used when creating dialog boxes, but applications that use dialog box templates can use it to create other types of windows. For a list of values, see [**Extended Window Styles**](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles).

**style**

Type: **DWORD**

The style of the dialog box. This member can be a combination of [window style values](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) and [dialog box style values](https://learn.microsoft.com/windows/win32/dlgbox/dialog-box-styles).

If **style** includes the **DS\_SETFONT** or **DS\_SHELLFONT** dialog box style, the **DLGTEMPLATEEX** header of the extended dialog box template contains four additional members ( **pointsize**, **weight**, **italic**, and **typeface**) that describe the font to use for the text in the client area and controls of the dialog box. If possible, the system creates a font according to the values specified in these members. Then the system sends a [**WM\_SETFONT**](https://learn.microsoft.com/windows/desktop/winmsg/wm-setfont) message to the dialog box and to each control to provide a handle to the font.

For more information, see [Dialog Box Fonts](https://learn.microsoft.com/windows/win32/dlgbox/about-dialog-boxes).

**cDlgItems**

Type: **WORD**

The number of controls in the dialog box.

**x**

Type: **short**

The x-coordinate, in dialog box units, of the upper-left corner of the dialog box.

**y**

Type: **short**

The y-coordinate, in dialog box units, of the upper-left corner of the dialog box.

**cx**

Type: **short**

The width, in dialog box units, of the dialog box.

**cy**

Type: **short**

The height, in dialog box units, of the dialog box.

**menu**

Type: **sz\_Or\_Ord**

A variable-length array of 16-bit elements that identifies a menu resource for the dialog box. If the first element of this array is 0x0000, the dialog box has no menu and the array has no other elements. If the first element is 0xFFFF, the array has one additional element that specifies the ordinal value of a menu resource in an executable file. If the first element has any other value, the system treats the array as a null-terminated Unicode string that specifies the name of a menu resource in an executable file.

**windowClass**

Type: **sz\_Or\_Ord**

A variable-length array of 16-bit elements that identifies the window class of the dialog box. If the first element of the array is 0x0000, the system uses the predefined dialog box class for the dialog box and the array has no other elements. If the first element is 0xFFFF, the array has one additional element that specifies the ordinal value of a predefined system window class. If the first element has any other value, the system treats the array as a null-terminated Unicode string that specifies the name of a registered window class.

**title**

Type: **WCHAR\[titleLen\]**

The title of the dialog box. If the first element of this array is 0x0000, the dialog box has no title and the array has no other elements.

**pointsize**

Type: **WORD**

The point size of the font to use for the text in the dialog box and its controls.

This member is present only if the **style** member specifies **DS\_SETFONT** or **DS\_SHELLFONT**.

**weight**

Type: **WORD**

The weight of the font. Note that, although this can be any of the values listed for the **lfWeight** member of the [**LOGFONT**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-logfonta) structure, any value that is used will be automatically changed to **FW\_NORMAL**.

This member is present only if the **style** member specifies **DS\_SETFONT** or **DS\_SHELLFONT**.

**italic**

Type: **BYTE**

Indicates whether the font is italic. If this value is **TRUE**, the font is italic.

This member is present only if the **style** member specifies **DS\_SETFONT** or **DS\_SHELLFONT**.

**charset**

Type: **BYTE**

The character set to be used. For more information, see the **lfcharset** member of [**LOGFONT**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-logfonta).

This member is present only if the **style** member specifies **DS\_SETFONT** or **DS\_SHELLFONT**.

**typeface**

Type: **WCHAR\[stringLen\]**

The name of the typeface for the font.

This member is present only if the **style** member specifies **DS\_SETFONT** or **DS\_SHELLFONT**.

## Remarks

You can use an extended dialog box template instead of a standard dialog box template in the [**CreateDialogIndirectParam**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-createdialogindirectparama), [**DialogBoxIndirectParam**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-dialogboxindirectparama), [**CreateDialogIndirect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-createdialogindirecta), and [**DialogBoxIndirect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-dialogboxindirecta) functions.

Following the **DLGTEMPLATEEX** header in an extended dialog box template is one or more [**DLGITEMTEMPLATEEX**](https://learn.microsoft.com/windows/win32/dlgbox/dlgitemtemplateex) structures that describe the controls of the dialog box. The **cDlgItems** member of the **DLGITEMTEMPLATEEX** structure specifies the number of **DLGITEMTEMPLATEEX** structures that follow in the template.

Each [**DLGITEMTEMPLATEEX**](https://learn.microsoft.com/windows/win32/dlgbox/dlgitemtemplateex) structure in the template must be aligned on a **DWORD** boundary. If the **style** member specifies the **DS\_SETFONT** or **DS\_SHELLFONT** style, the first **DLGITEMTEMPLATEEX** structure begins on the first **DWORD** boundary after the **typeface** string. If these styles are not specified, the first structure begins on the first **DWORD** boundary after the **title** string.

The **menu**, **windowClass**, **title**, and **typeface** arrays must be aligned on **WORD** boundaries.

If you specify character strings in the **menu**, **windowClass**, **title**, and **typeface** arrays, you must use Unicode strings. Use the [**MultiByteToWideChar**](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) function to generate these Unicode strings from ANSI strings.

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

[**DialogBoxIndirect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-dialogboxindirecta)

[**DialogBoxIndirectParam**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-dialogboxindirectparama)

[**DLGITEMTEMPLATEEX**](https://learn.microsoft.com/windows/win32/dlgbox/dlgitemtemplateex)

[**MapDialogRect**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-mapdialogrect)

[**WM\_SETFONT**](https://learn.microsoft.com/windows/desktop/winmsg/wm-setfont)

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/win32/dlgbox/dialog-boxes)

**Other Resources**

[**LOGFONT**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-logfonta)

[**MultiByteToWideChar**](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar)

