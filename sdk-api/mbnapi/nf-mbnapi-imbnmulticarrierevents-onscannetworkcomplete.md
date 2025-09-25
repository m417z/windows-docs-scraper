# IMbnMultiCarrierEvents::OnScanNetworkComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

This notification method is called by the Mobile Broadband service to indicate the completion of a [ScanNetwork](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-scannetwork) operation.

## Parameters

### `mbnInterface` [in]

An [IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier) object that represents the Mobile Broadband device [ScanNetwork](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-scannetwork) operation.

### `requestID` [in]

The request ID assigned by the Mobile Broadband service to the [ScanNetwork](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-scannetwork) operation.

### `status` [in]

A status code that indicates the outcome of [ScanNetwork](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-scannetwork).

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_MBN_RADIO_POWER_OFF** | Can't get a visible network list because the device radio is off. The application can issue a network scan request when it gets the radio-turned-on notification. |
| **E_MBN_DEVICE_BUSY** | The device is busy and can't currently perform a network scan operation. This is returned by devices which don't support a network scan operation when it has a data connection established. |
| **E_MBN_ALREADY_ACTIVE** | A network scan operation is already in progress. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The operation is not supported by the device. This may be returned by devices which do not support multi-carrier. |

## Return value

This method must return **S_OK**.

## Remarks

If *status* is **S_OK**, the Mobile Broadband service successfully updated the cached list of visible providers. An application can then call the [GetVisibleProviders](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-getvisibleproviders) method of the passed [IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier) to get the list of visible providers.

If multiple applications registered for notifications, then this method will be called on all registered applications. This means that an application that did not initiate the update operation will receive a notification.

## See also

[IMbnMultiCarrierEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrierevents)