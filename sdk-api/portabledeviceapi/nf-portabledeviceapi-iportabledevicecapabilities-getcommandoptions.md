# IPortableDeviceCapabilities::GetCommandOptions

## Description

The **GetCommandOptions** method retrieves all the supported options for the specified command on the device.

## Parameters

### `Command` [in]

A **REFPROPERTYKEY** that specifies a command to query for supported options. For a list of the commands that are defined by Windows Portable Devices, see [Commands](https://learn.microsoft.com/windows/desktop/wpd_sdk/commands).

### `ppOptions` [out]

Address of a variable that receives a pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that contains the supported options. If no options are supported, this will not contain any values. The caller must release this interface when it is done with it. For more information, see Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is called by applications that want to call a command directly on the driver by calling [IPortableDevice::SendCommand](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevice-sendcommand). Some commands allow the caller to specify additional options. For example, some drivers support recursive child deletion when deleting an object using the WPD_COMMAND_OBJECT_MANAGEMENT_DELETE_OBJECTS command.

If an option is a simple Boolean value, the key of the retrieved [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface will be the name of the option, and the **PROPVARIANT** value will be a VT_BOOL value of True or False. If an option has several values, the retrieved **PROPVARIANT** value will be a collection type that holds the supported values.

If this method is called for the WPD_COMMAND_STORAGE_FORMAT command and the *ppOptions* parameter is set to WPD_OPTION_VALID_OBJECT_IDS, the driver will return an [IPortableDevicePropVariant](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicepropvariantcollection) collection of type VT_LPWSTR that specifies the identifiers for each object on the device that can be formatted. (If this option does not exist, the format command is available for all objects.)

## See also

[IPortableDeviceCapabilities Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicecapabilities)