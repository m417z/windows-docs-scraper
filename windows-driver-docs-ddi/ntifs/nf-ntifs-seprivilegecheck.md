# SePrivilegeCheck function

## Description

The **SePrivilegeCheck** routine determines whether a specified set of privileges is enabled in the subject's access token.

## Parameters

### `RequiredPrivileges` [in, out]

Pointer to a PRIVILEGE_SET structure. The **Privilege** member of this structure is an array of LUID_AND_ATTRIBUTES structures. Before calling **SePrivilegeCheck**, use the **Privilege** array to indicate the set of privileges to check. Set the **Control** member to PRIVILEGE_SET_ALL_NECESSARY if all of the privileges must be enabled; or set it to zero if it is sufficient that any one of the privileges be enabled.

When **SePrivilegeCheck** returns, the **Attributes** member of each LUID_AND_ATTRIBUTES structure is set to SE_PRIVILEGE_USED_FOR_ACCESS if the corresponding privilege is enabled.

### `SubjectSecurityContext` [in]

Pointer to the subject's captured security context.

### `AccessMode` [in]

The access mode to use for the privilege check. Either **UserMode** or **KernelMode**. If **AccessMode** is set to **KernelMode**, then all privileges are marked as being possessed by the subject, and **SePrivilegeCheck** returns **TRUE**.

## Return value

**SePrivilegeCheck** returns **TRUE** if all specified privileges are held by the subject, **FALSE** otherwise.

## Remarks

An access token contains a list of the privileges held by the account associated with the token. These privileges can be enabled or disabled; most are disabled by default. **SePrivilegeCheck** checks only for enabled privileges. To get a list of all the enabled and disabled privileges held by an access token, call [**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken).

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[**LUID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_luid_and_attributes)

[**PRIVILEGE_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_privilege_set)

[**SECURITY_SUBJECT_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#security_subject_context)

[**SeAccessCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck)

[**SeAppendPrivileges**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seappendprivileges)

[**SeFreePrivileges**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefreeprivileges)

[**SeQueryInformationToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryinformationtoken)

[**SeSinglePrivilegeCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-sesingleprivilegecheck)