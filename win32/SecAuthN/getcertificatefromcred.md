# GetCertificateFromCred function

Gets the certificate from the user credential.

## Parameters

*ProviderHandle* \[in\]

Identity provider handle.

*ClientToken* \[in\]

Token of the caller who is retrieving the certificate.

*SuppliedCred* \[in\]

A pointer to a [**SECPKG\_SUPPLIED\_CREDENTIAL**](https://learn.microsoft.com/windows/desktop/api/Ntsecpkg/ns-ntsecpkg-secpkg_supplied_credential) structure that contains the credential of an online ID whose certificate is requested. The identity provider must validate the input data as if it is coming from an untrusted source.

*SuppliedCredSize* \[in\]

The size, in bytes, of the *SuppliedCred* buffer.

*CertContext* \[out\]

If the function succeeds, this parameter is a pointer to the returned CCERT\_CONTEXT pointer. When you have finished using the certificate context, release it by calling the [**CertFreeCertificateContext**](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function.

## Return value

If the function succeeds, the function returns STATUS\_SUCCESS.

If the function fails, the function may return one of the following NTSTATUS error codes.

| Return value | Description |
|---------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| STATUS\_NOT\_SUPPORTED | The identity provider does not recognize the credential type of the supplied credential. LSA will try the next identity provider.<br> |
| STATUS\_LOGON\_FAILURE | The credential is incorrect.<br> |
| STATUS\_INVALID\_PARAMETER | A parameter is not valid. The credential may be in an incorrect format and not in the defined [**SECPKG\_SUPPLIED\_CREDENTIAL**](https://learn.microsoft.com/windows/desktop/api/Ntsecpkg/ns-ntsecpkg-secpkg_supplied_credential) structure.<br> |
| STATUS\_NETWORK\_UNREACHABLE | The identity provider cannot contact the cloud to obtain the certificate.<br> |
| STATUS\_PASSWORD\_EXPIRED | The account password has expired.<br> |
| STATUS\_ACCOUNT\_LOCKED\_OUT | The account has been locked out. <br> |
| Others | Other provider-specific error codes. <br> |

## Remarks

Before fetching the certificate from the cloud, the identity provider should check that there is a valid certificate for this user in the user's "MY" certificate store. If a valid certificate exists, the provider should return this certificate to avoid unnecessary network traffic.

The identity provider can also cache the certificate locally as long as it is protected from the current user.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | Lsaidprov.h |

