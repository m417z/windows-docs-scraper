# IMbnInterface::GetVisibleProviders

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the list of visible providers.

## Parameters

### `age` [out, retval]

A pointer to the time in seconds since the last refresh of the visible provider list from the device.

### `visibleProviders` [out, retval]

Pointer to an array of [MBN_PROVIDER](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_provider) structures that contains the list of providers for the interface. If this method returns any value other than **S_OK**, this parameter is **NULL**. Otherwise, upon completion, the calling program must free the allocated memory by calling [SafeArrayDestroy](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-safearraydestroy).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. *visibleProviders* contains valid values. Based on the age of the information, the calling application can decide to issue a new call to [ScanNetwork](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-scannetwork). |
| **E_PENDING** | The information is not available. An active network scan is in progress. The calling application can get notified when the device capabilities are available by registering for the [OnScanNetworkComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onscannetworkcomplete) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents). |
| **E_MBN_INVALID_CACHE** | Mobile Broadband's cache of the visible network list is invalid. The calling application should call [ScanNetwork](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-scannetwork) to populate the cache. |

## Remarks

This method returns the list of currently visible providers. CDMA devices will report only their home provider if any network in their preferred roaming list (PRL) is available.

To avoid frequent network scan operations, the operating system maintains a list of recent scan operations and the provider list is returned from the cached list.

An application can call this method to get a list of visible providers upon the completion of [ScanNetwork](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-scannetwork).

## See also

[IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface)