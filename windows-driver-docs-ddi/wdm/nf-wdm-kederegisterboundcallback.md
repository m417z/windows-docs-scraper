# KeDeregisterBoundCallback function

## Description

The **KeDeregisterBoundCallback** routine deregisters a user-mode bound exception callback registered by [KeRegisterBoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterboundcallback).

## Parameters

### `Handle` [in]

Specifies the value returned by [KeRegisterBoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterboundcallback) when the callback was registered.

## Return value

The **KeDeregisterBoundCallback** routine returns STATUS_SUCCESS if the callback is successfully removed. It returns STATUS_INVALID_HANDLE if no callback matching the provided *Handle* value is found.

## See also

[KeRegisterBoundCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterboundcallback)