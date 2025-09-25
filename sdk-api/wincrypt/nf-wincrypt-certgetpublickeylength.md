# CertGetPublicKeyLength function

## Description

The **CertGetPublicKeyLength** function acquires the bit length of public/private keys from a [public key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Parameters

### `dwCertEncodingType` [in]

Specifies the encoding type used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pPublicKey` [in]

A pointer to the [public key BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) containing the keys for which the length is being retrieved.

## Return value

Returns the length of the public/private keys in bits. If unable to determine the key's length, returns zero.

Call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to see the reason for any failures.

## See also

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)