# CRYPT_TIMESTAMP_INFO structure

## Description

The **CRYPT_TIMESTAMP_INFO** structure contains a signed data content type in Cryptographic Message Syntax (CMS) format.

## Members

### `dwVersion`

A **DWORD** value that specifies the version of the time stamp request.

| Value | Meaning |
| --- | --- |
| **TIMESTAMP_VERSION**<br><br>1 | Specifies that this is a version 1 time stamp request. |

### `pszTSAPolicyId`

Optional. A pointer to a null-terminated string that specifies the Time Stamping Authority (TSA) policy under which the time stamp token was provided. This value must correspond with the value passed in the [CRYPT_TIMESTAMP_REQUEST](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_timestamp_request) structure.

### `HashAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains information about the algorithm used to calculate the hash. This value must correspond with the value passed in the [CRYPT_TIMESTAMP_REQUEST](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_timestamp_request) structure.

### `HashedMessage`

A [CRYPT_DER_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structure that specifies the hash values to be time stamped.

### `SerialNumber`

 A [CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the serial number assigned by the TSA to each time stamp token.

### `ftTime`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) value that specifies the time at which the time stamp token was produced by the TSA.

### `pvAccuracy`

Optional. A pointer to a [CRYPT_TIMESTAMP_ACCURACY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_timestamp_accuracy) structure that contains the time deviation around the UTC time at which the time stamp token was created by the TSA.

### `fOrdering`

This member is reserved.

### `Nonce`

Optional. A [CRYPT_DER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the nonce value used by the client to verify the
timeliness of the response when no local clock is available. This value must correspond with the value passed in the [CRYPT_TIMESTAMP_REQUEST](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_timestamp_request) structure.

### `Tsa`

Optional. A [CRYPT_DER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the subject name of the TSA certificate.

### `cExtension`

The number of elements in the array pointed to by the **rgExtension** member.

### `rgExtension`

A pointer to an array of [CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structures that contain extension information returned from the request.