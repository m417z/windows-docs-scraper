# _IRQ_DEVICE_POLICY enumeration (miniport.h)

## Description

The **IRQ_DEVICE_POLICY** enumeration type indicates the policy the operating system can use to assign the interrupts from a device to different processors.

## Constants

### `IrqPolicyMachineDefault`

The device does not require any particular assignment of interrupts to processors.

### `IrqPolicyAllCloseProcessors`

The operating system should assign interrupts from the device to processors that are close to the device. On non-NUMA computers, the effect of this value is identical to that of **IrqPolicyAllProcessorsInMachine**.

### `IrqPolicyOneCloseProcessor`

The operating system should assign a single interrupt for the device to one processor that is close to the device. On non-NUMA computers, the operating system can assign the interrupt to any processor.

### `IrqPolicyAllProcessorsInMachine`

The operating system should assign interrupts from the device to all processors.

### `IrqPolicySpecifiedProcessors`

The operating system should assign interrupts from the device to a specific set of processors.

### `IrqPolicySpreadMessagesAcrossAllProcessors`

The operating system should assign different message-signaled interrupts to different processors, if possible.

### `IrqPolicyAllProcessorsInMachineWhenSteered`

## Remarks

The **Interrupt.AffinityPolicy** member of the [IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure is an **IRQ_DEVICE_POLICY** enumeration value.

## See also

[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)