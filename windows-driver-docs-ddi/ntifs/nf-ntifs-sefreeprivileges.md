# SeFreePrivileges function

## Description

The **SeFreePrivileges** routine frees a privilege set returned by **SeAccessCheck**.

## Parameters

### `Privileges` [in]

Pointer to the privilege set to be freed.

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[PRIVILEGE_SET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551860(v=vs.85))

[SeAccessCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck)

[SeAppendPrivileges](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seappendprivileges)

[SePrivilegeCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seprivilegecheck)