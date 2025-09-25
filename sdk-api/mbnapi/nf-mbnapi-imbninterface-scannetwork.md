# IMbnInterface::ScanNetwork

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Asynchronously scans the network to get a list of visible providers.

## Parameters

### `requestID` [out]

Pointer to the request ID set by the operating system for this request. The asynchronous response will contain this same *requestID*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |
| **E_HANDLE** | The interface is invalid. Most likely because the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The interface is invalid. Most likely because the Mobile Broadband device has been removed from the system. |

## Remarks

This method initiates a network scan operation. When completed successfully, it populates the operating system's cache of visible providers and applications can call the [GetVisibleProviders](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getvisibleproviders) method of [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) to get a list of visible networks.

This is a time consuming operation. Therefore, applications should first call [GetVisibleProviders](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getvisibleproviders) and should call **ScanNetwork** only when the cached information is old.

This is an asynchronous operation and **ScanNetwork** will return immediately. If this method returns successfully (with **S_OK**), then upon completion of the scan operation, the operating system will call the [OnScanNetworkComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onscannetworkcomplete) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents) to notify the application of operation completion.

If the device is removed from the system before this operation is complete, there is no guarantee that the completion notification will be received by the application.

## See also

[IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface)