# CERT_SELECT_CRITERIA structure

## Description

The **CERT_SELECT_CRITERIA** structure specifies selection criteria that is passed to the [CertSelectCertificateChains](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certselectcertificatechains) function.

## Members

### `dwType`

Specifies the type of selection criteria used for the **ppPara** member. This member can have one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_SELECT_BY_ENHKEY_USAGE**<br><br>1 | Select certificates based on a specific [enhanced key usage](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly). When this flag is set, the *ppPara* must reference a null-terminated [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) ANSI string that specifies the enhanced key usage.<br><br>This criteria is evaluated on the [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). |
| **CERT_SELECT_BY_KEY_USAGE**<br><br>2 | Select certificates based on a specific **szOID_KEY_USAGE** extension in the certificate. When this flag is set, the **ppPara**  member must reference a [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structure where the value of the extension is a **DWORD** that identifies the Key Usage bits.<br><br>This criteria is evaluated on the certificate. |
| **CERT_SELECT_BY_POLICY_OID**<br><br>3 | Select certificates based on a specific issuance policy. The **ppPara** member must reference a null-terminated OID ANSI string of the desired issuance policy.<br><br>This criteria is evaluated on the issuance policy of the certificate chain. |
| **CERT_SELECT_BY_PROV_NAME**<br><br>4 | Select certificates based on a specific [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) provider. The **ppPara** member must reference a null-terminated Unicode string that represents the name of the provider. |
| **CERT_SELECT_BY_EXTENSION**<br><br>5 | Select certificates based on the presence of a specified extension and an optional specified value. The **ppPara** member must reference a [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structure that specifies the extension OID and the associated value. |
| **CERT_SELECT_BY_SUBJECT_HOST_NAME**<br><br>6 | Select certificates based on the Subject DNS HOST Name. The **ppPara** member must reference a null-terminated Unicode string that contains the subject host name. The selection performed based on this flag is the same as the evaluation of the **pwszServerName** member of the [SSL_EXTRA_CERT_CHAIN_POLICY_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-httpspolicycallbackdata) structure during a call to the [CertVerifyCertificateChainPolicy](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifycertificatechainpolicy) function. <br><br>This criteria is evaluated on the certificate. |
| **CERT_SELECT_BY_ISSUER_ATTR**<br><br>7 | Select certificates based on the [relative distinguished name](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) (RDN) element of the issuer of the certificate. The **ppPara** member must reference a [CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) structure that contains the RDN element of the issuer.<br><br>This criteria is evaluated on the certificate chain. |
| **CERT_SELECT_BY_SUBJECT_ATTR**<br><br>8 | Select certificates based on the RDN element in the Subject of the certificate. The **ppPara** member must be a reference to a [CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) structure that contains the RDN element of the Subject.<br><br>This criteria is evaluated on the certificate. |
| **CERT_SELECT_BY_ISSUER_NAME**<br><br>9 | Select certificates based on the issuer of the certificate. The **ppPara** member must be a reference to a [CERT_NAME_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structure that contains the name of the issuer.<br><br>This criteria is evaluated on the certificate chain. |
| **CERT_SELECT_BY_PUBLIC_KEY**<br><br>10 | Select certificates based on the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of the certificate. The **ppPara** member must reference a pointer to a [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure that contains the public key.<br><br>This criteria is evaluated on the certificate. |
| **CERT_SELECT_BY_TLS_SIGNATURES**<br><br>11 | Select certificates based on the [Transport Layer Security protocol](https://learn.microsoft.com/windows/win32/api/schannel/ns-schannel-secpkgcontext_supportedsignatures) (TLS) Signature requirement. The **ppPara** member must reference a [SecPkgContext_SupportedSignatures](https://learn.microsoft.com/windows/desktop/api/schannel/ns-schannel-secpkgcontext_supportedsignatures) structure.<br><br>This criteria is evaluated on the certificate. |

### `cPara`

A **DWORD** value that specifies the number of search attributes specified in the **ppPara** member.

### `ppPara`

A pointer to a pointer to one or more selection values. The data type depends on the selection type specified by the **dwType** member. If more than one selection value is present, an application must match only one value.