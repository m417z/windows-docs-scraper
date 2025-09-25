# IWDFUsbRequestCompletionParams::GetDeviceControlTransferParameters

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetDeviceControlTransferParameters** method retrieves parameters that are associated with the completion of a device I/O control request.

## Parameters

### `ppMemory` [out, optional]

A pointer to a variable that receives a pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface, for access to the buffer for the device I/O control request. This parameter is optional and can be **NULL**.

### `pLengthTransferred` [out, optional]

A pointer to a variable that receives the size, in bytes, of transferred data. This parameter is optional and can be **NULL**.

### `pOffset` [out, optional]

A pointer to a variable that receives the offset, in bytes, into the buffer for the I/O control request. This parameter is optional and can be **NULL**.

### `pSetupPacket` [out, optional]

A pointer that receives the WinUsb setup packet for the control transfer. This pointer is a PWINUSB_SETUP_PACKET data type that is defined as PVOID. This parameter is optional and can be **NULL**.

## See also

[IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)

[IWDFUsbRequestCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfusb/nn-wudfusb-iwdfusbrequestcompletionparams)