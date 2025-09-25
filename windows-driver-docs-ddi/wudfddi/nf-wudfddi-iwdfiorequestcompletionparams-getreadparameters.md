# IWDFIoRequestCompletionParams::GetReadParameters

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetReadParameters** method retrieves parameters that are associated with the completion of a read request.

## Parameters

### `ppReadMemory` [out]

A pointer to a variable that receives a pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface for access to the read buffer for the completion of the read request.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

### `pBytesRead` [out]

A pointer to a variable that receives the size, in bytes, of the read buffer for the completion of the read request.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

### `pReadMemoryOffset` [out]

A pointer to a variable that receives the offset, in bytes, into the read buffer for the completion of the read request.

This parameter is optional. The driver can pass **NULL** if the driver does not require the information.

## See also

[IWDFIoRequestCompletionParams](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequestcompletionparams)

[IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)