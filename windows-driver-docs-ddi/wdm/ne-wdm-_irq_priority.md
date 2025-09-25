# _IRQ_PRIORITY enumeration (wdm.h)

## Description

The **IRQ_PRIORITY** enumeration type indicates the priority the system should give to servicing a device's interrupts.

## Constants

### `IrqPriorityUndefined`

Specifies that the device does not require any particular priority for its interrupts.

### `IrqPriorityLow`

Specifies that the device's interrupts are of low priority. This setting is appropriate for devices that can tolerate higher-than-normal latency.

### `IrqPriorityNormal`

Specifies that the device's interrupts are of normal priority.

### `IrqPriorityHigh`

Specifies that the device's interrupts are of high priority. This setting is appropriate for devices that require low latency.

## Remarks

The system uses **IRQ_PRIORITY** to assign IRQLs for devices. For example, it might assign a higher IRQL to a device that has an **IRQ_PRIORITY** of **IrqPriorityHigh** than it does to a device that has an **IRQ_PRIORITY** of **IrqPriorityLow**.

## See also

[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)