# UcmTcpciPortControllerCreate function

## Description

Creates a port controller object to register with UcmTcpciCx.

## Parameters

### `WdfDevice`

A handle to a framework device object that the client driver received in the previous call to [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Config`

A pointer to the [UCMTCPCI_PORT_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/ns-ucmtcpciportcontroller-_ucmtcpci_port_controller_config) that is initialized by calling **UCMTCPCI_PORT_CONTROLLER_CONFIG_INIT**. This value cannot be NULL.

### `Attributes`

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied attributes for the new object. This parameter is optional and can be **WDF_NO_OBJECT_ATTRIBUTES**.

### `PortControllerObject`

A pointer to a location that receives a handle to the new port controller object.

## Return value

(NTSTATUS) The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The handle to a framework device object is invalid. |
| **STATUS_INFO_LENGTH_MISMATCH** | Invalid size for the structure pointed to by *Config* or  *Config->Capabilities*. Must be size of [UCMTCPCI_PORT_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/ns-ucmtcpciportcontroller-_ucmtcpci_port_controller_config) or [UCMTCPCI_PORT_CONTROLLER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/ns-ucmtcpciportcontroller-_ucmtcpci_port_controller_capabilities), respectively. |

## See also

[EVT_WDF_DRIVER_DEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[UCMTCPCI_PORT_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpciportcontroller/ns-ucmtcpciportcontroller-_ucmtcpci_port_controller_config)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)