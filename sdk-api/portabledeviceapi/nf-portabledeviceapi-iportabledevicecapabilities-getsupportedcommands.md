# IPortableDeviceCapabilities::GetSupportedCommands

## Description

The **GetSupportedCommands** method retrieves a list of all the supported commands for this device.

## Parameters

### `ppCommands` [out]

Address of a variable that receives a pointer to an [IPortableDeviceKeyCollection](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicekeycollection) interface that holds all the valid commands. For a list of commands that are defined by Windows Portable Devices, see [Commands](https://learn.microsoft.com/windows/desktop/wpd_sdk/commands). The caller must release this interface when it is done with it.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

None.

## See also

[IPortableDeviceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecapabilities)