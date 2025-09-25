# PAGESETUPDLGA structure

## Description

Contains information the [PageSetupDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646937(v=vs.85)) function uses to initialize the **Page Setup** dialog box. After the user closes the dialog box, the system returns information about the user-defined page parameters in this structure.

## Members

### `lStructSize`

Type: **DWORD**

The size, in bytes, of this structure.

### `hwndOwner`

Type: **HWND**

A handle to the window that owns the dialog box. This member can be any valid window handle, or it can be **NULL** if the dialog box has no owner.

### `hDevMode`

Type: **HGLOBAL**

A handle to a global memory object that contains a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure. On input, if a handle is specified, the values in the corresponding **DEVMODE** structure are used to initialize the controls in the dialog box. On output, the dialog box sets **hDevMode** to a global memory handle to a **DEVMODE** structure that contains values specifying the user's selections. If the user's selections are not available, the dialog box sets **hDevMode** to **NULL**.

### `hDevNames`

Type: **HGLOBAL**

A handle to a global memory object that contains a [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structure. This structure contains three strings that specify the driver name, the printer name, and the output port name. On input, if a handle is specified, the strings in the corresponding **DEVNAMES** structure are used to initialize controls in the dialog box. On output, the dialog box sets
**hDevNames** to a global memory handle to a **DEVNAMES** structure that contains strings specifying the user's selections. If the user's selections are not available, the dialog box sets **hDevNames** to **NULL**.

### `Flags`

Type: **DWORD**

A set of bit flags that you can use to initialize the **Page Setup** dialog box. When the dialog box returns, it sets these flags to indicate the user's input. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **PSD_DEFAULTMINMARGINS**<br><br>0x00000000 | Sets the minimum values that the user can specify for the page margins to be the minimum margins allowed by the printer. This is the default. This flag is ignored if the **PSD_MARGINS** and **PSD_MINMARGINS** flags are also specified. |
| **PSD_DISABLEMARGINS**<br><br>0x00000010 | Disables the margin controls, preventing the user from setting the margins. |
| **PSD_DISABLEORIENTATION**<br><br>0x00000100 | Disables the orientation controls, preventing the user from setting the page orientation. |
| **PSD_DISABLEPAGEPAINTING**<br><br>0x00080000 | Prevents the dialog box from drawing the contents of the sample page. If you enable a [PagePaintHook](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lppagepainthook) hook procedure, you can still draw the contents of the sample page. |
| **PSD_DISABLEPAPER**<br><br>0x00000200 | Disables the paper controls, preventing the user from setting page parameters such as the paper size and source. |
| **PSD_DISABLEPRINTER**<br><br>0x00000020 | Obsolete.<br><br>**Windows XP/2000:** Disables the **Printer** button, preventing the user from invoking a dialog box that contains additional printer setup information. |
| **PSD_ENABLEPAGEPAINTHOOK**<br><br>0x00040000 | Enables the hook procedure specified in the **lpfnPagePaintHook** member. |
| **PSD_ENABLEPAGESETUPHOOK**<br><br>0x00002000 | Enables the hook procedure specified in the **lpfnPageSetupHook** member. |
| **PSD_ENABLEPAGESETUPTEMPLATE**<br><br>0x00008000 | Indicates that the **hInstance** and **lpPageSetupTemplateName** members specify a dialog box template to use in place of the default template. |
| **PSD_ENABLEPAGESETUPTEMPLATEHANDLE**<br><br>0x00020000 | Indicates that the **hPageSetupTemplate** member identifies a data block that contains a preloaded dialog box template. The system ignores the **lpPageSetupTemplateName** member if this flag is specified. |
| **PSD_INHUNDREDTHSOFMILLIMETERS**<br><br>0x00000008 | Indicates that hundredths of millimeters are the unit of measurement for margins and paper size. The values in the **rtMargin**, **rtMinMargin**, and **ptPaperSize** members are in hundredths of millimeters. You can set this flag on input to override the default unit of measurement for the user's locale. When the function returns, the dialog box sets this flag to indicate the units used. |
| **PSD_INTHOUSANDTHSOFINCHES**<br><br>0x00000004 | Indicates that thousandths of inches are the unit of measurement for margins and paper size. The values in the **rtMargin**, **rtMinMargin**, and **ptPaperSize** members are in thousandths of inches. You can set this flag on input to override the default unit of measurement for the user's locale. When the function returns, the dialog box sets this flag to indicate the units used. |
| **PSD_INWININIINTLMEASURE**<br><br>0x00000000 | Reserved. |
| **PSD_MARGINS**<br><br>0x00000002 | Causes the system to use the values specified in the **rtMargin** member as the initial widths for the left, top, right, and bottom margins. If **PSD_MARGINS** is not set, the system sets the initial widths to one inch for all margins. |
| **PSD_MINMARGINS**<br><br>0x00000001 | Causes the system to use the values specified in the **rtMinMargin** member as the minimum allowable widths for the left, top, right, and bottom margins. The system prevents the user from entering a width that is less than the specified minimum. If **PSD_MINMARGINS** is not specified, the system sets the minimum allowable widths to those allowed by the printer. |
| **PSD_NONETWORKBUTTON**<br><br>0x00200000 | Hides and disables the **Network** button. |
| **PSD_NOWARNING**<br><br>0x00000080 | Prevents the system from displaying a warning message when there is no default printer. |
| **PSD_RETURNDEFAULT**<br><br>0x00000400 | [PageSetupDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646937(v=vs.85)) does not display the dialog box. Instead, it sets the **hDevNames** and **hDevMode** members to handles to [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) and [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structures that are initialized for the system default printer. **PageSetupDlg** returns an error if either **hDevNames** or **hDevMode** is not **NULL**. |
| **PSD_SHOWHELP**<br><br>0x00000800 | Causes the dialog box to display the **Help** button. The **hwndOwner** member must specify the window to receive the [HELPMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/helpmsgstring) registered messages that the dialog box sends when the user clicks the **Help** button. |

### `ptPaperSize`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The dimensions of the paper selected by the user. The **PSD_INTHOUSANDTHSOFINCHES** or **PSD_INHUNDREDTHSOFMILLIMETERS** flag indicates the units of measurement.

### `rtMinMargin`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The minimum allowable widths for the left, top, right, and bottom margins. The system ignores this member if the **PSD_MINMARGINS** flag is not set. These values must be less than or equal to the values specified in the **rtMargin** member. The **PSD_INTHOUSANDTHSOFINCHES** or **PSD_INHUNDREDTHSOFMILLIMETERS** flag indicates the units of measurement.

### `rtMargin`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

The widths of the left, top, right, and bottom margins. If you set the **PSD_MARGINS** flag, **rtMargin** specifies the initial margin values. When [PageSetupDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646937(v=vs.85)) returns, **rtMargin** contains the margin widths selected by the user. The **PSD_INHUNDREDTHSOFMILLIMETERS** or **PSD_INTHOUSANDTHSOFINCHES** flag indicates the units of measurement.

### `hInstance`

Type: **HINSTANCE**

If the **PSD_ENABLEPAGESETUPTEMPLATE** flag is set in the **Flags** member, **hInstance** is a handle to the application or module instance that contains the dialog box template named by the **lpPageSetupTemplateName** member.

### `lCustData`

Type: **LPARAM**

Application-defined data that the system passes to the hook procedure identified by the **lpfnPageSetupHook** member. When the system sends the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message to the hook procedure, the message's *lParam* parameter is a pointer to the **PAGESETUPDLG** structure specified when the dialog was created. The hook procedure can use this pointer to get the **lCustData** value.

### `lpfnPageSetupHook`

Type: **LPPAGESETUPHOOK**

A pointer to a [PageSetupHook](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lppagesetuphook) hook procedure that can process messages intended for the dialog box. This member is ignored unless the **PSD_ENABLEPAGESETUPHOOK** flag is set in the **Flags** member.

### `lpfnPagePaintHook`

Type: **LPPAGEPAINTHOOK**

A pointer to a [PagePaintHook](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lppagepainthook) hook procedure that receives **WM_PSD_*** messages from the dialog box whenever the sample page is redrawn. By processing the messages, the hook procedure can customize the appearance of the sample page. This member is ignored unless the **PSD_ENABLEPAGEPAINTHOOK** flag is set in the **Flags** member.

### `lpPageSetupTemplateName`

Type: **LPCTSTR**

The name of the dialog box template resource in the module identified by the **hInstance** member. This template is substituted for the standard dialog box template. For numbered dialog box resources, **lpPageSetupTemplateName** can be a value returned by the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. This member is ignored unless the **PSD_ENABLEPAGESETUPTEMPLATE** flag is set in the **Flags** member.

### `hPageSetupTemplate`

Type: **HGLOBAL**

If the **PSD_ENABLEPAGESETUPTEMPLATEHANDLE** flag is set in the **Flags** member, **hPageSetupTemplate** is a handle to a memory object containing a dialog box template.

## Remarks

If the **PSD_INHUNDREDTHSOFMILLIMETERS** and **PSD_INTHOUSANDTHSOFINCHES** flags are not specified, the system queries the **LOCALE_IMEASURE** value of the default user locale to determine the unit of measure (either hundredths of millimeters or thousandths of inches) for the margin widths and paper size.

If both **hDevNames** and **hDevMode** have valid handles and the printer name specified by the
**wDeviceOffset** member of the [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structure is not the same as the name specified by the **dmDeviceName** member of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure, the system uses the name specified by **wDeviceOffset** by default.

> [!NOTE]
> The commdlg.h header defines PAGESETUPDLG as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

**Other Resources**

[PagePaintHook](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lppagepainthook)

[PageSetupDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646937(v=vs.85))

[PageSetupHook](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lppagesetuphook)

**Reference**

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)