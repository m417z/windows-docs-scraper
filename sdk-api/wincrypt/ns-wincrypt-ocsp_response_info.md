# OCSP_RESPONSE_INFO structure

## Description

The **OCSP_RESPONSE_INFO** structure indicates the success or failure of the corresponding [online certificate status protocol](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OCSP) request. For successful requests, it contains the type and value of response information.

## Members

### `dwStatus`

A value that indicates the processing status of the corresponding request. If the status is anything other than **OCSP_SUCCESSFUL_RESPONSE**, **pszObjId** and **Value** are not set.

This member can be one of the following possible values.

| Value | Meaning |
| --- | --- |
| **OCSP_SUCCESSFUL_RESPONSE**<br><br>0 | The response has valid confirmations. |
| **OCSP_MALFORMED_REQUEST_RESPONSE**<br><br>1 | The request received does not conform to OCSP syntax. |
| **OCSP_INTERNAL_ERROR_RESPONSE**<br><br>2 | The responder encountered an internal error. The request should be resent to a different responder. |
| **OCSP_TRY_LATER_RESPONSE**<br><br>3 | The responder service is operational but temporarily unable to respond. |
| 4 | This value is not used. |
| **OCSP_SIG_REQUIRED_RESPONSE**<br><br>5 | Before the responder service can respond, it requires that the client sign the request. |
| **OCSP_UNAUTHORIZED_RESPONSE**<br><br>6 | The client is not authorized to request a response from this responder service. |

### `pszObjId`

A pointer to a string that identifies the type of data in **Value**.

The following table lists possible values for **pszObjId**.

| Value | Meaning |
| --- | --- |
| **szOID_PKIX_OCSP_BASIC_SIGNED_RESPONSE** | 1.3.6.1.5.5.7.48.1.1 |

### `Value`

An array of bytes that contain data encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER), as specified by **pszObjId**.

## Remarks

OCSP applications can encode or decode this structure by using **X509_ASN_ENCODING** or **PKCS_7_ASN_ENCODING**.

## See also

[OCSP_BASIC_SIGNED_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_signed_response_info)

[RFC 2560 Online Certificate Status Protocol](https://www.ietf.org/rfc/rfc2560.txt)