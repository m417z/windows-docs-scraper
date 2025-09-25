# CMC_STATUS_INFO structure

## Description

The **CMC_STATUS_INFO** structure contains status information about Certificate Management Messages over CMS.

## Members

### `dwStatus`

A **DWORD** value that indicates the status of the message.

| Value | Meaning |
| --- | --- |
| **CMC_STATUS_SUCCESS**<br><br>0 | Request was granted. |
| **CMC_STATUS_FAILED**<br><br>2 | Request failed. There is addition information in other parts of the message. |
| **CMC_STATUS_PENDING**<br><br>3 | Request body part has not been processed. Requester must poll again. This value is returned only on [certificate requests](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). |
| **CMC_STATUS_NO_SUPPORT**<br><br>4 | Requested operation is not supported. |
| **CMC_STATUS_CONFIRM_REQUIRED**<br><br>5 | Confirmation by using the idConfirmCertAcceptance control is required before the certificate can be used. |

### `cBodyList`

A **DWORD** count of the elements in the **rgdwBodyList** array.

### `rgdwBodyList`

A **DWORD** array.

### `pwszStatusString`

Optional string text indicating message status.

### `dwOtherInfoChoice`

A **DWORD** value that identifies the union member to be used.

This member can be one of the following values:

* CMC_OTHER_INFO_NO_CHOICE
* CMC_OTHER_INFO_FAIL_CHOICE
* CMC_OTHER_INFO_PENDING_CHOICE

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.dwFailInfo`

A **DWORD** member of the union. This member is used if **dwOtherInfoChoice** is CMC_OTHER_INFO_FAIL_CHOICE. The following values are returned for various failures.

| Value | Meaning |
| --- | --- |
| **CMC_FAIL_BAD_ALG**<br><br>0 | Unrecognized or unsupported algorithm. |
| **CMC_FAIL_BAD_MESSAGE_CHECK**<br><br>1 | Integrity check failed. |
| **CMC_FAIL_BAD_REQUEST**<br><br>2 | Transaction not permitted or supported. |
| **CMC_FAIL_BAD_TIME**<br><br>3 | Message time field was not sufficiently close to the system time. |
| **CMC_FAIL_BAD_CERT_ID**<br><br>4 | No certificate could be identified matching the provided criteria. |
| **CMC_FAIL_UNSUPORTED_EXT**<br><br>5 | Requested X.509 extension is not supported by the recipient CA. |
| **CMC_FAIL_MUST_ARCHIVE_KEYS**<br><br>6 | Private key material must be supplied. |
| **CMC_FAIL_BAD_IDENTITY**<br><br>7 | Identification attribute failed to verify. |
| **CMC_FAIL_POP_REQUIRED**<br><br>8 | Server requires a POP proof before issuing certificate. |
| **CMC_FAIL_POP_FAILED**<br><br>9 | POP processing failed. |
| **CMC_FAIL_NO_KEY_REUSE**<br><br>10 | Server policy does not allow key re-use. |
| **CMC_FAIL_INTERNAL_CA_ERROR**<br><br>11 | [Certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) had an internal failure. |
| **CMC_FAIL_TRY_LATER**<br><br>12 | Request failed for an unknown reason. The request should be reissued later. |

### `DUMMYUNIONNAME.pPendInfo`

A pointer to the [CMC_PEND_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmc_pend_info) structure member of the union. This member is used if **dwOtherInfoChoice** is CMC_OTHER_INFO_PEND_CHOICE.

## Remarks

Additional members of the union may be defined in future versions.