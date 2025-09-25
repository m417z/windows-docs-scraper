# IWDFIoRequestCompletionParams::GetWriteParameters

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetWriteParameters** method retrieves parameters that are associated with the completion of a write request.

## Parameters

### `ppWriteMemory` [out]

A pointer to a variable that receives a pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface for access to the write buffer for the completion of the write request.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

### `pBytesWritten` [out]

A pointer to a variable that receives the size, in bytes, of the write buffer for the completion of the write request.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

### `pWriteMemoryOffset` [out]

A pointer to a variable that receives the offset, in bytes, into the write buffer for the completion of the write request.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

## See also

[IWDFIoRequestCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequestcompletionparams)

[IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)