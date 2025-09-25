## Description

Provides a server certificate to be used to encrypt messages to the license server.

## Parameters

### `certificate`

A **BYTE** array containing the certificate.

### `certificateSize`

The size of the array in *certificate*.

## Return value

Returns S_OK on success.

## Remarks

**SetServerCertificate** is based on the Encrypted Media Extension specification's [SetServerCertificate](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeys-setservercertificate).

## See also