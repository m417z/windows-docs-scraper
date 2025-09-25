# IPortableDeviceProperties::GetValues

## Description

The **GetValues** method retrieves a list of specified properties from a specified object on a device.

## Parameters

### `pszObjectID` [in]

Pointer to a null-terminated string that contains the ID of the object to query. To specify the device, use WPD_DEVICE_OBJECT_ID.

### `pKeys` [in]

Pointer to an [IPortableDeviceKeyCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicekeycollection) interface that contains one or more properties to query for. If this is **NULL**, all properties will be retrieved. See [Properties and Attributes](https://learn.microsoft.com/windows/desktop/wpd_sdk/properties-and-attributes) for a list of properties that are defined by Windows Portable Devices.

### `ppValues` [out]

Address of a variable that receives a pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that contains the requested property values. These will be returned as PROPERTYKEY/value pairs, where the data type of the value depends on the property. If a value could not be retrieved for some reason, the returned type will be VT_ERROR, and contain an HRESULT value describing the retrieval error. The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | All requested property values were retrieved. |
| **S_FALSE** | One or more property values could not be retrieved. The problem properties will have an HRESULT value in the retrieved *ppValues* parameter. |

## See also

[IPortableDeviceProperties Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceproperties)

[IPortableDeviceProperties::SetValues](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledeviceproperties-setvalues)

[Retrieving Content-Object Properties](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-content-object-properties)

[Retrieving Properties for a Single Object](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-properties-for-a-single-object)

[Retrieving the Rendering Capabilities Supported by a Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-the-rendering-capabilities-supported-by-a-device)