# ScsiPortValidateRange function

## Description

The **ScsiPortValidateRange** routine indicates whether the specified access range values have already been claimed in the registry by another driver.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the hardware device extension. This is a per-HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the HBA's mapped access ranges. This area is available to the miniport driver in the **DeviceExtension->HwDeviceExtension** member of the HBA's device object immediately after the miniport driver calls [ScsiPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize). The port driver frees this memory when it removes the device.

### `BusType` [in]

Specifies the value of the **AdapterInterfaceType** member in the PORT_CONFIGURATION_INFORMATION structure when *HwScsiFindAdapter* is called.

### `SystemIoBusNumber` [in]

Specifies the value of the **SystemIoBusNumber** member in the configuration information when *HwScsiFindAdapter* is called.

### `IoAddress` [in]

Specifies a bus-relative base address for the range of ports or device memory to be validated *before* the miniport driver's *HwScsiFindAdapter* routine attempts to map the access range for the adapter at that address.

### `NumberOfBytes` [in]

Specifies the size in bytes or number of elements in the range.

### `InIoSpace` [in]

Indicates when TRUE that the range is in I/O space, rather than in memory. When **FALSE**, the range is in memory space.

## Return value

**ScsiPortValidateRange** returns **TRUE** if the HwScsiFindAdapter routine can safely map and use the mapped range to access the adapter. **ScsiPortValidateRange** returns **FALSE** if the specified access range values have already been claimed in the registry by another driver.

## Remarks

**ScsiPortValidateRange** can be called only from a miniport driver's [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine. Calls from other miniport driver routines will result in system failure or incorrect operation for the caller.

If the operating system-specific port driver initializes any **AccessRanges** element of the PORT_CONFIGURATION_INFORMATION structure before it calls the miniport driver's *HwScsiFindAdapter* routine, the miniport driver must pass the supplied values to **ScsiPortGetDeviceBase** and use the mapped logical addresses for the range to determine whether an HBA is one that it supports.

The port driver either fills an ACCESS_RANGE-type element with a complete description of a bus-relative address range for an adapter, or the port driver zeros all members of the element.

For input **AccessRanges** elements set with default zeros, the *HwScsiFindAdapter* routine can attempt to locate an adapter it supports on the given I/O bus. In these circumstances, a miniport driver usually has a set of driver-determined default addresses for its type(s) of HBA. However, a previously loaded driver might already be using an initialized adapter at one of this miniport driver's default address ranges, particularly in x86-only systems in which some devices are initialized in x86 real mode. To prevent such a device from being inadvertently reprogrammed, each miniport driver's *HwScsiFindAdapter* routine should call **ScsiPortValidateRange** before it maps any driver-supplied addresses with **ScsiPortGetDeviceBase** and then uses the mapped logical addresses to interrogate adapters on an I/O bus.

If **ScsiPortValidateRange** returns **FALSE**, *HwScsiFindAdapter* must not attempt to map the input range addresses because another driver has already claimed the range in the registry.

If **ScsiPortValidateRange** returns **TRUE**, *HwScsiFindAdapter* can safely do the following:

1. Map the bus-relative range addresses to system-space logical range addresses with **ScsiPortGetDeviceBase**.
2. Use the mapped logical addresses with the **ScsiPortRead/Write***Xxx* to determine whether the adapter actually is an HBA that the driver supports.

If a miniport driver uses a range successfully passed to **ScsiPortValidateRange** for an HBA it supports, that driver must invert the *InIoSpace* value when it sets the **RangeInMemory** member of an **AccessRanges** element in the PORT_CONFIGURATION_INFORMATION.

**ScsiPortValidateRange** uses **SCSI_PHYSICAL_ADDRESS** to represent bus-relative addresses.

```cpp
typedef PHYSICAL_ADDRESS SCSI_PHYSICAL_ADDRESS, *PSCSI_PHYSICAL_ADDRESS;

```

The **SCSI_PHYSICAL_ADDRESS** type is an operating system-independent data type that SCSI miniport drivers use to represent either a physical addresses or a bus-relative address.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## See also

[ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_access_range)

[HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85))

[PORT_CONFIGURATION_INFORMATION (SCSI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_port_configuration_information)

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)

[ScsiPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize)