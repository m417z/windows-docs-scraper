# _ACE_HEADER structure

## Description

The ACE_HEADER structure describes the type and size of an access-control entry (ACE).

## Members

### `AceType`

ACE type. This member can be one of the following values:

| Value | Meaning |
| --- | --- |
| ACCESS_ALLOWED_ACE_TYPE | Access-allowed ACE that uses the ACCESS_ALLOWED_ACE structure. |
| ACCESS_DENIED_ACE_TYPE | Access-denied ACE that uses the ACCESS_DENIED_ACE structure. |
| SYSTEM_AUDIT_ACE_TYPE | System-audit ACE that uses the SYSTEM_AUDIT_ACE structure. |

### `AceFlags`

Set of ACE type-specific control flags. This member can be a combination of the following values:

| Value | Meaning |
| --- | --- |
| CONTAINER_INHERIT_ACE | Child objects that are containers, such as directories, inherit the ACE as an effective ACE. The inherited ACE is inheritable unless the NO_PROPAGATE_INHERIT_ACE bit flag is also set. |
| FAILED_ACCESS_ACE_FLAG | Used with system-audit ACEs in a SACL to generate audit messages for failed access attempts. |
| INHERIT_ONLY_ACE | Indicates an inherit-only ACE which does not control access to the object to which it is attached. If this flag is not set, the ACE is an effective ACE which controls access to the object to which it is attached. <br><br>Both effective and inherit-only ACEs can be inherited depending on the state of the other inheritance flags. |
| INHERITED_ACE | **Microsoft Windows 2000 or later:** Indicates that the ACE was inherited. The system sets this bit when it propagates an inherited ACE to a child object. |
| NO_PROPAGATE_INHERIT_ACE | If the ACE is inherited by a child object, the system clears the OBJECT_INHERIT_ACE and CONTAINER_INHERIT_ACE flags in the inherited ACE. This prevents the ACE from being inherited by subsequent generations of objects. |
| OBJECT_INHERIT_ACE | Noncontainer child objects inherit the ACE as an effective ACE. <br><br>For child objects that are containers, the ACE is inherited as an inherit-only ACE unless the NO_PROPAGATE_INHERIT_ACE bit flag is also set. |
| SUCCESSFUL_ACCESS_ACE_FLAG | Used with system-audit ACEs in a SACL to generate audit messages for successful access attempts. |

### `AceSize`

Size, in bytes, of the ACE.

## Remarks

The ACE_HEADER structure is the first member of the various types of ACE structures, such as ACCESS_ALLOWED_ACE.

System-alarm ACEs are not currently supported. The **AceType** member cannot specify the SYSTEM_ALARM_ACE_TYPE. Do not use the SYSTEM_ALARM_ACE structure.

## See also

[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_access_allowed_ace)

[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_access_denied_ace)

[ACE](https://learn.microsoft.com/windows-hardware/drivers/ifs/ace)

[ACL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_acl)

[SYSTEM_ALARM_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_system_alarm_ace)

[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_system_audit_ace)