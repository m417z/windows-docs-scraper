# IWMDeviceManager::EnumDevices

## Description

The **EnumDevices** method retrieves a pointer to the [IWMDMEnumDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumdevice) interface that can be used to enumerate portable devices connected to the computer.

## Parameters

### `ppEnumDevice` [out]

Pointer to a pointer to an [IWMDMEnumDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumdevice) interface used to enumerate devices. The caller must release this interface when done with it.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method returns devices based on earlier versions of Windows Media Device Manager. To get all devices, including newer devices (such as MTP devices), call [IWMDMDeviceManager2::EnumDevices2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdevicemanager2-enumdevices2).

## See also

[Enumerating Devices](https://learn.microsoft.com/windows/desktop/WMDM/enumerating-devices)

[IWMDMEnumDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumdevice)

[IWMDeviceManager Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdevicemanager)

[IWMDeviceManager2::EnumDevices2](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdevicemanager2-enumdevices2)