# InternetSetPerSiteCookieDecisionW function

## Description

Sets a decision on cookies for a given domain.

## Parameters

### `pchHostName` [in]

An **LPCTSTR** that points to a string containing a domain.

### `dwDecision` [in]

A value of type **DWORD** that contains one of the [InternetCookieState](https://learn.microsoft.com/windows/win32/api/wininet/ne-wininet-internet_scheme) enumeration values.

## Return value

Returns **TRUE** if the decision is set and **FALSE** otherwise.

## Remarks

WinINet minimizes the domain specified in the *pchHostName* parameter and sets the cookie policy on the minimum legal domain. For example, if the specified host name is widgets.microsoft.com, the policy is set on the minimized host name microsoft.com.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetSetPerSiteCookieDecision as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[InternetClearAllPerSiteCookieDecisions](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclearallpersitecookiedecisions)

[InternetEnumPerSiteCookieDecision](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetenumpersitecookiedecisiona)

[InternetGetPerSiteCookieDecision](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetpersitecookiedecisiona)

[PrivacyGetZonePreferenceW](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-privacygetzonepreferencew)

[PrivacySetZonePreferenceW](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-privacysetzonepreferencew)