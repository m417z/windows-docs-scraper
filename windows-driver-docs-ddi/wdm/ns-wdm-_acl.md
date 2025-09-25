# _ACL structure

## Description

The ACL structure is the header of an access-control list (ACL). A complete ACL consists of an ACL structure followed by an ordered list of zero or more access-control entries (ACE).

## Members

### `AclRevision`

Revision level of the ACL.

**Microsoft Windows NT 4.0 and earlier:** This value must be ACL_REVISION.

**Microsoft Windows 2000 and later:** This value can be ACL_REVISION or ACL_REVISION_DS. It must be ACL_REVISION_DS if the ACL contains an object-specific ACE.

### `Sbz1`

A zero byte of padding that aligns the **AclRevision** member on a 16-bit boundary.

### `AclSize`

Size, in bytes, of the ACL. This value includes both the ACL structure and all the ACEs.

### `AceCount`

Number of ACEs stored in the ACL.

### `Sbz2`

Two zero bytes of padding that align the ACL structure on a 32-bit boundary.

## Remarks

An ACL includes a sequential list of zero or more ACEs. The individual ACEs in an ACL are numbered from 0 to *n*, where *n*+1 is the number of ACEs in the ACL. When editing an ACL, a driver refers to an ACE within the ACL by its index.

There are two types of ACL: discretionary and system.

A discretionary ACL (DACL) is controlled by the owner of an object or anyone granted WRITE_DAC access to the object. It specifies the access particular users and groups can have to an object. For example, the owner of a file can use a DACL to control which users and groups can and cannot have access to the file.

An object may also have system-level security information associated with it, in the form of a system ACL (SACL) controlled by a system administrator. A SACL can allow the system administrator to audit any attempts to gain access to an object.

Three ACE structures are currently defined:

| Attribute | Description |
| --- | --- |
| ACCESS_ALLOWED_ACE | Grants specified rights to a user or group. This ACE is stored in a DACL. |
| ACCESS_DENIED_ACE | Denies specified rights to a user or group. This ACE is stored in a DACL. |
| SYSTEM_AUDIT_ACE | Specifies what types of access will cause system-level audits. This ACE is stored in a SACL. |

A fourth ACE structure, SYSTEM_ALARM_ACE, is not currently supported.

The ACL structure is to be treated as though it were opaque, and drivers should not attempt to work with its members directly. To ensure that ACLs are semantically correct, drivers can use the functions listed in the See Also section to create and manipulate ACLs.

ACL and ACE structures must be aligned on 32-bit boundaries.

## See also

[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_access_allowed_ace)

[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_access_denied_ace)

[ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[RtlAddAccessAllowedAce](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtladdaccessallowedace)

[RtlCreateAcl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateacl)

[RtlGetAce](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlgetace)

[RtlSetDaclSecurityDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlsetdaclsecuritydescriptor)

[SYSTEM_ALARM_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_system_alarm_ace)

[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_system_audit_ace)

[TOKEN_DEFAULT_DACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_token_default_dacl)