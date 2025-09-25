# WDF_INTERRUPT_EXTENDED_POLICY_INIT function (wdfinterrupt.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_INTERRUPT_EXTENDED_POLICY_INIT** function initializes a [WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy) structure.

## Parameters

### `ExtendedPolicy`

A pointer to a driver-allocated [**WDF_INTERRUPT_EXTENDED_POLICY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy) structure.

## Remarks

The **WDF_INTERRUPT_EXTENDED_POLICY_INIT** function zeros the specified [WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy) structure and sets the structure's **Size** member. It also sets the structure's **Policy** member to **WdfIrqPolicyMachineDefault** and sets the structure's **Priority** member to **WdfIrqPriorityUndefined**.

#### Examples

For a code example that uses **WDF_INTERRUPT_EXTENDED_POLICY_INIT**, see [WdfInterruptSetExtendedPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetextendedpolicy).

## See also

[WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy)