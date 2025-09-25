# EVT_IDD_CX_MONITOR_OPM_CREATE_PROTECTED_OUTPUT callback function

## Description

**EVT_IDD_CX_MONITOR_OPM_CREATE_PROTECTED_OUTPUT** is called by the OS to create an OPM protected output context.

## Parameters

### `MonitorObject` [in]

A handle used by the OS to identify the monitor that the OPM context should be created on.

### `OpmCxtObject` [in]

A context used by the OS to identify the OPM context the call is for.

### `pInArgs` [in]

Input arguments used by **EVT_IDD_CX_MONITOR_OPM CREATE_PROTECTED_OUTPUT**.

## Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.