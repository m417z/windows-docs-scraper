# IPortableDeviceServiceCapabilities::GetSupportedCommands

## Description

The **GetSupportedCommands** method retrieves the commands supported by the service.

## Parameters

### `ppCommands` [out]

The [IPortableDeviceKeyCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicekeycollection) interface that receives the list of commands.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)