# IMbnMultiCarrier::GetVisibleProviders

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the list of visible providers in the current area for a multi-carrier device minus preferred and registered providers.

## Parameters

### `age` [out]

A pointer to the time, in seconds, since the last refresh of the visible provider list for the device.

### `visibleProviders` [out, retval]

Pointer to an array of [MBN_PROVIDER2](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_provider2) structures that contains the list of providers for the interface. If this method returns any value other than **S_OK**, *visibleProviders* is **NULL**. When **GetVisibleProviders** returns **S_OK**, the calling application must free the allocated memory by calling [SafeArrayDestroy](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-safearraydestroy).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. *visibleProviders* contains valid values. Based on the age of the information, the calling application can decide to issue a new call to [ScanNetwork](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-scannetwork) |
| **E_PENDING** | The information is not available. An active network scan is in progress. The calling application can get notified when the device capabilities are available by registering for the [OnScanNetworkComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrierevents-onscannetworkcomplete) method of [IMbnMultiCarrierEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrierevents) |
| **E_MBN_INVALID_CACHE** | Mobile Broadband's cache of the visible network list is invalid. The calling application should call [ScanNetwork](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-scannetwork) to populate the cache. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The operation is not supported by the device. This may be returned by devices which do not support multi-carrier. |

## Remarks

This method returns the list of currently visible providers. CDMA devices will report only their home provider if any network in their preferred roaming list (PRL) is available.

To avoid frequent network scan operations, Windows maintains a list of recent scan operations and the provider list is returned from the cached list.

An application can call this method to get a list of visible providers upon the completion of [ScanNetwork](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-scannetwork).

This list contains all the currently visible networks available at the user’s location excluding the ones reported by current registered provider and the list of preferred providers. This list contains network entries that users have not subscribed to. This list providers the user with an additional set of network choices they can potentially sign up for.

## See also

[IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier)