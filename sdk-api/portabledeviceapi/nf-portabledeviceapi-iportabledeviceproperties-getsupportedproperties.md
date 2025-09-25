# IPortableDeviceProperties::GetSupportedProperties

## Description

The **GetSupportedProperties** method retrieves a list of properties that a specified object supports. Note that not all of these properties may actually have values.

## Parameters

### `pszObjectID` [in]

Pointer to a null-terminated string that contains the object ID of the object to query. To specify the device, use **WPD_DEVICE_OBJECT_ID**.

### `ppKeys` [out]

Address of a variable that receives a pointer to an [IPortableDeviceKeyCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicekeycollection) interface that contains the supported properties. For a list of properties defined by Windows Portable Devices, see [Properties and Attributes](https://learn.microsoft.com/windows/desktop/wpd_sdk/properties-and-attributes). The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To get the values of supported properties, call **GetPropertyAttributes**.

## See also

[IPortableDeviceProperties Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceproperties)