# CHOOSECOLORW structure

## Description

Contains information the [ChooseColor](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646912(v=vs.85)) function uses to initialize the **Color** dialog box. After the user closes the dialog box, the system returns information about the user's selection in this structure.

## Members

### `lStructSize`

Type: **DWORD**

The length, in bytes, of the structure.

### `hwndOwner`

Type: **HWND**

A handle to the window that owns the dialog box. This member can be any valid window handle, or it can be **NULL** if the dialog box has no owner.

### `hInstance`

Type: **HWND**

If the **CC_ENABLETEMPLATEHANDLE** flag is set in the **Flags** member, **hInstance** is a handle to a memory object containing a dialog box template. If the **CC_ENABLETEMPLATE** flag is set, **hInstance** is a handle to a module that contains a dialog box template named by the **lpTemplateName** member. If neither **CC_ENABLETEMPLATEHANDLE** nor **CC_ENABLETEMPLATE** is set, this member is ignored.

### `rgbResult`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

If the **CC_RGBINIT** flag is set, **rgbResult** specifies the color initially selected when the dialog box is created. If the specified color value is not among the available colors, the system selects the nearest solid color available. If **rgbResult** is zero or **CC_RGBINIT** is not set, the initially selected color is black. If the user clicks the **OK** button, **rgbResult** specifies the user's color selection. To create a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) color value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `lpCustColors`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)***

A pointer to an array of 16 values that contain red, green, blue (RGB) values for the custom color boxes in the dialog box. If the user modifies these colors, the system updates the array with the new RGB values. To preserve new custom colors between calls to the [ChooseColor](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646912(v=vs.85)) function, you should allocate static memory for the array. To create a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) color value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `Flags`

Type: **DWORD**

A set of bit flags that you can use to initialize the **Color** dialog box. When the dialog box returns, it sets these flags to indicate the user's input. This member can be a combination of the following flags.

| Value | Meaning |
| --- | --- |
| **CC_ANYCOLOR**<br><br>0x00000100 | Causes the dialog box to display all available colors in the set of basic colors. |
| **CC_ENABLEHOOK**<br><br>0x00000010 | Enables the hook procedure specified in the **lpfnHook** member of this structure. This flag is used only to initialize the dialog box. |
| **CC_ENABLETEMPLATE**<br><br>0x00000020 | The **hInstance** and **lpTemplateName** members specify a dialog box template to use in place of the default template. This flag is used only to initialize the dialog box. |
| **CC_ENABLETEMPLATEHANDLE**<br><br>0x00000040 | The **hInstance** member identifies a data block that contains a preloaded dialog box template. The system ignores the **lpTemplateName** member if this flag is specified. This flag is used only to initialize the dialog box. |
| **CC_FULLOPEN**<br><br>0x00000002 | Causes the dialog box to display the additional controls that allow the user to create custom colors. If this flag is not set, the user must click the **Define Custom Color** button to display the custom color controls. |
| **CC_PREVENTFULLOPEN**<br><br>0x00000004 | Disables the **Define Custom Color** button. |
| **CC_RGBINIT**<br><br>0x00000001 | Causes the dialog box to use the color specified in the **rgbResult** member as the initial color selection. |
| **CC_SHOWHELP**<br><br>0x00000008 | Causes the dialog box to display the Help button. The **hwndOwner** member must specify the window to receive the [HELPMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/helpmsgstring) registered messages that the dialog box sends when the user clicks the **Help** button. |
| **CC_SOLIDCOLOR**<br><br>0x00000080 | Causes the dialog box to display only solid colors in the set of basic colors. |

### `lCustData`

Type: **LPARAM**

Application-defined data that the system passes to the hook procedure identified by the **lpfnHook** member. When the system sends the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message to the hook procedure, the message's *lParam* parameter is a pointer to the **CHOOSECOLOR** structure specified when the dialog was created. The hook procedure can use this pointer to get the **lCustData** value.

### `lpfnHook`

Type: **LPCCHOOKPROC**

A pointer to a [CCHookProc](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lpcchookproc) hook procedure that can process messages intended for the dialog box. This member is ignored unless the **CC_ENABLEHOOK** flag is set in the **Flags** member.

### `lpTemplateName`

Type: **LPCTSTR**

The name of the dialog box template resource in the module identified by the **hInstance** member. This template is substituted for the standard dialog box template. For numbered dialog box resources, **lpTemplateName** can be a value returned by the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. This member is ignored unless the **CC_ENABLETEMPLATE** flag is set in the **Flags** member.

### `lpEditInfo`

## Remarks

## See also

[CCHookProc](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lpcchookproc)

[ChooseColor](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646912(v=vs.85))

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

**Reference**