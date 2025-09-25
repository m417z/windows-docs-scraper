# IPortableDeviceServiceCapabilities::GetSupportedFormatProperties

## Description

The **GetSupportedFormatProperties** method retrieves the properties supported by the service for the specified format.

## Parameters

### `Format` [in]

The format whose properties are retrieved.

### `ppKeys` [out]

The [IPortableDeviceKeyCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicekeycollection) interface that receives the list of properties.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

The retrieved property collection is a superset of all properties supported by an object of the specified format.

An application can also retrieve the properties for an object by calling the [IPortableDeviceService::SendCommand](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceservice-sendcommand) method with the [WPD_COMMAND_OBJECT_PROPERTIES_GET_SUPPORTED](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-command-object-properties-get-supported2) property passed as the command identifier. However, the **GetSupportedFormatProperties** method is typically faster than the **IPortableDeviceService::SendCommand** method.

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)