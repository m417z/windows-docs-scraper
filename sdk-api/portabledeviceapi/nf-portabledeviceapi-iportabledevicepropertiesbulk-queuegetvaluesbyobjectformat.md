# IPortableDevicePropertiesBulk::QueueGetValuesByObjectFormat

## Description

The **QueueGetValuesByObjectFormat** interface queues a request for properties of objects of a specific format on a device.

## Parameters

### `pguidObjectFormat` [in]

Pointer to a **GUID** that specifies the object format. Only objects of this type are queried.

### `pszParentObjectID` [in]

Pointer to a null-terminated string that contains the object ID of the parent object where the search should begin. To search all the objects on a device, specify **WPD_DEVICE_OBJECT_ID**.

### `dwDepth` [in]

The maximum depth to search below the parent, where 1 means immediate children only. It is acceptable for this number to be greater than the actual number of levels. To search to any depth, specify 0xFFFFFFFF

### `pKeys` [in]

Pointer to an **IPortableDeviceKeyCollection** interface that contains the properties to retrieve. For a list of properties that are defined by Windows Portable Devices, see [Properties and Attributes](https://learn.microsoft.com/windows/desktop/wpd_sdk/properties-and-attributes). Specify **NULL** to indicate all properties from the specified format.

### `pCallback` [in]

Pointer to an application-implemented [IPortableDevicePropertiesBulkCallback](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulkcallback) interface that will receive the information as it is retrieved.

### `pContext` [out]

Pointer to a GUID that will be used to start, cancel, or identify the request in **IPortableDevicePropertiesBulkCallback** callbacks, if implemented.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was queued successfully. |

## Remarks

If you specify WPD_OBJECT_FORMAT_ALL for the *pguidObjectFormat* parameter, this method will return properties for all objects on the device.

If the *pszParentObjectID* parameter is set to an empty string (""), the method will perform a search that is dependent on the *dwDepth* parameter as described in the following table.

|  |  |
| --- | --- |
| **dwDepth** | **Method returns** |
| 0 | No results |
| 1 | Values for the specified device only. |
| 2 | Values for the specified device and all functional objects found on that device. |

If the *pszParentObjectID* parameter is set to WPD_DEVICE_OBJECT_ID, the method will perform a search that is dependent on the *dwDepth* parameter as described in the following table.

|  |  |
| --- | --- |
| **dwDepth** | **Method returns** |
| 0 | Values for the specified device only. |
| 1 | Values for the specified device and all functional objects found on that device. |

The queued request is not started until the application calls [Start](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicepropertiesbulk-start). For more information on how to use this method, see [IPortableDevicePropertiesBulk Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulk).

Due to performance issues, some devices may not return a comprehensive list of properties when the *pKeys* parameter is **NULL**.

## See also

[IPortableDevicePropertiesBulk Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulk)