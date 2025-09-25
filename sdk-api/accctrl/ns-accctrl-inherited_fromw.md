# INHERITED_FROMW structure

## Description

The **INHERITED_FROM** structure provides information about an object's inherited [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE).

## Members

### `GenerationGap`

Number of levels, or generations, between the object and the ancestor. Set this to zero for an explicit ACE. If the ancestor cannot be determined for the inherited ACE, set this member to –1.

### `AncestorName`

Name of the ancestor from which the ACE was inherited. For an explicit ACE, set this to **NULL**.

## See also

[FreeInheritedFromArray](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-freeinheritedfromarray)

[GetInheritanceSource](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getinheritancesourcea)

## Remarks

> [!NOTE]
> The accctrl.h header defines INHERITED_FROM as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).