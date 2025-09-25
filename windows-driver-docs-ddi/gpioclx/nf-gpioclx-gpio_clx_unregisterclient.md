# GPIO_CLX_UnregisterClient function

## Description

The **GPIO_CLX_UnregisterClient** method removes a general-purpose I/O (GPIO) controller driver's registration with the GPIO framework extension (GpioClx).

## Parameters

### `Driver` [in]

A WDFDRIVER handle to the framework driver object for the GPIO controller driver.

## Return value

**GPIO_CLX_UnregisterClient** returns STATUS_SUCCESS if the call is successful. Possible return values include the following error code.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_FOUND** | The caller is not a registered client of GpioClx. |

## Remarks

A GPIO controller driver calls this method to cancel its registration. The driver registered in a previous call to the [GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient) method.

Typically, the GPIO controller driver calls this method from its [EvtDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_unload) event callback function, which runs shortly before the driver unloads.

## See also

[EvtDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_unload)

[GPIO_CLX_RegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_registerclient)