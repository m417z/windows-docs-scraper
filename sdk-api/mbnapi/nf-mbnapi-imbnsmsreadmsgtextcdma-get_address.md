# IMbnSmsReadMsgTextCdma::get_Address

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The mobile number associated with a message.

This property is read-only.

## Parameters

## Remarks

For a received message, this is the sender's number. For a sent or draft message, this is the receiver's number.

The *address* can be in either of these formats.

* "+ \<International Country Code> \<SMS Service Center Number>\0"
* "\<SMS Service Center Number>\0"

## See also

[IMbnSmsReadMsgTextCdma](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsreadmsgtextcdma)