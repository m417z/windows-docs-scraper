# ScsiPortGetDeviceBase function

## Description

The **ScsiPortGetDeviceBase** routine returns a mapped, logical base address that can be used to communicate with an HBA. Every miniport driver must pass mapped, logical access range addresses to the **ScsiPort..Port***Xxx* and **ScsiPort..Register***Xxx* routines to communicate with its HBA(s).

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the hardware device extension. This is a per-HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the HBA's mapped access ranges. This area is available to the miniport driver in the **DeviceExtension->HwDeviceExtension** member of the HBA's device object immediately after the miniport driver calls [ScsiPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize). The port driver frees this memory when it removes the device.

### `BusType` [in]

Specifies the interface type of the I/O bus on which the HBA is connected. The miniport driver's [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine obtains the value for this parameter from the **AdapterInterfaceType** member of the input PORT_CONFIGURATION_INFORMATION.

### `SystemIoBusNumber` [in]

Specifies the system-assigned number of the I/O bus on which the HBA is connected. The *HwScsiFindAdapter* routine obtains the value for this parameter from the **SystemIoBusNumber** member of the input PORT_CONFIGURATION_INFORMATION.

### `IoAddress` [in]

Specifies the bus-relative base address of a range used by the HBA. The *HwScsiFindAdapter* routine obtains the value for this parameter from one of the **AccessRanges** elements in the PORT_CONFIGURATION_INFORMATION if the port driver supplies range-configuration information. Otherwise, this address can be a value returned by **ScsiPortGetBusData** or a miniport driver-supplied default value. Avoid using a base address of zero because its successful return status can conflict with the error status (**NULL**).

### `NumberOfBytes` [in]

Specifies the size in bytes of the range that the mapping should cover. The *HwScsiFindAdapter* routine obtains the value of this parameter from the same **AccessRanges** element as *IoAddress* if the port driver supplies range configuration information. Otherwise, this value can be returned by **ScsiPortGetBusData** or a miniport driver-supplied default. In any case, the driver must not access the hardware outside of the returned, mapped range.

### `InIoSpace` [in]

**TRUE** indicates the range to be mapped is in I/O space, and the miniport driver will pass mapped addresses in this range to the **ScsiPort...Port***Xxx* to communicate with the HBA. The *HwScsiFindAdapter* routine obtains the value of this parameter from the same **AccessRanges** element as *IoAddress*. Note that a miniport driver *must invert* the value of the **InMemorySpace** member in an ACCESS_RANGE-type element before it is passed to **ScsiPortGetDeviceBase** as the *InIoSpace* argument. **FALSE** indicates that the range to be mapped is in memory space.

## Return value

**ScsiPortGetDeviceBase** returns a mapped logical base address for the given *IoAddress* if it successfully mapped the given range from *IoAddress* to *NumberOfBytes*. If a given range cannot be mapped, **ScsiPortGetDeviceBase** returns **NULL**.

## Remarks

NT-based operating system platforms can have several types of I/O buses and several I/O buses of the same type. Moreover, the HAL can map I/O space to memory in some platforms.

Consequently, a miniport driver cannot use bus-relative access range addresses to communicate with its HBA. To maintain miniport driver portability across CISC- and RISC-based machines, the addresses they use to access HBAs must be translated with **ScsiPortGetDeviceBase**.

Every miniport driver must use system-space logical range addresses, mapped by **ScsiPortGetDeviceBase**, to communicate with its HBA(s). Calls to the **ScsiPort...Port/Register***Xxx* routines require these mapped, logical addresses.

**ScsiPortGetDeviceBase** can be called several times, depending on how many HBAs the miniport driver supports and how many access ranges each HBA requires. Each mapped range corresponds to a range of bus-relative device addresses specified in an ACCESS_RANGE-type element of the **AccessRanges** array.

**ScsiPortGetDeviceBase** can be called only from a miniport driver's [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine or from HwScsiAdapterControl when the control type is **ScsiSetRunningConfig**. Calls from other miniport driver routines will result in system failure or in incorrect operation for the caller.

Follow these guidelines for calling **ScsiPortGetDeviceBase**:

* If *HwScsiFindAdapter* is using a miniport driver-supplied set of default bus-relative access ranges or values returned by **ScsiPortGetBusData**, it should call [ScsiPortValidateRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportvalidaterange) before attempting to call **ScsiPortGetDeviceBase**.
* If *HwScsiFindAdapter* determines that a particular HBA is not one that the miniport driver supports, it must call **ScsiPortFreeDeviceBase** to release the mapping(s) it set up to communicate with that HBA.

The logical address returned by **ScsiPortGetDeviceBase** should be used for all subsequent references made to the hardware but should *not* be added to any **AccessRanges** specification in the PORT_CONFIGURATION_INFORMATION. Miniport driver writers should make no assumptions about how many bits are used in the logical base address returned by **ScsiPortGetDeviceBase**.

**ScsiPortGetDeviceBase** uses **SCSI_PHYSICAL_ADDRESS** to represent bus-relative addresses.

```cpp
typedef PHYSICAL_ADDRESS SCSI_PHYSICAL_ADDRESS, *PSCSI_PHYSICAL_ADDRESS;

```

The **SCSI_PHYSICAL_ADDRESS** type is an operating system-independent data type that SCSI miniport drivers use to represent either a physical addresses or a bus-relative address.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## See also

[ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_access_range)

[HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85))

[PORT_CONFIGURATION_INFORMATION (SCSI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_port_configuration_information)

[ScsiPortFreeDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportfreedevicebase)

[ScsiPortGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetbusdata)

[ScsiPortValidateRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportvalidaterange)