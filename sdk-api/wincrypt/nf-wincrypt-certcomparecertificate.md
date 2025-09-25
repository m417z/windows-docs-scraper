# CertCompareCertificate function

## Description

The **CertCompareCertificate** function determines whether two certificates are identical by comparing the issuer name and serial number of the certificates.

**Caution** The **CertCompareCertificate** function must not be used for security assertions because it does not compare [BLOBs](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly).

## Parameters

### `dwCertEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pCertId1` [in]

A pointer to the
[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) for the first certificate in the comparison.

### `pCertId2` [in]

A pointer to the [CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info) for the second certificate in the comparison.

## Return value

If the certificates are identical and the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**).

## See also

[CERT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_info)

[CertCompareCertificateName](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcomparecertificatename)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)