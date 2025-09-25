## Description

Informs the class extension of a requirement to reset the device.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

## Remarks

The client driver may call the **HidSpiCxNotifyDeviceReset** function at any time when the device is in, or transitioning to D0. The class extension then calls the [**EVT_HIDSPICX_RESETDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nc-hidspicx-evt_hidspicx_resetdevice) callback for the device. The device is then reinitialized by the class extension.

## See also

[**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)

[**EVT_HIDSPICX_RESETDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nc-hidspicx-evt_hidspicx_resetdevice)