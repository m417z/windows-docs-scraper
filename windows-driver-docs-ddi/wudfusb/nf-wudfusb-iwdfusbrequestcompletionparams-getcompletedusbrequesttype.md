# IWDFUsbRequestCompletionParams::GetCompletedUsbRequestType

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetCompletedUsbRequestType** method retrieves the type of operation that the request to be completed contains.

## Return value

**GetCompletedUsbRequestType** returns a value of type [WDF_USB_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_request_type) that identifies the USB request type.

## See also

[IWDFUsbRequestCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbrequestcompletionparams)

[WDF_USB_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfusb/ne-wdfusb-_wdf_usb_request_type)