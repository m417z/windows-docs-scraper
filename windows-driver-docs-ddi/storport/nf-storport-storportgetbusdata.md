# StorPortGetBusData function

## Description

The **StorPortGetBusData** routine retrieves the bus-specific configuration information necessary to initialize the HBA.

## Parameters

### `DeviceExtension` [in]

Pointer to the miniport driver's per-HBA storage area.

### `BusDataType` [in]

Contains a value of type [**BUS_DATA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ne-ntddk-_bus_data_type) that specifies the type of bus-specific configuration data to be returned. Currently, this value can be one of the following: **Cmos**, **EisaConfiguration**, **Pos**, or **PCIConfiguration**. However, additional types of bus configuration will be supported in the future. The upper bound on the types supported is always **MaximumBusDataType**.

### `SystemIoBusNumber` [in]

Specifies the system-assigned number of the I/O bus. The miniport driver's [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine obtains this value from the **SystemIoBusNumber** member initially set in [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information).

### `SlotNumber` [in]

Specifies the logical slot number or location of the device.

If **PCIConfiguration** is specified as the *BusDataType*, this parameter must be specified as a PCI_SLOT_NUMBER-type value.

### `Buffer` [in, out]

Pointer to a buffer or area to which the configuration data is returned or, if the given *Length* is zero, points to a location to which the OS-specific port driver returns a pointer to a buffer that it allocates.

### `Length` [in]

Specifies the maximum number of bytes to return at *Buffer*, or zero if the caller requires the OS-specific port driver to allocate a buffer to contain the data.

## Return value

**StorPortGetBusData** returns the number of bytes of configuration information it stored in the buffer. When the input *BusDataType* is **PCIConfiguration**, **StorPortGetBusData** can return either of the following values to indicate an error.

| Return code | Description |
| ----------- | ----------- |
| **0 (zero)** | The PCI bus does not exist. |
| **2** | The PCI bus exists, but there is no device at the given PCI *SlotNumber*. The *Buffer* contains the value PCI_INVALID_VENDOR_ID at the PCI_COMMON_CONFIG **VendorId** member. |

## Remarks

A miniport driver can call **StorPortGetBusData** from the following routines:

* From its [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) callback routine.
* From its [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) only when the [**ControlType** is **ScsiSetRunningConfig**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-scsi_adapter_control_type).

Calls from other miniport driver routines will result in system failure or incorrect operation for the caller.

Configuration data returned by **StorPortGetBusData** is valid only until the miniport driver calls **StorPortGetBusData** again. As soon as the caller's [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine returns control, any returned configuration data becomes invalid.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter)

[**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information)

[**SCSI_ADAPTER_CONTROL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-scsi_adapter_control_type)