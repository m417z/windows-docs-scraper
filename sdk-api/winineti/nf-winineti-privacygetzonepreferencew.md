# PrivacyGetZonePreferenceW function

## Description

Retrieves the privacy settings for a given
[URLZONE](https://learn.microsoft.com/dotnet/api/microsoft.visualstudio.ole.interop.urlzone) and [PrivacyType](https://learn.microsoft.com/windows/desktop/WinInet/privacy-type).

## Parameters

### `dwZone` [in]

A value of type *DWORD* that specifies the [URLZONE](https://learn.microsoft.com/dotnet/api/microsoft.visualstudio.ole.interop.urlzone) for which privacy settings are being retrieved.

### `dwType` [in]

A value of type *DWORD* that specifies the [PrivacyType](https://learn.microsoft.com/windows/desktop/WinInet/privacy-type) for which privacy settings are being retrieved.

### `pdwTemplate` [out, optional]

An **LPDWORD** that returns a pointer to a **DWORD** containing which of the [PrivacyTemplates](https://learn.microsoft.com/windows/desktop/WinInet/privacy-templates) is in use for this *dwZone* and *dwType*.

### `pszBuffer` [out, optional]

An **LPWSTR** that points to a buffer containing a **LPCWSTR** representing a string version of the *pdwTemplate* or a customized string if the *pdwTemplate* is set to **PRIVACY_TEMPLATE_CUSTOM**. See [PrivacySetZonePreferenceW](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-privacysetzonepreferencew) for a description of a customized privacy preferences string.

### `pdwBufferLength` [in, out, optional]

An **LPDWORD** that contains the buffer length in characters. If the buffer length is not sufficient, **PrivacyGetZonePreferenceW** returns with this parameter set to the number of characters required and with a return value of **ERROR_MORE_DATA**.

## Return value

Returns zero if successful. Otherwise, one of the Error Messages defined in winerr.h is returned.

## Remarks

These privacy settings for the Internet zone are found on the Privacy tab of the Internet Options dialog box.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetClearAllPerSiteCookieDecisions](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclearallpersitecookiedecisions)

[InternetEnumPerSiteCookieDecision](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetenumpersitecookiedecisiona)

[InternetGetPerSiteCookieDecision](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetpersitecookiedecisiona)

[InternetSetPerSiteCookieDecisions](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetpersitecookiedecisiona)

[PrivacySetZonePreferenceW](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-privacysetzonepreferencew)