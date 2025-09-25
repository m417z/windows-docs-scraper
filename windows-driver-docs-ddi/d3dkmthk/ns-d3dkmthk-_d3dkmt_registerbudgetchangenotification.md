# _D3DKMT_REGISTERBUDGETCHANGENOTIFICATION structure

## Description

Used to register budget change notification.

## Members

### `hDevice` [in]

A handle to the device.

### `Callback` [in]

Pointer to the [PFND3DKMT_BUDGETCHANGENOTIFICATIONCALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nc-d3dkmthk-pfnd3dkmt_budgetchangenotificationcallback) callback.

### `Context` [in]

The callback context.

### `Handle` [out]

A handle to unregister.

## Remarks

## See also