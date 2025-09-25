# IPortableDevicePropertiesBulk::QueueSetValuesByObjectList

## Description

The **QueueSetValuesByObjectList** method queues a request to set one or more specified values on one or more specified objects on the device.

## Parameters

### `pObjectValues` [in]

Pointer to an [IPortableDeviceValuesCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevaluescollection) interface that contains the properties and values to set on specified objects. This interface holds one or more [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interfaces, each representing a single object. Each **IPortableDeviceValues** interface holds a collection of key/value pairs, where the key is the **PROPERTYKEY** identifying the property, and the value is a data type that varies by property. Each **IPortableDeviceValues** interface also holds one WPD_OBJECT_ID property that identifies the object to which this interface refers.

### `pCallback` [in]

Pointer to an application-implemented [IPortableDevicePropertiesBulkCallback](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulkcallback) interface that will receive the information as it is retrieved.

### `pContext` [out]

Pointer to a GUID that is used to start, cancel, or identify the request to any client-implemented **IPortableDevicePropertiesBulkCallback** callbacks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was queued successfully. |

## Remarks

The queued request is not started until the application calls [Start](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicepropertiesbulk-start). For more information on how to use this method, see [IPortableDevicePropertiesBulk Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulk).

## See also

[IPortableDevicePropertiesBulk Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulk)

[IPortableDevicePropertiesBulk::QueueGetValuesByObjectList](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicepropertiesbulk-queuegetvaluesbyobjectlist)