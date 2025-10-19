# BuildTrusteeWithSidW function

## Description

The **BuildTrusteeWithSid** function initializes a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure. The caller specifies the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the trustee. The function sets other members of the structure to default values and does not look up the name associated with the SID.

## Parameters

### `pTrustee` [in, out]

A pointer to a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure to initialize. The **BuildTrusteeWithSid** function does not allocate any memory. If this parameter is **NULL** or a pointer that is not valid, the results are undefined.

### `pSid` [in, optional]

A pointer to a
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that identifies the trustee. The **BuildTrusteeWithSid** function assigns this pointer to the **ptstrName** member of the [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure. The function sets the other members of the **TRUSTEE** structure as follows.

| Value | Meaning |
| --- | --- |
| **pMultipleTrustee** | **NULL** |
| **MultipleTrusteeOperation** | NO_MULTIPLE_TRUSTEE |
| **TrusteeForm** | TRUSTEE_IS_SID |
| **TrusteeType** | TRUSTEE_IS_UNKNOWN |

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[BuildTrusteeWithName](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildtrusteewithnamea)

[BuildTrusteeWithObjectsAndName](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildtrusteewithobjectsandnamea)

[BuildTrusteeWithObjectsAndSid](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildtrusteewithobjectsandsida)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)

## Remarks

> [!NOTE]
> The aclapi.h header defines BuildTrusteeWithSid as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).