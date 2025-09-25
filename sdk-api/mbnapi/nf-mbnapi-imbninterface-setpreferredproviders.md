# IMbnInterface::SetPreferredProviders

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Updates the preferred providers list for the device.

## Parameters

### `preferredProviders` [in]

An array of [MBN_PROVIDER](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_provider) structures that contains the list of preferred providers.

### `requestID` [out]

Pointer to the request ID set by the operating system for this request. The asynchronous response will contain this same *requestID*.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |
| **E_HANDLE** | The interface is invalid, most likely because the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The interface is invalid. Most likely because the Mobile Broadband device has been removed from the system. |

## Remarks

The **SetPreferredProviders** method initiates an update of the preferred provider list for the interface. This is an asynchronous operation, and the method call returns immediately. If this method returns successfully (with **S_OK**), then the operating system will notify the calling application about the completion status of this operation by calling the [OnSetPreferredProvidersComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onsetpreferredproviderscomplete) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents).

If the device is removed from the system before this operation is complete, then there is no guarantee that the completion notification will be received by the calling application.

## See also

[IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface)