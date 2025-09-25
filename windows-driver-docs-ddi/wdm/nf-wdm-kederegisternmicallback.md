# KeDeregisterNmiCallback function

## Description

The **KeDeregisterNmiCallback** routine deregisters a nonmaskable interrupt (NMI) callback registered by [KeRegisterNmiCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisternmicallback).

## Parameters

### `Handle` [in]

Specifies the value returned by [KeRegisterNmiCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisternmicallback) when the NMI callback was registered.

## Return value

The **KeDeregisterNmiCallback** routine returns STATUS_SUCCESS if the callback is successfully removed. It returns STATUS_INVALID_HANDLE if no callback matching the provided *Handle* value is found.

## See also

[KeRegisterNmiCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisternmicallback)