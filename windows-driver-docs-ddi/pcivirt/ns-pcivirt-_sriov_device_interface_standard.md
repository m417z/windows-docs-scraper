# _SRIOV_DEVICE_INTERFACE_STANDARD structure

## Description

Stores function pointers to callback functions implemented by the physical function (PF) driver in the device stack for the of the SR-IOV device.

## Members

### `Size`

Size of this structure.

### `Version`

Version of this structure

### `Context`

Driver-defined context passed by the driver.

### `InterfaceReference`

Pointer to a routine that increments the number of references to this interface. For more information about this routine, see [InterfaceReference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_reference).

### `InterfaceDereference`

Pointer to a routine that decrements the number of references to this interface. For more information about this routine, see [InterfaceDereference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinterface_dereference).

### `ReadVfConfig`

Pointer to the driver's implementation of the [SRIOV_READ_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/nc-pcivirt-sriov_read_config) callback function that serves as a handler for reading the VF’s configurations space from the non-privileged VM.

### `WriteVfConfig`

Pointer to the driver's implementation of the [SRIOV_WRITE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/nc-pcivirt-sriov_write_config) callback function that serves as a handler for writing the VF’s configuration space from the non-privileged VM.

### `ReadVfConfigBlock`

Pointer to the driver's implementation of the [SRIOV_READ_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/nc-pcivirt-sriov_read_block) callback function that serves as a handler for reading blocks of configuration data from the non-privileged VM.

### `WriteVfConfigBlock`

Pointer to the driver's implementation of the [SRIOV_WRITE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/nc-pcivirt-sriov_write_block) callback function that serves as a handler for writing blocks of configuration data from the non-privileged VM..

### `QueryProbedBars`

Pointer to the driver's implementation of the [SRIOV_QUERY_PROBED_BARS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/nc-pcivirt-sriov_query_probed_bars) callback function that allows a non-privileged VM to determine the value of the VF’s Base Address Registers if the value of -1 previously is written.

### `GetVendorAndDevice`

Pointer to the driver's implementation of the [SRIOV_GET_VENDOR_AND_DEVICE_IDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/nc-pcivirt-sriov_get_vendor_and_device_ids) callback function that supplies the values from which the Plug and Play IDs for device is derived.

### `GetDeviceLocation`

Pointer to the driver's implementation of the [SRIOV_GET_DEVICE_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/nc-pcivirt-sriov_get_device_location) callback function that allows a non-privileged VM to determine the bus to which the device is attached.

### `ResetVf`

Pointer to the driver's implementation of the [SRIOV_RESET_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/nc-pcivirt-sriov_reset_function) callback function that causes the VF to be reset.

### `SetVfPowerState`

Pointer to the driver's implementation of the [SRIOV_SET_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/nc-pcivirt-sriov_set_power_state) callback function that serves as a handle for changing the device’s power state from the non-privileged VM.

### `GetResourceForBar`

Pointer to the driver's implementation of the [SRIOV_GET_RESOURCE_FOR_BAR](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/nc-pcivirt-sriov_get_resource_for_bar) callback function that gets the translated resource for a specific BAR.

### `QueryLuid`

Pointer to the driver's implementation of the [SRIOV_QUERY_LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/nc-pcivirt-sriov_query_luid) callback function that gets the unique identifier of the VF.

## Syntax

```cpp
typedef struct _SRIOV_DEVICE_INTERFACE_STANDARD {
  USHORT                           Size;
  USHORT                           Version;
  PVOID                            Context;
  PINTERFACE_REFERENCE             InterfaceReference;
  PINTERFACE_REFERENCE             InterfaceDereference;
  PSRIOV_READ_CONFIG               ReadVfConfig;
  PSRIOV_WRITE_CONFIG              WriteVfConfig;
  PSRIOV_READ_BLOCK                ReadVfConfigBlock;
  PSRIOV_WRITE_BLOCK               WriteVfConfigBlock;
  PSRIOV_QUERY_PROBED_BARS         QueryProbedBars;
  PSRIOV_GET_VENDOR_AND_DEVICE_IDS GetVendorAndDevice;
  PSRIOV_GET_DEVICE_LOCATION       GetDeviceLocation;
  PSRIOV_RESET_FUNCTION            ResetVf;
  PSRIOV_SET_POWER_STATE           SetVfPowerState;
  PSRIOV_GET_RESOURCE_FOR_BAR      GetResourceForBar;
  PSRIOV_QUERY_LUID                QueryLuid;
} SRIOV_DEVICE_INTERFACE_STANDARD, SRIOV_DEVICE_INTERFACE_STANDARD;
```

## See also

[WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface)

[WDF_QUERY_INTERFACE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdf_query_interface_config_init)