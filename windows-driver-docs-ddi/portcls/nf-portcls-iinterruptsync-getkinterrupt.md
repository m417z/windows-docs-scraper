# IInterruptSync::GetKInterrupt

## Description

The `GetKInterrupt` method gets a WDM interrupt object from a port-class synchronization object.

## Return value

`GetKInterrupt` returns a pointer to a WDM interrupt object.

## Remarks

The PKINTERRUPT pointer is one of the two parameters that are passed to every interrupt service routine (see [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine)). Every **IInterruptSync** object has an associated PKINTERRUPT pointer. It points to the associated kernel interrupt object, which is opaque.

A driver typically calls `GetKInterrupt` only if it needs to obtain this pointer so that it can call [KeSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution) directly.

## See also

[IInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iinterruptsync)

[InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine)

[KeSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution)