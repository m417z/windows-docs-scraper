# SpbDeviceInitialize function

## Description

The **SpbDeviceInitialize** method completes the initialization of the SPB controller driver after this driver creates the associated device object.

## Parameters

### `FxDevice` [in]

A WDFDEVICE handle to the device object that represents the SPB controller.

### `Config` [in]

A pointer to a [SPB_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_controller_config) structure that contains the device configuration information for the SPB controller driver. This structure must have been initialized by the [SPB_CONTROLLER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_controller_config_init) function.

## Return value

**SpbDeviceInitialize** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

Your SPB controller driver calls this method to register its event callback functions with the SPB framework extension (SpbCx) and to specify the transfer mode to use for the controller's I/O queue. **SpbDeviceInitialize** creates all of the controller's internal data structures, including the I/O queue.

The SPB controller driver must call this method before it *commits* the device object—that is, before it returns from the *EvtDriverDeviceAdd* callback or adds the PDO to the controller's child list. The child list represents the devices that are attached to the bus. For more information, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

After **SpbDeviceInitialize** returns, the controller is ready to process I/O requests, but the SPB controller driver can, as needed, continue to configure the controller settings before it commits the device object.

If the structure pointed to by *Config* is not filled out correctly, [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development) will raise an error. For more information about the requirements for the *Config* parameter, see [SPB_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_controller_config).

## See also

[EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device)

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[SPB_CONTROLLER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/ns-spbcx-_spb_controller_config)

[SPB_CONTROLLER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nf-spbcx-spb_controller_config_init)