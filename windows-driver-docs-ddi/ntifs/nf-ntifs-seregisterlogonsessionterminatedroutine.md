# SeRegisterLogonSessionTerminatedRoutine function

## Description

The **SeRegisterLogonSessionTerminatedRoutine** routine registers a callback routine to be called when a logon session terminates. A logon session terminates when the last token referencing the logon session is deleted.

## Parameters

### `CallbackRoutine` [in]

Address of routine to call when a logon session terminates.

## Return value

**SeRegisterLogonSessionTerminatedRoutine** can return one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The callback routine was successfully registered. |
| **STATUS_INVALID_PARAMETER** | The value of *CallbackRoutine* is **NULL**. |
| **STATUS_INSUFFICIENT_RESOURCES** | A list entry could not be allocated for the callback routine. |

## Remarks

Each call to **SeRegisterLogonSessionTerminatedRoutine** must be matched by a subsequent call to **SeUnregisterLogonSessionTerminatedRoutine**.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[SeUnregisterLogonSessionTerminatedRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seunregisterlogonsessionterminatedroutine)