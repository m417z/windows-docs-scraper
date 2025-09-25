# EVT_IDD_CX_MONITOR_OPM_GET_INFOMATION callback function

## Description

**EVT_IDD_CX_MONITOR_OPM_GET_INFOMATION** is called by the OS to get OPM information.

## Parameters

### `OpmCxtObject` [in]

The object for the OPM context that information will be gotten from.

### `pInArgs` [in]

Input arguments used by **EVT_IDD_CX_MONITOR_OPM_GET_INFOMATION**.

### `pOutArgs` [out]

Output arguments returned by **EVT_IDD_CX_MONITOR_OPM_GET_INFOMATION**.

## Return value

(NTSTATUS) If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.