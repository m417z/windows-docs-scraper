# IWMDeviceManager2::Reinitialize

## Description

The **Reinitialize** method forces Windows Media Device Manager to rediscover all the Windows Media Device Manager devices.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

Windows Media Device Manager monitors Plug and Play (PnP) notifications to keep track of connected devices which are controlled by a PnP-compliant service provider. If a non-compliant device is plugged in or some other changes are made to a device for which the device does not generate PnP notifications (for example, insertion or removal of a storage card), the application should call this method before calling [IWMDeviceManager2::EnumDevices2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdevicemanager2-enumdevices2). The application would typically do this on a refresh request from the user.

## See also

[IWMDeviceManager2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdevicemanager2)

[IWMDeviceManager2::EnumDevices2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdevicemanager2-enumdevices2)