# CertIsRDNAttrsInCertificateName function

## Description

The **CertIsRDNAttrsInCertificateName** function compares the attributes in the [certificate name](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) with the specified
[CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) to determine whether all attributes are included there. The comparison iterates through the **CERT_RDN** and looks for an attribute match in any of the **CERT_RDN**s of the certificate name.

## Parameters

### `dwCertEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING

Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `dwFlags` [in]

CERT_UNICODE_IS_RDN_ATTRS_FLAG must be set if the *pRDN* was initialized with Unicode strings as in
[CryptEncodeObject](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptencodeobject) with *lpszStructType* set to X509_UNICODE_NAME.

CERT_CASE_INSENSITIVE_IS_RDN_ATTRS_FLAG is set to do a case insensitive match. Otherwise, an exact, case sensitive match is done.

### `pCertName` [in]

A pointer to a
[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains the encoded subject or issuer name.

### `pRDN` [in]

Array of
[CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) structures that contain the attributes to be found in the name. The
[CERT_RDN_ATTR](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn_attr) member of the **CERT_RDN** structure behaves according to the following rules.

* If **pszObjId** is **NULL**, the attribute [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) is ignored.
* If **dwValueType** is CERT_RDN_ANY_TYPE, the value type is ignored.
* If the **pbData** member of **Value** is **NULL**, any value can be a match.

## Return value

If the function succeeds and all of the RDN values in the specified [CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) are in the certificate name, the return value is nonzero (**TRUE**).

If the function fails, or if there are RDN values in the specified [CERT_RDN](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_rdn) that are not in the certificate name, the return value is zero (**FALSE**). For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following table lists some possible error codes.

| Return code | Description |
| --- | --- |
| **CRYPT_E_NO_MATCH** | Not all the attributes were found and matched. |
| **ERROR_FILE_NOT_FOUND** | Invalid certificate encoding type. Currently only X509_ASN_ENCODING is supported. |

If the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) may return an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoding/decoding error. For information about these errors, see
[ASN.1 Encoding/Decoding Return Values](https://learn.microsoft.com/windows/desktop/SecCrypto/asn-1-encoding-decoding-return-values).

## Remarks

Currently, only an exact, case-sensitive match is supported.

## See also

[CertFindCertificateInStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfindcertificateinstore)

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)