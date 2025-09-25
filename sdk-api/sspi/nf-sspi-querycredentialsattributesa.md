# QueryCredentialsAttributesA function

## Description

Retrieves the [attributes](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) of a [credential](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), such as the name associated with the credential. The information is valid for any [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) created with the specified credential.

## Parameters

### `phCredential` [in]

A handle of the credentials to be queried.

### `ulAttribute` [in]

Specifies the [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) to query. This parameter can be any of the following attributes.

| Value | Meaning |
| --- | --- |
| SECPKG_CRED_ATTR_CERT | Returns the certificate thumbprint in a *pbuffer* of type [SecPkgCredentials_Cert](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcredentials_cert).<br><br>This attribute is only supported by Kerberos.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This attribute is not available. |
| SECPKG_CRED_ATTR_NAMES | Returns the name of a credential in a *pbuffer* of type [SecPkgCredentials_Names](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcredentials_namesa).<br><br>This attribute is not supported by Schannel in WOW64 mode. |
| SECPKG_ATTR_SUPPORTED_ALGS | Returns the supported algorithms in a *pbuffer* of type [SecPkgCred_SupportedAlgs](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380102(v=vs.85)). All supported algorithms are included, regardless of whether they are supported by the provided certificate or enabled on the local computer.<br><br>This attribute is supported only by Schannel. |
| SECPKG_ATTR_CIPHER_STRENGTHS | Returns the cipher strengths in a *pbuffer* of type [SecPkgCred_CipherStrengths](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380101(v=vs.85)).<br><br>This attribute is supported only by Schannel. |
| SECPKG_ATTR_SUPPORTED_PROTOCOLS | Returns the supported algorithms in a *pbuffer* of type [SecPkgCred_SupportedProtocols](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380103(v=vs.85)). All supported protocols are included, regardless of whether they are supported by the provided certificate or enabled on the local computer.<br><br>This attribute is supported only by Schannel. |

### `pBuffer` [out]

A pointer to a buffer that receives the requested attribute. The type of structure returned depends on the value of *ulAttribute*.

## Return value

If the function succeeds, the return value is SEC_E_OK.

If the function fails, the return value may be one of the following error codes.

| Return code | Description |
| --- | --- |
| **SEC_E_INVALID_HANDLE** | The handle passed to the function is not valid. |
| **SEC_E_UNSUPPORTED_FUNCTION** | The specified [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) is not supported by Schannel. This return value will only be returned when the Schannel SSP is being used. |
| **SEC_E_INSUFFICIENT_MEMORY** | The memory that is available is not sufficient to complete the request. |

## Remarks

The **QueryCredentialsAttributes** function allows an application to determine several characteristics of a credential, including the name associated with the specified credentials.

Querying the SECPKG_ATTR_CIPHER_STRENGTHS attribute returns a
[SecPkgCred_CipherStrengths](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380101(v=vs.85)) structure. The cipher strength in this structure is the same as the cipher strength in the
[SCH_CREDENTIALS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-sch_credentials) structure used when a credential was created.

**Note** An application can find the system default cipher strength by querying this attribute with a default credential. A default credential is created by calling
[AcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea) with a **NULL** *pAuthData* parameter.

Querying the SECPKG_ATTR_SUPPORTED_ALGS attribute returns a
[SecPkgCred_SupportedAlgs](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380102(v=vs.85)) structure. The algorithms in this structure are compatible with those indicated in the [SCH_CREDENTIALS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-sch_credentials) structure used when a credential was created.

Querying the SECPKG_ATTR_SUPPORTED_PROTOCOLS attribute returns a
[SecPkgCred_SupportedProtocols](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380103(v=vs.85)) structure that contains a bit array compatible with the *grbitEnabledProtocols* field of the [SCH_CREDENTIALS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-sch_credentials) structure.

The caller must allocate the structure pointed to by the *pBuffer* parameter. The [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) allocates the buffer for any pointer returned in the *pBuffer* structure. The caller can call the
[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer) function to free any pointers allocated by the security package.

> [!NOTE]
> The sspi.h header defines QueryCredentialsAttributes as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea)

[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer)

[SCH_CREDENTIALS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-sch_credentials)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecPkgCred_CipherStrengths](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380101(v=vs.85))

[SecPkgCred_SupportedAlgs](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380102(v=vs.85))

[SecPkgCred_SupportedProtocols](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380103(v=vs.85))

[SecPkgCredentials_Names](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcredentials_namesa)