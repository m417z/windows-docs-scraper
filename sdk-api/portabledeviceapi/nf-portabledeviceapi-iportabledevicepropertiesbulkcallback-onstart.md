# IPortableDevicePropertiesBulkCallback::OnStart

## Description

The **OnStart** method is called by the SDK when a bulk operation started by [IPortableDevicePropertiesBulk::Start](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicepropertiesbulk-start) is about to begin.

## Parameters

### `pContext` [in]

Pointer to a GUID that identifies which operation has started. This value is produced by a **Queue**... method of the [IPortableDevicePropertiesBulk](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulk) interface.

## Return value

The application should return either S_OK or an error code to abandon the operation. The application should handle all error codes in the same manner.

## See also

[IPortableDevicePropertiesBulkCallback Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulkcallback)