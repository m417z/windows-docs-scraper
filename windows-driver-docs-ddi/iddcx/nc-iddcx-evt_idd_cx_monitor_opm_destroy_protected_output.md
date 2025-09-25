# EVT_IDD_CX_MONITOR_OPM_DESTROY_PROTECTED_OUTPUT callback function

## Description

**EVT_IDD_CX_MONITOR_OPM_DESTROY_PROTECTED_OUTPUT** is called by the OS to destroy an OPM protected output context.

## Parameters

### `OpmCxtObject` [in]

The object for the OPM context that will be destroyed.

## Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.