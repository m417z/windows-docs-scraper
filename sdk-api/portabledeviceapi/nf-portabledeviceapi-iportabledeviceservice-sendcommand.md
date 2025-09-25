# IPortableDeviceService::SendCommand

## Description

The **SendCommand** method sends a standard WPD command and its parameters to the service.

## Parameters

### `dwFlags` [in]

Not used.

### `pParameters` [in]

The [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface specifying the command parameters.

### `ppResults` [out]

The [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface specifying the command results.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

This method should only be used to send standard WPD commands to the service. To invoke service methods, use the [IPortableDeviceServiceMethods](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicemethods) interface.

This method may fail even though it returns **S_OK** as its **HRESULT** value. To determine if a command succeeded, an application should always examine the properties referenced by the *ppResults* parameter:

* The [WPD_PROPERTY_COMMON_HRESULT](https://learn.microsoft.com/windows/desktop/wpd_sdk/common-properties) property indicates if the command succeeded.
* If the command failed, the [WPD_PROPERTY_COMMON_DRIVER_ERROR_CODE](https://learn.microsoft.com/windows/desktop/wpd_sdk/common-properties) property will contain driver-specific error codes.

The object referenced by the *pParameters* parameter must specify at least these properties:

* [WPD_PROPERTY_COMMON_COMMAND_CATEGORY](https://learn.microsoft.com/windows/desktop/wpd_sdk/common-properties), which should contain a command category, such as the **fmtid** member of the [WPD_COMMAND_COMMON_RESET_DEVICE](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-command-common-reset-device-command) property
* [WPD_PROPERTY_COMMON_COMMAND_ID](https://learn.microsoft.com/windows/desktop/wpd_sdk/common-properties), which should contain a command identifier, such as the **pid** member of the [WPD_COMMAND_COMMON_RESET_DEVICE](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-command-common-reset-device-command) property.

## See also

[IPortableDeviceService Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice)