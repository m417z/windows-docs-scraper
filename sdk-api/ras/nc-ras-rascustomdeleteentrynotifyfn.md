# RasCustomDeleteEntryNotifyFn callback function

## Description

The
*RasCustomDeleteEntryNotify* function is an application-defined function that is exported by a third-party custom-dialing DLL. This function allows third-party vendors to implement custom dialogs for managing phone-book entries.

## Parameters

### `lpszPhonebook` [in]

Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

### `lpszEntry` [in]

Pointer to a **null**-terminated string that contains the name of the phone-book entry to dial.

### `dwFlags` [in]

Specifies one or more of the following flags:

#### RCD_SingleUser (0x00000000)

#### RCD_AllUsers (0x00000001)

#### RCD_Eap (0x00000002)

#### RCD_Logon (0x00000004)

## Return value

This function should return value **ERROR_SUCCESS** if successful.

## See also

[Custom Dialers](https://learn.microsoft.com/windows/desktop/RRAS/custom-dialers)

[RasCustomDial](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomdialfn)

[RasCustomDialDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nc-rasdlg-rascustomdialdlgfn)

[RasCustomEntryDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nc-rasdlg-rascustomentrydlgfn)

[RasCustomHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomhangupfn)

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)