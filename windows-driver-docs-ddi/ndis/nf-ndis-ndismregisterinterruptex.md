# NdisMRegisterInterruptEx function

## Description

NDIS miniport drivers call the
**NdisMRegisterInterruptEx** function to register an interrupt.

## Parameters

### `MiniportAdapterHandle` [in]

The miniport adapter handle that NDIS passed to the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `MiniportInterruptContext` [in]

A pointer to a block of context information. The miniport driver allocates this memory to store
information about the interrupt. NDIS passes the context information block in subsequent calls to other
functions that are associated with the interrupt.

### `MiniportInterruptCharacteristics` [in]

A pointer to an
[NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_interrupt_characteristics) structure that the miniport driver created. The driver
initializes this structure with handler entry points and configuration parameters that define the
interrupt characteristics.

### `NdisInterruptHandle` [out]

A pointer to an NDIS handle. NDIS writes the handle for the newly created interrupt object to the
address that the
*NdisInterruptHandle* pointer specifies.

## Return value

**NdisMRegisterInterruptEx** can return one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS initialized the interrupt object and supplied a valid interrupt handle at *NdisInterruptHandle* . NDIS claimed hardware resources and set up the functions that it calls when an interrupt occurs. |
| **NDIS_STATUS_RESOURCES** | **NdisMRegisterInterruptEx** failed due to insufficient resources. |
| **NDIS_STATUS_*XXX* or NT_STATUS_*XXX*** | The attempt to initialize the interrupt object failed for reasons other than those in the preceding list. |

## Remarks

A miniport driver must call
**NdisMRegisterInterruptEx** from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function if
it manages a NIC that generates interrupts.

*MiniportInitializeEx* must call the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function before calling
**NdisMRegisterInterruptEx**.

The miniport driver must specify entry points for the following interrupt service functions:

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt)

[MiniportEnableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_enable_interrupt)

If the NIC supports message-signaled interrupts (MSI), the miniport driver should specify entry points
for the following MSI service functions:

[MiniportMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt)

[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc)

[MiniportDisableMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_message_interrupt)

[MiniportEnableMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_enable_message_interrupt)

If a driver specifies entry points for MSI, it must also specify entry points for the non-MSI
interrupt service functions. Also, if
**NdisMRegisterInterruptEx** returns NDIS_STATUS_SUCCESS, the driver must examine the value of the
**InterruptType** member of the
[NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_interrupt_characteristics) structure to determine the type of interrupts NDIS granted.
If NDIS cannot grant MSI support, it will grant support for line based interrupts.

When interrupts are enabled on the NIC, a driver's
*MiniportInterrupt*(or
*MiniportMessageInterrupt*) function can be called at any time after the driver calls
**NdisMRegisterInterruptEx**, even before
**NdisMRegisterInterruptEx** returns. Therefore, a driver should not call
**NdisMRegisterInterruptEx** until it is ready to handle an interrupt.

Drivers call the
[NdisMDeregisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterinterruptex) function to release resources that were previously allocated with
**NdisMRegisterInterruptEx**.

## See also

[MiniportDisableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_interrupt)

[MiniportDisableMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_disable_message_interrupt)

[MiniportEnableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_enable_interrupt)

[MiniportEnableMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_enable_message_interrupt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[MiniportMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt)

[MiniportMessageInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt_dpc)

[NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_interrupt_characteristics)

[NdisMDeregisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterinterruptex)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)