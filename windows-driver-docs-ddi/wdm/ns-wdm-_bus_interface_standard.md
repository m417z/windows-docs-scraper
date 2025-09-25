# _BUS_INTERFACE_STANDARD structure

## Description

The **BUS_INTERFACE_STANDARD** interface structure enables device drivers to make direct calls to parent bus driver routines. This structure defines the [GUID_BUS_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/kernel/obtaining-device-configuration-information-at-irql---dispatch-level) interface.

## Members

### `Size`

The size, in bytes, of this structure.

### `Version`

The driver-defined interface version.

### `Context`

A pointer to interface-specific context information.

### `InterfaceReference`

A pointer to an [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference) routine that increments the interface's reference count.

### `InterfaceDereference`

A pointer to an [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference) routine that decrements the interface's reference count.

### `TranslateBusAddress`

A pointer to a [TranslateBusAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-translate_bus_address) routine that translates addresses on the parent bus to logical addresses.

### `GetDmaAdapter`

A pointer to a [GetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_dma_adapter) routine that returns a DMA adapter structure ([DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)) for the target device.

### `SetBusData`

A pointer to a [SetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/gg604856(v=vs.85)) routine that writes data to the device's configuration space.

### `GetBusData`

A pointer to a [GetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_set_device_data) routine that reads data from the device's configuration space.

## Remarks

The **BUS_INTERFACE_STANDARD** structure is an extension of the [INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface) structure.

Some operations on a device are reserved for the device's parent bus driver. These operations might include accessing the device-specific configuration space of a bus or programming a DMA controller.

To read from or write to a device's configuration space, a device driver must rely on the agency of the bus driver in either of two ways:

- By sending the I/O request packets (IRPs) [IRP_MN_READ_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-read-config) and [IRP_MN_WRITE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-write-config) to the bus driver.

- By obtaining an interface from the bus driver. The device driver can then access its device's configuration space by making direct calls to the bus driver routines provided by the **BUS_INTERFACE_STANDARD** interface structure. Its member routines, [GetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_set_device_data) and [SetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/gg604856(v=vs.85)), can be used to read from and write to a device's configuration space, respectively.

For more information about the ways to access configuration space, see [Accessing Device Configuration Space](https://learn.microsoft.com/windows-hardware/drivers/kernel/accessing-device-configuration-space).

Some types of devices, such as a bus-mastering storage device, have on-board DMA controllers. However, the device drivers for these devices cannot program these DMA controllers directly. Instead they must rely on routines provided by the parent bus driver. For a device driver to program the DMA controller for its device, it must first request an adapter object from the parent bus driver. The adapter object contains the routines supplied by the bus driver that can be used to program the device's DMA controller. Device drivers must rely on the **BUS_INTERFACE_STANDARD**, either directly or indirectly, to obtain the adapter object.

If the driver is executing at IRQL = PASSIVE_LEVEL, it should obtain a device's DMA adapter object by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter). **IoGetDmaAdapter** detects whether the bus driver supports the **BUS_INTERFACE_STANDARD** interface. If it does, **IoGetDmaAdapter** calls the routine pointed to by the [GetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_dma_adapter) member of this interface to obtain the adapter object. Otherwise, **IoGetDmaAdapter** calls an equivalent legacy routine.

However, if a driver must obtain an adapter object while running at IRQL >= DISPATCH_LEVEL, it cannot do so with [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter). In this case, the driver must query for the **BUS_INTERFACE_STANDARD** interface while still at IRQL = PASSIVE_LEVEL by using [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface).

## See also

[DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[GUID_BUS_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/kernel/obtaining-device-configuration-information-at-irql---dispatch-level)

[GetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_set_device_data)

[GetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_dma_adapter)

[INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_interface)

[IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)

[IRP_MN_READ_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-read-config)

[IRP_MN_WRITE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-write-config)

[InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference)

[InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[SetBusData](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/gg604856(v=vs.85))

[TranslateBusAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-translate_bus_address)