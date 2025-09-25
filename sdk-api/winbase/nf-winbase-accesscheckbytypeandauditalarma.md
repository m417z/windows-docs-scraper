# AccessCheckByTypeAndAuditAlarmA function

## Description

The **AccessCheckByTypeAndAuditAlarm** function determines whether a [security descriptor](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) grants a specified set of access rights to the client being impersonated by the calling thread. The function can check the client's access to a hierarchy of objects, such as an object, its property sets, and properties. The function grants or denies access to the hierarchy as a whole. If the security descriptor has a [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) with [access control entries](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACEs) that apply to the client, the function generates any necessary audit messages in the security event log.

Alarms are not currently supported.

## Parameters

### `SubsystemName` [in]

A pointer to a null-terminated string that specifies the name of the subsystem calling the function. This string appears in any audit message that the function generates.

### `HandleId` [in]

A pointer to a unique value that represents the client's handle to the object. If the access is denied, the system ignores this value.

### `ObjectTypeName` [in]

A pointer to a null-terminated string that specifies the type of object being created or accessed. This string appears in any audit message that the function generates.

### `ObjectName` [in, optional]

A pointer to a null-terminated string that specifies the name of the object being created or accessed. This string appears in any audit message that the function generates.

### `SecurityDescriptor` [in]

A pointer to a
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure against which access is checked.

### `PrincipalSelfSid` [in, optional]

A pointer to a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID). If the security descriptor is associated with an object that represents a principal (for example, a user object), the *PrincipalSelfSid* parameter should be the SID of the object. When evaluating access, this SID logically replaces the SID in any ACE containing the well-known PRINCIPAL_SELF SID (S-1-5-10). For information about well-known SIDs, see [Well-known SIDs](https://learn.microsoft.com/windows/desktop/SecAuthZ/well-known-sids).

If the protected object does not represent a principal, set this parameter to **NULL**.

### `DesiredAccess` [in]

An [access mask](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that specifies the access rights to check. This mask must have been mapped by the
[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask) function to contain no generic access rights.

If this parameter is MAXIMUM_ALLOWED, the function sets the *GrantedAccess* access mask to indicate the maximum access rights the security descriptor allows the client.

### `AuditType` [in]

The type of audit to be generated. This can be one of the values from the
[AUDIT_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-audit_event_type) enumeration type.

### `Flags` [in]

A flag that controls the function's behavior if the calling [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) does not have the SE_AUDIT_NAME privilege enabled. If the AUDIT_ALLOW_NO_PRIVILEGE flag is set, the function performs the access check without generating audit messages when the privilege is not enabled. If this parameter is zero, the function fails if the privilege is not enabled.

### `ObjectTypeList` [in, out, optional]

A pointer to an array of
[OBJECT_TYPE_LIST](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-object_type_list) structures that identify the hierarchy of object types for which to check access. Each element in the array specifies a GUID that identifies the object type and a value that indicates the level of the object type in the hierarchy of object types. The array should not have two elements with the same GUID.

The array must have at least one element. The first element in the array must be at level zero and identify the object itself. The array can have only one level zero element. The second element is a subobject, such as a property set, at level 1. Following each level 1 entry are subordinate entries for the level 2 through 4 subobjects. Thus, the levels for the elements in the array might be {0, 1, 2, 2, 1, 2, 3}. If the object type list is out of order, **AccessCheckByTypeAndAuditAlarm** fails and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_PARAMETER.

### `ObjectTypeListLength` [in]

The number of elements in the *ObjectTypeList* array.

### `GenericMapping` [in]

A pointer to the
[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping) structure associated with the object for which access is being checked.

### `ObjectCreation` [in]

A flag that determines whether the calling application will create a new object when access is granted. A value of **TRUE** indicates the application will create a new object. A value of **FALSE** indicates the application will open an existing object.

### `GrantedAccess` [out]

A pointer to an access mask that receives the granted access rights. If *AccessStatus* is set to **FALSE**, the function sets the access mask to zero. If the function fails, it does not set the access mask.

### `AccessStatus` [out]

A pointer to a variable that receives the results of the access check. If the security descriptor allows the requested access rights to the client, *AccessStatus* is set to **TRUE**. Otherwise, *AccessStatus* is set to **FALSE** and you can call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

### `pfGenerateOnClose` [out]

A pointer to a flag set by the audit-generation routine when the function returns. Pass this flag to the
[ObjectCloseAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-objectcloseauditalarma) function when the object handle is closed.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For more information, see the [How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object) overview.

If the *PrincipalSelfSid* and *ObjectTypeList* parameters are **NULL**, the *AuditType* parameter is *AuditEventObjectAccess*, and the *Flags* parameter is zero, **AccessCheckByTypeAndAuditAlarm** performs in the same way as the
[AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma) function.

The *ObjectTypeList* array does not necessarily represent the entire defined object. Rather, it represents that subset of the object for which to check access. For instance, to check access to two properties in a property set, specify an object type list with four elements: the object itself at level zero, the property set at level 1, and the two properties at level 2.

The **AccessCheckByTypeAndAuditAlarm** function evaluates ACEs that apply to the object itself and object-specific ACEs for the object types listed in the *ObjectTypeList* array. The function ignores object-specific ACEs for object types not listed in the *ObjectTypeList* array. Thus, the results returned in the *AccessStatus* parameter indicate the access allowed to the subset of the object defined by the *ObjectTypeList* parameter, not to the entire object.

For more information about how a hierarchy of ACEs controls access to an object and its subobjects, see
[ACEs to Control Access to an Object's Properties](https://learn.microsoft.com/windows/desktop/SecAuthZ/aces-to-control-access-to-an-object-s-properties).

To generate audit messages in the security event log, the calling process must have the SE_AUDIT_NAME privilege enabled. The system checks for this privilege in the [primary token](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) of the calling process, not the [impersonation token](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) of the thread. If the *Flags* parameter includes the AUDIT_ALLOW_NO_PRIVILEGE flag, the function performs the access check without generating audit messages when the privilege is not enabled.

The **AccessCheckByTypeAndAuditAlarm** function fails if the calling thread is not impersonating a client.

If the security descriptor does not contain owner and group SIDs, **AccessCheckByTypeAndAuditAlarm** fails with ERROR_INVALID_SECURITY_DESCR.

## See also

[AUDIT_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-audit_event_type)

[AccessCheck](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheck)

[AccessCheckAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckandauditalarma)

[AccessCheckByType](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheckbytype)

[AccessCheckByTypeResultList](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-accesscheckbytyperesultlist)

[AccessCheckByTypeResultListAndAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-accesscheckbytyperesultlistandauditalarma)

[Client/Server Access Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-server-access-control)

[Client/Server Access Control Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[GENERIC_MAPPING](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-generic_mapping)

[How AccessCheck Works](https://learn.microsoft.com/windows/desktop/SecAuthZ/how-dacls-control-access-to-an-object)

[MakeAbsoluteSD](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-makeabsolutesd)

[MapGenericMask](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-mapgenericmask)

[OBJECT_TYPE_LIST](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-object_type_list)

[ObjectCloseAuditAlarm](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-objectcloseauditalarma)

[PRIVILEGE_SET](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-privilege_set)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)