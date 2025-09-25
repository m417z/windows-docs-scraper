# IMbnSms::SmsDelete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Deletes a set of SMS messages from a device.

## Parameters

### `smsFilter` [in]

A pointer to a [MBN_SMS_FILTER](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_sms_filter) structure that defines the set of messages to delete.

### `requestID` [out]

A pointer to a request ID issued by the Mobile Broadband service to identify this request.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_SERVICE_NOT_ACTIVE)** | The Mobile Broadband service is not running on this system. |
| **E_HANDLE** | The interface is invalid, most likely because the device was removed from the system. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The interface is invalid. Most likely the Mobile Broadband device has been removed from the system. |

## Remarks

This is an asynchronous operation that will return immediately. If the method returns without error, then the Mobile Broadband service will call the [OnSmsDeleteComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsevents-onsmsdeletecomplete) method of the [IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents) interface.

## See also

[IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms)