# IPortableDevicePropertiesBulkCallback::OnEnd

## Description

The **OnEnd** method is called by the SDK when a bulk operation that is started by [IPortableDevicePropertiesBulk::Start](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicepropertiesbulk-start) is completed.

## Parameters

### `pContext` [in]

Pointer to a GUID that identifies which operation has finished. This value is produced by a **Queue**... method of the [IPortableDevicePropertiesBulk](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulk) interface.

### `hrStatus` [out]

Contains any errors returned by the driver after the bulk operation has completed.

## Return value

The method's return value is ignored.

## See also

[IPortableDevicePropertiesBulkCallback Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicepropertiesbulkcallback)