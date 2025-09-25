# IPortableDeviceServiceCapabilities::GetFormatPropertyAttributes

## Description

The **GetFormatPropertyAttributes** method retrieves the attributes of a format property.

## Parameters

### `Format` [in]

The format whose property has its attributes retrieved.

### `Property` [in]

The property whose attributes are retrieved.

### `ppAttributes` [out]

The [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that receives the list of attributes.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## Remarks

A Windows Portable Devices (WPD) driver often treats objects of a given format the same. Many properties will therefore have attributes that are identical across all objects of that format. This method retrieves such attributes.

Note that this method will not retrieve attributes that differ across object instances.

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)