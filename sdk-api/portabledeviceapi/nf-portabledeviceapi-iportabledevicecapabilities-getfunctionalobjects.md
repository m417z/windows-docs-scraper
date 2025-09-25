# IPortableDeviceCapabilities::GetFunctionalObjects

## Description

The [GetFunctionalObjects](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecapabilities) method retrieves all functional objects that match a specified category on the device.

## Parameters

### `Category` [in]

A **REFGUID** that specifies the category to search for. This can be WPD_FUNCTIONAL_CATEGORY_ALL to return all functional objects.

### `ppObjectIDs` [out]

Address of a variable that receives a pointer to an [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that contains the object IDs of the functional objects as strings (type VT_LPWSTR in the retrieved **PROPVARIANT** items). If no objects of the requested type are found, this will be an empty collection (not **NULL**). The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This operation is usually fast, because the driver does not need to perform a full content enumeration, and the number of retrieved functional objects is typically less than 10. If no objects of the requested type are found, this method will not return an error, but returns an empty collection for *ppObjectIDs*.

#### Examples

For an example of how to use this method, see [Retrieving the Functional Object Identifiers for a Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-the-functional-object-identifiers-for-a-device)

## See also

[IPortableDeviceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecapabilities)

[Retrieving the Functional Object Identifiers for a Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-the-functional-object-identifiers-for-a-device)

[Retrieving the Rendering Capabilities Supported by a Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/retrieving-the-rendering-capabilities-supported-by-a-device)