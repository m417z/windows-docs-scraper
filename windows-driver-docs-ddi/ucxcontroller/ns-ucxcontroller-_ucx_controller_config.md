# _UCX_CONTROLLER_CONFIG structure

## Description

This structure configuration data for a USB controller.

## Members

### `Size`

The size in bytes of this structure.

### `NumberOfPresentedDeviceMgmtEvtCallbacks`

The number of device event callback functions provided by this structure.

### `EvtControllerQueryUsbCapability`

A pointer to an [EVT_UCX_CONTROLLER_QUERY_USB_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_query_usb_capability) callback function.

### `Reserved1`

Do not use.

### `EvtControllerGetCurrentFrameNumber`

A pointer to an [EVT_UCX_CONTROLLER_GET_CURRENT_FRAMENUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_get_current_framenumber) call back function.

### `EvtControllerUsbDeviceAdd`

A pointer to an [EVT_UCX_CONTROLLER_USBDEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_usbdevice_add) callback function.

### `EvtControllerReset`

A pointer to an [EVT_UCX_CONTROLLER_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_reset) callback function.

### `Reserved2`

Do not use.

### `Reserved3`

Do not use.

### `Reserved4`

Do not use.

### `ParentBusType`

The parent bus type of the USB controller.

### `PciDeviceInfo`

Information about the PCI USB controller (if present).

### `AcpiDeviceInfo`

Information about the advanced configuration and power interface (ACPI) USB controller (if present).

### `DeviceDescription`

A description for the device.

### `ManufacturerNameString`

String containing the manufacturer name.

### `ModelNameString`

String containing the model name of the controller hardware.

### `ModelNumberString`

String containing the model number of the controller hardware.

### `EvtControllerGetTransportCharacteristics`

A pointer to an [EVT_UCX_CONTROLLER_GET_TRANSPORT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_get_transport_characteristics) callback function.

### `EvtControllerSetTransportCharacteristicsChangeNotification`

A pointer to an [EVT_UCX_CONTROLLER_SET_TRANSPORT_CHARACTERISTICS_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_set_transport_characteristics_change_notification) callback function.

### `Reserved5`

Do not use.

### `Reserved6`

Do not use.

### `Reserved7`

Do not use.