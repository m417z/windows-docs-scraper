# IWDFIoRequestCompletionParams::GetIoctlParameters

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetIoctlParameters** method retrieves parameters that are associated with the completion of a device I/O control request.

## Parameters

### `pIoControlCode` [out, optional]

A pointer to a variable that receives the control code that identifies the specific operation to be performed.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

### `ppInputMemory` [out, optional]

A pointer to a variable that receives a pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface for access to the input buffer for the completion of the device I/O control request.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

### `pInputMemoryOffset` [out, optional]

A pointer to a variable that receives the offset, in bytes, into the input buffer for the completion of the I/O control request.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

### `ppOutputMemory` [out, optional]

A pointer to a variable that receives a pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface for access to the output buffer for the completion of the device I/O control request.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

### `pOutputMemoryOffset` [out, optional]

A pointer to a variable that receives the offset, in bytes, into the output buffer for the completion of the I/O control request.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

### `pOutBytes` [out, optional]

A pointer to a variable that receives the number of bytes that are output for the completion of the device I/O control request.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

## See also

[IWDFIoRequestCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequestcompletionparams)

[IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)