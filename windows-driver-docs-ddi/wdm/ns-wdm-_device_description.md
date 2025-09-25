# _DEVICE_DESCRIPTION structure

## Description

The **DEVICE_DESCRIPTION** structure describes the attributes of the physical device for which a driver is requesting a DMA adapter.

## Members

### `Version`

The version of this structure. The **Version** member of the **DEVICE_DESCRIPTION** structure that is passed to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine determines which version of the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure is returned by this routine. The following is a list of the possible values of the **Version** member and the corresponding **DMA_ADAPTER** versions:

#### DEVICE_DESCRIPTION_VERSION

If **Version** = **DEVICE_DESCRIPTION_VERSION**, **IoGetDmaAdapter** ignores the **IgnoreCount** member, and returns version 1 of the **DMA_ADAPTER** structure.

#### DEVICE_DESCRIPTION_VERSION1

If **Version** = **DEVICE_DESCRIPTION_VERSION1**, **IoGetDmaAdapter** uses the **IgnoreCount** member, and returns version 1 of the **DMA_ADAPTER** structure.

#### DEVICE_DESCRIPTION_VERSION2

If **Version** = **DEVICE_DESCRIPTION_VERSION2**, **IoGetDmaAdapter** uses the **IgnoreCount** member, and returns version 2 of the **DMA_ADAPTER** structure. Version 2 is available starting with Windows XP.

#### DEVICE_DESCRIPTION_VERSION3

If **Version** = **DEVICE_DESCRIPTION_VERSION3**, **IoGetDmaAdapter** uses the **IgnoreCount** member, and returns version 3 of the **DMA_ADAPTER** structure. Version 3 is available starting with Windows 8.

### `Master`

Whether the device is a bus-master DMA device. Set to **TRUE** if the device is a bus-master DMA device. Set to **FALSE** if it is a subordinate DMA device.

### `ScatterGather`

For a bus-master DMA device, this member indicates whether the device supports scatter/gather DMA. Set to **TRUE** if the device can do scatter/gather DMA. Otherwise, set this member to **FALSE**.

For a subordinate DMA device, the **ScatterGather** value is not used. Instead, **IoGetDmaAdapter** assumes that the scatter/gather capability of a subordinate DMA device is the same as that of the underlying system DMA controller to which the device is connected.

### `DemandMode`

This member is used only if **Version** is DEVICE_DESCRIPTION_VERSION2.

For a subordinate DMA device, this member indicates whether to use the system DMA controller's demand mode. Set to **TRUE** to use demand mode. Otherwise, set this member to **FALSE**.

For a bus-master DMA device, the **DemandMode** value is not used.

If **Version** is DEVICE_DESCRIPTION_VERSION, DEVICE_DESCRIPTION_VERSION1, or DEVICE_DESCRIPTION_VERSION3, the **DemandMode** value is not used.

### `AutoInitialize`

For a subordinate DMA device, this member indicates whether to use the system DMA controller's autoinitialize mode. Set to **TRUE** to use autoinitialize mode. Otherwise, set this member to **FALSE**.

For a bus-master DMA device, the **AutoInitialize** value is not used.

### `Dma32BitAddresses`

This member is used only if **Version** is DEVICE_DESCRIPTION_VERSION, DEVICE_DESCRIPTION_VERSION1, or DEVICE_DESCRIPTION_VERSION2.

**Dma32BitAddresses** specifies whether the device can use full 32-bit addresses for DMA operations. Set to **TRUE** if the device supports 32-bit addresses. Otherwise, set this member to **FALSE**.

If **Version** = DEVICE_DESCRIPTION_VERSION3, the **Dma32BitAddresses** value is not used.

### `IgnoreCount`

Whether to ignore the DMA controller's transfer counter. Set to **TRUE** if the DMA controller in this platform does not maintain an accurate transfer counter, and therefore requires a workaround. Otherwise, set this member to **FALSE**.

If **Version** = DEVICE_DESCRIPTION_VERSION, the **IgnoreCount** value is not used.

For more information, see the Remarks section.

### `Reserved1`

Reserved for system use. Must be **FALSE**.

### `Dma64BitAddresses`

This member is used only if **Version** is DEVICE_DESCRIPTION_VERSION, DEVICE_DESCRIPTION_VERSION1, or DEVICE_DESCRIPTION_VERSION2.

**Dma64BitAddresses** specifies whether the device can use full 64-bit addresses for DMA operations. Set to **TRUE** if the device supports 64-bit addresses. Otherwise, set this member to **FALSE**.

If **Version** = DEVICE_DESCRIPTION_VERSION3, the **Dma64BitAddresses** value is not used.

### `BusNumber`

The system-assigned bus number for the I/O bus. This member is not used by WDM drivers.

### `DmaChannel`

