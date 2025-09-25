# SetCredentialsAttributesW function

## Description

Sets the [attributes](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) of a [credential](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), such as the name associated with the credential. The information is valid for any [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) created with the specified credential.

## Parameters

### `phCredential` [in]

A handle of the credentials to be set.

### `ulAttribute` [in]

Specifies the [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) to set. This parameter can be any of the following attributes.

| Value | Meaning |
| --- | --- |
| SECPKG_CRED_ATTR_NAMES | Sets the name of a credential in a *pBuffer* parameter of type [SecPkgCredentials_Names](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcredentials_namesa).<br><br>This attribute is not supported by Schannel in WOW64 mode. |
| SECPKG_CRED_ATTR_KDC_PROXY_SETTINGS | Sets the Kerberos proxy setting in a *pBuffer* parameter of type [SecPkgCredentials_KdcProxySettings](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcredentials_kdcproxysettingsw).<br><br>This attribute is only supported by Kerberos. |
| SECPKG_ATTR_SUPPORTED_ALGS | Sets the supported algorithms in a *pBuffer* parameter of type [SecPkgCred_SupportedAlgs](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380102(v=vs.85)). All supported algorithms are included, regardless of whether they are supported by the provided certificate or enabled on the local computer.<br><br>This attribute is supported only by Schannel. |
| SECPKG_ATTR_CIPHER_STRENGTHS | Sets the cipher strengths in a *pBuffer* parameter of type [SecPkgCred_CipherStrengths](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380101(v=vs.85)).<br><br>This attribute is supported only by Schannel. |
| SECPKG_ATTR_SUPPORTED_PROTOCOLS | Sets the supported algorithms in a *pBuffer* parameter of type [SecPkgCred_SupportedProtocols](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380103(v=vs.85)). All supported protocols are included, regardless of whether they are supported by the provided certificate or enabled on the local computer.<br><br>This attribute is supported only by Schannel. |

### `pBuffer` [in]

A pointer to a buffer that contains the new attribute value. The type of structure returned depends on the value of *ulAttribute*.

### `cbBuffer`

The size, in bytes, of the *pBuffer* buffer.

## Return value

If the function succeeds, the return value is SEC_E_OK.

If the function fails, the return value may be one of the following error codes.

| Return code | Description |
| --- | --- |
| **SEC_E_INVALID_HANDLE** | The handle passed to the function is not valid. |
| **SEC_E_UNSUPPORTED_FUNCTION** | The specified [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) is not supported by Schannel. This return value will only be returned when the Schannel SSP is being used. |
| **SEC_E_INSUFFICIENT_MEMORY** | Not enough memory is available to complete the request. |

## See also

[AcquireCredentialsHandle](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acquirecredentialshandlea)

[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer)

[SCH_CREDENTIALS](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-sch_credentials)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecPkgCred_CipherStrengths](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380101(v=vs.85))

[SecPkgCred_SupportedAlgs](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380102(v=vs.85))

[SecPkgCred_SupportedProtocols](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa380103(v=vs.85))

[SecPkgCredentials_Names](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcredentials_namesa)

## Remarks

> [!NOTE]
> The sspi.h header defines SetCredentialsAttributes as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).