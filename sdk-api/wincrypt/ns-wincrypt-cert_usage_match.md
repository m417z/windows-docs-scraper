# CERT_USAGE_MATCH structure

## Description

The **CERT_USAGE_MATCH** structure provides criteria for identifying issuer certificates to be used to build a certificate chain.

## Members

### `dwType`

Determines the kind of issuer matching to be done. In **AND** logic, the certificate must meet all criteria. In **OR** logic, the certificate must meet at least one of the criteria. The following codes are defined to determine the logic used in the match. For more information about how this applied, see Remarks.

| Value | Meaning |
| --- | --- |
| **USAGE_MATCH_TYPE_AND** | **AND** logic |
| **USAGE_MATCH_TYPE_OR** | **OR** logic |

Default usage match logic is USAGE_MATCH_TYPE_AND.

### `Usage`

[CERT_ENHKEY_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure (**CERT_ENHKEY_USAGE** is an alternate typedef name for the **CTL_USAGE** structure) that includes an array of certificate [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs) that a certificate must match in order to be valid.

## Remarks

If the *dwType* member is set to **USAGE_MATCH_TYPE_OR**, the *Usage* member cannot be empty.

If the *dwType* member is set to **USAGE_MATCH_TYPE_AND**, an empty *Usage* member means that any nested usage in the chain will work.

The following describes the behavior given two enhanced key usage (EKU) extensions EKU A and EKU B.

### AND Logic

If the caller specifies EKU A AND EKU B then the target certificate is valid if EKU A and EKU B are supported by every certificate in the path (either by an explicit EKU setting or through an absent EKU extension in CA certificates.)

### OR Logic

If the caller specifies EKU A OR EKU B then the target certificate is valid if either EKU A or EKU B is supported in the path.

 Besides the simple case where the certificates in the path contain EKU A or EKU B, the **OR** clause has the following special evaluation.

Given the following path, the **OR** test is deemed valid:

 Although the intersection of the EKUs in the chain is an empty set, the use of the EE certificate is valid for EKU A because the request to the cryptography API specifies that the certificate is valid if each certificate of the path supports either EKU A OR EKU B.