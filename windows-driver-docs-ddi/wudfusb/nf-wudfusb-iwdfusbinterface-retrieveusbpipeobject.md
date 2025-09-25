# IWDFUsbInterface::RetrieveUsbPipeObject

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrieveUsbPipeObject** method retrieves a USB pipe object for the specified pipe index.

## Parameters

### `PipeIndex` [in]

The index of the USB pipe object to retrieve.

### `ppPipe` [out]

A pointer to a variable that receives a pointer to the [IWDFUsbTargetPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetpipe) interface for the USB pipe object whose index is specified by *PipeIndex*.

## Return value

**RetrieveUsbPipeObject** returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | [RetrieveUsbPipeObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbinterface-retrieveusbpipeobject) successfully retrieved the USB pipe object. |
| **E_OUTOFMEMORY** | [RetrieveUsbPipeObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbinterface-retrieveusbpipeobject) encountered an allocation failure. |
| **An error code that is defined in Winerror.h** | This value corresponds to the error code that the WinUsb API returned. |

## Remarks

A UMDF driver can call the methods of the [IWDFUsbTargetPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetpipe) interface that the **RetrieveUsbPipeObject** method retrieves to obtain the type of pipe and other information.

#### Examples

For a code example of how to use the**RetrieveUsbPipeObject** method, see [IWDFUsbInterface::GetNumEndPoints](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nf-wudfusb-iwdfusbinterface-getnumendpoints).

## See also

[IWDFUsbInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbinterface)

[IWDFUsbTargetPipe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbtargetpipe)