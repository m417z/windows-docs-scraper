# AddMandatoryAce function

## Description

 The **AddMandatoryAce** function adds a [SYSTEM_MANDATORY_LABEL_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_mandatory_label_ace) [access control entry](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ACE) to the specified [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL).

## Parameters

### `pAcl` [in, out]

A pointer to an
SACL. This function adds a mandatory ACE to the end of this SACL. The ACE is in the form of a
[SYSTEM_MANDATORY_LABEL_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_mandatory_label_ace) structure.

### `dwAceRevision` [in]

The revision level of the SACL being modified.
This value can be one of the following values.

| Value | Meaning |
| --- | --- |
| ****ACL_REVISION**** | The SACL does not contain object-specific ACEs. |
| ****ACL_REVISION_DS**** | The SACL contains object-specified ACEs. |

### `AceFlags` [in]

A set of bit flags that control ACE inheritance. This function sets these flags in the **AceFlags** member of the
[ACE_HEADER](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ace_header) structure of the new ACE.

This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **OBJECT_INHERIT_ACE**<br><br>0x1 | The ACE is inherited by noncontainer objects. |
| **CONTAINER_INHERIT_ACE**<br><br>0x2 | The ACE is inherited by container objects. |
| **NO_PROPAGATE_INHERIT_ACE**<br><br>0x4 | The **OBJECT_INHERIT_ACE** and **CONTAINER_INHERIT_ACE** bits are not propagated to an inherited ACE. |
| **INHERIT_ONLY_ACE**<br><br>0x8 | The ACE does not apply to the object to which the SACL is assigned, but the ACE can be inherited by child objects. |
| **INHERITED_ACE**<br><br>0x10 | The ACE is inherited. Operations that change the security on a tree of objects may modify inherited ACEs without changing ACEs that were directly applied to the object. |

### `MandatoryPolicy` [in]

The access policy for principals with a mandatory integrity level lower than the object associated with the SACL that contains this ACE.

| Value | Meaning |
| --- | --- |
| **SYSTEM_MANDATORY_LABEL_NO_WRITE_UP**<br><br>0x1 | A principal with a lower mandatory level than the object cannot write to the object. |
| **SYSTEM_MANDATORY_LABEL_NO_READ_UP**<br><br>0x2 | A principal with a lower mandatory level than the object cannot read the object. |
| **SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP**<br><br>0x4 | A principal with a lower mandatory level than the object cannot execute the object. |

### `pLabelSid` [in]

A pointer to an SID that specifies the mandatory integrity level of the object associated with the SACL being appended.

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The following are possible error values.

| Return code/value | Description |
| --- | --- |
| **ERROR_ALLOTTED_SPACE_EXCEEDED**<br><br>0x540 | The new ACE does not fit into the *pAcl* buffer. |

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[SYSTEM_MANDATORY_LABEL_ACE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_mandatory_label_ace)