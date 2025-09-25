# _IRQ_DEVICE_POLICY enumeration (wdm.h)

## Description

The **IRQ_DEVICE_POLICY** enumeration type indicates the policy the operating system can use to assign the interrupts from a device to different processors.

## Constants

### `IrqPolicyMachineDefault:0`

The device does not require any particular assignment of interrupts to processors.

### `IrqPolicyAllCloseProcessors:1`

The operating system should assign interrupts from the device to processors that are close to the device. On non-NUMA computers, the effect of this value is identical to that of **IrqPolicyAllProcessorsInMachine**.

### `IrqPolicyOneCloseProcessor:2`

The operating system should assign a single interrupt for the device to one processor that is close to the device. On non-NUMA computers, the operating system can assign the interrupt to any processor.

### `IrqPolicyAllProcessorsInMachine:3`

The operating system should assign interrupts from the device to all processors.

### `IrqPolicySpecifiedProcessors:4`

The operating system should assign interrupts from the device to a specific set of processors.

### `IrqPolicySpreadMessagesAcrossAllProcessors:5`

The operating system should assign different message-signaled interrupts to different processors, if possible.

### `IrqPolicyAllProcessorsInMachineWhenSteered:6`

Reserved for system use. Do not use in your driver.

## Remarks

The **Interrupt.AffinityPolicy** member of the [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure is an **IRQ_DEVICE_POLICY** enumeration value.

## See also

- [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)