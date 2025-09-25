# RasCustomEntryDlgFn callback function

## Description

The
**RasCustomEntryDlg** function is an application-defined function that is exported by a third-party custom-dialing DLL. This function allows third-party vendors to implement custom dialogs for managing phone-book entries.

## Parameters

### `hInstDll`

Handle to the instance of the custom-dial DLL that was loaded.

### `lpszPhonebook`

Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

### `lpszEntry`

Pointer to a **null**-terminated string that contains the name of the phone-book entry to edit, copy, or create.

If you are editing or copying an entry, this parameter is the name of an existing phone-book entry. If you are copying an entry, set the RASEDFLAG_CloneEntry flag in the **dwFlags** member of the
[RASENTRYDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377260(v=vs.85)) structure.

If you are creating an entry, this parameter is a default new entry name that the user can change. If this parameter is **NULL**, the function provides a default name. If you are creating an entry, set the RASEDFLAG_NewEntry flag in the **dwFlags** member of the
[RASENTRYDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377260(v=vs.85)) structure.

### `lpInfo`

Pointer to a
[RASENTRYDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377260(v=vs.85)) structure that contains additional input and output parameters. On input, the **dwSize** member of this structure must specify sizeof(
**RASENTRYDLG**). Use the **dwSize** member to indicate whether creating, editing, or copying an entry. If an error occurs, the **dwError** member returns an error code; otherwise, it returns zero.

### `dwFlags`

Reserved for future use.

## Return value

If the user creates, copies, or edits a phone-book entry, the return value should be **TRUE**. Otherwise, the function should return **FALSE**.

If an error occurs, **RasCustomEntryDlg** should set the **dwError** member of the
[RASENTRYDLG](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377260(v=vs.85)) structure to a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

## Remarks

RAS calls this entry point from
[RasEntryDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasentrydlga), if the **szCustomDialDll** member of the
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure for the entry being dialed specifies a custom-dialing DLL.

If the custom-dial DLL does not support this entry point, RAS returns ERROR_NO_CUSTOMENTRYDLG to the caller of
[RasEntryDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasentrydlga).

## See also

[Custom Dialers](https://learn.microsoft.com/windows/desktop/RRAS/custom-dialers)

[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85))

[RasCustomDial](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomdialfn)

[RasCustomDialDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nc-rasdlg-rascustomdialdlgfn)

[RasCustomHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomhangupfn)

[RasEntryDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nf-rasdlg-rasentrydlga)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)