# IWDFIoRequest::GetDeviceIoControlParameters

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetDeviceIoControlParameters** method retrieves the request parameters for a device I/O control-type request.

## Parameters

### `pControlCode` [out]

A pointer to a variable that receives the control code that identifies the specific operation to be performed.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

### `pInBufferSize` [out]

A pointer to a variable that receives the size, in bytes, of the input data buffer for the request. To retrieve the input data buffer, the driver calls the [IWDFIoRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory) method.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

### `pOutBufferSize` [out]

A pointer to a variable that receives the size, in bytes, of the output data buffer for the request. To retrieve the output data buffer, the driver calls the [IWDFIoRequest::GetOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getoutputmemory) method.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

## Remarks

The call to **GetDeviceIoControlParameters** fails if the request type is not a device I/O control type.

Although the driver can optionally specify **NULL** for each of the *pControlCode*, *pInBufferSize*, and *pOutBufferSize* parameters, the driver must specify at least one non-**NULL** parameter for **GetDeviceIoControlParameters** to execute successfully.

## See also

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoRequest::GetInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getinputmemory)

[IWDFIoRequest::GetOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfiorequest-getoutputmemory)