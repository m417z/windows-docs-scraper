# IMbnSmsEvents::OnSmsSendComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method that indicates the completion of a message send operation.

## Parameters

### `sms` [in]

An [IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms) interface representing the Mobile Broadband device from which the operation completed.

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
| **E_MBN_SMS_UNKNOWN_SMSC_ADDRESS** | Unknown or incomplete SMS service center address. |
| **E_MBN_SERVICE_NOT_ACTIVATED** | Cellular service is not activated on the device. |
| **E_INVALIDARG** | The device detected invalid parameters in the send request. |
| **E_MBN_SMS_NETWORK_TIMEOUT** | There was a network timeout. |
| **E_MBN_NOT_REGISTERED** | The device is not registered to any network. |
| **E_MBN_SMS_LANG_NOT_SUPPORTED** | The CDMA device does not support the language. |
| **E_MBN_SMS_ENCODING_NOT_SUPPORTED** | The CDMA device does not support the requested encoding. |
| **E_MBN_SMS_OPERATION_NOT_ALLOWED** | The requested SMS operation is not allowed by the SIM. |
| **E_MBN_SMS_MEMORY_FULL** | The device/SIM memory is full. |

## Return value

This method must return **S_OK**.

## Remarks

A send operation should be tried only after the device is successfully registered to the network.

## See also

[IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents)