# IPortableDevice::SendCommand

## Description

The **SendCommand** method sends a command to the device and retrieves the results synchronously.

## Parameters

### `dwFlags` [in]

Currently not used; specify zero.

### `pParameters` [in]

Pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that specifies the command and parameters to call on the device. This interface must include the following two values to indicate the command. Additional parameters vary depending on the command. For a list of the parameters that are required for each command, see [Commands](https://learn.microsoft.com/windows/desktop/wpd_sdk/commands).

| Command or property | Description |
| --- | --- |
| WPD_PROPERTY_COMMON_COMMAND_CATEGORY | The category **GUID** of the command to send. For example, to reset a device, you would send **WPD_COMMAND_COMMON_RESET_DEVICE.fmtid**. |
| WPD_PROPERTY_COMMON_COMMAND_ID | The PID of the command to send. For example, to reset a device, you would send **WPD_COMMAND_COMMON_RESET_DEVICE.pid**. |

### `ppResults` [out]

Address of a variable that receives a pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that indicates the results of the command results, including success or failure, and any command values returned by the device. The caller must release this interface when it is done with it. The retrieved values vary by command; see the appropriate command documentation in [Commands](https://learn.microsoft.com/windows/desktop/wpd_sdk/commands) to learn what values are returned by each command call.

## Return value

The returned value indicates success or failure to send a command and return a result from the driver; it does not indicate whether the driver supports the command or if it encountered some error in processing the command. (For more information, see Remarks.) These errors are returned in the **HRESULT** values of the *ppResults* parameter. The possible **HRESULT** values returned by this method include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The command was successfully received by the driver. This does not indicate that the command itself succeeded—you must check *ppResults* to determine the success or failure of the command. |
| **E_POINTER** | At least one of the arguments was a NULL pointer. |

## Remarks

This function is used to send a command directly to the driver. A command is a **PROPERTYKEY** that is sent to the driver to indicate the expected action, along with a list of required parameters. Each command has a list of required and optional parameters and results that must be packaged with the command for the driver to perform the requested action. A list of commands defined by Windows Portable Devices, with the required parameters and return values, is given in [Commands](https://learn.microsoft.com/windows/desktop/wpd_sdk/commands).

Most Windows Portable Devices methods actually work by sending one or more of the Windows Portable Devices commands for you and wrapping the parameters for you. Some commands have no corresponding Windows Portable Devices methods. The only way to call these commands is by using **SendCommand**. The following commands have no corresponding method:

* [WPD_COMMAND_COMMON_RESET_DEVICE](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-command-common-reset-device-command)
* [WPD_COMMAND_DEVICE_HINTS_GET_CONTENT_LOCATION](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-command-device-hints-get-content-location-command)
* [WPD_COMMAND_SMS_SEND](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-command-sms-send-command)
* [WPD_COMMAND_STILL_IMAGE_CAPTURE_INITIATE](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-command-still-image-capture-initiate-command)
* [WPD_COMMAND_STORAGE_EJECT](https://learn.microsoft.com/windows/desktop/wpd_sdk/wpd-command-storage-eject-command)

You also must call **SendCommand** to send any custom driver commands driver.

Some custom commands may require a specific Input/Output Control Code (IOCTL) access level. Your application sets this access level by calling the [IPortableDeviceValues::SetUnsignedIntegerValue](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues-setunsignedintegervalue) method on the command parameters that it passes to the **SendCommand** method. For example, if a custom command requires read-only access, you would call **SetUnsignedIntegerValue** and pass WPD_API_OPTION_IOCTL_ACCESS as the first argument and FILE_READ_ACCESS as the second argument. By updating these command parameters, your application ensures that the Windows Portable Devices API issues the command with the read-only IOCTL.

Errors that are encountered by the driver while processing a command are retrieved by the *ppResults* parameter, not by the **SendCommand** return value. The return value of this method is any error (or success) code that is encountered while sending the command to the driver.

If a driver does not support the specified command, this method will succeed, but the only guaranteed element in the returned *ppResults* parameter will be WPD_PROPERTY_COMMON_HRESULT, which will contain E_NOTIMPL. You can verify whether a driver supports a command by calling [IPortableDeviceCapabilities::GetSupportedCommands](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecapabilities-getsupportedcommands) before calling a command.

If a command supports options (such as delete recursively or delete nonrecursively), you can query for supported options by calling [IPortableDeviceCapabilities::GetCommandOptions](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicecapabilities-getcommandoptions).

There is no option to set a timeout in a call to **SendCommand** but the developer can attempt to cancel the command by calling [IPortableDevice::Cancel](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevice-cancel) from a separate thread.

#### Examples

```cpp

//

void ResetDevice(IPortableDevice* pDevice)
{
    HRESULT  hr = S_OK;
    CComPtr<IPortableDeviceValues>  pDevValues;

    hr = CoCreateInstance(CLSID_PortableDeviceValues,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IPortableDeviceValues,
        (VOID**) &pDevValues);
    if (SUCCEEDED(hr))
    {
        if (pDevValues != NULL)
        {
            hr = pDevValues->SetGuidValue(WPD_PROPERTY_COMMON_COMMAND_CATEGORY,
                WPD_COMMAND_COMMON_RESET_DEVICE.fmtid);
            if (FAILED(hr))
            {
                printf("! IPortableDeviceValues::SetGuidValue failed, hr= 0x%lx\n", hr);
            }
            hr = pDevValues->SetUnsignedIntegerValue(WPD_PROPERTY_COMMON_COMMAND_ID,
                WPD_COMMAND_COMMON_RESET_DEVICE.pid);
            if (FAILED(hr))
            {
                printf("! IPortableDeviceValues::SetGuidValue failed, hr= 0x%lx\n", hr);
            }
        }
    }
    hr = pDevice->SendCommand(0, pDevValues, &pDevValues);
    if (FAILED(hr))
    {
        printf("! Failed to reset the device, hr = 0x%lx\n",hr);
    }
    else
        printf("Device successfully reset\n");
    return;
}

//

```

## See also

[IPortableDevice Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevice)