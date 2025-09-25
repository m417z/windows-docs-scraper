# IPortableDeviceServiceCapabilities::GetMethodParameterAttributes

## Description

The **GetMethodParameterAttributes** method retrieves the attributes used to describe a given method parameter.

## Parameters

### `Method`

The method that contains the parameter whose attributes are retrieved.

### `ppAttributes` [out]

The [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that receives the list of attributes.

### `Parameter` [in]

The parameter whose attributes are retrieved.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

Possible attributes include the [WPD_PARAMETER_ATTRIBUTE_ORDER](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-attributes), **WPD_PARAMETER_ATTRIBUTE_USAGE**, **WPD_PARAMETER_ATTRIBUTE_NAME**, and **WPD_PARAMETER_ATTRIBUTE_VARTYPE** properties.

#### Examples

For an example of how to use this method, see [Retrieving Supported Service Methods](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-methods).

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)

[Retrieving Supported Service Methods](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-methods)