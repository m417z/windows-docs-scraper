# IMDServiceProvider::EnumDevices

## Description

The **EnumDevices** method enumerates the installed physical or software devices that are currently attached and are known by the service provider.

## Parameters

### `ppEnumDevice` [out]

Pointer to an [IMDSPEnumDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspenumdevice) interface. If the service provider implements [IMDServiceProvider2::CreateDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdserviceprovider2-createdevice), this enumerator should only enumerate non-Plug and Play devices.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method is called on service providers that are not registered as Plug and Play aware (see [Enabling PnP for Devices](https://learn.microsoft.com/windows/desktop/WMDM/enabling-pnp-for-devices) and [Enumerating Devices](https://learn.microsoft.com/windows/desktop/WMDM/enumerating-devices-service-provider) for details). A service provider should return only the enumerator, which will enumerate only the devices that are currently attached to the computer and are supported by the service provider.

This method will be called only when an application starts, or when the application calls [IWMDeviceManager2::Reinitialize](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdevicemanager2-reinitialize).

At present, Windows Media Device Manager does not support returning installed devices.

The service provider cannot alert the application when devices connect or disconnect from the computer. If a Plug and Play device connects or disconnects and an application implements [IWMDMNotification](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmnotification), then Windows Media Device Manager will send a notification to the application.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[Enumerating Devices](https://learn.microsoft.com/windows/desktop/WMDM/enumerating-devices-service-provider)

[IMDServiceProvider Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdserviceprovider)