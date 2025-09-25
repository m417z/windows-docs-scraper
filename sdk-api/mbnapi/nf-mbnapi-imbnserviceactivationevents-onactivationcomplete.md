# IMbnServiceActivationEvents::OnActivationComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method called by the Mobile Broadband service to indicate that a service activation request ahs completed.

## Parameters

### `serviceActivation` [in]

Pointer to an [IMbnServiceActivation](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnserviceactivation) interface representing the device on which the request was performed.

### `vendorSpecificData` [in]

A byte array containing the data returned by the underlying Mobile Broadband miniport driver in [NDIS_STATUS_WWAN_SERVICE_ACTIVATION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-service-activation).

### `requestID` [in]

The request ID assigned by the Mobile Broadband service when the request was initialized.

### `status` [in]

The completion status.

A calling application can expect one of the following values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The miniport driver detected incorrect input data in the request. |
| **E_MBN_PIN_REQUIRED** | A PIN is required for the operation to complete. |
| **E_MBN_RADIO_POWER_OFF** | The Mobile Broadband device is not powered up. |
| **E_MBN_PROVIDER_NOT_VISIBLE** | The service provider is not visible. |
| **E_MBN_SIM_NOT_INSERTED** | There is no SIM in the device. |
| **E_MBN_BAD_SIM** | There is a bad SIM in the device. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The device does not support this operation. |

### `networkError` [in]

The error code returned by the network during the activation operation. This value is meaningful only when *status* is not S_OK.

The exact value of *networkError* is driver/network dependent.

## Return value

This method must return **S_OK**.

## Remarks

Successful service activation will also result in a change to the ready state of the device. the Mobile Broadband service will call the [OnReadyStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onreadystatechange) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents) as notification.

## See also

[IMbnServiceActivationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnserviceactivationevents)