# IPortableDeviceServiceCapabilities::GetEventParameterAttributes

## Description

The **GetEventParameterAttributes** method retrieves the attributes of an event parameter.

## Parameters

### `Event`

The event that contains the parameter whose attributes are retrieved.

### `ppAttributes` [out]

The [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that receives the list of attributes.

### `Parameter` [in]

The parameter whose attributes are retrieved.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

Possible attribute values include the [WPD_PARAMETER_ATTRIBUTE_VARTYPE](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-attributes) and WPD_PARAMETER_ATTRIBUTE_FORM properties.

#### Examples

For an example of how to use this method, see [Retrieving Supported Service Events](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-events).

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)

[Retrieving Supported Service Events](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-events)