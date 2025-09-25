# _WDF_INTERRUPT_POLICY enumeration (wudfinterrupt.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [WDF_INTERRUPT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ne-wudfinterrupt-_wdf_interrupt_policy) enumeration type identifies the affinity policies that the Plug and Play (PnP) manager can use when it assigns a device's interrupts to the processors of a multiprocessor system.

## Constants

### `WdfIrqPolicyMachineDefault`

Use the system's default affinity policy.

### `WdfIrqPolicyAllCloseProcessors`

For NUMA systems, the PnP manager should assign the device's interrupts to processors that are close to the device. For non-NUMA systems, specifying **WdfIrqPolicyAllCloseProcessors** is the same as specifying **WdfIrqPolicyAllProcessorsInMachine**.

### `WdfIrqPolicyOneCloseProcessor`

For NUMA systems, the PnP manager should assign one interrupt to a processor that is close to the device. For non-NUMA systems, the PnP manager can assign the interrupt to any processor.

### `WdfIrqPolicyAllProcessorsInMachine`

The PnP manager can assign a device's interrupts to any of the system's processors.

### `WdfIrqPolicySpecifiedProcessors`

The PnP manager should assign the device's interrupts only to specified processors.

### `WdfIrqPolicySpreadMessagesAcrossAllProcessors`

The PnP manager should assign different message-based interrupts to different processors, if possible.

## Remarks

The [WDF_INTERRUPT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ne-wudfinterrupt-_wdf_interrupt_policy) enumeration type is used as input to the [IWDFInterrupt::SetPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-setpolicy) method.

## See also

[IWDFInterrupt::SetPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-setpolicy)