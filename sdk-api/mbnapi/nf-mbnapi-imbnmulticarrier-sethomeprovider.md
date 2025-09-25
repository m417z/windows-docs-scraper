# IMbnMultiCarrier::SetHomeProvider

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Updates the home provider for a multi-carrier device.

## Parameters

### `homeProvider` [in]

An [MBN_PROVIDER2](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_provider2) structure that contains the home provider.

**Note**

The **SignalStrength** and **SignalError** members must be 0.

### `requestID` [out]

A pointer to the request ID set by the operating system for this request. The asynchronous response from [OnSetHomeProviderComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrierevents-onsethomeprovidercomplete) will contain this same *requestID*.

Pointer to the request ID set by the operating system for this request. The asynchronous response will contain this same requestID.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |
| **E_HANDLE** | Invalid interface. The Mobile Broadband device has probably been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | Invalid interface. Most likely the Mobile Broadband device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The operation is not supported by the device. This may be returned by devices which do not support multi-carrier. |

## Remarks

The **SetHomeProvider** method initiates an update of the home provider for the interface. This is an asynchronous operation, and the method call returns immediately. If this method returns successfully with **S_OK**, then Windows will notify the calling application about the completion status of this operation by calling the [OnSetHomeProviderComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrierevents-onsethomeprovidercomplete) method of [IMbnMultiCarrierEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrierevents).

The device will then automatically come up registered to the new network and indicate a registration state change. The device will continue to come up registered to this new home network across Windows reboots unless **SetHomeProvider** is used again to set a new home provider.

If the device is removed from the system before this operation is complete, there is no guarantee that the completion notification will be received by the calling application.

## See also

[IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier)