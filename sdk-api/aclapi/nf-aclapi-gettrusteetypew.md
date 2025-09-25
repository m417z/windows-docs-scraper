# GetTrusteeTypeW function

## Description

The **GetTrusteeType** function retrieves the trustee type from the specified [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure. This value indicates whether the trustee is a user, a group, or the trustee type is unknown.

## Parameters

### `pTrustee` [in, optional]

A pointer to a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure.

## Return value

The return value is one of the constants from the [TRUSTEE_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-trustee_type) enumeration.

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)

[TRUSTEE_TYPE](https://learn.microsoft.com/windows/desktop/api/accctrl/ne-accctrl-trustee_type)

## Remarks

> [!NOTE]
> The aclapi.h header defines GetTrusteeType as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).