## Description

The **HIDSPICX_DEVICE_CONFIG_INIT** routine is used to initialize a [**HIDSPICX_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/ns-hidspicx-hidspicx_device_config) structure before passing it to the to the **HidSpiCxDeviceConfigure** function.

## Parameters

### `DeviceConfig`

A pointer to the client driver-allocated [**HIDSPICX_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/ns-hidspicx-hidspicx_device_config) structure.

### `EvtResetDevice`

A pointer to the client driver's implementation of the [**EVT_HIDSPICX_RESETDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nc-hidspicx-evt_hidspicx_resetdevice) callback function.

### `EvtNotifyPowerDown`

A pointer to the client driver's implementation of the [**EVT_HIDSPICX_NOTIFY_POWERDOWN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nc-hidspicx-evt_hidspicx_notify_powerdown) callback function.

### `InputReportQueue`

A **WDFQUEUE** handle to a client-created, non-power-managed, queue for receipt of input report requests from the HID SPI class extension.

### `OutputReportQueue`

A **WDFQUEUE** handle to a client-created, non-power-managed, queue for receipt of output report requests from the HID SPI class extension.

## Remarks

Before passing a [**HIDSPICX_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/ns-hidspicx-hidspicx_device_config) structure pointer to the [**HidSpiCxDeviceConfigure**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nf-hidspicx-hidspicxdeviceconfigure) function, it must first be initialized by a call to this macro.

## See also

[**HidSpiCxDeviceConfigure**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nf-hidspicx-hidspicxdeviceconfigure)

[**HIDSPICX_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/ns-hidspicx-hidspicx_device_config)

[**EVT_HIDSPICX_RESETDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nc-hidspicx-evt_hidspicx_resetdevice)

[**EVT_HIDSPICX_NOTIFY_POWERDOWN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nc-hidspicx-evt_hidspicx_notify_powerdown)