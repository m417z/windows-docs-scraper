# EVT_IDD_CX_MONITOR_OPM_GET_CERTIFICATE callback function

## Description

**EVT_IDD_CX_MONITOR_OPM_GET_CERTIFICATE** is called by the OS to get an OPM certificate.

## Parameters

### `AdapterObject` [in]

The object for the adapter that the OPM certificate will be gotten for.

### `pInArgs` [in]

Input arguments used by **EVT_IDD_CX_MONITOR_OPM_GET_CERTIFICATE**.

## Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.