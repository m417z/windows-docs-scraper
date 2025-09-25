# AccessCheckByType function

## Description

The **AccessCheckByType** function determines whether a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) grants a specified set of access rights to the client identified by an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). The function can check the client's access to a hierarchy of objects, such as an object, its property sets, and properties. The function grants or denies access to the hierarchy as a whole. Typically, server applications use this function to check access to a private object.

## Parameters

### `pSecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure against which access is checked.

### `PrincipalSelfSid` [in, optional]

A pointer to a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID). If the security descriptor is associated with an object that represents a principal (for example, a user object), the *PrincipalSelfSid* parameter should be the SID of the object. When evaluating access, this SID logically replaces the SID in any [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) containing the well-known PRINCIPAL_SELF SID (S-1-5-10). For information about well-known SIDs, see [Well-known SIDs](https://learn.microsoft.com/windows/desktop/SecAuthZ/well-known-sids).

Set this parameter to **NULL** if the protected object does not represent a principal.

### `ClientToken` [in]

A handle to an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) that represents the client attempting to gain access. The handle must have TOKEN_QUERY access to the token; otherwise, the function fails with ERROR_ACCESS_DENIED.

### `DesiredAccess` [in]

[Access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that specifies the access rights to check. This mask must have been mapped by the
[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask) function to contain no generic access rights.

If this parameter is MAXIMUM_ALLOWED, the function sets the *GrantedAccess* access mask to indicate the maximum access rights the security descriptor allows the client.

### `ObjectTypeList` [in, out, optional]

A pointer to an array of
[OBJECT_TYPE_LIST](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-object_type_list) structures that identify the hierarchy of object types for which to check access. Each element in the array specifies a GUID that identifies the object type and a value indicating the level of the object type in the hierarchy of object types. The array should not have two elements with the same GUID.

The array must have at least one element. The first element in the array must be at level zero and identify the object itself. The array can have only one level zero element. The second element is a subobject, such as a property set, at level 1. Following each level 1 entry are subordinate entries for the level 2 through 4 subobjects. Thus, the levels for the elements in the array might be {0, 1, 2, 2, 1, 2, 3}. If the object type list is out of order, **AccessCheckByType** fails and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_PARAMETER.

If *ObjectTypeList* is **NULL**, **AccessCheckByType** is the same as the
[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck) function.

### `ObjectTypeListLength` [in]

Specifies the number of elements in the *ObjectTypeList* array.

### `GenericMapping` [in]

A pointer to the
[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure associated with the object for which access is being checked. The **GenericAll** member of the **GENERIC_MAPPING** structure should contain all the access rights that can be granted by the resource manager, including STANDARD_RIGHTS_ALL and all of the rights that are set in the **GenericRead**, **GenericWrite**, and **GenericExecute** members.

### `PrivilegeSet` [out, optional]

A pointer to a
[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set) structure that receives the [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) used to perform the access validation. If no privileges were used, the function sets the **PrivilegeCount** member to zero.

### `PrivilegeSetLength` [in, out]

Specifies the size, in bytes, of the buffer pointed to by the *PrivilegeSet* parameter.

### `GrantedAccess` [out]

A pointer to an access mask that receives the granted access rights. If *AccessStatus* is set to **FALSE**, the function sets the access mask to zero. If the function fails, it does not set the access mask.

### `AccessStatus` [out]

A pointer to a variable that receives the results of the access check. If the security descriptor allows the requested access rights to the client identified by the access token, *AccessStatus* is set to **TRUE**. Otherwise, *AccessStatus* is set to **FALSE**, and you can call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For more information, see the [How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object) overview.

The **AccessCheckByType** function compares the specified security descriptor with the specified access token and indicates, in the *AccessStatus* parameter, whether access is granted or denied.

The *ObjectTypeList* array does not necessarily represent the entire defined object. Rather, it represents that subset of the object for which to check access. For instance, to check access to two properties in a property set, specify an object type list with four elements: the object itself at level zero, the property set at level 1, and the two properties at level 2.

The **AccessCheckByType** function evaluates ACEs that apply to the object itself and object-specific ACEs for the object types listed in the *ObjectTypeList* array. The function ignores object-specific ACEs for object types not listed in the *ObjectTypeList* array. Thus, the results returned in the *AccessStatus* parameter indicate the access allowed to the subset of the object defined by the *ObjectTypeList* parameter, not to the entire object.

For more information about how a hierarchy of ACEs controls access to an object and its subobjects, see
[ACEs to Control Access to an Object's Properties](https://learn.microsoft.com/windows/desktop/SecAuthZ/aces-to-control-access-to-an-object-s-properties).

If the security descriptor's DACL is **NULL**, the *AccessStatus* parameter returns **TRUE**, indicating that the client has the requested access.

If the security descriptor does not contain owner and group SIDs, **AccessCheckByType** fails with ERROR_INVALID_SECURITY_DESCR.

## See also

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)

[AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma)

[AccessCheckByTypeAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckbytypeandauditalarma)

[AccessCheckByTypeResultList](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheckbytyperesultlist)

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