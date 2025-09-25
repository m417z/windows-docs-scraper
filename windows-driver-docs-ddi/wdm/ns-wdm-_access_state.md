# _ACCESS_STATE structure

## Description

The ACCESS_STATE structure describes the state of an access in progress. It contains an object's subject context, remaining desired access types, granted access types, and, optionally, a privilege set to indicate which privileges were used to permit the access.

Drivers are not to modify the ACCESS_STATE structure directly. To create and manipulate this structure, use the support routines listed in the See Also section.

## Members

### `OperationID`

The identifier of the operation that this access relates to. This member is replaced by TransactionId in the **AuxData** member and is currently unused by drivers.

### `SecurityEvaluated`

A Boolean value that specifies whether security was evaluated as part of the access check. This member is currently unused by drivers.

### `GenerateAudit`

A Boolean value that specifies whether the access should generate an audit. This member is currently unused by drivers.

### `GenerateOnClose`

A Boolean value that specifies whether an audit should be generated when the handle being created is closed. This member is currently unused by drivers.

### `PrivilegesAllocated`

A Boolean value that specifies whether privileges were allocated as part of the access check. This member is currently unused by drivers.

### `Flags`

A 32-bit value that contains bit-field flags for the access. A driver can check for the traverse access flag (TOKEN_HAS_TRAVERSE_PRIVILEGE). For more information about how to check for traverse access, see [Check for Traverse Privilege on IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/checking-for-traverse-privilege-on-irp-mj-create). A driver can also check for the TOKEN_IS_RESTRICTED flag. These flags are defined in Ntifs.h.

### `RemainingDesiredAccess`

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) type that describes the access rights that have not yet been granted to the caller. A driver uses this member to determine if the Windows security system can grant access. If access can be granted, the driver updates the **PreviouslyGrantedAccess** and **RemainingDesiredAccess** members accordingly.

### `PreviouslyGrantedAccess`

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) type that specifies the information about access that has already been granted to the caller of one of the [Security Reference Monitor Routines](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff563711(v=vs.85)). The Windows security system grants certain rights based on the privileges of the caller, such as traverse right (the ability to traverse through a directory as part of opening a subdirectory or file).

### `OriginalDesiredAccess`

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) type that contains the original access rights that were requested by the caller.

### `SubjectSecurityContext`

A [SECURITY_SUBJECT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that contains information about the subject security context that is used to validate and audit access.

### `SecurityDescriptor`

A pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure that contains security information for the object that this access relates to.

### `AuxData`

A pointer to a memory block that contains auxiliary data for the access.

### `Privileges`

A union that can contain one of the following structures. This union allows three privileges to be embedded in the access state structure. If any more privileges are required during the operation, they will be allocated in the **AuxData** member extension. This member is currently unused by drivers.

### `Privileges.InitialPrivilegeSet`

An [INITIAL_PRIVILEGE_SET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551860(v=vs.85)) structure that specifies a set of initial privileges for the access.

### `Privileges.PrivilegeSet`

A [PRIVILEGE_SET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551860(v=vs.85)) structure that specifies a set of privileges for the access.

### `AuditPrivileges`

A Boolean value that specifies whether a privilege usage should be audited. This member is currently unused by drivers.

### `ObjectName`

A [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the object name string for the access. This member is used for auditing.

### `ObjectTypeName`

A [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the object type name string for the access. This member is used for auditing.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[ObOpenObjectByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-obopenobjectbypointer)

[PRIVILEGE_SET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551860(v=vs.85))

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SECURITY_SUBJECT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[SeAppendPrivileges](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seappendprivileges)

[SeCaptureSubjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secapturesubjectcontext)

[SeOpenObjectAuditAlarm](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seopenobjectauditalarm)

[SeOpenObjectForDeleteAuditAlarm](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seopenobjectfordeleteauditalarm)

[SeSetAccessStateGenericMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sesetaccessstategenericmapping)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)