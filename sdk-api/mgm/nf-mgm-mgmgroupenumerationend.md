# MgmGroupEnumerationEnd function

## Description

The
**MgmGroupEnumerationEnd** function releases the specified enumeration handle that was obtained from a previous call to
[MgmGroupEnumerationStart](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationstart).

## Parameters

### `hEnum` [in]

Specifies the enumeration handle to release.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. |
| **ERROR_INVALID_PARAMETER** | Invalid enumeration handle. |

## See also

[MgmGroupEnumerationGetNext](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationgetnext)

[MgmGroupEnumerationStart](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationstart)