# IPortableDevicePropertiesBulk::QueueGetValuesByObjectList

## Description

The **QueueGetValuesByObjectList** method queues a request for one or more specified properties from one or more specified objects on the device.

## Parameters

### `pObjectIDs` [in]

Pointer to an [IPortableDevicePropVariantCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) interface that lists the object IDs of all the objects to query. These will be of type VT_LPWSTR.

### `pKeys` [in]

Pointer to an [IPortableDeviceKeyCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicekeycollection) interface that specifies the properties to request. For a list of properties defined by Windows Portable Devices, see [Properties and Attributes](https://learn.microsoft.com/windows/desktop/wpd_sdk/properties-and-attributes). Specify **NULL** to indicate all properties from the specified objects.

### `pCallback` [in]

Pointer to an application-implemented [IPortableDevicePropertiesBulkCallback](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulkcallback) interface that will receive the information as it is retrieved.

### `pContext` [out]

Pointer to a GUID that is used to start, cancel, or identify the request **IPortableDevicePropertiesBulkCallback** callbacks, if implemented.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The queued request is not started until the application calls [Start](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicepropertiesbulk-start). For more information on how to use this method, see [IPortableDevicePropertiesBulk Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulk).

Due to performance issues, some devices may not return a comprehensive list of properties when the *pKeys* parameter is **NULL**.

## See also

[IPortableDevicePropertiesBulk Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulk)

[IPortableDevicePropertiesBulk::QueueSetValuesByObjectList](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicepropertiesbulk-queuesetvaluesbyobjectlist)