# IMbnInterfaceEvents::OnPreferredProvidersChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

This notification method is called by the Mobile Broadband service to indicate a change in a device's preferred provider list.

## Parameters

### `newInterface` [in]

An [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) that represents the Mobile Broadband device whose preferred provider list has changed.

## Return value

This method must return **S_OK**.

## Remarks

In some cases, a device's preferred provider list can be updated by the network by SMS or OTA (over The air) update. The Mobile Broadband service will call this method to notify the application about any change in the preferred provider list. The application can call the [GetPreferredProviders](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getpreferredproviders) method of the passed [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) to get the updated list of preferred providers.

If there is a change in the preferred provider list because of a call to the [SetPreferredProviders](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-setpreferredproviders) method of [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface), then this notification will not be called.

## See also

[IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents)