# IWMDMDevice3::SetProperty

## Description

The **SetProperty** method sets a specific device property, if it is writable.

## Parameters

### `pwszPropName` [in]

A wide character, null-terminated string name of the property to set. This overwrites any existing property with the same name. Once the application has made this call, it should free any dynamic memory using **PropVariantClear**. A list of standard property name constants is given in [Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants).

### `pValue` [in]

Value of the property being set.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method sets the specified device property. To obtain the list of supported device properties, the client should query the [IWMDMDevice3::GetProperty](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getproperty) method for the **g_wszWMDMSupportedDeviceProperties** property.

For the list of device property names, see [Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants).

This method is similar to the **SetMetadata** method for storages, but this method can set only one property at one time.

Not all properties of the device can be set.

## See also

[Enumerating Devices](https://learn.microsoft.com/windows/desktop/WMDM/enumerating-devices)

[IWMDMDevice3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice3)

[IWMDMDevice3::GetProperty](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getproperty)

[IWMDMStorage3::SetMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage3-setmetadata)

[IWMDMStorage4::GetSpecifiedMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage4-getspecifiedmetadata)

[Setting Metadata on a File](https://learn.microsoft.com/windows/desktop/WMDM/setting-metadata-on-a-file)