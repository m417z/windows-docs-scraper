# SeUnregisterLogonSessionTerminatedRoutine function

## Description

The **SeUnregisterLogonSessionTerminatedRoutine** routine unregisters a callback routine that was registered by an earlier call to **SeRegisterLogonSessionTerminatedRoutine**.

## Parameters

### `CallbackRoutine` [in]

Address of routine that was originally passed in to **SeRegisterLogonSessionTerminatedRoutine**.

## Return value

**SeUnregisterLogonSessionTerminatedRoutine** can return one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callback routine was successfully removed. |
| **STATUS_INVALID_PARAMETER** | The value of *CallbackRoutine* is **NULL**. |
| **STATUS_INSUFFICIENT_RESOURCES** | A list entry could not be found for the callback routine. |

## Remarks

Each call to **SeRegisterLogonSessionTerminatedRoutine** must be matched by a subsequent call to **SeUnregisterLogonSessionTerminatedRoutine**.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[SeMarkLogonSessionForTerminationNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-semarklogonsessionforterminationnotification)

[SeRegisterLogonSessionTerminatedRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seregisterlogonsessionterminatedroutine)