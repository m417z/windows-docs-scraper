# SIGNER\_CERT\_STORE\_INFO structure

The **SIGNER\_CERT\_STORE\_INFO** structure specifies the certificate store used to sign a document.

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**cbSize**

The size, in bytes, of the structure.

**pSigningCert**

A pointer to a [**CERT\_CONTEXT**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-cert_context) structure for the signing certificate.

**dwCertPolicy**

Specifies how certificates are added to the signature. To find the certificate chain, the MY, CA, ROOT, and SPC stores, in addition to the store specified by the **hCertStore** member, are checked. This member can be one or more of the following values.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**SIGNER\_CERT\_POLICY\_CHAIN**

2 (0x2)

| Add only certificates in the certificate chain.<br> |
|

**SIGNER\_CERT\_POLICY\_CHAIN\_NO\_ROOT**

8 (0x8)

| Add only certificates in the certificate chain, excluding the root certificate.<br> |
|

**SIGNER\_CERT\_POLICY\_STORE**

1 (0x1)

| Add all certificates in the store specified by the **hCertStore** member. This flag can be a bitwise-**OR** combination with any of the other possible values for this member.<br> |

**hCertStore**

Optional. A handle to an additional certificate store.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**SIGNER\_CERT**](https://learn.microsoft.com/windows/win32/seccrypto/signer-cert)

