# IMbnSmsReadMsgTextCdma::get_Message

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The contents of the message.

This property is read-only.

## Parameters

## Remarks

The maximum size of the message is specified by the [CdmaShortMsgSize](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsconfiguration-get_cdmashortmsgsize) property of [IMbnSmsConfiguration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsconfiguration) The size can also be no larger than **MBN_CDMA_SHORT_MSG_SIZE_MAX** (160).

## See also

[IMbnSmsReadMsgTextCdma](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsreadmsgtextcdma)