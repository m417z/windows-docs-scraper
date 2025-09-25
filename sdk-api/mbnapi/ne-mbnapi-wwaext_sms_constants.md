# WWAEXT_SMS_CONSTANTS enumeration

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_SMS_CONSTANTS** enumerated type contains SMS constant values.

## Constants

### `MBN_MESSAGE_INDEX_NONE:0`

The message is not stored in device memory. This constant is used by [IMbnSmsReadMsgPdu](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsreadmsgpdu) and [IMbnSmsReadMsgTextCdma](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsreadmsgtextcdma).

### `MBN_CDMA_SHORT_MSG_SIZE_UNKNOWN:0`

The device does not support SMS. This constant is used by [IMbnSmsConfiguration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsconfiguration).

### `MBN_CDMA_SHORT_MSG_SIZE_MAX:160`

The maximum size of a CDMA short message.