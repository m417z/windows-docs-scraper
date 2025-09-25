# IPortableDeviceService::GetServiceObjectID

## Description

The **GetServiceObjectID** method retrieves an object identifier for the service. This object identifier can be used to access the properties of the service, for example.

## Parameters

### `ppszServiceObjectID` [out]

The retrieved service object identifier.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## See also

[IPortableDeviceService Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservice)