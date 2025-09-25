# X509Certificate structure

## Description

The **X509Certificate** structure represents an [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) certificate.

## Members

### `Version`

The X.509 version number.

### `SerialNumber`

The serial number of the certificate.

### `SignatureAlgorithm`

The ID of the algorithm used to create the [digital signature](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) for the certificate.

### `ValidFrom`

The beginning of the period of validity for the certificate.

### `ValidUntil`

The end of the period of validity for the certificate.

### `pszIssuer`

A pointer to a string that specifies the issuer of the certificate.

### `pszSubject`

A pointer to a string that specifies the subject of the certificate.

### `pPublicKey`

A pointer to the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) used to create the signature for the certificate.