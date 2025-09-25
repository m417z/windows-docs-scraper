# IPortableDeviceWebControl::GetDeviceFromIdAsync

## Description

Instantiates a WPD Automation [Device](https://learn.microsoft.com/previous-versions/windows/desktop/wiaaut/-wiaaut-device) object asynchronously for a given WPD device identifier.

## Parameters

### `deviceId` [in]

A **BSTR** that is used by Plug-and-play to identify a currently connected WPD device. The Plug and Play (PnP) identifier for a particular device can be obtained from the [IPortableDeviceManager::GetDevices](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevicemanager-getdevices) method in the WPD C++/COM API.

A Windows Store app can obtain the PnP identifier of a WPD device by using [Windows.Devices.Portable.ServiceDevice.GetDeviceSelector](https://learn.microsoft.com/uwp/api/windows.devices.portable.servicedevice.getdeviceselector) or [Windows.Devices.Portable.ServiceDevice.GetDeviceSelectorFromServiceId](https://learn.microsoft.com/uwp/api/windows.devices.portable.servicedevice.getdeviceselectorfromserviceid) to get a selector string to pass to [Windows.Devices.Enumeration.DeviceInformation.FindAllAsync](https://learn.microsoft.com/uwp/api/windows.devices.enumeration.deviceinformation.findallasync). [FindAllAsync](https://learn.microsoft.com/uwp/api/windows.devices.enumeration.deviceinformation.findallasync) returns a collection of [DeviceInformation](https://learn.microsoft.com/uwp/api/windows.devices.enumeration.deviceinformation) objects that represent the currently connected WPD devices. A **DeviceInformation** object's [Id](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice-id-vb) property is the device's PnP identifier.

### `pCompletionHandler` [in]

A completion handler.

### `pErrorHandler` [in]

An error handler.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_ACCESSDENIED** | A call to this method outside of a Windows Store app running on Windows 8 will return this error code. |

## Remarks

**Note** This method can only be used in Windows Store apps.

#### Examples

For WPD devices that use an MTP device service, you can create a COM Automation object to work with the device like this:

```javascript

deviceFactory = new ActiveXObject("PortableDeviceAutomation.Factory");

// Get the first device object from the device factory
        deviceFactory.getDeviceFromIdAsync(deviceInfoElement.id,
            function (device) {
                // Get the first service on the device
                var deviceService = device.services[0];
                // Get the first storage on the device
                var deviceStorage = devices.storages[0];
                // …
            }
       }

```

## See also

[IPortableDeviceWebControl](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledevicewebcontrol)

[Portable Device Service Sample](https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/PortableDeviceServices)