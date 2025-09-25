# CRYPT_TIMESTAMP_REQUEST structure

## Description

The **CRYPT_TIMESTAMP_REQUEST** structure defines a time stamp request structure that corresponds to the [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) definition of a **TimeStampReq** type. The **CRYPT_TIMESTAMP_REQUEST** structure is used internally.

## Members

### `dwVersion`

A **DWORD** value that specifies the version of the time stamp request.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TIMESTAMP_VERSION**<br><br>1 | A version 1 time stamp request. |

### `HashAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains information about the algorithm used to calculate the hash.

### `HashedMessage`

A [CRYPT_DER_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structure that specifies the hash values to be time stamped.

### `pszTSAPolicyId`

Optional. A pointer to a null-terminated string that specifies the Time Stamping Authority (TSA) policy under which the time stamp token should be provided.

### `Nonce`

Optional. A [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the nonce value used by the client to verify the
timeliness of the response when no local clock is available.

### `fCertReq`

A Boolean value that indicates whether the TSA must include the certificates used to sign the time stamp token in the response.

### `cExtension`

The number of elements in the array pointed to by the **rgExtension** member.

### `rgExtension`

A pointer to an array of [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structures that contain extension information that is passed in the request.