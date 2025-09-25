# CRYPT_TIMESTAMP_PARA structure

## Description

The **CRYPT_TIMESTAMP_PARA** structure defines additional parameters for the time stamp request.

## Members

### `pszTSAPolicyId`

Optional. A pointer to a null-terminated character string that contains the Time Stamping Authority (TSA) policy under which the time stamp token
should be provided.

### `fRequestCerts`

A Boolean value that specifies whether the TSA must include the certificates
used to sign the time stamp token in the response .

### `Nonce`

Optional. A [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the nonce value used by the client to verify the
timeliness of the response when no local clock is available.

### `cExtension`

The number of elements in the array pointed to by the **rgExtension** member.

### `rgExtension`

A pointer to an array of [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structures that contain extension information that is passed in the request.