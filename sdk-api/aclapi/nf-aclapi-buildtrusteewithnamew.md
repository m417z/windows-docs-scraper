# BuildTrusteeWithNameW function

## Description

The **BuildTrusteeWithName** function initializes a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure. The caller specifies the trustee name. The function sets other members of the structure to default values.

## Parameters

### `pTrustee` [in, out]

A pointer to a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure to initialize. The **BuildTrusteeWithName** function does not allocate any memory. If this parameter is **NULL** or a pointer that is not valid, the results are undefined.

### `pName` [in, optional]

A pointer to a null-terminated string that contains the name of the trustee for the **ptstrName** member of the [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure. The **BuildTrusteeWithName** function sets the other members of the **TRUSTEE** structure as follows.

| Value | Meaning |
| --- | --- |
| ****pMultipleTrustee**** | NULL |
| ****MultipleTrusteeOperation**** | NO_MULTIPLE_TRUSTEE |
| ****TrusteeForm**** | TRUSTEE_IS_NAME |
| ****TrusteeType**** | TRUSTEE_IS_UNKNOWN |

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[BuildTrusteeWithObjectsAndName](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildtrusteewithobjectsandnamea)

[BuildTrusteeWithObjectsAndSid](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildtrusteewithobjectsandsida)

[BuildTrusteeWithSid](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-buildtrusteewithsida)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)

## Remarks

> [!NOTE]
> The aclapi.h header defines BuildTrusteeWithName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).