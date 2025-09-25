# IMbnSmsEvents::OnSmsDeleteComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method that signals the completion of an SMS deletion operation.

## Parameters

### `sms` [in]

An [IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms) interface representing the Mobile Broadband device from which the messages were deleted.

### `requestID` [in]

A request ID assigned by the Mobile Broadband service to identify the operation.

### `status` [in]

A status code that indicates the outcome of the operation.

A calling application can expect one of the following values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_MBN_SIM_NOT_INSERTED** | There is no SIM in the device. |
| **E_MBN_BAD_SIM** | There is a bad SIM in the device. |
| **E_MBN_PIN_REQUIRED** | A PIN is required for the operation to complete. |
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | Either the SMS operation or the particular SMS format is not supported by the device. |
| **E_MBN_SMS_MEMORY_FAILURE** | SMS memory failure. |
| **E_MBN_SMS_INVALID_MEMORY_INDEX** | There is no memory index with the requested value. |
| **E_MBN_SMS_FILTER_NOT_SUPPORTED** | The device does not support the requested filter. |

## Return value

This method must return **S_OK**.

## See also

[IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents)