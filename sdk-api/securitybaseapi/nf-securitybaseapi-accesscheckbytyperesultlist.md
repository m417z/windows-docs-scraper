# AccessCheckByTypeResultList function

## Description

The **AccessCheckByTypeResultList** function determines whether a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) grants a specified set of access rights to the client identified by an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). The function can check the client's access to a hierarchy of objects, such as an object, its property sets, and properties. The function reports the access rights granted or denied to each object type in the hierarchy. Typically, server applications use this function to check access to a private object.

## Parameters

### `pSecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure against which access is checked.

### `PrincipalSelfSid` [in, optional]

A pointer to a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID). If the security descriptor is associated with an object that represents a principal (for example, a user object), the *PrincipalSelfSid* parameter should be the SID of the object. When evaluating access, this SID logically replaces the SID in any [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) that contains the well-known PRINCIPAL_SELF SID (S-1-5-10). For information about well-known SIDs, see [Well-known SIDs](https://learn.microsoft.com/windows/desktop/SecAuthZ/well-known-sids).

If the protected object does not represent a principal, set this parameter to **NULL**.

### `ClientToken` [in]

A handle to an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) that represents the client attempting to gain access. The handle must have TOKEN_QUERY access to the token; otherwise, the function fails with ERROR_ACCESS_DENIED.

### `DesiredAccess` [in]

An [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that specifies the access rights to check. This mask must have been mapped by the
[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask) function to contain no generic access rights.

If this parameter is MAXIMUM_ALLOWED, the function sets the access masks in the *GrantedAccess* array to indicate the client's maximum access rights to each element in the object type list.

### `ObjectTypeList` [in, out, optional]

A pointer to an array of
[OBJECT_TYPE_LIST](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-object_type_list) structures that identify the hierarchy of object types for which to check access. Each element in the array specifies a GUID that identifies the object type and a value that indicates the level of the object type in the hierarchy of object types. The array should not have two elements with the same GUID.

The array must have at least one element. The first element in the array must be at level zero and identify the object itself. The array can have only one level zero element. The second element is a subobject, such as a property set, at level 1. Following each level 1 entry are subordinate entries for the level 2 through 4 subobjects. Thus, the levels for the elements in the array might be {0, 1, 2, 2, 1, 2, 3}. If the object type list is out of order, **AccessCheckByTypeResultList** fails and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_PARAMETER.

### `ObjectTypeListLength` [in]

The number of elements in the *ObjectTypeList* array. This is also the number of elements in the arrays pointed to by the *GrantedAccessList* and *AccessStatusList* parameters.

### `GenericMapping` [out]

A pointer to the
[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure associated with the object for which access is being checked.

### `PrivilegeSet` [out, optional]

A pointer to a
[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set) structure that receives the [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) used to perform the access validation. If no privileges were used, the function sets the **PrivilegeCount** member to zero.

### `PrivilegeSetLength` [in, out]

The size, in bytes, of the buffer pointed to by the *PrivilegeSet* parameter.

### `GrantedAccessList` [out]

A pointer to an array of access masks. The function sets each access mask to indicate the access rights granted to the corresponding element in the object type list. If the function fails, it does not set the access masks.

### `AccessStatusList` [out]

A pointer to an array of status codes for the corresponding elements in the object type list. The function sets an element to zero to indicate success or a nonzero value to indicate the specific error during the access check. If the function fails, it does not set any of the elements in the array.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For more information, see the [How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object) overview.

The **AccessCheckByTypeResultList** function compares the specified security descriptor with the specified [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) and indicates, in the *AccessStatusList* parameter, whether access is granted or denied for each of the elements in the object types list.

The *ObjectTypeList* array does not necessarily represent the entire defined object. Rather, it represents that subset of the object for which to check access. For instance, to check access to two properties in a property set, specify an object type list with four elements: the object itself at level zero, the property set at level 1, and the two properties at level 2.

The **AccessCheckByTypeResultList** function evaluates ACEs that apply to the object itself and object-specific ACEs for the object types listed in the *ObjectTypeList* array. The function ignores object-specific ACEs for object types not listed in the *ObjectTypeList* array. Thus, the results returned for element zero in the *AccessStatusList* parameter indicate the access allowed to the subset of the object defined by the *ObjectTypeList* parameter, not to the entire object.

For more information about how a hierarchy of ACEs controls access to an object and its subobjects, see
[ACEs to Control Access to an Object's Properties](https://learn.microsoft.com/windows/desktop/SecAuthZ/aces-to-control-access-to-an-object-s-properties).

If the security descriptor's [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL) is **NULL**, the function grants the requested access to all of the elements in the object type list.

If the security descriptor does not contain owner and group SIDs, **AccessCheckByTypeResultList** fails with ERROR_INVALID_SECURITY_DESCR.

## See also

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)

[AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma)

[AccessCheckByType](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheckbytype)

[AccessCheckByTypeAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckbytypeandauditalarma)

[AccessCheckByTypeResultListAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckbytyperesultlistandauditalarma)

[Client/Server Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping)

[How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object)

[MakeAbsoluteSD](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-makeabsolutesd)

[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask)

[OBJECT_TYPE_LIST](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-object_type_list)

[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)