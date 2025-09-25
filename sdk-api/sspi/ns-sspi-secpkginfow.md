# SecPkgInfoW structure

## Description

The **SecPkgInfo** structure provides general information about a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly), such as its name and capabilities.

## Members

### `fCapabilities`

Set of bit flags that describes the capabilities of the security package. This member can be a combination of the following flags.

| Value | Meaning |
| --- | --- |
| **SECPKG_FLAG_INTEGRITY**<br><br>0x1 | The security package supports the [MakeSignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-makesignature) and [VerifySignature](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-verifysignature) functions. |
| **SECPKG_FLAG_PRIVACY**<br><br>0x2 | The security package supports the [EncryptMessage (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-encryptmessage) and [DecryptMessage (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-decryptmessage) functions. |
| **SECPKG_FLAG_TOKEN_ONLY**<br><br>0x4 | The package is interested only in the security-token portion of messages, and will ignore any other buffers. This is a performance-related issue. |
| **SECPKG_FLAG_DATAGRAM**<br><br>0x8 | Supports [datagram](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly)-style authentication. For more information, see [SSPI Context Semantics](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi-context-semantics).<br><br>**Important** The [Microsoft Kerberos](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-kerberos) package does not support datagram contexts in user-to-user mode. |
| **SECPKG_FLAG_CONNECTION**<br><br>0x10 | Supports connection-oriented style authentication. For more information, see [SSPI Context Semantics](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi-context-semantics). |
| **SECPKG_FLAG_MULTI_REQUIRED**<br><br>0x20 | Multiple legs are required for authentication. |
| **SECPKG_FLAG_CLIENT_ONLY**<br><br>0x40 | Server authentication support is not provided. |
| **SECPKG_FLAG_EXTENDED_ERROR**<br><br>0x80 | Supports extended error handling. For more information, see [Extended Error Information](https://learn.microsoft.com/windows/desktop/SecAuthN/extended-error-information). |
| **SECPKG_FLAG_IMPERSONATION**<br><br>0x100 | Supports Windows impersonation in server contexts. |
| **SECPKG_FLAG_ACCEPT_WIN32_NAME**<br><br>0x200 | Understands Windows principal and target names. |
| **SECPKG_FLAG_STREAM**<br><br>0x400 | Supports stream semantics. For more information, see [SSPI Context Semantics](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi-context-semantics). |
| **SECPKG_FLAG_NEGOTIABLE**<br><br>0X800 | Can be used by the [Microsoft Negotiate](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-negotiate) security package. |
| **SECPKG_FLAG_GSS_COMPATIBLE**<br><br>0x1000 | Supports GSS compatibility. |
| **SECPKG_FLAG_LOGON**<br><br>0x2000 | Supports [LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser). |
| **SECPKG_FLAG_ASCII_BUFFERS**<br><br>0x4000 | Token buffers are in ASCII characters format. |
| **SECPKG_FLAG_FRAGMENT**<br><br>0x8000 | Supports separating large tokens into smaller buffers so that applications can make repeated calls to [InitializeSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) and [AcceptSecurityContext (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-acceptsecuritycontext) with the smaller buffers to complete authentication. |
| **SECPKG_FLAG_MUTUAL_AUTH**<br><br>0x10000 | Supports mutual authentication. |
| **SECPKG_FLAG_DELEGATION**<br><br>0x20000 | Supports delegation. |
| **SECPKG_FLAG_READONLY_WITH_CHECKSUM**<br><br>0x40000 | The security package supports using a checksum instead of in-place encryption when calling the [EncryptMessage](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-encryptmessage) function. |
| **SECPKG_FLAG_RESTRICTED_TOKENS**<br><br>0x80000 | Supports callers with restricted tokens. |
| **SECPKG_FLAG_NEGO_EXTENDER**<br><br>0x00100000 | The security package extends the [Microsoft Negotiate](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-negotiate) security package. There can be at most one package of this type. |
| **SECPKG_FLAG_NEGOTIABLE2**<br><br>0x00200000 | This package is negotiated by the package of type **SECPKG_FLAG_NEGO_EXTENDER**. |
| **SECPKG_FLAG_APPCONTAINER_PASSTHROUGH**<br><br>0x00400000 | This package receives all calls from app container apps. |
| **SECPKG_FLAG_APPCONTAINER_CHECKS**<br><br>0x00800000 | This package receives calls from app container apps if one of the following checks succeeds. <br><br>* Caller has default credentials capability.<br>* The target is a proxy server.<br>* The caller has supplied credentials. |
| **SECPKG_CALLFLAGS_APPCONTAINER**<br><br>0x00000001 | The caller is an app container. |
| **SECPKG_CALLFLAGS_AUTHCAPABLE**<br><br>0x00000002 | The caller can use default credentials. |
| **SECPKG_CALLFLAGS_FORCE_SUPPLIED**<br><br>0x00000004 | The caller can only use supplied credentials. |

### `wVersion`

Specifies the version of the package protocol. Must be 1.

### `wRPCID`

Specifies a DCE RPC identifier, if appropriate. If the package does not implement one of the DCE registered security systems, the reserved value SECPKG_ID_NONE is used.

### `cbMaxToken`

Specifies the maximum size, in bytes, of the token.

### `Name`

Pointer to a null-terminated string that contains the name of the security package.

### `Name.string`

### `Comment`

Pointer to a null-terminated string. This can be any additional string passed back by the package.

### `Comment.string`

## See also

[EnumerateSecurityPackages](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-enumeratesecuritypackagesa)

[QuerySecurityPackageInfo](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querysecuritypackageinfoa)

## Remarks

> [!NOTE]
> The sspi.h header defines SecPkgInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).