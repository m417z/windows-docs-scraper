# IMbnMultiCarrierEvents::OnPreferredProvidersChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

This notification method is called by the Mobile Broadband service to indicate the completion of a [GetPreferredProviders](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-getpreferredproviders) operation and a change in a device's preferred provider list.

## Parameters

### `mbnInterface` [in]

[IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier)

An [IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier) object that represents the Mobile Broadband device [GetPreferredProviders](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-getpreferredproviders) operation.

## Return value

This method must return **S_OK**.

## Remarks

A device's preferred provider list can be updated by the network by SMS or OTA (over The air) update. The Mobile Broadband service will call this method to notify the application about any change in the preferred provider list. The application can call the [GetPreferredProviders](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-getpreferredproviders) method of the [IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier) object to get the updated list of preferred providers.

## See also

[IMbnMultiCarrierEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrierevents)