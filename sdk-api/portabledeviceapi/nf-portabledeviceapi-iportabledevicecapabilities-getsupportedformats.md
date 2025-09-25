# IPortableDeviceCapabilities::GetSupportedFormats

## Description

The **GetSupportedFormats** method retrieves the supported formats for a specified object type on the device. For example, specifying audio objects might return **WPD_OBJECT_FORMAT_WMA**, **WPD_OBJECT_FORMAT_WAV**, and **WPD_OBJECT_FORMAT_MP3**.

## Parameters

### `ContentType` [in]

A **REFGUID** that specifies a content type, such as image, audio, or video. For a list of content types that are defined by Windows Portable Devices, see [Requirements for Objects](https://learn.microsoft.com/windows/desktop/wpd_sdk/requirements-for-objects).

### `ppFormats` [out]

Address of a variable that receives a pointer to an [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that lists the supported formats for the specified content type. These are GUID values (type VT_CLSID) in the retrieved collection items. For a list of formats that are supported by Windows Portable Devices, see [Object Formats](https://learn.microsoft.com/windows/desktop/wpd_sdk/object-format-guids). The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | At least one of the arguments was a **NULL** pointer. |

## See also

[IPortableDeviceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecapabilities)

[IPortableDeviceCapabilities::GetSupportedFormatProperties](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecapabilities-getsupportedformatproperties)