# MgmGroupEnumerationStart function

## Description

The
**MgmGroupEnumerationStart** function obtains an enumeration handle that is later used to obtain the list of groups that have been joined. After the client obtains the handle, it should use the
[MgmGroupEnumerationGetNext](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationgetnext) function to enumerate the groups.

## Parameters

### `hProtocol` [in]

Handle to the protocol obtained from a previous call to
[MgmRegisterMProtocol](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmregistermprotocol).

### `metEnumType` [in]

Specifies the type of enumeration. The following enumerations are available.

| Enumeration | Meaning |
| --- | --- |
| **ALL_SOURCES** | Retrieves wildcard joins (*, g) and source-specific joins (s, g). |
| **ANY_SOURCE** | Retrieves group entries that have at least one source specified. |

### `phEnumHandle` [out]

Receives the handle to the enumeration. Use this handle in calls to
[MgmGroupEnumerationGetNext](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationgetnext) and
[MgmGroupEnumerationEnd](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationend).

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Value | Meaning |
| --- | --- |
| **ERROR_CAN_NOT_COMPLETE** | Could not complete the call to this function. |
| **ERROR_INVALID_PARAMETER** | Invalid handle to a protocol. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory to complete this operation. |

## See also

[MGM_ENUM_TYPES](https://learn.microsoft.com/windows/desktop/api/mgm/ne-mgm-mgm_enum_types)

[MgmGroupEnumerationEnd](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationend)

[MgmGroupEnumerationGetNext](https://learn.microsoft.com/windows/desktop/api/mgm/nf-mgm-mgmgroupenumerationgetnext)