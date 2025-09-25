# POLICY_MODIFICATION_INFO structure

## Description

The **POLICY_MODIFICATION_INFO** structure is used to query information about the creation time and last modification of the LSA database. The
[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy) function uses this structure when its *InformationClass* parameter is set to PolicyModificationInformation.

## Members

### `ModifiedId`

A
[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) structure containing a 64-bit unsigned integer that is incremented each time anything in the LSA database is modified. This value is modified only on primary domain controllers.

### `DatabaseCreationTime`

A [LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) structure that indicates the date and time the LSA database was created. This is a UTC-based time that uses the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) format. On backup domain controllers, this value is replicated from the primary domain controller. For more information about UTC-based time, see
[System Time](https://learn.microsoft.com/windows/desktop/SysInfo/system-time).

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy)

[LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy)

[POLICY_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_information_class)