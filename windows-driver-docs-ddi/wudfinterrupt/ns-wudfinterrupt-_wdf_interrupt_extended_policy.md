# _WDF_INTERRUPT_EXTENDED_POLICY structure (wudfinterrupt.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy) structure contains information about an interrupt's policy, priority, affinity, and group.

## Members

### `Size`

The size, in bytes, of this structure.

### `Policy`

A [WDF_INTERRUPT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ne-wudfinterrupt-_wdf_interrupt_policy)-typed enumerator that specifies a processor affinity policy for the interrupt.

### `Priority`

A [WDF_INTERRUPT_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ne-wdfinterrupt-_wdf_interrupt_priority)-typed enumerator that specifies a priority for the interrupt.

### `TargetProcessorSetAndGroup`

A [GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity) structure that specifies a processor group and a processor affinity mask within the group, if the *Policy* parameter is set to **WdfIrqPolicySpecifiedProcessors**. The GROUP_AFFINITY structure is defined in *Winnt.h*.

## Remarks

The [WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy) structure is used as input for the [IWDFInterrupt::SetExtendedPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-setextendedpolicy) method.

To initialize a [WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy) structure, your driver must call [WDF_INTERRUPT_EXTENDED_POLICY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_extended_policy_init).

## See also

[IWDFInterrupt::SetExtendedPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-setextendedpolicy)

[WDF_INTERRUPT_EXTENDED_POLICY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_extended_policy_init)