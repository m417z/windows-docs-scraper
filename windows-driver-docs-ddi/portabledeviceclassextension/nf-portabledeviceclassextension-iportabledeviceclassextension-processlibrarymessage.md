# IPortableDeviceClassExtension::ProcessLibraryMessage

## Description

The ProcessLibraryMessage interface processes class library-specific messages and commands. A WPD driver calls this method whenever it needs to update device information (on its devnode), for example the device friendly name, enable or disable device service Plug and Play (PnP) interfaces, and so on.

## Parameters

### `pParams` [in]

An IPortableDeviceValues object that contains the library-specific command parameters. Supported commands (and associated parameters and results) are WPD_COMMAND_CLASS_EXTENSION_WRITE_DEVICE_INFORMATION, WPD_COMMAND_CLASS_EXTENSION_REGISTER_SERVICE_INTERFACES, and WPD_COMMAND_CLASS_EXTENSION_UNREGISTER_SERVICE_INTERFACES.

### `pResults` [out]

An IPortableDeviceValues object that contains the library-specific command results.

## Return value

The method returns an **HRESULT**. The possible return values are shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A required pointer argument was **NULL**. |

## Remarks

To be supplied.

## See also

[IPortableDeviceClassExtension Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portabledeviceclassextension/nn-portabledeviceclassextension-iportabledeviceclassextension)