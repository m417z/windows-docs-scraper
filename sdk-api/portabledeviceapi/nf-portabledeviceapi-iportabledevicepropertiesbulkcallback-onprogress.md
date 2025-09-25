# IPortableDevicePropertiesBulkCallback::OnProgress

## Description

The **OnProgress** method is called by the SDK when a bulk operation started by [IPortableDevicePropertiesBulk::Start](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicepropertiesbulk-start) has sent data to the device and received some information back.

## Parameters

### `pContext` [in]

Pointer to a GUID that identifies which operation is in progress. This value is produced by a **Queue**... method of the [IPortableDevicePropertiesBulk](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulk) interface.

### `pResults` [in]

Pointer to an [IPortableDeviceValuesCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevaluescollection) interface that contains the results retrieved from the device. This interface will hold one or more [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interfaces. Each of these interfaces will hold one [WPD_OBJECT_ID](https://learn.microsoft.com/windows/desktop/wpd_sdk/object-properties) property with a string value (VT_LPSTR) specifying the object ID of the object that these values pertain to. The rest of the values in each **IPortableDeviceValues** interface vary, depending on the bulk operation being reported. For the **QueueGetValuesByObjectFormat** and **QueueGetValuesByObjectList** methods, they will be retrieved values of varying types. For [QueueSetValuesByObjectList](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicepropertiesbulk-queuesetvaluesbyobjectlist), they will be **VT_ERROR****HRESULT** values for any errors encountered when setting values.

## Return value

The application should return either S_OK, or an error code to abandon the operation. All error codes are handled the same way.

## Remarks

This method can be called once or multiple times, depending on how large the operation is.

This method does not necessarily retrieve all properties at once, nor does it return the properties in a particular order.

If this method is called multiple times, it may return properties for the same object identifier each time.

## See also

[IPortableDevicePropertiesBulkCallback Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulkcallback)