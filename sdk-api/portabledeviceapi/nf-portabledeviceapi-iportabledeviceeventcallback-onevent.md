# IPortableDeviceEventCallback::OnEvent

## Description

The **OnEvent** method is called by the SDK to notify the application about asynchronous events.

## Parameters

### `pEventParameters` [in]

Pointer to an [IPortableDeviceValues](https://learn.microsoft.com/windows/desktop/wpd_sdk/iportabledevicevalues) interface that contains event details.

## Return value

Any values returned by the application are ignored by Windows Portable Devices.

## Remarks

The application must register to receive events by calling [IPortableDevice::Advise](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nf-portabledeviceapi-iportabledevice-advise).

#### Examples

For an example of how to use this method, see [Handling Events from the Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/handling-events-from-the-device).

## See also

[Handling Events from the Device](https://learn.microsoft.com/windows/desktop/wpd_sdk/handling-events-from-the-device)

[IPortableDeviceEventCallback Interface](https://learn.microsoft.com/windows/desktop/api/portabledeviceapi/nn-portabledeviceapi-iportabledeviceeventcallback)