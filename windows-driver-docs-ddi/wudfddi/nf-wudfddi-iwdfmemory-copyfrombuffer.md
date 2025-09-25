# IWDFMemory::CopyFromBuffer

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

The **CopyFromBuffer** method safely copies data from the specified source buffer to a memory object.

## Parameters

### `DestOffset` [in]

The offset, in bytes, into the memory object to start to copy data to.

### `SourceBuffer` [in]

A pointer to the source buffer that data is copied from.

### `NumOfBytesToCopyFrom` [in]

The number of bytes to copy from the *SourceBuffer*.

## Return value

**CopyFromBuffer** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## See also

- [IWDFIoQueue::RetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-retrievenextrequest)
- [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)