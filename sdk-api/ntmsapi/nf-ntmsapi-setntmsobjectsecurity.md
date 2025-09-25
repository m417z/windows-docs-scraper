# SetNtmsObjectSecurity function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**SetNtmsObjectSecurity** function writes the security descriptor for the specified RSM object.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpObjectId` [in]

Unique identifier of the RSM object.

### `dwType` [in]

RSM object type. For a list of object types, see the
[NtmsObjectsTypes](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ne-ntmsapi-ntmsobjectstypes).

### `SecurityInformation` [in]

A
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) value that specifies the security information to write to the RSM object.

### `lpSecurityDescriptor` [in]

Pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that specifies the security descriptor to write to the RSM object: NTMS_USE_ACCESS, NTMS_CONTROL_ACCESS, or NTMS_MODIFY_ACCESS.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The privileges required to modify the security descriptor are denied. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_DATABASE_FULL** | The database is full. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_PARAMETER** | The object ID is missing. |
| **ERROR_NO_SECURITY_ON_OBJECT** | There is no security information for this object. |
| **ERROR_OBJECT_NOT_FOUND** | The object ID is not valid. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

If an application uses
**SetNtmsObjectSecurity** to set the discretionary access-control list (ACL) of an object, the application must have WRITE_DAC permission or be the owner of the object.

If an application uses
**SetNtmsObjectSecurity** to set the system ACL of an object, the SE_SECURITY_NAME privilege must be enabled for the application. For more information, see the [SetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setprivateobjectsecurity) function. For more information on RSM security, see
[RSM Security](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/rsm-security).

## See also

[EnumerateNtmsObject](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-enumeratentmsobject)

[GetNtmsObjectSecurity](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-getntmsobjectsecurity)

[Object Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)