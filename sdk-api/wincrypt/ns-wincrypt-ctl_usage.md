# CTL_USAGE structure

## Description

The **CTL_USAGE** structure contains an array of [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs) for [Certificate Trust List](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) extensions. **CTL_USAGE** structures are used in functions that search for CTLs for specific uses.

## Members

### `cUsageIdentifier`

Number of elements in the **rgpszUsageIdentifier** member array.

### `rgpszUsageIdentifier`

Array of object identifiers (OIDs) of CTL extensions.

## See also

[CTL_FIND_USAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_find_usage_para)

[CTL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_info)

[CertFindCertificateInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindcertificateinstore)

[CertGetCertificateContextProperty](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetcertificatecontextproperty)

[CertVerifyCTLUsage](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certverifyctlusage)

[CryptDecodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptdecodeobject)

[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject)