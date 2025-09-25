# OCSP_BASIC_REVOKED_INFO structure

## Description

The **OCSP_BASIC_REVOKED_INFO** structure contains the reason a certificate was revoked. The [OCSP_BASIC_RESPONSE_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_response_entry) structure uses this structure.

## Members

### `RevocationDate`

Date that the certificate was revoked. For more information, see the **RevocationDate** member description for [CRL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_entry).

### `dwCrlReasonCode`

A value that specifies the reason a certificate was revoked. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRL_REASON_UNSPECIFIED**<br><br>0 | No reason was specified for revocation. |
| **CRL_REASON_KEY_COMPROMISE**<br><br>1 | It is known or suspected that the subject's [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) or other aspects of the subject validated in the certificate are compromised. |
| **CRL_REASON_CA_COMPROMISE**<br><br>2 | It is known or suspected that the [certification authority's](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA's) private key or other aspects of the CA validated in the certificate are compromised. |
| **CRL_REASON_AFFILIATION_CHANGED**<br><br>3 | The subject's name or other information in the certificate has been modified but there is no cause to suspect that the private key has been compromised. |
| **CRL_REASON_SUPERSEDED**<br><br>4 | The certificate has been superseded, but there is no cause to suspect that the private key has been compromised. |
| **CRL_REASON_CESSATION_OF_OPERATION**<br><br>5 | The certificate is no longer needed for the purpose for which it was issued, but there is no cause to suspect that the private key has been compromised. |
| **CRL_REASON_CERTIFICATE_HOLD**<br><br>6 | The certificate has been placed on hold. |
| **CRL_REASON_REMOVE_FROM_CRL**<br><br>8 | The certificate has been removed from the [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL). |

## See also

[CRL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_entry)

[OCSP_BASIC_RESPONSE_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ocsp_basic_response_entry)