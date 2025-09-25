# PRINTDLGA structure

## Description

Contains information that the [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function uses to initialize the [Print Dialog Box](https://learn.microsoft.com/windows/desktop/dlgbox/print-dialog-box). After the user closes the dialog box, the system uses this structure to return information about the user's selections.

## Members

### `lStructSize`

Type: **DWORD**

The structure size, in bytes.

### `hwndOwner`

Type: **HWND**

A handle to the window that owns the dialog box. This member can be any valid window handle, or it can be **NULL** if the dialog box has no owner.

### `hDevMode`

Type: **HGLOBAL**

A handle to a movable global memory object that contains a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure. If **hDevMode** is not **NULL** on input, you must allocate a movable block of memory for the **DEVMODE** structure and initialize its members. The [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function uses the input data to initialize the controls in the dialog box. When **PrintDlg** returns, the **DEVMODE** members indicate the user's input.

If **hDevMode** is **NULL** on input, [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) allocates memory for the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure, initializes its members to indicate the user's input, and returns a handle that identifies it.

If the device driver for the specified printer does not support extended device modes, **hDevMode** is **NULL** when [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) returns.

If the device name (specified by the **dmDeviceName** member of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure) does not appear in the [devices] section of WIN.INI, [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) returns an error.

For more information about the **hDevMode** and **hDevNames** members, see the Remarks section at the end of this topic.

### `hDevNames`

Type: **HGLOBAL**

A handle to a movable global memory object that contains a [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structure. If **hDevNames** is not **NULL** on input, you must allocate a movable block of memory for the **DEVNAMES** structure and initialize its members. The [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function uses the input data to initialize the controls in the dialog box. When **PrintDlg** returns, the **DEVNAMES** members contain information for the printer chosen by the user. You can use this information to create a device context or an information context.

The **hDevNames** member can be **NULL**, in which case, [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) allocates memory for the [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structure, initializes its members to indicate the user's input, and returns a handle that identifies it.

For more information about the **hDevMode** and **hDevNames** members, see the Remarks section at the end of this topic.

### `hDC`

Type: **HDC**

A handle to a device context or an information context, depending on whether the **Flags** member specifies the **PD_RETURNDC** or **PC_RETURNIC** flag. If neither flag is specified, the value of this member is undefined. If both flags are specified, **PD_RETURNDC** has priority.

### `Flags`

Type: **DWORD**

Initializes the **Print** dialog box. When the dialog box returns, it sets these flags to indicate the user's input. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **PD_ALLPAGES**<br><br>0x00000000 | The default flag that indicates that the **All** radio button is initially selected. This flag is used as a placeholder to indicate that the **PD_PAGENUMS** and **PD_SELECTION** flags are not specified. |
| **PD_COLLATE**<br><br>0x00000010 | If this flag is set, the **Collate** check box is selected. <br><br>If this flag is set when the [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function returns, the application must simulate collation of multiple copies. For more information, see the description of the **PD_USEDEVMODECOPIESANDCOLLATE** flag.<br><br>See **PD_NOPAGENUMS**. |
| **PD_DISABLEPRINTTOFILE**<br><br>0x00080000 | Disables the **Print to File** check box. |
| **PD_ENABLEPRINTHOOK**<br><br>0x00001000 | Enables the hook procedure specified in the **lpfnPrintHook** member. This enables the hook procedure for the **Print** dialog box. |
| **PD_ENABLEPRINTTEMPLATE**<br><br>0x00004000 | Indicates that the **hInstance** and **lpPrintTemplateName** members specify a replacement for the default **Print** dialog box template. |
| **PD_ENABLEPRINTTEMPLATEHANDLE**<br><br>0x00010000 | Indicates that the **hPrintTemplate** member identifies a data block that contains a preloaded dialog box template. This template replaces the default template for the **Print** dialog box. The system ignores the **lpPrintTemplateName** member if this flag is specified. |
| **PD_ENABLESETUPHOOK**<br><br>0x00002000 | Enables the hook procedure specified in the **lpfnSetupHook** member. This enables the hook procedure for the **Print Setup** dialog box. |
| **PD_ENABLESETUPTEMPLATE**<br><br>0x00008000 | Indicates that the **hInstance** and **lpSetupTemplateName** members specify a replacement for the default **Print Setup** dialog box template. |
| **PD_ENABLESETUPTEMPLATEHANDLE**<br><br>0x00020000 | Indicates that the **hSetupTemplate** member identifies a data block that contains a preloaded dialog box template. This template replaces the default template for the **Print Setup** dialog box. The system ignores the **lpSetupTemplateName** member if this flag is specified. |
| **PD_HIDEPRINTTOFILE**<br><br>0x00100000 | Hides the **Print to File** check box. |
| **PD_NONETWORKBUTTON**<br><br>0x00200000 | Hides and disables the **Network** button. |
| **PD_NOPAGENUMS**<br><br>0x00000008 | Disables the **Pages** radio button and the associated edit controls. Also, it causes the **Collate** check box to appear in the dialog. |
| **PD_NOSELECTION**<br><br>0x00000004 | Disables the **Selection** radio button. |
| **PD_NOWARNING**<br><br>0x00000080 | Prevents the warning message from being displayed when there is no default printer. |
| **PD_PAGENUMS**<br><br>0x00000002 | If this flag is set, the **Pages** radio button is selected. If this flag is set when the [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function returns, the **nFromPage** and **nToPage** members indicate the starting and ending pages specified by the user. |
| **PD_PRINTSETUP**<br><br>0x00000040 | Causes the system to display the **Print Setup** dialog box rather than the **Print** dialog box. |
| **PD_PRINTTOFILE**<br><br>0x00000020 | If this flag is set, the **Print to File** check box is selected. If this flag is set when the [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function returns, the offset indicated by the **wOutputOffset** member of the [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structure contains the string "FILE:". When you call the [StartDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startdoca) function to start the printing operation, specify this "FILE:" string in the **lpszOutput** member of the [DOCINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-docinfoa) structure. Specifying this string causes the print subsystem to query the user for the name of the output file. |
| **PD_RETURNDC**<br><br>0x00000100 | Causes [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) to return a device context matching the selections the user made in the dialog box. The device context is returned in **hDC**. |
| **PD_RETURNDEFAULT**<br><br>0x00000400 | If this flag is set, the [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function does not display the dialog box. Instead, it sets the **hDevNames** and **hDevMode** members to handles to [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) and [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structures that are initialized for the system default printer. Both **hDevNames** and **hDevMode** must be **NULL**, or **PrintDlg** returns an error. |
| **PD_RETURNIC**<br><br>0x00000200 | Similar to the **PD_RETURNDC** flag, except this flag returns an information context rather than a device context. If neither **PD_RETURNDC** nor **PD_RETURNIC** is specified, **hDC** is undefined on output. |
| **PD_SELECTION**<br><br>0x00000001 | If this flag is set, the **Selection** radio button is selected. If neither **PD_PAGENUMS** nor **PD_SELECTION** is set, the **All** radio button is selected. |
| **PD_SHOWHELP**<br><br>0x00000800 | Causes the dialog box to display the **Help** button. The **hwndOwner** member must specify the window to receive the [HELPMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/helpmsgstring) registered messages that the dialog box sends when the user clicks the **Help** button. |
| **PD_USEDEVMODECOPIES**<br><br>0x00040000 | Same as **PD_USEDEVMODECOPIESANDCOLLATE**. |
| **PD_USEDEVMODECOPIESANDCOLLATE**<br><br>0x00040000 | This flag indicates whether your application supports multiple copies and collation. Set this flag on input to indicate that your application does not support multiple copies and collation. In this case, the **nCopies** member of the **PRINTDLG** structure always returns 1, and **PD_COLLATE** is never set in the **Flags** member. <br><br>If this flag is not set, the application is responsible for printing and collating multiple copies. In this case, the **nCopies** member of the **PRINTDLG** structure indicates the number of copies the user wants to print, and the **PD_COLLATE** flag in the **Flags** member indicates whether the user wants collation. <br><br>Regardless of whether this flag is set, an application can determine from **nCopies** and **PD_COLLATE** how many copies to render and whether to print them collated.<br><br>If this flag is set and the printer driver does not support multiple copies, the **Copies** edit control is disabled. Similarly, if this flag is set and the printer driver does not support collation, the **Collate** check box is disabled.<br><br>The **dmCopies** and **dmCollate** members of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure contain the copies and collate information used by the printer driver. If this flag is set and the printer driver supports multiple copies, the **dmCopies** member indicates the number of copies requested by the user. If this flag is set and the printer driver supports collation, the **dmCollate** member of the **DEVMODE** structure indicates whether the user wants collation. If this flag is not set, the **dmCopies** member always returns 1, and the **dmCollate** member is always zero.<br><br>**Known issue on Windows 2000/XP/2003:** If this flag is not set before calling [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)), **PrintDlg** might swap **nCopies** and **dmCopies** values when it returns. The workaround for this issue is use **dmCopies** if its value is larger than 1, else, use **nCopies**, for you to get the actual number of copies to be printed when **PrintDlg** returns. |

To ensure that [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) or [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) returns the correct values in the **dmCopies** and **dmCollate** members of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure, set **PD_RETURNDC** = **TRUE** and **PD_USEDEVMODECOPIESANDCOLLATE** = **TRUE**. In so doing, the **nCopies** member of the **PRINTDLG** structure is always 1 and **PD_COLLATE** is always **FALSE**.

To ensure that [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) or [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) returns the correct values in **nCopies** and **PD_COLLATE**, set **PD_RETURNDC** = **TRUE** and **PD_USEDEVMODECOPIESANDCOLLATE** = **FALSE**. In so doing, **dmCopies** is always 1 and **dmCollate** is always **FALSE**.

On Windows Vista and Windows 7, when you call [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) or [PrintDlgEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646942(v=vs.85)) with **PD_RETURNDC** set to **TRUE** and **PD_USEDEVMODECOPIESANDCOLLATE** set to **FALSE**, the **PrintDlg** or **PrintDlgEx** function sets the number of copies in the **nCopies** member of the **PRINTDLG** structure, and it sets the number of copies in the structure represented by the hDC member of the **PRINTDLG** structure.

When making calls to GDI, you must ignore the value of **nCopies**, consider the value as 1, and use the returned hDC to avoid printing duplicate copies.

### `nFromPage`

Type: **WORD**

The initial value for the starting page edit control.

When [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) returns, **nFromPage** is the starting page specified by the user. If the **Pages** radio button is selected when the user clicks the **Okay** button, **PrintDlg** sets the **PD_PAGENUMS** flag and does not return until the user enters a starting page value that is within the minimum to maximum page range.

 If the input value for either **nFromPage** or **nToPage** is outside the minimum/maximum range, [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) returns an error only if the **PD_PAGENUMS** flag is specified; otherwise, it displays the dialog box but changes the out-of-range value to the minimum or maximum value.

### `nToPage`

Type: **WORD**

The initial value for the ending page edit control. When [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) returns, **nToPage** is the ending page specified by the user. If the **Pages** radio button is selected when the use clicks the **Okay** button, **PrintDlg** sets the **PD_PAGENUMS** flag and does not return until the user enters an ending page value that is within the minimum to maximum page range.

### `nMinPage`

Type: **WORD**

The minimum value for the page range specified in the **From** and **To** page edit controls. If **nMinPage** equals **nMaxPage**, the **Pages** radio button and the starting and ending page edit controls are disabled.

### `nMaxPage`

Type: **WORD**

The maximum value for the page range specified in the **From** and **To** page edit controls.

### `nCopies`

Type: **WORD**

The initial number of copies for the **Copies** edit control if **hDevMode** is **NULL**; otherwise, the **dmCopies** member of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure contains the initial value. When [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) returns, **nCopies** contains the actual number of copies to print. This value depends on whether the application or the printer driver is responsible for printing multiple copies. If the **PD_USEDEVMODECOPIESANDCOLLATE** flag is set in the **Flags** member, **nCopies** is always 1 on return, and the printer driver is responsible for printing multiple copies. If the flag is not set, the application is responsible for printing the number of copies specified by **nCopies**. For more information, see the description of the **PD_USEDEVMODECOPIESANDCOLLATE** flag.

### `hInstance`

Type: **HINSTANCE**

If the **PD_ENABLEPRINTTEMPLATE** or **PD_ENABLESETUPTEMPLATE** flag is set in the **Flags** member, **hInstance** is a handle to the application or module instance that contains the dialog box template named by the **lpPrintTemplateName** or **lpSetupTemplateName** member.

### `lCustData`

Type: **LPARAM**

Application-defined data that the system passes to the hook procedure identified by the **lpfnPrintHook** or **lpfnSetupHook** member. When the system sends the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message to the hook procedure, the message's *lParam* parameter is a pointer to the **PRINTDLG** structure specified when the dialog was created. The hook procedure can use this pointer to get the **lCustData** value.

### `lpfnPrintHook`

Type: **LPPRINTHOOKPROC**

A pointer to a [PrintHookProc](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lpprinthookproc) hook procedure that can process messages intended for the **Print** dialog box. This member is ignored unless the **PD_ENABLEPRINTHOOK** flag is set in the **Flags** member.

### `lpfnSetupHook`

Type: **LPSETUPHOOKPROC**

A pointer to a [SetupHookProc](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lpsetuphookproc) hook procedure that can process messages intended for the **Print Setup** dialog box. This member is ignored unless the **PD_ENABLESETUPHOOK** flag is set in the **Flags** member.

### `lpPrintTemplateName`

Type: **LPCTSTR**

The name of the dialog box template resource in the module identified by the **hInstance** member. This template replaces the default **Print** dialog box template. This member is ignored unless the **PD_ENABLEPRINTTEMPLATE** flag is set in the **Flags** member.

### `lpSetupTemplateName`

Type: **LPCTSTR**

The name of the dialog box template resource in the module identified by the **hInstance** member. This template replaces the default **Print Setup** dialog box template. This member is ignored unless the **PD_ENABLESETUPTEMPLATE** flag is set in the **Flags** member.

### `hPrintTemplate`

Type: **HGLOBAL**

If the **PD_ENABLEPRINTTEMPLATEHANDLE** flag is set in the **Flags** member, **hPrintTemplate** is a handle to a memory object containing a dialog box template. This template replaces the default **Print** dialog box template.

### `hSetupTemplate`

Type: **HGLOBAL**

If the **PD_ENABLESETUPTEMPLATEHANDLE** flag is set in the **Flags** member, **hSetupTemplate** is a handle to a memory object containing a dialog box template. This template replaces the default **Print Setup** dialog box template.

## Remarks

If both
**hDevMode** and **hDevNames** are **NULL**, [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) initializes the dialog box using the current default printer. To initialize the dialog box for a different printer, use the **wDeviceOffset** member of the [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structure to specify the name of the printer.

Note that the **dmDeviceName** member of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure also specifies a printer name. However, **dmDeviceName** is limited to 32 characters, and the **wDeviceOffset** name is not. If the **wDeviceOffset** and **dmDeviceName** names are not the same, [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) initializes the dialog box using the printer specified by **wDeviceOffset**.

If the **PD_RETURNDEFAULT** flag is set and both **hDevMode** and **hDevNames** are **NULL**, [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) uses the **hDevNames** and **hDevMode** members to return information about the current default printer without displaying the dialog box.

> [!NOTE]
> The commdlg.h header defines PRINTDLG as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames)

[PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85))

**Reference**

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)