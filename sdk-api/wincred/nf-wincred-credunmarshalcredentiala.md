# CredUnmarshalCredentialA function

## Description

The **CredUnmarshalCredential** function transforms a marshaled credential back into its original form.

## Parameters

### `MarshaledCredential` [in]

Pointer to a null-terminated string that contains the marshaled credential.

### `CredType` [out]

Type of credential specified by *MarshaledCredential*.

This is one of the [CRED_MARSHAL_TYPE](https://learn.microsoft.com/windows/desktop/api/wincred/ne-wincred-cred_marshal_type) values.

### `Credential` [out]

Pointer to the unmarshaled credential. If *CredType* returns *CertCredential*, the returned pointer is to a [CERT_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-cert_credential_info) structure. If *CredType* returns *UsernameTargetCredential*, the returned pointer is to a [USERNAME_TARGET_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-username_target_credential_info) structure.

The caller should free the returned buffer using [CredFree](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credfree).

## Return value

This function returns **TRUE** on success and **FALSE** on failure. The [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function can be called to get a more specific status code. The following status code can be returned:

ERROR_INVALID_PARAMETER

*MarshaledCredential* is not valid.

## See also

[CERT_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-cert_credential_info)

[CRED_MARSHAL_TYPE](https://learn.microsoft.com/windows/desktop/api/wincred/ne-wincred-cred_marshal_type)

[CredFree](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credfree)

[CredMarshalCredential](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credmarshalcredentiala)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[USERNAME_TARGET_CREDENTIAL_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-username_target_credential_info)

## Remarks

> [!NOTE]
> The wincred.h header defines CredUnmarshalCredential as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).