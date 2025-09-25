# GetTrusteeFormA function

## Description

The **GetTrusteeForm** function retrieves the trustee name from the specified [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure. This value indicates whether the structure uses a name string or a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) to identify the trustee.

## Parameters

### `pTrustee` [in]

A pointer to a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure.

## Return value

The return value is one of the constants from the
[TRUSTEE_FORM](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-trustee_form) enumeration.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GetTrusteeName](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-gettrusteenamea)

[GetTrusteeType](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-gettrusteetypea)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)

[TRUSTEE_FORM](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-trustee_form)

## Remarks

> [!NOTE]
> The aclapi.h header defines GetTrusteeForm as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).