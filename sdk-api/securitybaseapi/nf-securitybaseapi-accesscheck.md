# AccessCheck function

## Description

The **AccessCheck** function determines whether a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) grants a specified set of access rights to the client identified by an [access token](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly). Typically, server applications use this function to check access to a private object.

## Parameters

### `pSecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure against which access is checked.

### `ClientToken` [in]

A handle to an [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) that represents the client that is attempting to gain access. The handle must have TOKEN_QUERY access to the token; otherwise, the function fails with ERROR_ACCESS_DENIED.

### `DesiredAccess` [in]

[Access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that specifies the access rights to check. This mask must have been mapped by the
[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask) function to contain no generic access rights.

If this parameter is MAXIMUM_ALLOWED, the function sets the *GrantedAccess* access mask to indicate the maximum access rights the [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) allows the client.

### `GenericMapping` [in]

A pointer to the
[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure associated with the object for which access is being checked.

### `PrivilegeSet` [out, optional]

A pointer to a
[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set) structure that receives the [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) used to perform the access validation. If no privileges were used, the function sets the **PrivilegeCount** member to zero.

### `PrivilegeSetLength` [in, out]

Specifies the size, in bytes, of the buffer pointed to by the *PrivilegeSet* parameter.

### `GrantedAccess` [out]

A pointer to an [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that receives the granted access rights. If *AccessStatus* is set to **FALSE**, the function sets the access mask to zero. If the function fails, it does not set the access mask.

### `AccessStatus` [out]

A pointer to a variable that receives the results of the access check. If the security descriptor allows the requested access rights to the client identified by the access token, *AccessStatus* is set to **TRUE**. Otherwise, *AccessStatus* is set to **FALSE**, and you can call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For more information, see the [How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object) overview.

The **AccessCheck** function compares the specified [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) with the specified access token and indicates, in the *AccessStatus* parameter, whether access is granted or denied. If access is granted, the requested [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) becomes the object's granted access mask.

If the security descriptor's DACL is **NULL**, the *AccessStatus* parameter returns **TRUE**, which indicates that the client has the requested access.

The **AccessCheck** function fails with ERROR_INVALID_SECURITY_DESCR if the security descriptor does not contain owner and group SIDs.

The **AccessCheck** function does not generate an audit. If your application requires audits for access checks, use functions such as [AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma), [AccessCheckByTypeAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckbytypeandauditalarma), [AccessCheckByTypeResultListAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckbytyperesultlistandauditalarma), or [AccessCheckByTypeResultListAndAuditAlarmByHandle](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckbytyperesultlistandauditalarmbyhandlea), instead of **AccessCheck**.

#### Examples

For an example that uses this function, see
[Verifying Client Access with ACLs](https://learn.microsoft.com/windows/desktop/SecAuthZ/verifying-client-access-with-acls-in-c--).

## See also

[AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma)

[AreAllAccessesGranted](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-areallaccessesgranted)

[AreAnyAccessesGranted](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-areanyaccessesgranted)

[Client/Server Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping)

[How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object)

[MakeAbsoluteSD](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-makeabsolutesd)

[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask)

[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set)

[PrivilegeCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-privilegecheck)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)