# SeAppendPrivileges function

## Description

The **SeAppendPrivileges** routine appends additional privileges to the privilege set in an access state structure.

## Parameters

### `AccessState` [in, out]

Pointer to a caller-allocated ACCESS_STATE structure representing the current access request.

### `Privileges` [in]

Pointer to a caller-allocated PRIVILEGE_SET structure containing the privileges to be added.

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The append operation succeeded. |
| **STATUS_INSUFFICIENT_RESOURCES** | **SeAppendPrivileges** encountered a pool allocation failure when allocating memory for the new privileges. |

## Remarks

Initially, an access state structure can hold up to three privileges in its privilege set. If more than three privileges need to be stored, **SeAppendPrivileges** allocates a new privilege set from the paged pool and copies into it both the current privileges and the new privileges.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[ACCESS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_access_state)

[PRIVILEGE_SET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551860(v=vs.85))

[SeAccessCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck)

[SeFreePrivileges](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefreeprivileges)

[SePrivilegeCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seprivilegecheck)

[SeSetAccessStateGenericMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sesetaccessstategenericmapping)