# StorPortGetDeviceBase function

## Description

The **StorPortGetDeviceBase** routine maps an I/O address to system address space.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `BusType` [in]

Specifies the interface type of the I/O bus on which the HBA is connected. The miniport driver's [HwStorFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine obtains the value for this parameter from the **AdapterInterfaceType** member of the input [PORT_CONFIGURATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information).

### `SystemIoBusNumber` [in]

Specifies the system-assigned number of the I/O bus on which the HBA is connected. The [HwStorFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine obtains the value for this parameter from the **SystemIoBusNumber** member of the input [PORT_CONFIGURATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information).

### `IoAddress` [in]

Specifies the bus-relative base address of a range used by the HBA. The [HwStorFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine obtains the value for this parameter from one of the **AccessRanges** elements in the [PORT_CONFIGURATION_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) if the port driver supplies range-configuration information. Otherwise, this address can be a value returned by [StorPortGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetbusdata) or a miniport driver-supplied default value. Avoid using a base address of zero because its successful return status can conflict with the error status (**NULL**).

### `NumberOfBytes` [in]

Specifies the size in bytes of the range that the mapping should cover. The [HwStorFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine obtains the value of this parameter from the same **AccessRanges** element as *IoAddress* if the port driver supplies range configuration information. Otherwise, this value can be returned by [StorPortGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetbusdata) or a miniport driver-supplied default. In any case, the driver must not access the hardware outside of the returned, mapped range.

### `InIoSpace` [in]

TRUE indicates the range to be mapped is in I/O space, and the miniport driver will pass mapped addresses in this range to the Storport *port* read/write routines to communicate with the HBA. The [HwStorFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine obtains the value of this parameter from the same **AccessRanges** element as *IoAddress*. Note that a miniport driver *must invert* the value of the **InMemorySpace** member in an ACCESS_RANGE-type element before it is passed to **StorPortGetDeviceBase** as the *InIoSpace* argument. **FALSE** indicates that the range to be mapped is in memory space.

## Return value

A mapped, logical base address corresponding to the bus-relative address supplied in the *IoAddress* parameter.

## Remarks

Every miniport driver must pass mapped, logical access range addresses to the Storport *port* read/write routines and the Storport *register* read/write routines when communicating with its HBA(s).

This routine supports only those addresses that were assigned to the driver by the system Plug and Play (PnP) manager.

## See also

[StorPortFreeDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreedevicebase)