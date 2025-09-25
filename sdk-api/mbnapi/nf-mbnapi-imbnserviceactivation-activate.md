# IMbnServiceActivation::Activate

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Send the service activation request to the network.

## Parameters

### `vendorSpecificData` [in]

A vendor-specific array of bytes passed in a service activation operation. This data will be passed by the Mobile Broadband service in a SET OID_WWAN_SERVICE_ACTIVATION OID request to the miniport driver.

### `requestID` [out]

The request ID for this operation.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |
| **E_HANDLE** | Invalid interface. Most likely the device has been removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The interface is invalid. Most likely the Mobile Broadband device has been removed from the system.<br><br>Invalid interface. Most likely the device has been removed from the system. |

## Remarks

The **Activate** method can be used by an application to activate cellular service. The format of data passed in this request is vendor-specific.

The **VendorSpecificBufferSize** field of the OID request would be set to the size of data in the SAFEARRAY, *vendorSpecificData*. The contents of *vendorSpecificData* will be copied byte-by-byte in the OID request to the driver.

Refer to the Mobile Broadband Driver Model for more information about service activation operations.

This is an asynchronous operation that will return immediately. If the method returns without error, then the Mobile Broadband service will call the [OnActivationComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnserviceactivationevents-onactivationcomplete) method of the [IMbnServiceActivationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnserviceactivationevents) interface.

## See also

[IMbnServiceActivation](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnserviceactivation)