# SYSTEM_MANDATORY_LABEL_ACE structure

## Description

The **SYSTEM_MANDATORY_LABEL_ACE** structure defines an [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) for the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL) that specifies the mandatory access level and policy for a securable object.

## Members

### `Header`

An [ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure that specifies the size and type of the ACE. The structure also contains flags that control inheritance of the ACE by child objects. The **AceType** member of the **ACE_HEADER** structure must be set to **SYSTEM_MANDATORY_LABEL_ACE_TYPE**, and the **AceSize** member must be set to the total number of bytes allocated for the **SYSTEM_MANDATORY_LABEL_ACE** structure.

### `Mask`

The access policy for principals with a mandatory integrity level lower than the object associated with the SACL that contains this ACE.

| Value | Meaning |
| --- | --- |
| **SYSTEM_MANDATORY_LABEL_NO_WRITE_UP**<br><br>0x1 | A principal with a lower mandatory level than the object cannot write to the object. |
| **SYSTEM_MANDATORY_LABEL_NO_READ_UP**<br><br>0x2 | A principal with a lower mandatory level than the object cannot read the object. |
| **SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP**<br><br>0x4 | A principal with a lower mandatory level than the object cannot execute the object. |

### `SidStart`

Specifies the first **DWORD** of a [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid). The remaining bytes of the **SID** are stored in contiguous memory after the **SidStart** member. The identifier authority of the **SID** must be **SECURITY_MANDATORY_LABEL_AUTHORITY**. The [RID](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) of the **SID** specifies the mandatory integrity level of the object associated with the SACL that contains this ACE. The *RID* must be one of the following values.

| Value | Meaning |
| --- | --- |
| 0x1000 | Low integrity level. |
| 0x2000 | Medium integrity level. |
| 0x3000 | High integrity level. |

## See also

[ACL](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-acl)