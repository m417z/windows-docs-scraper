# CERT_EXTENSION structure

## Description

The **CERT_EXTENSION** structure contains the extension information for a [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), [Certificate Revocation List](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) or [Certificate Trust List](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL).

## Members

### `pszObjId`

[Object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) that specifies the structure of the extension data contained in the **Value** member. For specifics on extension OIDs and their related structures, see
[X.509 Certificate Extension Structures](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-structures).

### `fCritical`

If **TRUE**, any limitations specified by the extension in the **Value** member of this structure are imperative. If **FALSE**, limitations set by this extension can be ignored.

### `Value`

A
[CRYPT_OBJID_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the encoded extension data. The **cbData** member of **Value** indicates the length in bytes of the **pbData** member. The **pbData** member byte string is the encoded extension.

## See also

[CERT_EXTENSIONS](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extensions)

[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info)

[CRL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_entry)

[CRL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_info)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CTL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_entry)

[CTL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_info)

[CertFindExtension](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindextension)