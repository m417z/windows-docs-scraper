# IPortableDeviceServiceCapabilities::GetCommandOptions

## Description

The **GetCommandOptions** method retrieves the options of a WPD command.

## Parameters

### `Command` [in]

The command whose options are retrieved.

### `ppOptions` [out]

The [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that receives the list of options.

## Return value

If the method succeeds, it returns **S_OK**. Any other **HRESULT** value indicates that the call failed.

## See also

[IPortableDeviceServiceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceservicecapabilities)