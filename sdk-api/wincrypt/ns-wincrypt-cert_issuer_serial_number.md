# CERT_ISSUER_SERIAL_NUMBER structure

## Description

The **CERT_ISSUER_SERIAL_NUMBER** structure acts as a unique identifier of a certificate containing the issuer and issuer's serial number for a certificate.

## Members

### `Issuer`

A [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) structure that contains the name of the issuer.

### `SerialNumber`

A [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the serial number of the certificate. The combination of the issuer name and the serial number is a unique identifier of a certificate.