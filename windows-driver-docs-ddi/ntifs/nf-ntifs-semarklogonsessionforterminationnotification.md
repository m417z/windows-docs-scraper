# SeMarkLogonSessionForTerminationNotification function

## Description

The **SeMarkLogonSessionForTerminationNotification** routine marks a logon session so that the caller's registered callback routine is called when the logon session terminates. A logon session terminates when the last token referencing the logon session is deleted.

## Parameters

### `LogonId` [in]

Pointer to the logon ID of the logon session.

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The logon session was successfully marked. |
| **STATUS_NOT_FOUND** | The logon session was not found. |

## Remarks

To register the callback routine, use [SeRegisterLogonSessionTerminatedRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seregisterlogonsessionterminatedroutine).

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[SeRegisterLogonSessionTerminatedRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seregisterlogonsessionterminatedroutine)

[SeUnregisterLogonSessionTerminatedRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seunregisterlogonsessionterminatedroutine)