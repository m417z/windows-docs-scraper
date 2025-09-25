# RasCustomDialDlgFn callback function

## Description

[This function is not available as of Windows Server 2008.

]

The
**RasCustomDialDlg** function is an application-defined function that is exported by a third-party custom-dialing DLL. This function allows third-party vendors to implement custom RAS connection dialog boxes.

## Parameters

### `hInstDll`

Handle to the instance of the custom-dialing DLL that was loaded.

### `dwFlags`

A set of bit flags that specify **RasCustomDialDlg** options.

| Value | Meaning |
| --- | --- |
| **RCD_Logon** | If this flag is set to one, the connection was dialed from a Windows Logon context. [RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) uses this information to get the appropriate user preferences for the connection entry. If **RasDial** is called from this entry point, the *dwfOptions* member of the *lpRasDialExtension* parameter must have the **RDEOPT_NoUser** flag set to indicate the connection was dialed from a Windows Logon context. |

**Windows Server 2003 and Windows XP/2000:** This parameter is reserved and should not be used.

### `lpszPhonebook`

Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

### `lpszEntry`

Pointer to a **null**-terminated string that contains the name of the phone-book entry to dial.

### `lpszPhoneNumber`

Pointer to a **null**-terminated string that contains a phone number that overrides the numbers stored in the phone-book entry. If this parameter is **NULL**,
[RasDialDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasdialdlga) uses the numbers in the phone-book entry.

### `lpInfo`

Pointer to a
[RASDIALDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377023(v=vs.85)) structure that contains additional input and output parameters. On input, the **dwSize** member of this structure must specify sizeof(
**RASDIALDLG**). If an error occurs, the **dwError** member returns an error code; otherwise, it returns zero.

### `pvInfo`

Reserved for internal use. This parameter will always be **NULL**.

## Return value

If the user creates, copies, or edits a phone-book entry, the return value should be **TRUE**. Otherwise, the function should return **FALSE**.

If an error occurs,
[RasCustomEntryDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nc-rasdlg-rascustomentrydlgfn) should set the **dwError** member of the
[RASENTRYDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377260(v=vs.85)) structure to a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

## Remarks

RAS calls this entry point from
[RasDialDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasdialdlga), if the **szCustomDialDll** member of the
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure for the entry being dialed specifies a custom-dialing DLL.

If this entry point calls
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala), the *lpRasDialExtensions* parameter must not be **NULL**, and the **dwfOptions** member of the
[RASDIALEXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377029(v=vs.85)) structure must have the **RDEOPT_CustomDial** flag set.

The custom-dial dialog must support
[WM_COMMAND](https://learn.microsoft.com/windows/desktop/menurc/wm-command) messages where
[LOWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms632659(v=vs.85))(*wParam*) equals IDCANCEL.

If the custom-dial DLL does not support this entry point, RAS returns **ERROR_CANNOT_DO_CUSTOMDIAL** to the caller of
[RasDialDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasdialdlga).

## See also

[Custom Dialers](https://learn.microsoft.com/windows/desktop/RRAS/custom-dialers)

[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85))

[RasCustomDial](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomdialfn)

[RasCustomEntryDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nc-rasdlg-rascustomentrydlgfn)

[RasCustomHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomhangupfn)

[RasDialDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasdialdlga)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)