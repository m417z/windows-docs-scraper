# IWDFUsbTargetPipe::GetType

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetType** method retrieves the type of a USB pipe.

## Return value

**GetType** returns a USBD_PIPE_TYPE value that identifies the type of the USB pipe.

## Remarks

The **GetType** method is provided for convenience because a UMDF driver can obtain the type of the USB pipe from the **PipeType** member of the [WINUSB_PIPE_INFORMATION](https://learn.microsoft.com/windows/win32/api/winusbio/ns-winusbio-winusb_pipe_information) structure that the driver retrieves when it calls the [IWDFUsbTargetPipe::GetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe-getinformation) method.

For a code example of how to use the **GetType** method, see [IWDFUsbInterface::GetNumEndPoints](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbinterface-getnumendpoints).

## See also

[IWDFUsbTargetPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetpipe)

[IWDFUsbTargetPipe::GetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbtargetpipe-getinformation)