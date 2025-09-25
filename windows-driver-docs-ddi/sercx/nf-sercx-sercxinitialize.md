# SerCxInitialize function

## Description

The **SerCxInitialize** method completes the initialization of the serial framework extension (SerCx) after this driver creates the associated device object.

## Parameters

### `FxDevice` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

### `Config` [in]

A pointer to a caller-allocated [SERCX_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx_config) structure that contains configuration information for SerCx. The caller previously called the [SERCX_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx_config_init) function to initialize this structure.

## Return value

**SerCxInitialize** returns STATUS_SUCCESS if it is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The method was called at the wrong IRQL; or the WDFDEVICE handle is not valid; or either *FxDevice* or *Config* is NULL. |
| **STATUS_INSUFFICIENT_RESOURCES** | Could not allocate system resources (typically memory). |

## Remarks

The serial controller driver calls this method after it creates the associated device object.

**SerCxInitialize** registers the controller driver’s I/O callback functions with SerCx. In addition, this method defines the transfer mode for the I/O queue. During the call, this method creates all of the internal structures required by SerCx (including the I/O queue for the serial controller). After this method returns, SerCx is ready to process I/O. However, the controller driver might configure controller hardware settings before it returns from the [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback or before it adds the PDO to the child list.

If the parameters are invalid (as described in [SERCX_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx_config)), [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development) will raise an error.

This routine must be called before committing the device (returning from [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) or adding the PDO to the child list).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[SERCX_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/ns-sercx-_sercx_config)

[SERCX_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx_config_init)