# IMbnSms::SmsRead

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Reads a set of SMS messages from a device.

## Parameters

### `smsFilter` [in]

A pointer to a [MBN_SMS_FILTER](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_sms_filter) structure that defines the set of messages to read.

### `smsFormat` [in]

An [MBN_SMS_FORMAT](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_sms_format) value that specifies the format in which an SMS message should be read.

For GSM devices, it should always be **MBN_SMS_FORMAT_PDU**.

For CDMA devices, if this is specified as MBN_SMS_FORMAT_PDU, then the device will read a binary mode CDMA message. If it is specified as MBN_SMS_FORMAT_TEXT, then the device will read a text mode CDMA message. If the device doesn’t support the specified format then it can return an error code.

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
| **E_INVALIDARG** | *smsFormat* or *smsFilter* is invalid. |

## Remarks

Using *smsFilter*, an application can specify basic filters such as new messages, draft messages, or a specific message using an index. A complex filter can be used by integrating a combination of basic filters. All the interfaces support the index based filters and new message type filters. Support for other filters is optional for some interfaces. If the specified filter is not supported then operation completion callback function will return a status of **E_MBN_STATUS_FILTER_NOT_SUPPORTED**.

This is an asynchronous operation that will return immediately. If the method returns without error, then the Mobile Broadband service will call the [OnSmsReadComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsevents-onsmsreadcomplete) method of the [IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents) interface.

## See also

[IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms)