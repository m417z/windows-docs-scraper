# NdisMDeregisterInterruptEx function

## Description

Miniport drivers call
**NdisMDeregisterInterruptEx** to release resources that were previously allocated with the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function.

## Parameters

### `NdisInterruptHandle` [in]

An interrupt handle that the miniport driver obtained in a previous call to
**NdisMRegisterInterruptEx**.

## Remarks

**NdisMDeregisterInterruptEx** releases the resources that were allocated in
**NdisMRegisterInterruptEx**. After
**NdisMDeregisterInterruptEx** returns, NDIS will not call the miniport driver's
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) function or
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) function.

A miniport driver can call
**NdisMDeregisterInterruptEx** from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) or
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function only if
*MiniportInitializeEx* previously made a successful call to
**NdisMRegisterInterruptEx**.

The miniport driver should disable its NIC from generating interrupts before it calls
**NdisMDeregisterInterruptEx**. After
**NdisMDeregisterInterruptEx** returns control, the miniport driver cannot call the
[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex) function.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInetrrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex)

[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex)