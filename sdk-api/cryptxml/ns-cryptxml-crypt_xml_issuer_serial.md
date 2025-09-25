# CRYPT_XML_ISSUER_SERIAL structure

## Description

The **CRYPT_XML_ISSUER_SERIAL** structure contains an [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) issued distinguished name–serial number pair.

## Members

### `wszIssuer`

A pointer to a null-terminated wide character string that contains the issuer of the certificate.

### `wszSerial`

A pointer to a null-terminated wide character string that contains the serial number of the certificate.