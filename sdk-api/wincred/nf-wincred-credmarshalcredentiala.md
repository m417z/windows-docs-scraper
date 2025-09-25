# CredMarshalCredentialA function

## Description

The **CredMarshalCredential** function transforms a credential into a text string. Historically, many functions, such as [NetUseAdd](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netuseadd), take a domain name, user name, and password as credentials. These functions do not accept certificates as credentials. The **CredMarshalCredential** function converts such credentials into a form that can be passed into these APIs.

The marshaled credential should be passed as the user name string to any API that is currently passed credentials. The domain name, if applicable, passed to that API should be passed as **NULL** or empty. For certificate credentials, the PIN of the certificate should be passed to that API as the password.

The caller should not modify or print marshaled credentials. The returned value can be freely converted between the Unicode, ANSI, and OEM characters sets. The string is case sensitive.

## Parameters

### `CredType` [in]

Type of the credential to marshal.

### `Credential` [in]

Credential to marshal.

This is one of the [CRED_MARSHAL_TYPE](https://learn.microsoft.com/windows/desktop/api/wincred/ne-wincred-cred_marshal_type) values.

If *CredType* is *CertCredential*, *Credential* points to a [CERT_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-cert_credential_info) structure.

If *CredType* is *UsernameTargetCredential*, *Credential* points to a [USERNAME_TARGET_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-username_target_credential_info) structure.

### `MarshaledCredential` [out]

Pointer to a **null**-terminated
string that contains the marshaled credential. The caller should free the returned buffer using [CredFree](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credfree).

## Return value

This function returns **TRUE** on success and **FALSE** on failure. The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function can be called to get a more specific status code. The following status code can be returned:

ERROR_INVALID_PARAMETER

*CredType* is not valid.

## See also

[CERT_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-cert_credential_info)

[CRED_MARSHAL_TYPE](https://learn.microsoft.com/windows/desktop/api/wincred/ne-wincred-cred_marshal_type)

[CredFree](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credfree)

[CredUnmarshalCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credunmarshalcredentiala)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[USERNAME_TARGET_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-username_target_credential_info)

## Remarks

> [!NOTE]
> The wincred.h header defines CredMarshalCredential as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).