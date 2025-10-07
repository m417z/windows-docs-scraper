# WinHttpRequestAutoLogonPolicy enumeration

The **WinHttpRequestAutoLogonPolicy** enumeration includes possible settings for the [Automatic Logon Policy](https://learn.microsoft.com/windows/win32/winhttp/authentication-in-winhttp).

## Constants

**AutoLogonPolicy\_Always**

An authenticated log on, using the default credentials, is performed for all requests.

**AutoLogonPolicy\_OnlyIfBypassProxy**

An authenticated log on, using the default credentials, is performed only for requests on the local intranet. The local intranet is considered to be any server on the proxy bypass list in the current proxy configuration.

**AutoLogonPolicy\_Never**

Authentication is not used automatically.

## Remarks

To set the automatic logon policy, call the [**SetAutoLogonPolicy**](https://learn.microsoft.com/windows/win32/winhttp/iwinhttprequest-setautologonpolicy) method and specify one of the preceding constants.

> [!Note]
> For Windows XP and Windows 2000, see the [Run-Time Requirements](https://learn.microsoft.com/windows/win32/winhttp/winhttp-start-page) section of the WinHTTP start page.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP, Windows 2000 Professional with SP3 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003, Windows 2000 Server with SP3 \[desktop apps only\]<br> |
| Redistributable<br> | WinHTTP 5.0 and Internet Explorer 5.01 or later on Windows XP and Windows 2000.<br> |
| IDL<br> | HttpRequest.idl |

## See also

[WinHTTP Versions](https://learn.microsoft.com/windows/win32/winhttp/winhttp-versions)

