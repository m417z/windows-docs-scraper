# EVT_IDD_CX_MONITOR_OPM_GET_CERTIFICATE_SIZE callback function

## Description

**EVT_IDD_CX_MONITOR_OPM_GET_CERTIFICATE_SIZE** is called by the OS to get the size of an OPM certificate.

## Parameters

### `AdapterObject` [in]

The object for the adapter that the OPM certificate size will be gotten for.

### `pInArgs` [in]

Input arguments used by **EVT_IDD_CX_MONITOR_OPM_GET_CERTIFICATE_SIZE**.

### `pOutArgs` [out]

Output arguments returned by **EVT_IDD_CX_MONITOR_OPM_GET_CERTIFICATE_SIZE**.

## Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.