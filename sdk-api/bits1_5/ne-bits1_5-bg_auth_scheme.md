# BG_AUTH_SCHEME enumeration

## Description

Defines constants that specify the authentication scheme to use when a proxy or server requests user authentication.

## Constants

### `BG_AUTH_SCHEME_BASIC:1`

*Basic* is a scheme in which the user name and password are sent in clear-text to the server or proxy.

### `BG_AUTH_SCHEME_DIGEST`

*Digest* is a challenge-response scheme that uses a server-specified data string for the challenge.

### `BG_AUTH_SCHEME_NTLM`

*NTLM* is a challenge-response scheme that uses the credentials of the user for authentication in a Windows network environment.

### `BG_AUTH_SCHEME_NEGOTIATE`

*Simple and Protected Negotiation* (Snego) is a challenge-response scheme that negotiates with the server or proxy to determine which scheme to use for authentication. Examples are the Kerberos protocol, and NTLM.

### `BG_AUTH_SCHEME_PASSPORT`

*Passport* is a centralized authentication service provided by Microsoft that offers a single logon for member sites.

## Remarks

BITS supports Passport authentication for explicit credentials only, not implicit credentials tied to the account.

The following table shows the authentication requests that BITS does not support.

|Scenario|Windows XP|Windows Server 2003|
|-|-|-|
|Passport authentication on the server when the proxy requires authentication (using the HTTPS protocol).|Not supported|Not supported|
|Any authentication scheme on the server when the proxy requires Digest authentication.|Not supported|Not supported|
|Negotiate authentication on the server when the proxy requires Basic authentication.|Not supported||
|Using HTTPS when the proxy requires Digest authentication.|Not supported||

## See also

* [Authentication](https://learn.microsoft.com/windows/desktop/Bits/authentication)
* [BG_AUTH_CREDENTIALS structure](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_auth_credentials)
* [IBackgroundCopyJob2::SetCredentials method](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setcredentials)