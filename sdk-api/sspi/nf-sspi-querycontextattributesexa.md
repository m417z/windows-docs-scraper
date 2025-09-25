# QueryContextAttributesExA function

## Description

Enables a transport application to query a [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) for certain [attributes](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) of a security [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

## Parameters

### `phContext` [in]

A handle to the security context to be queried.

### `ulAttribute` [in]

Specifies the attribute of the context to be returned. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SECPKG_ATTR_ACCESS_TOKEN**<br><br>18 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_AccessToken](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_accesstoken) structure.<br><br>Returns a handle to the access token. |
| **SECPKG_ATTR_APP_DATA**<br><br>0x5e | The *pBuffer* parameter contains a pointer to a [SecPkgContext_SessionAppData](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_sessionappdata) structure.<br><br>Returns or specifies application data for the session.<br><br>This attribute is supported only by the Schannel security package. |
| **SECPKG_ATTR_AUTHORITY**<br><br>6 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_Authority](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_authoritya) structure.<br><br>Queries the name of the authenticating authority. |
| **SECPKG_ATTR_CLIENT_SPECIFIED_TARGET**<br><br>27 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_ClientSpecifiedTarget](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_clientspecifiedtarget) structure that represents the [service principal name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SPN) of the initial target supplied by the client. <br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_ATTR_CONNECTION_INFO**<br><br>0x5a | The *pBuffer* parameter contains a pointer to a [SecPkgContext_ConnectionInfo](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_connectioninfo) structure.<br><br>Returns detailed information on the established connection.<br><br>This attribute is supported only by the Schannel security package. |
| **SECPKG_ATTR_CREDS_2**<br><br>0x80000086 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_ClientCreds](https://learn.microsoft.com/windows/desktop/api/credssp/ns-credssp-secpkgcontext_clientcreds) structure that specifies client credentials. <br><br>If the client credential is user name and password, the buffer is a packed [KERB_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_interactive_logon) structure.<br><br>If the client credential is user name and smart card PIN, the buffer is a packed [KERB_CERTIFICATE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_certificate_logon) structure.<br><br>If the client credential is an online identity credential, the buffer is a marshaled [SEC_WINNT_AUTH_IDENTITY_EX2](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_identity_ex2) structure.<br><br>This attribute is supported only on the CredSSP server.<br><br>**Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_ATTR_DCE_INFO**<br><br>3 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_DceInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_dceinfo) structure.<br><br>Queries for authorization data used by DCE services. |
| **SECPKG_ATTR_ENDPOINT_BINDINGS**<br><br>26 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_Bindings](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_bindings) structure that specifies channel binding information.<br><br>This attribute is supported only by the Schannel security package.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_ATTR_EAP_KEY_BLOCK**<br><br>0x5b | The *pBuffer* parameter contains a pointer to a [SecPkgContext_EapKeyBlock](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_eapkeyblock) structure.<br><br>Queries for key data used by the EAP TLS protocol.<br><br>This attribute is supported only by the Schannel security package. |
| **SECPKG_ATTR_FLAGS**<br><br>14 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_Flags](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_flags) structure.<br><br>Returns information about the negotiated context flags. |
| **SECPKG_ATTR_ISSUER_LIST_EX**<br><br>0x59 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_IssuerListInfoEx](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_issuerlistinfoex) structure.<br><br>Returns a list of certificate issuers that are accepted by the server.<br><br>This attribute is supported only by the Schannel security package. |
| **SECPKG_ATTR_KEY_INFO**<br><br>5 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_KeyInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_keyinfoa) structure.<br><br>Queries information about the keys used in a security context. |
| **SECPKG_ATTR_LAST_CLIENT_TOKEN_STATUS**<br><br>30 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_LastClientTokenStatus](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_lastclienttokenstatus) structure that specifies whether the token from the most recent call to the [InitializeSecurityContext](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-initializesecuritycontexta) function is the last token from the client.<br><br>This value is supported only by the Negotiate, Kerberos, and NTLM security packages.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_ATTR_LIFESPAN**<br><br>2 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_Lifespan](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_lifespan) structure.<br><br>Queries the life span of the context. |
| **SECPKG_ATTR_LOCAL_CERT_CONTEXT**<br><br>0x54 | The *pBuffer* parameter contains a pointer to a [PCCERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure.<br><br>Finds a certificate context that contains a local end certificate.<br><br>This attribute is supported only by the Schannel security package. |
| **SECPKG_ATTR_LOCAL_CRED** | The *pBuffer* parameter contains a pointer to a **SecPkgContext_LocalCredentialInfo** structure. (obsolete)<br><br>Superseded by SECPKG_ATTR_LOCAL_CERT_CONTEXT. |
| **SECPKG_ATTR_NAMES**<br><br>1 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_Names](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_namesa) structure.<br><br>Queries the name associated with the context. |
| **SECPKG_ATTR_NATIVE_NAMES**<br><br>13 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_NativeNames](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-_secpkgcontext_nativenamesa) structure.<br><br>Returns the principal name (CNAME) from the outbound ticket. |
| **SECPKG_ATTR_NEGOTIATION_INFO**<br><br>12 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_NegotiationInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_negotiationinfoa) structure.<br><br>Returns information about the security package to be used with the negotiation process and the current state of the negotiation for the use of that package. |
| **SECPKG_ATTR_PACKAGE_INFO**<br><br>10 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_PackageInfo](https://learn.microsoft.com/windows/win32/api/sspi/ns-sspi-secpkgcontext_packageinfoa) structure.<br><br>Returns information on the SSP in use. |
| **SECPKG_ATTR_PASSWORD_EXPIRY**<br><br>8 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_PasswordExpiry](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_passwordexpiry) structure.<br><br>Returns password expiration information. |
| **SECPKG_ATTR_REMOTE_CERT_CONTEXT**<br><br>0x53 | The *pBuffer* parameter contains a pointer to a [PCCERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure.<br><br>Finds a certificate context that contains the end certificate supplied by the server.<br><br>This attribute is supported only by the Schannel security package. |
| **SECPKG_ATTR_ROOT_STORE**<br><br>0x55 | The *pBuffer* parameter contains a pointer to a **HCERTCONTEXT**. Finds a certificate context that contains a certificate supplied by the Root store. |
| **SECPKG_ATTR_SESSION_KEY**<br><br>9 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_SessionKey](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_sessionkey) structure.<br><br>Returns information about the session keys. |
| **SECPKG_ATTR_SESSION_INFO**<br><br>0x5d | The *pBuffer* parameter contains a pointer to a [SecPkgContext_SessionInfo](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_sessioninfo) structure.<br><br>Returns information about the session.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported.<br><br>This attribute is supported only by the Schannel security package. |
| **SECPKG_ATTR_SIZES**<br><br>0 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_Sizes](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_sizes) structure.<br><br>Queries the sizes of the structures used in the per-message functions. |
| **SECPKG_ATTR_STREAM_SIZES**<br><br>4 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_StreamSizes](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_streamsizes) structure.<br><br>Queries the sizes of the various parts of a stream used in the per-message functions.<br><br>This attribute is supported only by the Schannel security package. |
| **SECPKG_ATTR_SUBJECT_SECURITY_ATTRIBUTES**<br><br>124 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_SubjectAttributes](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_subjectattributes) structure.<br><br>This value returns information about the security attributes for the connection.<br><br>This value is supported only on the CredSSP server.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_ATTR_SUPPORTED_SIGNATURES**<br><br>0x66 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_SupportedSignatures](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-secpkgcontext_supportedsignatures) structure.<br><br>This value returns information about the signature types that are supported for the connection.<br><br>This value is supported only by the Schannel security package.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |
| **SECPKG_ATTR_TARGET_INFORMATION**<br><br>17 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_TargetInformation](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_targetinformation) structure.<br><br>Returns information about the name of the remote server. |
| **SECPKG_ATTR_UNIQUE_BINDINGS**<br><br>25 | The *pBuffer* parameter contains a pointer to a [SecPkgContext_Bindings](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_bindings) structure that specifies channel binding information.<br><br>This value is supported only by the Schannel security package.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported. |

### `pBuffer` [out]

A pointer to a structure that receives the attributes. The type of structure pointed to depends on the value specified in the *ulAttribute* parameter.

### `cbBuffer` [in]

The size, in bytes, of the *pBuffer* parameter.

## Return value

If the function succeeds, the return value is SEC_E_OK.

If the function fails, the return value is a nonzero error code.

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[FreeContextBuffer](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-freecontextbuffer)

[SSPI Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-functions)

[SecPkgContext_Authority](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_authoritya)

[SecPkgContext_ConnectionInfo](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_connectioninfo)

[SecPkgContext_DceInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_dceinfo)

[SecPkgContext_IssuerListInfoEx](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_issuerlistinfoex)

[SecPkgContext_KeyInfo](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_keyinfoa)

[SecPkgContext_Lifespan](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_lifespan)

[SecPkgContext_Names](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_namesa)

[SecPkgContext_Sizes](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_sizes)

[SecPkgContext_StreamSizes](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-secpkgcontext_streamsizes)

## Remarks

> [!NOTE]
> The sspi.h header defines QueryContextAttributesEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).