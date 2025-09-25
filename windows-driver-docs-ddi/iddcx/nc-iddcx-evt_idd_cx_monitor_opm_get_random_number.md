# EVT_IDD_CX_MONITOR_OPM_GET_RANDOM_NUMBER callback function

## Description

**EVT_IDD_CX_MONITOR_OPM_GET_RANDOM_NUMBER** is called by the OS to get an OPM random number.

## Parameters

### `OpmCxtObject` [in]

The object for the OPM context that a random number will be gotten from.

### `pOutArgs` [out]

Output arguments returned by **EVT_IDD_CX_MONITOR_OPM_GET_RANDOM_NUMBER**.

## Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.