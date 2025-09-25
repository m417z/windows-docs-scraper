# CRYPT_TIMESTAMP_RESPONSE structure

## Description

The **CRYPT_TIMESTAMP_RESPONSE** structure is used internally to encapsulate an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoded response.

## Members

### `dwStatus`

A **DWORD** value that indicates the status of the time stamp response.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TIMESTAMP_STATUS_GRANTED**<br><br>0 | A TimeStampToken is present in the **ContentInfo** member. |
| **TIMESTAMP_STATUS_GRANTED_WITH_MODS**<br><br>1 | A TimeStampToken, with modifications, is present in the **ContentInfo** member. |
| **TIMESTAMP_STATUS_REJECTED**<br><br>2 | The time stamp request was rejected. |
| **TIMESTAMP_STATUS_WAITING**<br><br>3 | The time stamp request is still pending. |
| **TIMESTAMP_STATUS_REVOCATION_WARNING**<br><br>4 | The message in the **ContentInfo** member contains a warning that a revocation is imminent . |
| **TIMESTAMP_STATUS_REVOKED**<br><br>5 | The message in the **ContentInfo** member is a notification that a revocation has occurred. |

### `cFreeText`

Optional. The length, in characters, of the string pointed to by the **rgFreeText** member.

### `rgFreeText`

Optional. A pointer to a string that contains the text information about request failure.

### `FailureInfo`

A [CRYPT_BIT_BLOB](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_bit_blob) structure that contains the reason why the time stamp request was rejected. Each flag is encoded as a bit in the structure.

| Value | Meaning |
| --- | --- |
| **TIMESTAMP_FAILURE_BAD_ALG**<br><br>0 | An unrecognized or unsupported algorithm identifier was specified. |
| **TIMESTAMP_FAILURE_BAD_REQUEST**<br><br>2 | The transaction is not permitted or supported. |
| **TIMESTAMP_FAILURE_BAD_FORMAT**<br><br>5 | The data submitted is in the wrong format. |
| **TIMESTAMP_FAILURE_TIME_NOT_AVAILABLE**<br><br>14 | The Time Stamping Authority (TSA) time source is not available. |
| **TIMESTAMP_FAILURE_POLICY_NOT_SUPPORTED**<br><br>15 | The requested TSA policy is not supported by the TSA. |
| **TIMESTAMP_FAILURE_EXTENSION_NOT_SUPPORTED**<br><br>16 | The requested extension is not supported by the TSA. |
| **TIMESTAMP_FAILURE_INFO_NOT_AVAILABLE**<br><br>17 | The additional information requested was not recognized or is not available. |
| **TIMESTAMP_FAILURE_SYSTEM_FAILURE**<br><br>25 | The request cannot be handled due to a system failure. |

### `ContentInfo`

A [CRYPT_DER_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structure that encapsulates a signed data content type in Cryptographic Message Syntax (CMS) format.