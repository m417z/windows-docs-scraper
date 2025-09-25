# ScsiPortGetBusData function

## Description

The **ScsiPortGetBusData** routine returns bus-type-specific configuration information that a miniport driver's [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine might use to determine whether it supports a particular adapter on a particular I/O bus, and to configure the HBA if it does.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

### `BusDataType` [in]

Contains a value of type [BUS_DATA_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bus_data_type) that specifies the type of bus-specific configuration data to be returned. Currently, this value can be one of the following: **Cmos**, **EisaConfiguration**, **Pos**, or **PCIConfiguration**. However, additional types of bus configuration will be supported in the future. The upper bound on the types supported is always **MaximumBusDataType**.

### `SystemIoBusNumber` [in]

Specifies the system-assigned number of the I/O bus. The miniport driver's [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine obtains this value from the input PORT_CONFIGURATION_INFORMATION **SystemIoBusNumber** member.

### `SlotNumber` [in]

Specifies the logical slot number or location of the device.

If **PCIConfiguration** is specified as the *BusDataType*, this parameter must be specified as a PCI_SLOT_NUMBER-type value.

### `Buffer` [in]

Pointer to a buffer or area to which the configuration data is returned or, if the given *Length* is zero, points to a location to which the operating system-specific port driver returns a pointer to a buffer that it allocates.

### `Length` [in]

Specifies the maximum number of bytes to return at *Buffer*, or zero if the caller requires the operating system-specific port driver to allocate a buffer to contain the data.

## Return value

**ScsiPortGetBusData** returns the number of bytes of configuration information it stored in the buffer. When the input BusDataType is PCIConfiguration, ScsiPortGetBusData can return either of the following values to indicate an error.

| Return code | Description |
| --- | --- |
| **0 (zero)** | The PCI bus does not exist. |
| **2** | The PCI bus exists, but there is no device at the given PCI *SlotNumber*. The *Buffer* contains the value PCI_INVALID_VENDOR_ID at the PCI_COMMON_CONFIG **VendorId** member. |

## Remarks

**ScsiPortGetBusData** can be called only from a miniport driver's [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine or from *HwScsiAdapterControl* when the control type is **ScsiSetRunningConfig**. Calls from other miniport driver routines will result in system failure or incorrect operation for the caller.

Configuration data returned by **ScsiPortGetBusData** is valid only until the miniport driver calls **ScsiPortGetBusData** again. As soon as the caller's *HwScsiFindAdapter* routine returns control, any returned configuration data becomes invalid.

## See also

[HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85))

[PCI_COMMON_CONFIG](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff537455(v=vs.85))

[PCI_SLOT_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_slot_number)

[PORT_CONFIGURATION_INFORMATION (SCSI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_port_configuration_information)