# IMbnSmsEvents::OnSetSmsConfigurationComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method signaling that a set SMS configuration operation has completed, or that the SMS subsystem is initialized and ready for operation.

## Parameters

### `sms` [in]

A pointer to an [IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms) interface representing the Mobile Broadband device for which the SMS configuration has been updated.

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
| **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)** | The SMS format is not supported by the device. |

## Return value

This method must return **S_OK**.

## Remarks

This method is used to notify an application of the completion of a set SMS configuration operation. The application can use the passed [IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms) interface to get the new configuration information. It is also used by the device to indicate the readiness of the device's SMS subsystem. Upon system startup or device insertion, this method will be called to notify applications that the device SMS subsystem is ready for operation.

## See also

[IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents)