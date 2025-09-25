# InternetEnumPerSiteCookieDecisionA function

## Description

Retrieves the domains and cookie settings of websites for which site-specific cookie regulations are set.

## Parameters

### `pszSiteName` [out]

An **LPSTR** that receives a string specifying a website domain.

### `pcSiteNameSize` [in, out]

A pointer to an unsigned long that specifies the size of the *pcSiteNameSize* parameter provided to the InternetEnumPerSiteCookieDecision function when it is called. When **InternetEnumPerSiteCookieDecision** returns, *pcSiteNameSize* receives the actual length of the domain string returned in *pszSiteName*.

### `pdwDecision` [out]

Pointer to an unsigned long that receives the [InternetCookieState](https://learn.microsoft.com/windows/win32/api/wininet/ne-wininet-internet_scheme) enumeration value corresponding to *pszSiteName*.

### `dwIndex` [in]

An unsigned long that specifies the index of the website and corresponding cookie setting to retrieve.

## Return value

**TRUE** if the function retrieved the cookie setting for the given domain; otherwise, false. **FALSE**.

## Remarks

**InternetEnumPerSiteCookieDecision** should be initially called with *dwIndex* equal to 0. Incrementing the *dwIndex* parameter steps through the list of websites and cookie settings. The end of the list is reached when **InternetEnumPerSiteCookieDecision** returns **FALSE** and produces the wininet error, **ERROR_NO_MORE_ITEMS**.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The winineti.h header defines InternetEnumPerSiteCookieDecision as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[InternetClearAllPerSiteCookieDecisions](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclearallpersitecookiedecisions)

[InternetGetPerSiteCookieDecision](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetpersitecookiedecisiona)

[InternetSetPerSiteCookieDecision](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetpersitecookiedecisiona)

[PrivacyGetZonePreferenceW](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-privacygetzonepreferencew)

[PrivacySetZonePreferenceW](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-privacysetzonepreferencew)