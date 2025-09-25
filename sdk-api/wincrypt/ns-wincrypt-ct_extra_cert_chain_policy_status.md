## Description

Contains extra error information about the status of a Certificate Transparency chain policy check.

## Members

### `cbSize`

The size of the structure, in bytes.

### `lErrorStatus`

The error status of the certificate chain policy.

| Value | Description |
|--------|--------------------------------------------------------------------------|
| `> 0` | Warning - These errors can be ignored. Will map to **S_FALSE**. |
| `== 0` | Success - Will map to **S_OK**. |
| `< 0 ` | Fatal error - These errors shouldn't be ignored. Will map to **E_FAIL**. |

See [Remarks](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-ct_extra_cert_chain_policy_status#remarks) for more information.

### `lErrorSubStatus`

The substatus of the certificate chain policy. Depends on **lErrorStatus**. Can override **lErrorStatus**.

See [Remarks](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-ct_extra_cert_chain_policy_status#remarks) for more information.

### `cEntries`

The number of SCT entries in the certificate chain.

### `cValidated`

Indicates the number of SCT entries that have been successfully validated in the certificate chain.

## Remarks

The following values are possible **lErrorStatus** and **lErrorSubStatus** fields:

| Value | Description |
|-------|-------------|
| **CERT_CHAIN_POLICY_CT_ERROR_UNDECODABLE_SCT_EXTENSION**<br>`-112` | SCT extension could not be ASN.1 decoded (invalid syntax or not supported). |
| **CERT_CHAIN_POLICY_CT_ERROR_UNRETRIEVABLE_SCT_EXTENSION**<br>`-111` | SCT extension could not be retrieved. |
| **CERT_CHAIN_POLICY_CT_ERROR_MISSING_SCT_EXTENSION**<br>`-110` | SCT extension is missing. |
| **CERT_CHAIN_POLICY_CT_ERROR_INVALID_ISSUER_CERT**<br>`-101` | The issuer cert could not be converted to the proper format (invalid syntax). |
| **CERT_CHAIN_POLICY_CT_ERROR_INVALID_SUBJECT_CERT**<br>`-100` | The subject cert could not be converted to the proper format (invalid syntax). |
| **CERT_CHAIN_POLICY_CT_ERROR_SCT_VALIDATION_STATUS_INSUFFICIENT**<br>`-4` | One or more SCTs were validated but the total valid amount required to pass the CT policy check was not met. |
| **CERT_CHAIN_POLICY_CT_ERROR_SCT_VALIDATION_STATUS_UNKNOWN_VERSION**<br>`-3` | The SCT is of an unsupported version (only v1 is supported). |
| **CERT_CHAIN_POLICY_CT_ERROR_SCT_VALIDATION_STATUS_UNKNOWN_LOG**<br>`-2` | The SCT was issued by a log that was not in the CT Log Store. |
| **CERT_CHAIN_POLICY_CT_ERROR_SCT_VALIDATION_STATUS_INVALID**<br>`-1` | The SCT's signature is incorrect, its timestamp is in the future), or if it is otherwise invalid. |
| **CERT_CHAIN_POLICY_CT_SUCCESS_SCT_VALIDIDATION_STATUS_VALID**<br>`0` | The amount of valid SCTs required to pass the CT policy check was met. |

## See also

[CERT_CHAIN_POLICY_STATUS](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_chain_policy_status)