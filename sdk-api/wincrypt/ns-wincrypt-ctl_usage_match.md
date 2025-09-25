# CTL_USAGE_MATCH structure

## Description

The **CTL_USAGE_MATCH** structure provides parameters for finding [certificate trust lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL) used to build a certificate chain.

## Members

### `dwType`

Determines the kind of issuer matching to be done. In **AND** logic, the certificate must meet all criteria. In **OR** logic, the certificate must meet at least one of the criteria. The following codes are defined to determine the logic used in the match.

| Value | Meaning |
| --- | --- |
| **USAGE_MATCH_TYPE_AND** | **AND** logic |
| **USAGE_MATCH_TYPE_OR** | **OR** logic |

Default usage match logic is USAGE_MATCH_TYPE_AND.

### `Usage`

[CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure that includes an array of [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs) a CTL must match in order to be valid.