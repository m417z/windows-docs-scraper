# ICspAlgorithm::get_LongName

## Description

The **LongName** property retrieves the full name of the algorithm.

This property is read-only.

## Parameters

## Remarks

The [Name](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspalgorithm-get_name) property retrieves a short algorithm name. Call the **LongName** property to retrieve a more descriptive name. The names are not localized. Examples are shown in the following table.

**Note** Cryptography API: Next Generation (CNG) key storage providers (KSPs) do not support the long name concept. The **LongName** property and [Name](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspalgorithm-get_name) property return an abbreviated name.

| Algorithm OID | Name (KSP and CSP) | LongName (KSP) | LongName (CSP) |
| --- | --- | --- | --- |
| XCN_OID_OIWSEC_desCBC(1.3.14.3.2.7) | DES | DES | Data Encryption Standard (DES) |
| XCN_OID_OIWSEC_sha1(1.3.14.3.2.26) | SHA-1 | SHA-1 | Secure Hash Algorithm (SHA-1) |
| XCN_OID_RSA_MD2(1.2.840.113549.2.2) | MD2 | MD2 | Message Digest 2 (MD2) |
| XCN_OID_RSA_RC2CBC(1.2.840.113549.3.2) | RC2 | RC2 | RSA Data Security's RC2 |
| XCN_OID_ANSI_X942_DH(1.2.840.10046.2.1) | DH_KEYX | DH_KEYX | Diffie-Hellman Key Exchange Algorithm |

## See also

[ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm)