# ACTRL_ACCESS_ENTRYA structure

## Description

 Contains access-control information for a specified trustee. This structure stores information equivalent to the access-control information stored in an [ACE](https://learn.microsoft.com/windows/desktop/SecAuthZ/ace).

## Members

### `Trustee`

A [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure that identifies the user, group, or program (such as a service) to which the access-control entry applies.

### `fAccessFlags`

Indicates how the access rights specified by the **Access** and **ProvSpecificAccess** members apply to the trustee. This member can be one of the following values. If you are using this structure with the COM implementation of [IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol), this member must be ACTRL_ACCESS_ALLOWED or ACTRL_ACCESS_DENIED.

| Value | Meaning |
| --- | --- |
| **ACTRL_ACCESS_ALLOWED**<br><br>0x00000001 | The rights are allowed. |
| **ACTRL_ACCESS_DENIED**<br><br>0x00000002 | The rights are denied. |
| **ACTRL_AUDIT_SUCCESS**<br><br>0x00000004 | The system generates audit messages for failed attempts to use the rights. |
| **ACTRL_AUDIT_FAILURE**<br><br>0x00000008 | The system generates audit messages for successful attempts to use the rights. |

### `Access`

A bitmask that specifies the access rights that the entry allows, denies, or audits for the trustee.

This member must use the provider-independent access flags, such as ACTRL_READ_CONTROL, rather than access flags such as READ_CONTROL. The provider for the object type converts these provider-independent flags to the corresponding provider-specific flags.

If you are using this structure with the COM implementation of [IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol), this member must be COM_RIGHTS_EXECUTE.

#### ACTRL_SYSTEM_ACCESS

#### ACTRL_DELETE

#### ACTRL_READ_CONTROL

#### ACTRL_CHANGE_ACCESS

#### ACTRL_CHANGE_OWNER

#### ACTRL_SYNCHRONIZE

#### ACTRL_STD_RIGHTS_ALL

#### ACTRL_STD_RIGHT_REQUIRED

#### COM_RIGHTS_EXECUTE

#### COM_RIGHTS_EXECUTE_LOCAL

#### COM_RIGHTS_EXECUTE_REMOTE

#### COM_RIGHTS_ACTIVATE_LOCAL

#### COM_RIGHTS_ACTIVATE_REMOTE

### `ProvSpecificAccess`

A bitmask that specifies access rights specific to the provider type. The functions that use the **ACTRL_ACCESS_ENTRY** structure pass these bits on to the provider without interpreting them. In most cases, this member should be 0.

### `Inheritance`

A set of bit flags that determines whether other containers or objects can inherit the access-control entry from the primary object to which the access list is attached. If you are using this structure with the COM implementation of [IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol), this value must be NO_INHERITANCE, which indicates that the access-control entry is not inheritable. Otherwise, this value can be NO_INHERITANCE or it can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **CONTAINER_INHERIT_ACE**<br><br>0x2 | Other containers that are contained by the primary object inherit the entry. |
| **INHERIT_ONLY_ACE**<br><br>0x8 | The ACE does not apply to the primary object to which the ACL is attached, but objects contained by the primary object inherit the entry. |
| **NO_PROPAGATE_INHERIT_ACE**<br><br>0x4 | The OBJECT_INHERIT_ACE and CONTAINER_INHERIT_ACE flags are not propagated to an inherited entry. |
| **OBJECT_INHERIT_ACE**<br><br>0x1 | Noncontainer objects contained by the primary object inherit the entry. |
| **SUB_CONTAINERS_AND_OBJECTS_INHERIT**<br><br>0x3 | Both containers and noncontainer objects that are contained by the primary object inherit the entry. This flag corresponds to the combination of the CONTAINER_INHERIT_ACE and OBJECT_INHERIT_ACE flags. |
| **SUB_CONTAINERS_ONLY_INHERIT**<br><br>0x2 | Other containers that are contained by the primary object inherit the entry. This flag corresponds to the CONTAINER_INHERIT_ACE flag. |
| **SUB_OBJECTS_ONLY_INHERIT**<br><br>0x1 | Noncontainer objects contained by the primary object inherit the entry. This flag corresponds to the OBJECT_INHERIT_ACE flag. |

### `lpInheritProperty`

A pointer to a null-terminated string that identifies the object types that can inherit the entry. If you are using this structure with the COM implementation of [IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol), this member must be **NULL**.

## See also

[ACTRL_ACCESS_ENTRY_LIST](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-actrl_access_entry_lista)

[TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a)

## Remarks

> [!NOTE]
> The accctrl.h header defines ACTRL_ACCESS_ENTRY as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).