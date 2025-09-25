# NetDeviceOpenConfiguration function

## Description

The **NetDeviceOpenConfiguration** function opens a net device's configuration database.

## Parameters

### `Device` [_In_]

The WDFDEVICE object the client driver previously created with a call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `ConfigurationAttributes` [_In_opt_]

A pointer to a [**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied attributes for the new configuration object. This parameter is optional and can be **WDF_NO_OBJECT_ATTRIBUTES**.

### `Configuration` [_Out_]

A pointer to the location that receives the new NETCONFIGURATION object.

## Return value

This function returns STATUS_SUCCESS if the operation succeeds. Otherwise, this function may return an appropriate NTSTATUS error code.

## Remarks

Typically, the client calls this function from its [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

If the client provides a [**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes), it specifies **NULL** for **ParentObject**. The device configuration object is automatically parented to the device object.

As a result, WDF automatically deletes the configuration object when the device is deleted. However, the client can manually delete a configuration object by calling [**WdfObjectDelete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete), typically from its [*EVT_WDF_OBJECT_CONTEXT_CLEANUP*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) callback function.

## See also

[Accessing configuration information](https://learn.microsoft.com/windows-hardware/drivers/netcx/accessing-configuration-information)