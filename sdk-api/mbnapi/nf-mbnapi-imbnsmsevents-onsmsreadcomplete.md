# IMbnSmsEvents::OnSmsReadComplete

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method indicating the completion of a message read operation.

## Parameters

### `sms` [in]

An [IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms) interface representing the message store that completed the operation.

### `smsFormat` [in]

An [MBN_SMS_FORMAT](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_sms_format) value that defines the format of the SMS message.

### `readMsgs` [in]

An array of messages read from the device.

### `moreMsgs` [in]

A Boolean value that indicates whether there are more messages still being processed. If this is **TRUE**, then **OnSmsReadComplete** will be called repeatedly until there are not more messages and *moreMsgs* is **FALSE**.

### `requestID` [in]

A request ID assigned by the Mobile Broadband service to identify the message read operation.

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

## Remarks

For GSM devices, the calling application should call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the each element in *readMsgs* for an [IMbnSmsReadMsgPdu](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsreadmsgpdu) interface.

 For CDMA devices, if *smsFormat* is **MBN_SMS_FORMAT_TEXT**, the application should call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for an [IMbnSmsReadMsgTextCdma](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsreadmsgtextcdma) interface; otherwise, if *smsFormat* is **MBN_SMS_FORMAT_PDU**, the application should call **QueryInterface** for an [IMbnSmsReadMsgPdu](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsreadmsgpdu) interface.

If a read request results in a large amount of messages being read, then **OnSmsReadComplete** may be called repeatedly until *moreMsgs* indicates there are no more messages to be read.

## See also

[IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents)