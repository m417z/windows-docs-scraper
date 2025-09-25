# PrivacySetZonePreferenceW function

## Description

Sets the privacy settings for a given [URLZONE](https://learn.microsoft.com/dotnet/api/microsoft.visualstudio.ole.interop.urlzone) and [PrivacyType](https://learn.microsoft.com/windows/desktop/WinInet/privacy-type).

## Parameters

### `dwZone` [in]

Value of type **DWORD** that specifies the [URLZONE](https://learn.microsoft.com/dotnet/api/microsoft.visualstudio.ole.interop.urlzone) for which privacy settings are being set.

### `dwType` [in]

Value of type **DWORD** that specifies the [PrivacyType](https://learn.microsoft.com/windows/desktop/WinInet/privacy-type) for which privacy settings are being set.

### `dwTemplate` [in]

Value of type **DWORD** that specifies which of the [privacy templates](https://learn.microsoft.com/windows/desktop/WinInet/privacy-templates) is to be used to set the privacy settings.

### `pszPreference` [in, optional]

If *dwTemplate* is set to **PRIVACY_TEMPLATE_CUSTOM**, this parameter is the string representation of the custom preferences. Otherwise, it should be set to **NULL**. A description of this string representation is included in the Remarks section.

## Return value

Returns zero if successful. Otherwise, one of the errors defined in winerr.h is returned.

## Remarks

These privacy settings for the Internet zone are found on the **Privacy** tab of the **Internet Options** dialog box.

Setting the privacy options for the [URLZONE_INTERNET](https://learn.microsoft.com/dotnet/api/microsoft.visualstudio.ole.interop.urlzone) involves setting the [privacy templates](https://learn.microsoft.com/windows/desktop/WinInet/privacy-templates) for both [PrivacyTypes](https://learn.microsoft.com/windows/desktop/WinInet/privacy-type). The slider on the **Privacy** Menu in **Internet Options** only moves if privacy is set for both **PrivacyTypes**.

Custom privacy preferences for a given [URLZONE](https://learn.microsoft.com/dotnet/api/microsoft.visualstudio.ole.interop.urlzone) and [PrivacyType](https://learn.microsoft.com/windows/desktop/WinInet/privacy-type) can be set through the *pszPreference* parameter. The *pszPreference* parameter can contain a series of rules separated by white space describing the privacy preferences. It is important to note that the rules themselves cannot contain white space. The *pszPreference* has the following structure where there can be multiple logical rules: <*signature*> <*logical-rule*> <*special-rule*>.

Currently, the signature must be set to IE6-P3PSettings/V1:.

Logical rules have the following format: /<*expression*>=<*decision*>/.

An expression is a Boolean statement composed of compact policy tokens using the operators & (logical AND) and ! (logical NOT). The compact policy token is case-sensitive. (For more information on Platform for Privacy Preferences (P3P) privacy policies and compact policy tokens, see the [W3C: Platform for Privacy Preferences (P3P) Project](https://www.w3.org/P3P/) specification.) The decision is a single lowercase character that defines the action to take on the cookie whose compact policy contains the specified token(s). The following table lists valid decision characters.

| Character | Definition |
| --- | --- |
| a | Accept the cookie. |
| p | Prompt user to accept or deny the cookie. |
| r | Reject the cookie. |
| l | Leash the cookie (only send it in a first-party context). |
| d | Downgrade the cookie, if it is a persistent cookie, to a session cookie. |

Logical rules are evaluated in the order they are listed. The first logical-rule to be matched, if any, determines the cookie action.

An empty expression is also allowed. If an expression is empty, the left side evaluates to true. This form of a logical-rule can be used at the end of a set of rules to catch all situations that did not fall into the other categories.

The following examples show valid logical rules.

``` syntax
/DEM=d/
    Deny a cookie whose compact policy contains the DEM token
/CON&!TEL=a/	
    Accept a cookie whose compact policy contains the CON token
    and does not contain the TEL token
/=a/		
    Accept all cookies
```

Special rules are specified using the nopolicy, session, and always symbols. The nopolicy symbol is used to specify the action to taken when there is no compact policy. For example nopolicy=d specifies to downgrade all cookies without a compact policy to session cookies. The session symbol is used to specify the action to take on session cookies and can only be set to a. When session=a is specified, all session cookies are accepted regardless of the content of the compact policy. If this rule is not specified, session cookies are subject to the same rules as persistent cookies. Finally, the always symbol is used to specify to perform the same action for everything. For example, always=d specifies to deny all cookies regardless of the existence of a compact policy. Note that always=d is equivalent to /=d/.

The following example shows a privacy preferences string that specifies to accept cookies for which the compact policy contains a FIN/CONi token pair, reject cookies with compact policies containing FIN/CON, FIN/CONo, FIN/CONa and GOV/PUB token pairs or a TEL token, and to prompt the user when a cookie's compact policy contains the UNR token. It also specifies to downgrade cookies without a compact policy to session cookies and to accept all cookies that do not match one of the given rules. Note that the first rule that evaluates to true determines the cookie action.

``` syntax
IE6-P3PSettings/V1: /FIN&CONi=a/ /FIN&CONo=r/ /FIN&CONa=r/ /FIN&CON=r/
/GOV&PUB=r/ /TEL=r/ /UNR=p/ nopolicy=d /=a/
```

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[InternetClearAllPerSiteCookieDecisions](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetclearallpersitecookiedecisions)

[InternetEnumPerSiteCookieDecision](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetenumpersitecookiedecisiona)

[InternetGetPerSiteCookieDecision](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetpersitecookiedecisiona)

[InternetSetPerSiteCookieDecision](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetpersitecookiedecisiona)

[PrivacyGetZonePreferenceW](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-privacygetzonepreferencew)