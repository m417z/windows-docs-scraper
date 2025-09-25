# IPortableDeviceServiceCapabilities::GetEventAttributes

## Description

The **GetEventAttributes** method retrieves the attributes of an event.

## Parameters

### `Event` [in]

The event whose attributes are retrieved.

### `ppAttributes` [out]

The [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that receives the list of attributes.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

Possible attributes include the [WPD_EVENT_ATTRIBUTE_NAME](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-attributes), WPD_EVENT_ATTRIBUTE_PARAMETERS, and WPD_EVENT_ATTRIBUTE_OPTIONS properties.

#### Examples

For an example of how to use this method, see [Retrieving Supported Service Events](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-events).

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)

[Retrieving Supported Service Events](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-events)