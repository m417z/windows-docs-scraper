# _WDF_INTERRUPT_POLICY enumeration (wudfddi.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_INTERRUPT_POLICY** enumeration type identifies the affinity policies that the PnP manager can use when it assigns a device's interrupts to the processors of a multiprocessor system.

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

The **WDF_INTERRUPT_POLICY** enumeration type is used as input to the [WdfInterruptSetPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetpolicy) method.

## See also

[WdfInterruptSetPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetpolicy)