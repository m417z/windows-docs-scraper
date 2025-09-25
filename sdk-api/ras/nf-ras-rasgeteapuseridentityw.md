# RasGetEapUserIdentityW function

## Description

The
**RasGetEapUserIdentity** function retrieves identity information for the current user. Use this information to call
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) with a phone-book entry that requires Extensible Authentication Protocol (EAP).

## Parameters

### `pszPhonebook` [in]

Pointer to a **null**-terminated string that specifies the full path of the phone-book (PBK) file. If this parameter is **NULL**, the function uses the system phone book.

### `pszEntry` [in]

Pointer to a **null**-terminated string that specifies an existing entry name.

### `dwFlags` [in]

Specifies zero or more of the following flags that qualify the authentication process.

| Flag | Meaning |
| --- | --- |
| **RASEAPF_NonInteractive** | Specifies that the authentication protocol should not bring up a graphical user-interface. If this flag is not present, it is okay for the protocol to display a user interface. |
| **RASEAPF_Logon** | Specifies that the user data is obtained from WinLogon. |
| **RASEAPF_Preview** | Specifies that the user should be prompted for identity information before dialing. |

### `hwnd` [in]

Handle to the parent window for the UI dialog. If the *fInvokeUI* parameter is **FALSE**, then *hwnd* should be **NULL**.

### `ppRasEapUserIdentity` [out]

Pointer to a pointer that, on successful return, receives the address of the
[RASEAPUSERIDENTITY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377247(v=vs.85)) structure that contains EAP user identity information.
**RasGetEapUserIdentity** allocates the memory buffer for the
**RASEAPUSERIDENTITY** structure. Free this memory by calling
[RasFreeEapUserIdentity](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasfreeeapuseridentitya).

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Value | Meaning |
| --- | --- |
| **E_INVALID_ARG** | The *pcbEapUserIdentity* parameter is **NULL**. |
| **ERROR_INTERACTIVE_MODE** | The function was called with the RASEAPF_NonInteractive flag. However, the authentication protocol must display a UI in order to obtain the required identity information from the user. |
| **ERROR_INVALID_FUNCTION_FOR_ENTRY** | Either the authentication method for this phone-book entry is not EAP, or the authentication method is EAP but the protocol uses the standard Windows NT/Windows 2000 credentials dialog to obtain user identity information. In either case, the caller does not need to pass EAP identity information to [RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala). |
| **ERROR_RASMAN_CANNOT_INITIALIZE** | The Remote Access Service failed to initialize properly. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to retrieve the system error message that corresponds to the error code returned. |

## Remarks

**RasGetEapUserIdentity** calls the RAS function
[RasGetEapUserData](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeteapuserdataa) and the EAP function
[RasEapGetIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapgetidentity). **RasEapGetIdentity** is implemented by the authentication protocol.

If the function succeeds, that is the return value is NO_ERROR, the caller should copy the EAP identity information from the [RASEAPUSERIDENTITY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377247(v=vs.85)) structure pointed to by
the *ppRasEapUserIdentity* parameter to the
[RASDIALPARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377238(v=vs.85)) and
[RASDIALEXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377029(v=vs.85)) structures used in the call to
[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala).

If the remote access application being developed has a graphical user interface, the caller of
**RasGetEapUserIdentity** should not specify the RASEAPF_NonInteractive flag. If the application has a command-line user interface, the caller may want to specify the RASEAPF_NonInteractive flag to prevent the authentication protocol from displaying a graphical user interface.

> [!NOTE]
> The ras.h header defines RasGetEapUserIdentity as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RASEAPUSERIDENTITY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377247(v=vs.85))

[RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala)

[RasEapGetIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapgetidentity)

[RasFreeEapUserIdentity](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasfreeeapuseridentitya)

[RasGetEapUserData](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgeteapuserdataa)

[RasSetEapUserData](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasseteapuserdataa)