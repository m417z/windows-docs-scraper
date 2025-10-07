# SIGNER\_CERT structure

The **SIGNER\_CERT** structure specifies a [*certificate*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) used to sign a document. The certificate can be stored in a [*Software Publisher Certificate*](https://learn.microsoft.com/windows/win32/secgloss/s-gly) (SPC) file or in a [*certificate store*](https://learn.microsoft.com/windows/win32/secgloss/c-gly).

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**cbSize**

The size, in bytes, of the structure.

**dwCertChoice**

Specifies how the certificate is stored. This member can be one or more of the following values.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **SIGNER\_CERT\_SPC\_FILE**

1 | The certificate is stored in an SPC file. The **pwszSpcFile** member contains the path and file name of the SPC file.\ | | **SIGNER\_CERT\_STORE**

2 | The certificate is stored in a certificate store. The **pCertStoreInfo** member contains a pointer to a [**SIGNER\_CERT\_STORE\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-cert-store-info) structure that specifies the certificate store in which the certificate is stored.\ | | **SIGNER\_CERT\_SPC\_CHAIN**

3 | The certificate is stored in an SPC file and is associated with a certificate chain. The **pSpcChainInfo** member contains a pointer to a [**SIGNER\_SPC\_CHAIN\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-spc-chain-info) structure that contains the chain information for the certificate.\ |

**pwszSpcFile**

A pointer to a null-terminated Unicode string that contains the path and file name of the SPC file in which the certificate is stored. This member is only used if the **dwCertChoice** member contains **SIGNER\_CERT\_SPC\_FILE**.

**pCertStoreInfo**

A pointer to a [**SIGNER\_CERT\_STORE\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-cert-store-info) structure that specifies the certificate store in which the certificate is stored. This member is only used if the **dwCertChoice** member contains **SIGNER\_CERT\_STORE**.

**pSpcChainInfo**

A pointer to a [**SIGNER\_SPC\_CHAIN\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-spc-chain-info) structure that contains the chain information for the certificate. This member is only used if the **dwCertChoice** member contains **SIGNER\_CERT\_SPC\_CHAIN**.

**hwnd**

The handle of the window to use as the owner of any dialog boxes that are displayed. This member is not currently used and is ignored.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**SignerSign**](https://learn.microsoft.com/windows/win32/seccrypto/signersign)

[**SignerSignEx**](https://learn.microsoft.com/windows/win32/seccrypto/signersignex)

