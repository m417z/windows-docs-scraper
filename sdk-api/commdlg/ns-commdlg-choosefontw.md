# CHOOSEFONTW structure

## Description

Contains information that the [ChooseFont](https://docs.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) function uses to initialize the **Font** dialog box. After the user closes the dialog box, the system returns information about the user's selection in this structure.

## Members

### `lStructSize`

Type: **DWORD**

The length of the structure, in bytes.

### `hwndOwner`

Type: **HWND**

A handle to the window that owns the dialog box. This member can be any valid window handle, or it can be **NULL** if the dialog box has no owner.

### `hDC`

Type: **HDC**

This member is ignored by the [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) function.

**Windows Vista and Windows XP/2000:** A handle to the device context or information context of the printer whose fonts will be listed in the dialog box. This member is used only if the **Flags** member specifies the **CF_PRINTERFONTS** or **CF_BOTH** flag; otherwise, this member is ignored.

### `lpLogFont`

Type: **LPLOGFONT**

A pointer to a [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure. If you set the **CF_INITTOLOGFONTSTRUCT** flag in the **Flags** member and initialize the other members, the [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) function initializes the dialog box with a font that matches the **LOGFONT** members. If the user clicks the **OK** button, **ChooseFont** sets the members of the **LOGFONT** structure based on the user's selections.

### `iPointSize`

Type: **INT**

The size of the selected font, in units of 1/10 of a point. The [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) function sets this value after the user closes the dialog box.

### `Flags`

Type: **DWORD**

A set of bit flags that you can use to initialize the **Font** dialog box. When the dialog box returns, it sets these flags to indicate the user input. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **CF_APPLY**<br><br>0x00000200L | Causes the dialog box to display the **Apply** button. You should provide a hook procedure to process [WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) messages for the **Apply** button. The hook procedure can send the [WM_CHOOSEFONT_GETLOGFONT](https://learn.microsoft.com/windows/desktop/dlgbox/wm-choosefont-getlogfont) message to the dialog box to retrieve the address of the structure that contains the current selections for the font. |
| **CF_ANSIONLY**<br><br>0x00000400L | This flag is obsolete. To limit font selections to all scripts except those that use the OEM or Symbol character sets, use **CF_SCRIPTSONLY**. To get the original **CF_ANSIONLY** behavior, use **CF_SELECTSCRIPT** and specify **ANSI_CHARSET** in the **lfCharSet** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure pointed to by **lpLogFont**. |
| **CF_BOTH**<br><br>0x00000003 | This flag is ignored for font enumeration.<br><br>**Windows Vista and Windows XP/2000:** Causes the dialog box to list the available printer and screen fonts. The **hDC** member is a handle to the device context or information context associated with the printer. This flag is a combination of the **CF_SCREENFONTS** and **CF_PRINTERFONTS** flags. |
| **CF_EFFECTS**<br><br>0x00000100L | Causes the dialog box to display the controls that allow the user to specify strikeout, underline, and text color options. If this flag is set, you can use the **rgbColors** member to specify the initial text color. You can use the **lfStrikeOut** and **lfUnderline** members of the structure pointed to by **lpLogFont** to specify the initial settings of the strikeout and underline check boxes. [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) can use these members to return the user's selections. |
| **CF_ENABLEHOOK**<br><br>0x00000008L | Enables the hook procedure specified in the **lpfnHook** member of this structure. |
| **CF_ENABLETEMPLATE**<br><br>0x00000010L | Indicates that the **hInstance** and **lpTemplateName** members specify a dialog box template to use in place of the default template. |
| **CF_ENABLETEMPLATEHANDLE**<br><br>0x00000020L | Indicates that the **hInstance** member identifies a data block that contains a preloaded dialog box template. The system ignores the **lpTemplateName** member if this flag is specified. |
| **CF_FIXEDPITCHONLY**<br><br>0x00004000L | [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) should enumerate and allow selection of only fixed-pitch fonts. |
| **CF_FORCEFONTEXIST**<br><br>0x00010000L | [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) should indicate an error condition if the user attempts to select a font or style that is not listed in the dialog box. |
| **CF_INACTIVEFONTS**<br><br>0x02000000L | [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) should additionally display fonts that are set to Hide in Fonts Control Panel.<br><br>**Windows Vista and Windows XP/2000:** This flag is not supported until Windows 7. |
| **CF_INITTOLOGFONTSTRUCT**<br><br>0x00000040L | [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) should use the structure pointed to by the **lpLogFont** member to initialize the dialog box controls. |
| **CF_LIMITSIZE**<br><br>0x00002000L | [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) should select only font sizes within the range specified by the **nSizeMin** and **nSizeMax** members. |
| **CF_NOOEMFONTS**<br><br>0x00000800L | Same as the **CF_NOVECTORFONTS** flag. |
| **CF_NOFACESEL**<br><br>0x00080000L | When using a [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure to initialize the dialog box controls, use this flag to prevent the dialog box from displaying an initial selection for the font name combo box. This is useful when there is no single font name that applies to the text selection. |
| **CF_NOSCRIPTSEL**<br><br>0x00800000L | Disables the **Script** combo box. When this flag is set, the **lfCharSet** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure is set to **DEFAULT_CHARSET** when [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) returns. This flag is used only to initialize the dialog box. |
| **CF_NOSIMULATIONS**<br><br>0x00001000L | [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) should not display or allow selection of font simulations. |
| **CF_NOSIZESEL**<br><br>0x00200000L | When using a structure to initialize the dialog box controls, use this flag to prevent the dialog box from displaying an initial selection for the **Font Size** combo box. This is useful when there is no single font size that applies to the text selection. |
| **CF_NOSTYLESEL**<br><br>0x00100000L | When using a [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure to initialize the dialog box controls, use this flag to prevent the dialog box from displaying an initial selection for the **Font Style** combo box. This is useful when there is no single font style that applies to the text selection. |
| **CF_NOVECTORFONTS**<br><br>0x00000800L | [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) should not allow vector font selections. |
| **CF_NOVERTFONTS**<br><br>0x01000000L | Causes the **Font** dialog box to list only horizontally oriented fonts. |
| **CF_PRINTERFONTS**<br><br>0x00000002 | This flag is ignored for font enumeration.<br><br>**Windows Vista and Windows XP/2000:** Causes the dialog box to list only the fonts supported by the printer associated with the device context or information context identified by the **hDC** member. It also causes the font type description label to appear at the bottom of the **Font** dialog box. |
| **CF_SCALABLEONLY**<br><br>0x00020000L | Specifies that [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) should allow only the selection of scalable fonts. Scalable fonts include vector fonts, scalable printer fonts, TrueType fonts, and fonts scaled by other technologies. |
| **CF_SCREENFONTS**<br><br>0x00000001 | This flag is ignored for font enumeration.<br><br>**Windows Vista and Windows XP/2000:** Causes the dialog box to list only the screen fonts supported by the system. |
| **CF_SCRIPTSONLY**<br><br>0x00000400L | [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) should allow selection of fonts for all non-OEM and Symbol character sets, as well as the ANSI character set. This supersedes the **CF_ANSIONLY** value. |
| **CF_SELECTSCRIPT**<br><br>0x00400000L | When specified on input, only fonts with the character set identified in the **lfCharSet** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure are displayed. The user will not be allowed to change the character set specified in the **Scripts** combo box. |
| **CF_SHOWHELP**<br><br>0x00000004L | Causes the dialog box to display the **Help** button. The **hwndOwner** member must specify the window to receive the [HELPMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/helpmsgstring) registered messages that the dialog box sends when the user clicks the **Help** button. |
| **CF_TTONLY**<br><br>0x00040000L | [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) should only enumerate and allow the selection of TrueType fonts. |
| **CF_USESTYLE**<br><br>0x00000080L | The **lpszStyle** member is a pointer to a buffer that contains style data that [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) should use to initialize the **Font Style** combo box. When the user closes the dialog box, **ChooseFont** copies style data for the user's selection to this buffer.<br><br>**Note** To globalize your application, you should specify the style by using the **lfWeight** and **lfItalic** members of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure pointed to by **lpLogFont**. The style name may change depending on the system user interface language. |
| **CF_WYSIWYG**<br><br>0x00008000L | Obsolete. [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) ignores this flag.<br><br>**Windows Vista and Windows XP/2000:** [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) should allow only the selection of fonts available on both the printer and the display. If this flag is specified, the **CF_SCREENSHOTS** and **CF_PRINTERFONTS**, or **CF_BOTH** flags should also be specified. |

### `rgbColors`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

If the **CF_EFFECTS** flag is set, **rgbColors** specifies the initial text color. When [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) returns successfully, this member contains the RGB value of the text color that the user selected. To create a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) color value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `lCustData`

Type: **LPARAM**

Application-defined data that the system passes to the hook procedure identified by the **lpfnHook** member. When the system sends the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message to the hook procedure, the message's *lParam* parameter is a pointer to the [CHOOSEFONT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) structure specified when the dialog was created. The hook procedure can use this pointer to get the **lCustData** value.

### `lpfnHook`

Type: **LPCFHOOKPROC**

A pointer to a [CFHookProc](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lpcfhookproc) hook procedure that can process messages intended for the dialog box. This member is ignored unless the **CF_ENABLEHOOK** flag is set in the **Flags** member.

### `lpTemplateName`

Type: **LPCTSTR**

The name of the dialog box template resource in the module identified by the **hInstance** member. This template is substituted for the standard dialog box template. For numbered dialog box resources, **lpTemplateName** can be a value returned by the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. This member is ignored unless the **CF_ENABLETEMPLATE** flag is set in the **Flags** member.

### `hInstance`

Type: **HINSTANCE**

If the **CF_ENABLETEMPLATEHANDLE** flag is set in the **Flags** member, **hInstance** is a handle to a memory object containing a dialog box template. If the **CF_ENABLETEMPLATE** flag is set, **hInstance** is a handle to a module that contains a dialog box template named by the **lpTemplateName** member. If neither **CF_ENABLETEMPLATEHANDLE** nor **CF_ENABLETEMPLATE** is set, this member is ignored.

### `lpszStyle`

Type: **LPTSTR**

The style data. If the **CF_USESTYLE** flag is specified, [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) uses the data in this buffer to initialize the **Font Style** combo box. When the user closes the dialog box, **ChooseFont** copies the string in the **Font Style** combo box into this buffer.

### `nFontType`

Type: **WORD**

The type of the selected font when [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) returns. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **BOLD_FONTTYPE**<br><br>0x0100 | The font weight is bold. This information is duplicated in the **lfWeight** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure and is equivalent to **FW_BOLD**. |
| **ITALIC_FONTTYPE**<br><br>0x0200 | The italic font attribute is set. This information is duplicated in the **lfItalic** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure. |
| **PRINTER_FONTTYPE**<br><br>0x4000 | The font is a printer font. |
| **REGULAR_FONTTYPE**<br><br>0x0400 | The font weight is normal. This information is duplicated in the **lfWeight** member of the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure and is equivalent to **FW_REGULAR**. |
| **SCREEN_FONTTYPE**<br><br>0x2000 | The font is a screen font. |
| **SIMULATED_FONTTYPE**<br><br>0x8000 | The font is simulated by the graphics device interface (GDI). |

### `nSizeMin`

Type: **INT**

The minimum point size a user can select. [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) recognizes this member only if the **CF_LIMITSIZE** flag is specified.

### `nSizeMax`

Type: **INT**

The maximum point size a user can select. [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) recognizes this member only if the **CF_LIMITSIZE** flag is specified.

## See also

[ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85))

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

**Reference**

## Remarks

> [!NOTE]
> The commdlg.h header defines CHOOSEFONT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).