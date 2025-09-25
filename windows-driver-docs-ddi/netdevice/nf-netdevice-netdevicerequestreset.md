## Description

The **NetDeviceRequestReset** function triggers the NetAdapterCx framework to perform the platform-level device reset operation that recovers an unresponsive NIC device.

## Parameters

### `Device` [_In_]

The WDFDEVICE object the client driver previously created with a call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

## Remarks

A client driver calls **NetDeviceRequestReset** when it detects device failure. **NetDeviceRequestReset** returns immediately to the client driver. The driver can only call **NetDeviceRequestReset** at PASSIVE_LEVEL.

**NetDeviceRequestReset** is nonblocking and returns immediately to the client driver. The client driver should cancel any ongoing jobs that access the currently failed device.

We recommend that client drivers set up a [**NET_DEVICE_RESET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-net_device_reset_capabilities) structure to collect meaningful reset diagnostics during the device reset and recovery process.
For more on how to collect reset diagnostics, see [Register the optional diagnostics collection callback](https://learn.microsoft.com/windows-hardware/drivers/netcx/platform-level-device-reset/#register-the-optional-diagnostics-collection-callback).

**NetDeviceRequestReset** is only applicable for PCIe based NIC devices. For USB based NIC devices, follow the process described in [How to recover from USB pipe errors](https://learn.microsoft.com/windows-hardware/drivers/usbcon/how-to-recover-from-usb-pipe-errors).

If the device encounters an unrecoverable hardware or software error, the client driver can use the [WdfDeviceSetFailed](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetfailed) function.

## See also

[Recovering an unresponsive NIC with NetAdapterCx PLDR](https://learn.microsoft.com/windows-hardware/drivers/netcx/platform-level-device-reset/)

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[**NET_DEVICE_RESET_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdevice/ns-netdevice-net_device_reset_capabilities)