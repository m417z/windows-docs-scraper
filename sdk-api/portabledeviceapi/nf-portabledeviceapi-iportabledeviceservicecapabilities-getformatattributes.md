# IPortableDeviceServiceCapabilities::GetFormatAttributes

## Description

The **GetFormatAttributes** method retrieves the attributes of a format.

## Parameters

### `Format` [in]

The format whose attributes are retrieved.

### `ppAttributes` [out]

The [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that receives the list of attributes.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

[WPD_FORMAT_ATTRIBUTE_NAME](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-format-attributes) is an example of a commonly retrieved attribute.

#### Examples

For an example of how to use this method, see [Retrieving Supported Service Formats](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-formats).

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)

[Retrieving Supported Service Formats](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-supported-formats)