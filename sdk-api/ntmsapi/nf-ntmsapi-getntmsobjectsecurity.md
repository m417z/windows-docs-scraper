# GetNtmsObjectSecurity function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**GetNtmsObjectSecurity** function reads the security descriptor for the specified RSM object.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpObjectId` [in]

Unique identifier of the RSM object.

### `dwType` [in]

Object type. For a list of object types, see
[NtmsObjectsTypes](https://learn.microsoft.com/windows/desktop/api/ntmsapi/ne-ntmsapi-ntmsobjectstypes).

### `RequestedInformation` [in]

A
[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) value that specifies the requested security data.

### `lpSecurityDescriptor` [out]

Pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that receives the security descriptor.

### `nLength` [in]

Length of the descriptor.

### `lpnLengthNeeded` [out]

Required length of the buffer if it is not large enough for the security descriptor, in bytes.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | READ_CONTROL access to the object is denied.<br><br>**Windows XP:** No access rights are required. |
| **ERROR_DATABASE_FAILURE** | The database is inaccessible or damaged. |
| **ERROR_INVALID_HANDLE** | The session handle is missing or is not valid. |
| **ERROR_INVALID_PARAMETER** | The object ID is missing. |
| **ERROR_NO_SECURITY_ON_OBJECT** | There is no security information for this object. |
| **ERROR_OBJECT_NOT_FOUND** | The object ID is not valid. |
| **ERROR_SUCCESS** | The function was successful. |

## Remarks

RSM security uses the standard security descriptors and information members. This allows the standard security dialog boxes to be used to select RSM security. For more information, see the
[SetPrivateObjectSecurity](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setprivateobjectsecurity) function. For more information on RSM security, see
[RSM Security](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/rsm-security).

## See also

[EnumerateNtmsObject](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-enumeratentmsobject)

[Object Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

[SetNtmsObjectSecurity](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-setntmsobjectsecurity)