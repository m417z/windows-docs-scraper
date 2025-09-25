# InternetClearAllPerSiteCookieDecisions function

## Description

Clears all decisions that were made about cookies on a site by site basis.

## Return value

Returns **TRUE** if all decisions were cleared and **FALSE** otherwise.

## Remarks

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetEnumPerSiteCookieDecision](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetenumpersitecookiedecisiona)

[InternetGetPerSiteCookieDecisions](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetpersitecookiedecisiona)

[InternetSetPerSiteCookieDecisions](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetpersitecookiedecisiona)

[PrivacyGetZonePreferenceW](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-privacygetzonepreferencew)

[PrivacySetZonePreferenceW](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-privacysetzonepreferencew)