The number of the DMA channel to which a subordinate device is assigned. The device driver obtains this channel number from the resource list that it receives in the [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request that starts the device. For more information about this number, see the description of the **Dma.Channel** member in [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor).

### `InterfaceType`

The interface type of the I/O bus to use for DMA. Set this member to the [INTERFACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_interface_type) enumeration value that indicates the interface type. For more information, see the Remarks section.

### `DmaWidth`

For a subordinate DMA device, this member specifies the DMA data width for transfers by the system DMA controller. Possible values are **Width8Bits**, **Width16Bits**, **Width32Bits**, and **Width64Bits**.

For a bus-master DMA device, the **DmaWidth** value is not used.

### `DmaSpeed`

This member is used only if **Version** is DEVICE_DESCRIPTION_VERSION, DEVICE_DESCRIPTION_VERSION1, or DEVICE_DESCRIPTION_VERSION2.

For a subordinate DMA device, this member specifies one of the following speeds for system DMA: **Compatible**, **TypeA**, **TypeB**, **TypeC**, or **TypeF**.

For a bus-master DMA device, the **DmaSpeed** value is not used.

If **Version** = DEVICE_DESCRIPTION_VERSION3, the **DmaSpeed** value is not used.

### `MaximumLength`

The maximum number of bytes the device can transfer in a DMA operation that uses the allocated adapter object.

### `DmaPort`

The Microchannel-type bus port number. This parameter is obsolete, but is retained in the structure for compatibility with legacy drivers.

### `DmaAddressWidth`

This member is used only if **Version** = DEVICE_DESCRIPTION_VERSION3.

For a bus-master DMA device, **DmaAddressWidth** specifies the width, in bits, of a DMA address. The **DmaAddressWidth** value must be nonzero and must not exceed 64. If the memory address width is greater than the DMA address width, map registers are required to access a region of memory that is beyond the address reach of the DMA controller.

For a subordinate DMA device, the **DmaAddressWidth** value is not used. Instead, **IoGetDmaAdapter** assumes that the address width of a subordinate DMA device is the same as that of the underlying system DMA controller to which the device is connected.

### `DmaControllerInstance`

Not used.

### `DmaRequestLine`

This member is used only if **Version** = DEVICE_DESCRIPTION_VERSION3.

For a subordinate DMA device, **DmaRequestLine** specifies the request line on the DMA controller to which the device is connected. The device driver obtains the number of this request line from the resource list it receives in the **IRP_MN_START_DEVICE** request that starts the device. For more information about the request line number, see the description of the **u.DmaV3.RequestLine** member in [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor).

For a bus-master DMA device, the **DmaRequestLine** value is not used.

### `DeviceAddress`

This member is used only if **Version** = DEVICE_DESCRIPTION_VERSION3.

For a subordinate DMA device, **DeviceAddress** is the memory-mapped address of the data register on the device that is used as the source or destination for a DMA transfer. This data register is located at a known, device-specific offset from the device start address. The width of this register is specified by the **DmaWidth** member. The device driver obtains the device start address from the resource list it receives in the **IRP_MN_START_DEVICE** request that starts the device. For more information about this address, see the description of the **u.Memory.Start** member in [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor).

For a bus-master DMA device, the **DeviceAddress** member is not used.

## Remarks

The driver of a device that uses DMA to transfer data uses the **DEVICE_DESCRIPTION** structure to pass information about the device to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine. The driver calls this routine to request an adapter object for a physical device object (PDO). This PDO represents the device's physical connection to the I/O bus to use for DMA. For more information, see [Getting an Adapter Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/getting-an-adapter-object).

To allocate resources for a DMA controller, the I/O manager needs information about the controller but can obtain some of this information only from a driver. For example, the driver for a bus-master device knows whether the device supports scatter/gather DMA or uses full 32-bit addresses. Or, the driver for a subordinate device can determine the DMA channel number from the resource list that the driver receives in the [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) request that starts the device. The driver uses the **DEVICE_DESCRIPTION** structure to pass this information to the I/O manager.

Before calling **IoGetDmaAdapter**, the driver should first zero-initialize the entire **DEVICE_DESCRIPTION** structure, then fill in selected members to describe the device.

The **InterfaceType** member specifies the type of bus interface that will be used for DMA. If you set **InterfaceType** to **InterfaceTypeUndefined**, **IoGetDmaAdapter** queries the PDO to determine the correct interface type for your device. Or, you can specify an explicit interface type, such as **Internal**, **Isa**, **Eisa**, or **PCIBus**. For more information, see the list of supported interface types in [INTERFACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_interface_type).

If the **ScatterGather** member is set to **TRUE** and the **InterfaceType** member is set to **PCIBus**, the **Dma32BitAddresses** member is ignored and **IoGetDmaAdapter** assumes that the device supports 32-bit DMA addresses.

If the **Dma64BitAddresses** member is set to **TRUE**, the **Dma32BitAddresses** member is ignored and **IoGetDmaAdapter** assumes that the device supports 64-bit DMA addresses.

To indicate that the DMA controller hardware cannot reliably maintain an accurate transfer count, set **IgnoreCount** to **TRUE**, and set **Version** to a value other than DEVICE_DESCRIPTION_VERSION. In a platform that has such a DMA controller, the operating system ignores the DMA transfer counter but must take special precautions to maintain data integrity during DMA operations. Typically, the use of a workaround to compensate for a deficient DMA controller degrades the speed of DMA transfers.

A driver should specify **TypeF** as the **DmaSpeed** value only if the computer's ACPI firmware supports it.

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[INTERFACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_interface_type)

[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)