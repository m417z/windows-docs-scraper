# IWDFUsbTargetPipe::GetInformation

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetInformation** method retrieves information about a USB pipe (endpoint).

## Parameters

### `pInfo` [out]

A pointer to a variable that receives USB pipe information.

## Remarks

After a UMDF driver calls the [IWDFUsbInterface::RetrieveUsbPipeObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbinterface-retrieveusbpipeobject) method to retrieve a USB pipe object, the UMDF driver should retrieve information about the USB pipe. Therefore, the **GetInformation** method does not fail.

## See also

[IWDFUsbInterface::RetrieveUsbPipeObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbinterface-retrieveusbpipeobject)

[IWDFUsbTargetPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetpipe)