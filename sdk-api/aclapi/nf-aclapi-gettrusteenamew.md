# GetTrusteeNameW function

## Description

The **GetTrusteeName** function retrieves the trustee name from the specified [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure.

## Parameters

### `pTrustee` [in]

A pointer to a
[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure.

## Return value

If the **TrusteeForm** member of the [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure is TRUSTEE_IS_NAME, the return value is the pointer assigned to the **ptstrName** member of the structure.

If the **TrusteeForm** member is TRUSTEE_IS_SID, the return value is **NULL**. The function does not look up the name associated with a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID).

## Remarks

The **GetTrusteeName** function does not allocate any memory.

> [!NOTE]
> The aclapi.h header defines GetTrusteeName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Access Control Overview](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control)

[Basic Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)