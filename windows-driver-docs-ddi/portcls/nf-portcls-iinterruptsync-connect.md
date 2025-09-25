# IInterruptSync::Connect

## Description

The `Connect` method connects the synchronization object to the interrupt.

## Return value

`Connect` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

This method connects the synchronization object to the interrupt that was specified in the call to [PcNewInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcnewinterruptsync) that created the synchronization object. The interrupt is specified in the **PcNewInterruptSync** function's *ResourceList* and *ResourceIndex* parameters.

## See also

[IInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iinterruptsync)

[IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt)

[PcNewInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcnewinterruptsync)