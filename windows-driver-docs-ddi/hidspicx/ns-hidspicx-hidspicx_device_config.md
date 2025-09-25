## Description

The **HIDSPICX_DEVICE_CONFIG** structure provides configuration information to the class extension.

## Members

### `Size`

This field is set by the [**HIDSPICX_DEVICE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nf-hidspicx-hidspicx_device_config_init) function.

### `EvtResetDevice`

A pointer to the client driver's implementation of the [**EVT_HIDSPICX_RESETDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nc-hidspicx-evt_hidspicx_resetdevice) callback function.

### `EvtNotifyPowerDown`

A pointer to the client driver's implementation of the [**EVT_HIDSPICX_NOTIFY_POWERDOWN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nc-hidspicx-evt_hidspicx_notify_powerdown) callback function.

### `InputReportQueue`

A **WDFQUEUE** handle to a client-created, non-power-managed, queue for receipt of input report requests from the HID SPI class extension.

### `OutputReportQueue`

A **WDFQUEUE** handle to a client-created, non-power-managed, queue for receipt of output report requests from the HID SPI class extension.

### `NumberOfInputReportRequestsToPend`

**Optional:** Specifies how many requests are to be placed in the input report queue at a given time. If this is zero, the class extension will choose a default.

### `Reserved`

Must be zero and should not be explicitly set by client drivers.

## Remarks

Instances of this structure must be initialized by calling the [**HIDSPICX_DEVICE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nf-hidspicx-hidspicx_device_config_init) function.

## See also

[**HIDSPICX_DEVICE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidspicx/nf-hidspicx-hidspicx_device_config_init)