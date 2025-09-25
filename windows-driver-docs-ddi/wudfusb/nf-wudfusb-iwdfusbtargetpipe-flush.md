# IWDFUsbTargetPipe::Flush

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **Flush** method discards any data that WinUsb saved when the device returned more data than the client requested.

## Return value

**Flush** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [Flush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfworkitem-flush) successfully discarded any extra data that WinUsb saved. |
| **E_OUTOFMEMORY** | [Flush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfworkitem-flush) encountered an allocation failure. |
| **An error code that is defined in Winerror.h** | This value corresponds to the error code that the WinUsb API returned. |

## Remarks

The **Flush** method generates a UMDF request and synchronously sends the request to the I/O target.

For more information about how **Flush** works, see the [WinUsb_FlushPipe](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_flushpipe) function.

## See also

[IWDFUsbTargetPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetpipe)

[WinUsb_FlushPipe](https://learn.microsoft.com/windows/win32/api/winusb/nf-winusb-winusb_flushpipe)