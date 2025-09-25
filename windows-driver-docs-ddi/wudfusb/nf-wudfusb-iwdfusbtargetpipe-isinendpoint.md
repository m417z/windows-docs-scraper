# IWDFUsbTargetPipe::IsInEndPoint

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **IsInEndPoint** method determines whether a USB pipe (endpoint) is an IN pipe.

## Return value

**IsInEndPoint** returns a BOOL value that indicates whether the USB pipe is an IN pipe. **TRUE** indicates the pipe is an IN pipe. **FALSE** indicates the pipe is not an IN pipe.

## Remarks

If the USB pipe is an IN pipe, a UMDF driver can call the [IWDFIoTarget::FormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforread) method to format a read request. The framework can then send the request to the USB pipe.

**Note** The meaning of IN and OUT is opposite in WDF and USB.

#### Examples

For a code example of how to use the **IsInEndPoint** method, see [IWDFUsbInterface::GetNumEndPoints](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbinterface-getnumendpoints).

## See also

[IWDFIoTarget::FormatRequestForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiotarget-formatrequestforread)

[IWDFUsbTargetPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetpipe)