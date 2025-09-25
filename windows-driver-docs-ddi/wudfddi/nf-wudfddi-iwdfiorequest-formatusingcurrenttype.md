# IWDFIoRequest::FormatUsingCurrentType

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **FormatUsingCurrentType** method formats an I/O request so that the driver can forward it, unmodified, to the next-lower driver.

## Remarks

When a driver receives an I/O request, the driver might forward the request to the local I/O target, unmodified. To forward the unmodified request, the driver must:

* Call **FormatUsingCurrentType** to format the request so that the framework can pass the request to the driver's local I/O target.
* Call the [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send) method to send the request to the I/O target.

#### Examples

For a code example of how to use the **FormatUsingCurrentType** method, see [IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send).

## See also

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest::Send](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-send)