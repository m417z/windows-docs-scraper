# CERT_LOGOTYPE_EXT_INFO structure

## Description

The **CERT_LOGOTYPE_EXT_INFO** structure contains a set of logotype information.

## Members

### `cCommunityLogo`

The number of elements in the **rgCommunityLogo** array.

### `rgCommunityLogo`

An array of [CERT_LOGOTYPE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_info) structures that contain the community logotypes. The **cCommunityLogo** member contains the number of elements in this array.

### `pIssuerLogo`

The address of a [CERT_LOGOTYPE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_info) structure that contains the issuer logotype. This member is optional and may be **NULL**.

### `pSubjectLogo`

The address of a [CERT_LOGOTYPE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_info) structure that contains the subject logotype. This member is optional and may be **NULL**.

### `cOtherLogo`

The number of elements in the **rgOtherLogo** array.

### `rgOtherLogo`

An array of [CERT_OTHER_LOGOTYPE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_other_logotype_info) structures that contain any other logotypes. The **cOtherLogo** member contains the number of elements in this array.

## See also

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)

[CryptEncodeObjectEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobjectex)