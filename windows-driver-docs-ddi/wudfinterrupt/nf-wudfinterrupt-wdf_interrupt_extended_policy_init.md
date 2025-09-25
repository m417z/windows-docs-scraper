# WDF_INTERRUPT_EXTENDED_POLICY_INIT function (wudfinterrupt.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [WDF_INTERRUPT_EXTENDED_POLICY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_extended_policy_init) function initializes a [WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy) structure.

## Parameters

### `ExtendedPolicy`

A pointer to a driver-allocated [**WDF_INTERRUPT_EXTENDED_POLICY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy) structure.

## Remarks

The [WDF_INTERRUPT_EXTENDED_POLICY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_extended_policy_init) function zeros the specified [WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy) structure and sets the structure's **Size** member. It also sets the structure's **Policy** member to **WdfIrqPolicyMachineDefault** and sets the structure's **Priority** member to **WdfIrqPriorityUndefined**.

#### Examples

For a code example that uses [WDF_INTERRUPT_EXTENDED_POLICY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_extended_policy_init), see [IWDFInterrupt::SetExtendedPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-setextendedpolicy).

## See also

[WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy)