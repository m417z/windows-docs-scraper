# UcmTcpciDeviceInitialize function

## Description

Initializes the USB Type-C Port Controller Interface framework extension (UcmTcpciCx).

## Parameters

### `WdfDevice`

A handle to a framework device object that the client driver received in the previous call to [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Config`

A pointer to a caller-supplied [UCMTCPCI_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpcidevice/ns-ucmtcpcidevice-_ucmtcpci_device_config) structure that is initialized by calling [UCMTCPCI_DEVICE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpcidevice/nf-ucmtcpcidevice-ucmtcpci_device_config_init). This value cannot be NULL.

## Return value

(NTSTATUS) The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

| Return code | Description |
| --- | --- |
| **STATUS_INFO_LENGTH_MISMATCH** | Invalid size for the structure pointed to by *Config*. Must be size of [UCMTCPCI_DEVICE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpcidevice/ns-ucmtcpcidevice-_ucmtcpci_device_config). |
| **STATUS_INVALID_DEVICE_STATE** | The Plug and Play state of the framework device object's is uninitialized. Call [UcmTcpciDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtcpcidevice/nf-ucmtcpcidevice-ucmtcpcideviceinitialize) within the driver's implementation of [EVT_WDF_DRIVER_DEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add). |

## Remarks

The client driver must call **UcmTcpciDeviceInitialize** within the driver's implementation of [EVT_WDF_DRIVER_DEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add). This method configures the framework device object and allocates resources required, registers for PnP events, and sets up I/O targets.

## See also

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)