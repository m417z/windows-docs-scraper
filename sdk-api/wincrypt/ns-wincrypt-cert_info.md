# CERT_INFO structure

## Description

The **CERT_INFO** structure contains the information of a certificate.

## Members

### `dwVersion`

The version number of a certificate. This member can be one of the following version numbers.

| Value | Meaning |
| --- | --- |
| **CERT_V1** | Version 1 |
| **CERT_V2** | Version 2 |
| **CERT_V3** | Version 3 |

### `SerialNumber`

A [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that contains the serial number of a certificate. The least significant byte is the zero byte of the **pbData** member of *SerialNumber*. The index for the last byte of **pbData**, is one less than the value of the **cbData** member of *SerialNumber*. The most significant byte is the last byte of **pbData**. Leading 0x00 or 0xFF bytes are removed. For more information, see [CertCompareIntegerBlob](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcompareintegerblob).

### `SignatureAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the signature algorithm type and encoded additional encryption parameters.

### `Issuer`

The name, in encoded form, of the issuer of the certificate.

### `NotBefore`

Date and time before which the certificate is not valid. For dates between 1950 and 2049 inclusive, the date and time is encoded Coordinated Universal Time (Greenwich Mean Time) format in the form YYMMDDHHMMSS. This member uses a two-digit year and is precise to seconds. For dates before 1950 or after 2049, encoded generalized time is used. Encoded generalized time is in the form YYYYMMDDHHMMSSMMM, using a four-digit year, and is precise to milliseconds. Even though generalized time supports millisecond resolution, the **NotBefore** time is only precise to seconds.

### `NotAfter`

Date and time after which the certificate is not valid. For dates between 1950 and 2049 inclusive, the date and time is encoded Coordinated Universal Time format in the form YYMMDDHHMMSS. This member uses a two-digit year and is precise to seconds. For dates before 1950 or after 2049, encoded generalized time is used. Encoded generalized time is in the form YYYYMMDDHHMMSSMMM, using a four-digit year, and is precise to milliseconds. Even though generalized time supports millisecond resolution, the **NotAfter** time is only precise to seconds.

### `Subject`

The encoded name of the subject of the certificate.

### `SubjectPublicKeyInfo`

A [CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info) structure that contains the encoded public key and its algorithm. The **PublicKey** member of the **CERT_PUBLIC_KEY_INFO** structure contains the encoded public key as a [CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob), and the **Algorithm** member contains the encoded algorithm as a [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier).

### `IssuerUniqueId`

A BLOB that contains a unique identifier of the issuer.

### `SubjectUniqueId`

A BLOB that contains a unique identifier of the subject.

### `cExtension`

The number of elements in the **rgExtension** array.

### `rgExtension`

An array of pointers to
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structures, each of which contains extension information about the certificate.

## See also

[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension)

[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_public_key_info)

[CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info)

[CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CRYPT_VERIFY_MESSAGE_PARA](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_verify_message_para)

[CertCompareCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certcomparecertificate)

[CertGetSubjectCertificateFromStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certgetsubjectcertificatefromstore)

[CryptMsgControl](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgcontrol)

[CryptMsgGetParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsggetparam)

[CryptSignAndEncodeCertificate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsignandencodecertificate)