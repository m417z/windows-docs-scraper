# SetContextAttributesW function

## Description

Enables a transport application to set [attributes](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) of a security [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) for a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). This function is supported only by the Schannel security package.

## Parameters

### `phContext` [in]

A handle to the security context to be set.

### `ulAttribute` [in]

The attribute of the context to be set. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SECPKG_ATTR_APP_DATA**<br><br>94 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_SessionAppData](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_sessionappdata) structure.<br><br>Sets application data for the session.<br><br>This attribute is supported only by the Schannel security package. |
| **SECPKG_ATTR_EAP_PRF_INFO**<br><br>101 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_EapPrfInfo](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_eapprfinfo) structure.<br><br>Sets the pseudo-random function (PRF) used by the Extensible Authentication Protocol (EAP). This is the value that is returned by a call to the [QueryContextAttributes (Schannel)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesw) function when **SECPKG_ATTR_EAP_KEY_BLOCK** is passed as the value of the *ulAttribute* parameter.<br><br>This attribute is supported only by the Schannel security package. |
| **SECPKG_ATTR_EARLY_START**<br><br>105 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_EarlyStart](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_earlystart) structure.<br><br>Sets the False Start feature. See the [Building a faster and more secure web](https://learn.microsoft.com/windows/desktop/winmsg/windows) blog post for information on this feature. |
| **SECPKG_ATTR_DTLS_MTU**<br><br>34 | Sets and retrieves the MTU (maximum transmission unit) value for use with DTLS. If DTLS is not enabled in a security context, this attribute is not supported. <br><br>Valid values are between 200 bytes and 64 kilobytes. The default DTLS MTU value in Schannel is 1096 bytes. |
| **SECPKG_ATTR_KEYING_MATERIAL_INFO**<br><br>106 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_KeyingMaterialInfo](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_keyingmaterialinfo) structure. The keying material export feature follows the [RFC 5705 standard](https://tools.ietf.org/html/rfc5705).<br><br>This attribute is supported only by the Schannel security package in Windows 10 and Windows Server 2016 or later versions. |

### `pBuffer` [in]

A pointer to a structure that contains values to set the attributes to. The type of structure pointed to depends on the value specified in the *ulAttribute* parameter.

### `cbBuffer` [in]

The size, in bytes, of the *pBuffer* parameter.

## Return value

If the function succeeds, the function returns SEC_E_OK.

If the function fails, it returns a nonzero error code. The following error code is one of the possible error codes.

| Return code | Description |
| --- | --- |
| **SEC_E_UNSUPPORTED_FUNCTION** | This value is returned by Schannel kernel mode to indicate that this function is not supported. |

## Remarks

> [!NOTE]
> The sspi.h header defines SetContextAttributes as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).