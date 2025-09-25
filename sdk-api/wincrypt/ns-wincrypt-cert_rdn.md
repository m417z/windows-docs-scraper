# CERT_RDN structure

## Description

The **CERT_RDN** structure contains a [relative distinguished name](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) (RDN) consisting of an array of
[CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr) structures.

## Members

### `cRDNAttr`

Number of elements in the **rgRDNAttr** array.

### `rgRDNAttr`

Array of
[CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr) structures.

## See also

[CERT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_name_info)

[CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr)

[CertFindCertificateInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindcertificateinstore)

[CertIsRDNAttrsInCertificateName](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certisrdnattrsincertificatename)

[CertNameToStr](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certnametostra)