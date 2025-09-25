# IMbnSmsEvents::OnSmsNewClass0Message

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method signaling the arrival of a new class 0/flash message.

## Parameters

### `sms` [in]

An [IMbnSms](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsms) interface representing the Mobile Broadband device that received the new message(s).

### `smsFormat` [in]

An [MBN_SMS_FORMAT](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_sms_format) value that defines the format of the new SMS message.

### `readMsgs` [in]

An array of new messages.

## Return value

This method must return **S_OK**.

## Remarks

For GSM devices, the calling application should call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on each element in *readMsgs* for an [IMbnSmsReadMsgPdu](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsreadmsgpdu) interface.

For CDMA devices, if *smsFormat* is **MBN_SMS_FORMAT_TEXT**, then the calling application should call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for a [IMbnSmsReadMsgTextCdma](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsreadmsgtextcdma) interface. If *smsFormat* is **MBN_SMS_FORMAT_PDU**, then the calling application should call **QueryInterface** for a [IMbnSmsReadMsgPdu](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsreadmsgpdu) interface.

## See also

[IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents)