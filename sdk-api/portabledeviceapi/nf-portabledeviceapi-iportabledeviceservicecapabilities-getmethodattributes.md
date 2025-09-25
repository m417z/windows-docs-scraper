# IPortableDeviceServiceCapabilities::GetMethodAttributes

## Description

The **GetMethodAttributes** method retrieves the attributes used to describe a given method.

## Parameters

### `Method` [in]

The method whose attributes are retrieved.

### `ppAttributes` [out]

The [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that receives the list of attributes.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

Possible attributes include the [WPD_METHOD_ATTRIBUTE_NAME](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-attributes), **WPD_METHOD_ATTRIBUTE_ASSOCIATED_FORMAT**, **WPD_METHOD_ATTRIBUTE_ACCESS**, and [WPD_METHOD_ATTRIBUTE_PARAMETERS](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-method-attributes) properties.

#### Examples

For an example of how to use this method, see [Retrieving Supported Service Methods](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-methods).

## See also

[Device Interface GUIDs](https://learn.microsoft.com/windows/desktop/wpd_sdk/device-interface-guids)

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)

[Method, Format, and Parameter Attributes](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-attributes)

[Retrieving Supported Service Methods](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-methods)