# RsopAccessCheckByType function

## Description

The
**RSoPAccessCheckByType** function determines whether a security descriptor grants a specified set of access rights to the client identified by an **RSOPTOKEN**.

## Parameters

### `pSecurityDescriptor` [in]

Pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) against which access on the object is checked.

### `pPrincipalSelfSid` [in]

Pointer to a SID. If the security descriptor is associated with an object that represents a principal (for example, a user object), this parameter should be the SID of the object. When evaluating access, this SID logically replaces the SID in any ACE containing the well-known **PRINCIPAL_SELF** SID ("S-1-5-10"). For more information, see
[Security Identifiers](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-identifiers) and
[Well-Known SIDs](https://learn.microsoft.com/windows/desktop/SecAuthZ/well-known-sids).

This parameter should be **NULL** if the protected object does not represent a principal.

### `pRsopToken` [in]

Pointer to a valid **RSOPTOKEN** representing the client attempting to gain access to the object.

### `dwDesiredAccessMask` [in]

Specifies an access mask that indicates the access rights to check. This mask can contain a combination of
[generic](https://learn.microsoft.com/windows/desktop/SecAuthZ/generic-access-rights),
[standard](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights) and specific access rights. For more information, see
[Access Rights and Access Masks](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-and-access-masks).

### `pObjectTypeList` [in]

Pointer to an array of
[OBJECT_TYPE_LIST](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-object_type_list) structures that identify the hierarchy of object types for which to check access. Each element in the array specifies a **GUID** that identifies the object type and a value indicating the level of the object type in the hierarchy of object types. The array should not have two elements with the same **GUID**.

The array must have at least one element. The first element in the array must be at level zero and identify the object itself. The array can have only one level zero element. The second element is a subobject, such as a property set, at level 1. Following each level 1 entry are subordinate entries for the level 2 through 4 subobjects. Thus, the levels for the elements in the array might be {0, 1, 2, 2, 1, 2, 3}. If the object type list is out of order,
**RSoPAccessCheckByType** fails and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INVALID_PARAMETER**.

### `ObjectTypeListLength` [in]

Specifies the number of elements in the *pObjectTypeList* array.

### `pGenericMapping` [in]

Pointer to the
[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure associated with the object for which access is being checked.

### `pPrivilegeSet` [in]

This parameter is currently unused.

### `pdwPrivilegeSetLength` [in]

This parameter is currently unused.

### `pdwGrantedAccessMask` [out]

Pointer to an
[access mask](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-and-access-masks) that receives the granted access rights.

If the function succeeds, the *pbAccessStatus* parameter is set to **TRUE**, and the mask is updated to contain the standard and specific rights granted. If *pbAccessStatus* is set to **FALSE**, this parameter is set to zero. If the function fails, the mask is not modified.

### `pbAccessStatus` [out]

Pointer to a variable that receives the results of the access check.

If the function succeeds, and the requested set of access rights are granted, this parameter is set to **TRUE**. Otherwise, this parameter is set to **FALSE**. If the function fails, the status is not modified.

## Return value

If the function succeeds, the return value is **S_OK**. Otherwise, the function returns one of the COM error codes defined in the Platform SDK header file WinError.h.

## Remarks

The
**RSoPAccessCheckByType** function compares the specified security descriptor with the specified **RSOPTOKEN** and indicates, in the *pbAccessStatus* parameter, whether access is granted or denied.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[RSoPFileAccessCheck](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-rsopfileaccesscheck)