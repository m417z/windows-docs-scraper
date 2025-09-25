# _WDF_INTERRUPT_EXTENDED_POLICY structure (wdfinterrupt.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_INTERRUPT_EXTENDED_POLICY** structure contains information about an interrupt's policy, priority, affinity, and group.

## Members

### `Size`

The size, in bytes, of this structure.

### `Policy`

A [WDF_INTERRUPT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ne-wdfinterrupt-_wdf_interrupt_policy)-typed enumerator that specifies a processor affinity policy for the interrupt.

### `Priority`

A [WDF_INTERRUPT_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ne-wdfinterrupt-_wdf_interrupt_priority)-typed enumerator that specifies a priority for the interrupt.

### `TargetProcessorSetAndGroup`

A GROUP_AFFINITY structure that specifies a processor group and a processor affinity mask within the group, if the *Policy* parameter is set to **WdfIrqPolicySpecifiedProcessors**. The GROUP_AFFINITY structure is defined in *Winnt.h*.

## Remarks

The **WDF_INTERRUPT_EXTENDED_POLICY** structure is used as input the [WdfInterruptSetExtendedPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetextendedpolicy).

To initialize a **WDF_INTERRUPT_EXTENDED_POLICY** structure, your driver must call [WDF_INTERRUPT_EXTENDED_POLICY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_extended_policy_init).

## See also

[WDF_INTERRUPT_EXTENDED_POLICY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_extended_policy_init)

[WdfInterruptSetExtendedPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetextendedpolicy)