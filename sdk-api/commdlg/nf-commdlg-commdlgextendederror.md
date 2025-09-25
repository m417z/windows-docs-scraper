# CommDlgExtendedError function

## Description

Returns a common dialog box error code. This code indicates the most recent error to occur during the execution of one of the common dialog box functions.

## Return value

Type: **DWORD**

If the most recent call to a common dialog box function succeeded, the return value is undefined. If the common dialog box function returned **FALSE** because the user closed or canceled the dialog box, the return value is zero. Otherwise, the return value is a nonzero error code.

The **CommDlgExtendedError** function can return general error codes for any of the common dialog box functions. In addition, there are error codes that are returned only for a specific common dialog box. All of these error codes are defined in Cderr.h. The following general error codes can be returned for any of the common dialog box functions.

| Return code/value | Description |
| --- | --- |
| **CDERR_DIALOGFAILURE**<br><br>0xFFFF | The dialog box could not be created. The common dialog box function's call to the [DialogBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxa) function failed. For example, this error occurs if the common dialog box call specifies an invalid window handle. |
| **CDERR_FINDRESFAILURE**<br><br>0x0006 | The common dialog box function failed to find a specified resource. |
| **CDERR_INITIALIZATION**<br><br>0x0002 | The common dialog box function failed during initialization. This error often occurs when sufficient memory is not available. |
| **CDERR_LOADRESFAILURE**<br><br>0x0007 | The common dialog box function failed to load a specified resource. |
| **CDERR_LOADSTRFAILURE**<br><br>0x0005 | The common dialog box function failed to load a specified string. |
| **CDERR_LOCKRESFAILURE**<br><br>0x0008 | The common dialog box function failed to lock a specified resource. |
| **CDERR_MEMALLOCFAILURE**<br><br>0x0009 | The common dialog box function was unable to allocate memory for internal structures. |
| **CDERR_MEMLOCKFAILURE**<br><br>0x000A | The common dialog box function was unable to lock the memory associated with a handle. |
| **CDERR_NOHINSTANCE**<br><br>0x0004 | The **ENABLETEMPLATE** flag was set in the **Flags** member of the initialization structure for the corresponding common dialog box, but you failed to provide a corresponding instance handle. |
| **CDERR_NOHOOK**<br><br>0x000B | The **ENABLEHOOK** flag was set in the **Flags** member of the initialization structure for the corresponding common dialog box, but you failed to provide a pointer to a corresponding hook procedure. |
| **CDERR_NOTEMPLATE**<br><br>0x0003 | The **ENABLETEMPLATE** flag was set in the **Flags** member of the initialization structure for the corresponding common dialog box, but you failed to provide a corresponding template. |
| **CDERR_REGISTERMSGFAIL**<br><br>0x000C | The [RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea) function returned an error code when it was called by the common dialog box function. |
| **CDERR_STRUCTSIZE**<br><br>0x0001 | The **lStructSize** member of the initialization structure for the corresponding common dialog box is invalid. |

The following error codes can be returned for the [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function.

| Return code/value | Description |
| --- | --- |
| **PDERR_CREATEICFAILURE**<br><br>0x100A | The [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function failed when it attempted to create an information context. |
| **PDERR_DEFAULTDIFFERENT**<br><br>0x100C | You called the [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function with the **DN_DEFAULTPRN** flag specified in the **wDefault** member of the [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structure, but the printer described by the other structure members did not match the current default printer. This error occurs when you store the **DEVNAMES** structure, and the user changes the default printer by using the Control Panel.<br><br>To use the printer described by the [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structure, clear the **DN_DEFAULTPRN** flag and call [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) again.<br><br>To use the default printer, replace the [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structure (and the structure, if one exists) with **NULL**; and call [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) again. |
| **PDERR_DNDMMISMATCH**<br><br>0x1009 | The data in the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) and [DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames) structures describes two different printers. |
| **PDERR_GETDEVMODEFAIL**<br><br>0x1005 | The printer driver failed to initialize a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure. |
| **PDERR_INITFAILURE**<br><br>0x1006 | The [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function failed during initialization, and there is no more specific extended error code to describe the failure. This is the generic default error code for the function. |
| **PDERR_LOADDRVFAILURE**<br><br>0x1004 | The [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function failed to load the device driver for the specified printer. |
| **PDERR_NODEFAULTPRN**<br><br>0x1008 | A default printer does not exist. |
| **PDERR_NODEVICES**<br><br>0x1007 | No printer drivers were found. |
| **PDERR_PARSEFAILURE**<br><br>0x1002 | The [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function failed to parse the strings in the [devices] section of the WIN.INI file. |
| **PDERR_PRINTERNOTFOUND**<br><br>0x100B | The [devices] section of the WIN.INI file did not contain an entry for the requested printer. |
| **PDERR_RETDEFFAILURE**<br><br>0x1003 | The PD_RETURNDEFAULT flag was specified in the **Flags** member of the [PRINTDLG](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-printdlga) structure, but the **hDevMode** or **hDevNames** member was not **NULL**. |
| **PDERR_SETUPFAILURE**<br><br>0x1001 | The [PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85)) function failed to load the required resources. |

The following error codes can be returned for the [ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85)) function.

| Return code/value | Description |
| --- | --- |
| **CFERR_MAXLESSTHANMIN**<br><br>0x2002 | The size specified in the **nSizeMax** member of the [CHOOSEFONT](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-choosefonta) structure is less than the size specified in the **nSizeMin** member. |
| **CFERR_NOFONTS**<br><br>0x2001 | No fonts exist. |

The following error codes can be returned for the [GetOpenFileName](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-getopenfilenamea) and [GetSaveFileName](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-getsavefilenamea) functions.

| Return code/value | Description |
| --- | --- |
| **FNERR_BUFFERTOOSMALL**<br><br>0x3003 | The buffer pointed to by the **lpstrFile** member of the [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) structure is too small for the file name specified by the user. The first two bytes of the **lpstrFile** buffer contain an integer value specifying the size required to receive the full name, in characters. |
| **FNERR_INVALIDFILENAME**<br><br>0x3002 | A file name is invalid. |
| **FNERR_SUBCLASSFAILURE**<br><br>0x3001 | An attempt to subclass a list box failed because sufficient memory was not available. |

The following error code can be returned for the [FindText](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-findtexta) and [ReplaceText](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-replacetexta) functions.

| Return code/value | Description |
| --- | --- |
| **FRERR_BUFFERLENGTHZERO**<br><br>0x4001 | A member of the [FINDREPLACE](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-findreplacea) structure points to an invalid buffer. |

## See also

[CHOOSECOLOR](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-choosecolora-r1)

[CHOOSEFONT](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-choosefonta)

[ChooseColor](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646912(v=vs.85))

[ChooseFont](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646914(v=vs.85))

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[DEVNAMES](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-devnames)

[DialogBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dialogboxa)

[FINDREPLACE](https://learn.microsoft.com/windows/desktop/api/commdlg/ns-commdlg-findreplacea)

[FindText](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-findtexta)

[GetOpenFileName](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-getopenfilenamea)

[GetSaveFileName](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-getsavefilenamea)

[OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea)

[PAGESETUPDLG](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-pagesetupdlga)

[PRINTDLG](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-printdlga)

[PageSetupDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646937(v=vs.85))

[PrintDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646940(v=vs.85))

**Reference**

[RegisterWindowMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea)

[ReplaceText](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-replacetexta)