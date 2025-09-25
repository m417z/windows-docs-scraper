# RasCustomDialFn callback function

## Description

[This function is not available as of Windows Server 2008.

]

The
**RasCustomDial** function is an application-defined function that is exported by a third-party custom-dialing DLL. This function allows third-party vendors to implement custom remote-access dialing routines.

## Parameters

### `hInstDll`

Handle to the instance of the custom-dial DLL that was loaded.

### `lpRasDialExtensions`

Pointer to a
[RASDIALEXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377029(v=vs.85)) structure that specifies a set of
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) extended features to enable. Set this parameter to **NULL** if there is no need to enable the extensions.

### `lpszPhonebook`

Pointer to a **null**-terminated string that specifies the full path and file name of a phone-book (PBK) file. If this parameter is **NULL**, the function uses the current default phone-book file. The default phone-book file is the one selected by the user in the **User Preferences** property sheet of the **Dial-Up Networking** dialog box.

### `lpRasDialParams`

Pointer to a
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure that specifies calling parameters for the RAS connection.

The caller must set the
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) structure's **dwSize** member to sizeof(**RASDIALPARAMS**) to identify the version of the structure being passed.

### `dwNotifierType`

This parameter is the same as the *dwNotifierType* parameter for the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) function. See the
**RasDial** reference page for more information.

### `lpvNotifier`

This parameter is the same as the *lpvNotifier* parameter for the
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) function. See the
**RasDial** reference page for more information.

### `lphRasConn`

Pointer to a variable of type **HRASCONN**. Set the **HRASCONN** variable to **NULL** before calling
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala). If
**RasDial** succeeds, it stores a handle to the RAS connection into **lphRasConn*.

### `dwFlags`

This parameter reserved for future use.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS** and a handle to the RAS connection in the variable pointed to by the *lphRasConn* parameter is returned.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | The function could not allocate sufficient memory to complete the operation. |

## Remarks

RAS calls this entry point from
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala), if the **szCustomDialDll** member of the
[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85)) structure for the entry being dialed specifies a custom-dialing DLL.

If this entry point calls
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala), the *lpRasDialExtensions* parameter must not be **NULL**, and the **dwFlags** member of the
[RASDIALEXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377029(v=vs.85)) structure must have the RDEOPT_CustomDial flag set.

If the custom-dial DLL does not support this entry point, RAS returns ERROR_CANNOT_DO_CUSTOMDIAL to the caller of
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala).

## See also

[Custom Dialers](https://learn.microsoft.com/windows/desktop/RRAS/custom-dialers)

[RASENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377274(v=vs.85))

[RasCustomDialDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nc-rasdlg-rascustomdialdlgfn)

[RasCustomEntryDlg](https://learn.microsoft.com/windows/desktop/api/rasdlg/nc-rasdlg-rascustomentrydlgfn)

[RasCustomHangUp](https://learn.microsoft.com/windows/desktop/api/ras/nc-ras-rascustomhangupfn)

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Functions](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-functions)