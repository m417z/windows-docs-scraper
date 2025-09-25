# FreeGPOListA function

## Description

The
**FreeGPOList** function frees the specified list of GPOs.

## Parameters

### `pGPOList` [in]

A pointer to the list of GPO structures. This list is returned by the
[GetGPOList](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getgpolista) or
[GetAppliedGPOList](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getappliedgpolista) function. For more information, see
[GROUP_POLICY_OBJECT](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-group_policy_objecta).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[GROUP_POLICY_OBJECT](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-group_policy_objecta)

[GetAppliedGPOList](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getappliedgpolista)

[GetGPOList](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-getgpolista)

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

## Remarks

> [!NOTE]
> The userenv.h header defines FreeGPOList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).