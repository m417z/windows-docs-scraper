# IPortableDeviceCapabilities::GetSupportedContentTypes

## Description

The **GetSupportedContentTypes** method retrieves all supported content types for a specified functional object type on a device.

## Parameters

### `Category` [in]

A **REFGUID** that specifies a functional object category. To get a list of functional categories on the device, call [IPortableDeviceCapabilities::GetFunctionalCategories](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecapabilities-getfunctionalcategories).

### `ppContentTypes` [out]

Address of a variable that receives a pointer to an [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that lists all the supported object types for the specified functional object category. These object types will be **GUID** values of type VT_CLSID in the retrieved **PROPVARIANT** items. See [Requirements for Objects](https://learn.microsoft.com/windows/desktop/wpd_sdk/requirements-for-objects) for a list of object types defined by Windows Portable Devices. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IPortableDeviceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecapabilities)

[Retrieving the Content Types Supported by a Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-the-content-types-supported-by-a-device)