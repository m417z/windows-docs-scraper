# QueryContextAttributesW function

## Description

The **QueryContextAttributes (CredSSP)** function lets a transport application query the Credential Security Support Provider (CredSSP) [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for certain [attributes](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) of a [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `phContext` [in]

A handle to the security context to be queried.

### `ulAttribute` [in]

The attribute of the context to be returned. This parameter can be one of the following values. Unless otherwise specified, the attributes are applicable to both client and server.

| Value | Meaning |
| --- | --- |
| **SECPKG_ATTR_C_ACCESS_TOKEN**<br><br>0x80000012 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_AccessToken](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_accesstoken) structure that specifies the access token for the current security context.<br><br>This attribute is supported only on the server. |
| **SECPKG_ATTR_C_FULL_ACCESS_TOKEN**<br><br>0x80000082 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_AccessToken](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_accesstoken) structure that specifies the access token for the current security context.<br><br>This attribute is supported only on the server. |
| **SECPKG_ATTR_CERT_TRUST_STATUS**<br><br>0x80000084 | The *pBuffer* parameter contains a pointer to a [CERT_TRUST_STATUS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_trust_status) structure that specifies trust information about the certificate.<br><br>This attribute is supported only on the client. |
| **SECPKG_ATTR_CREDS**<br><br>0x80000080 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_ClientCreds](https://learn.microsoft.com/windows/desktop/api/credssp/ns-credssp-secpkgcontext_clientcreds) structure that specifies client credentials.<br><br>The client credentials can be either user name and password or user name and smart card PIN.<br><br>This attribute is supported only on the server. |
| **SECPKG_ATTR_CREDS_2**<br><br>0x80000086 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_ClientCreds](https://learn.microsoft.com/windows/desktop/api/credssp/ns-credssp-secpkgcontext_clientcreds) structure that specifies client credentials. <br><br>If the client credential is user name and password, the buffer is a packed [KERB_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_interactive_logon) structure.<br><br>If the client credential is user name and smart card PIN, the buffer is a packed [KERB_CERTIFICATE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_logon) structure.<br><br>If the client credential is an online identity credential, the buffer is a marshaled [SEC_WINNT_AUTH_IDENTITY_EX2](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure.<br><br>This attribute is supported only on the CredSSP server.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_ATTR_NEGOTIATION_PACKAGE**<br><br>0x80000081 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_PackageInfo](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-secpkginfoa) structure that specifies the name of the authentication package negotiated by the [Microsoft Negotiate](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-negotiate) provider. |
| **SECPKG_ATTR_PACKAGE_INFO**<br><br>10 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_PackageInfo](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-secpkginfoa) structure.<br><br>Returns information on the SSP in use. |
| **SECPKG_ATTR_SERVER_AUTH_FLAGS**<br><br>0x80000083 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_Flags](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_flags) structure that specifies information about the flags in the current security context.<br><br>This attribute is supported only on the client. |
| **SECPKG_ATTR_SIZES**<br><br>0x0 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_Sizes](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_sizes) structure.<br><br>Queries the sizes of the structures used in the per-message functions and authentication exchanges. |
| **SECPKG_ATTR_SUBJECT_SECURITY_ATTRIBUTES**<br><br>124 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_SubjectAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_subjectattributes) structure.<br><br>This value returns information about the security attributes for the connection.<br><br>This value is supported only on the CredSSP server.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |

### `pBuffer` [out]

A pointer to a structure that receives the attributes. The structure type depends on the value of the *ulAttribute* parameter.

## Return value

If the function succeeds, it returns SEC_E_OK.

If the function fails, it can return the following error codes.

| Return code/value | Description |
| --- | --- |
| **SEC_E_INVALID_HANDLE**<br><br>0x80100003 | The function failed. The *phContext* parameter specifies a handle to an incomplete context. |
| **SEC_E_UNSUPPORTED_FUNCTION**<br><br>0x80090302 | The function failed. The value of the *ulAttribute* parameter is not valid. |

## Remarks

The structure pointed to by the *pBuffer* parameter varies depending on the attribute being queried.

While the caller must allocate the *pBuffer* structure itself, the SSP allocates any memory required to hold variable-sized members of the *pBuffer* structure. Memory allocated by the SSP must be freed by calling the [FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function.

> [!NOTE]
> The sspi.h header defines QueryContextAttributes as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecPkgContext_ClientCreds](https://learn.microsoft.com/windows/desktop/api/credssp/ns-credssp-secpkgcontext_clientcreds)

[SecPkgContext_Sizes](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_sizes)