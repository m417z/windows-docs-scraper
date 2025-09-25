# EVT_IDD_CX_MONITOR_OPM_CONFIGURE_PROTECTED_OUTPUT callback function

## Description

**EVT_IDD_CX_MONITOR_OPM_CONFIGURE_PROTECTED_OUTPUT** is called by the OS to configure the protected output.

## Parameters

### `OpmCxtObject` [in]

A context used by the OS to identify the OPM context to configure output for.

### `pInArgs` [in]

Input arguments used by **EVT_IDD_CX_MONITOR_OPM CONFIGURE_PROTECTED_OUTPUT**.

## Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.