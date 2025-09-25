# ACE_HEADER structure

## Description

The **ACE_HEADER** structure defines the type and size of an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE).

## Members

### `AceType`

Specifies the ACE type. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ACCESS_ALLOWED_ACE_TYPE** | Access-allowed ACE that uses the [ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace) structure. |
| **ACCESS_ALLOWED_CALLBACK_ACE_TYPE** | Access-allowed callback ACE that uses the [ACCESS_ALLOWED_CALLBACK_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_callback_ace) structure. |
| **ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE** | Object-specific access-allowed callback ACE that uses the [ACCESS_ALLOWED_CALLBACK_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_callback_object_ace) structure. |
| **ACCESS_ALLOWED_COMPOUND_ACE_TYPE** | Reserved. |
| **ACCESS_ALLOWED_OBJECT_ACE_TYPE** | Object-specific access-allowed ACE that uses the [ACCESS_ALLOWED_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_object_ace) structure. |
| **ACCESS_DENIED_ACE_TYPE** | Access-denied ACE that uses the [ACCESS_DENIED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_ace) structure. |
| **ACCESS_DENIED_CALLBACK_ACE_TYPE** | Access-denied callback ACE that uses the [ACCESS_DENIED_CALLBACK_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_callback_ace) structure. |
| **ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE** | Object-specific access-denied callback ACE that uses the [ACCESS_DENIED_CALLBACK_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_callback_ace) structure. |
| **ACCESS_DENIED_OBJECT_ACE_TYPE** | Object-specific access-denied ACE that uses the [ACCESS_DENIED_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_object_ace) structure. |
| **ACCESS_MAX_MS_ACE_TYPE** | Same as SYSTEM_ALARM_OBJECT_ACE_TYPE. |
| **ACCESS_MAX_MS_V2_ACE_TYPE** | Same as SYSTEM_ALARM_ACE_TYPE. |
| **ACCESS_MAX_MS_V3_ACE_TYPE** | Reserved. |
| **ACCESS_MAX_MS_V4_ACE_TYPE** | Same as SYSTEM_ALARM_OBJECT_ACE_TYPE. |
| **ACCESS_MAX_MS_OBJECT_ACE_TYPE** | Same as SYSTEM_ALARM_OBJECT_ACE_TYPE. |
| **ACCESS_MIN_MS_ACE_TYPE** | Same as ACCESS_ALLOWED_ACE_TYPE. |
| **ACCESS_MIN_MS_OBJECT_ACE_TYPE** | Same as ACCESS_ALLOWED_OBJECT_ACE_TYPE. |
| **SYSTEM_ALARM_ACE_TYPE** | Reserved for future use. System-alarm ACE that uses the [SYSTEM_ALARM_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_alarm_ace) structure. |
| **SYSTEM_ALARM_CALLBACK_ACE_TYPE** | Reserved for future use. System-alarm callback ACE that uses the [SYSTEM_ALARM_CALLBACK_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_alarm_callback_ace) structure. |
| **SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE** | Reserved for future use. Object-specific system-alarm callback ACE that uses the [SYSTEM_ALARM_CALLBACK_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_alarm_callback_object_ace) structure. |
| **SYSTEM_ALARM_OBJECT_ACE_TYPE** | Reserved for future use. Object-specific system-alarm ACE that uses the [SYSTEM_ALARM_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_alarm_object_ace) structure. |
| **SYSTEM_AUDIT_ACE_TYPE** | System-audit ACE that uses the [SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace) structure. |
| **SYSTEM_AUDIT_CALLBACK_ACE_TYPE** | System-audit callback ACE that uses the [SYSTEM_AUDIT_CALLBACK_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_callback_ace) structure. |
| **SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE** | Object-specific system-audit callback ACE that uses the [SYSTEM_AUDIT_CALLBACK_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_callback_object_ace) structure. |
| **SYSTEM_AUDIT_OBJECT_ACE_TYPE** | Object-specific system-audit ACE that uses the [SYSTEM_AUDIT_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_alarm_object_ace) structure. |
| **SYSTEM_MANDATORY_LABEL_ACE_TYPE**<br><br>0x11 | Mandatory label ACE that uses the [SYSTEM_MANDATORY_LABEL_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_mandatory_label_ace) structure. |

### `AceFlags`

Specifies a set of ACE type-specific control flags. This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **CONTAINER_INHERIT_ACE** | Child objects that are containers, such as directories, inherit the ACE as an effective ACE. The inherited ACE is inheritable unless the NO_PROPAGATE_INHERIT_ACE bit flag is also set. |
| **FAILED_ACCESS_ACE_FLAG** | Used with system-audit ACEs in a [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) to generate audit messages for failed access attempts. |
| **INHERIT_ONLY_ACE** | Indicates an inherit-only ACE, which does not control access to the object to which it is attached. If this flag is not set, the ACE is an effective ACE which controls access to the object to which it is attached. <br><br>Both effective and inherit-only ACEs can be inherited depending on the state of the other inheritance flags. |
| **INHERITED_ACE** | Indicates that the ACE was inherited. The system sets this bit when it propagates an inherited ACE to a child object. |
| **NO_PROPAGATE_INHERIT_ACE** | If the ACE is inherited by a child object, the system clears the OBJECT_INHERIT_ACE and CONTAINER_INHERIT_ACE flags in the inherited ACE. This prevents the ACE from being inherited by subsequent generations of objects. |
| **OBJECT_INHERIT_ACE** | Noncontainer child objects inherit the ACE as an effective ACE. <br><br>For child objects that are containers, the ACE is inherited as an inherit-only ACE unless the NO_PROPAGATE_INHERIT_ACE bit flag is also set. |
| **SUCCESSFUL_ACCESS_ACE_FLAG** | Used with system-audit ACEs in a SACL to generate audit messages for successful access attempts. |

### `AceSize`

Specifies the size, in bytes, of the ACE.

## Remarks

The **ACE_HEADER** structure is the first member of the various types of ACE structures, such as [ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace).

System-alarm ACEs are not currently supported. The **AceType** member cannot specify the SYSTEM_ALARM_ACE_TYPE or SYSTEM_ALARM_OBJECT_ACE_TYPE values. Do not use the [SYSTEM_ALARM_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_alarm_ace) or [SYSTEM_ALARM_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_alarm_object_ace) structures.

## See also

[ACCESS_ALLOWED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_ace)

[ACCESS_ALLOWED_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_allowed_object_ace)

[ACCESS_DENIED_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_ace)

[ACCESS_DENIED_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-access_denied_object_ace)

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)

[SYSTEM_AUDIT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_audit_ace)

[SYSTEM_AUDIT_OBJECT_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_alarm_object_ace)