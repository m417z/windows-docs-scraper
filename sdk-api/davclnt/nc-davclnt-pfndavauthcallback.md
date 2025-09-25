## Description

The WebDAV client calls the application-defined *DavAuthCallback* callback function to prompt the user for credentials.

The *PFNDAVAUTHCALLBACK* type defines a pointer to this callback function. *DavAuthCallback* is a placeholder for the application-defined function name.

## Parameters

### `lpwzServerName` [in]

A pointer to a **NULL**-terminated Unicode string that contains the name of the target server.

### `lpwzRemoteName` [in]

A pointer to a **NULL**-terminated Unicode string that contains the name of the network resource.

### `dwAuthScheme` [in]

A bitmask of flags that specify the authentication schemes to be used.

| Value | Meaning |
| --- | --- |
| **DAV_AUTHN_SCHEME_BASIC**<br><br>0x00000001 | Basic authentication is to be used. |
| **DAV_AUTHN_SCHEME_NTLM**<br><br>0x00000002 | [Microsoft NTLM](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-ntlm) authentication is to be used. |
| **DAV_AUTHN_SCHEME_PASSPORT**<br><br>0x00000004 | [Passport authentication](https://learn.microsoft.com/windows/desktop/WinHttp/passport-authentication-in-winhttp) is to be used. |
| **DAV_AUTHN_SCHEME_DIGEST**<br><br>0x00000008 | [Microsoft Digest authentication](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-digest-authentication) is to be used. |
| **DAV_AUTHN_SCHEME_NEGOTIATE**<br><br>0x00000010 | [Microsoft Negotiate](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-negotiate) is to be used. |
| **DAV_AUTHN_SCHEME_CERT**<br><br>0x00010000 | Certificate authentication is to be used. |
| **DAV_AUTHN_SCHEME_FBA**<br><br>0x00100000 | Forms-based authentication is to be used. |

### `dwFlags` [in]

The flags that the WebDAV service passed in the *dwFlags* parameter when it called the [NPAddConnection3](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npaddconnection3) function.

### `pCallbackCred` [in, out]

A pointer to a [DAV_CALLBACK_CRED](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_cred) structure.

### `NextStep` [in, out]

A pointer to an [AUTHNEXTSTEP](https://learn.microsoft.com/windows/desktop/api/davclnt/ne-davclnt-authnextstep) enumeration value that specifies the next action that the WebDAV client should take after a successful call to the *DavAuthCallback* callback function.

### `pFreeCred` [out]

A pointer to a [DavFreeCredCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback_freecred) callback function.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The *DavAuthCallback* callback function must be registered by calling the [DavRegisterAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nf-davclnt-davregisterauthcallback) function.

To unregister this callback function, use the [DavUnregisterAuthCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nf-davclnt-davunregisterauthcallback) function.

This callback function should prompt the user for credentials (either a [user name and password](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_unp) or an [authentication BLOB](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_blob)) and store this information in the appropriate member of the [DAV_CALLBACK_CRED](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_cred) structure that the *pCallbackCred* parameter points to.

## See also

[CredUIPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforcredentialsa)

[CredUIPromptForWindowsCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforwindowscredentialsa)

[DAV_CALLBACK_AUTH_BLOB](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_blob)

[DAV_CALLBACK_AUTH_UNP](https://learn.microsoft.com/windows/desktop/api/davclnt/ns-davclnt-dav_callback_auth_unp)

[DavFreeCredCallback](https://learn.microsoft.com/windows/desktop/api/davclnt/nc-davclnt-pfndavauthcallback_freecred)