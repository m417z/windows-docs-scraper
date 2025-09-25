# IWDFMemory::CopyToBuffer

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

The **CopyToBuffer** method safely copies data from a memory object to the specified target buffer.

## Parameters

### `SourceOffset` [in]

The offset, in bytes, into the memory object from which to start copying data.

### `TargetBuffer` [out]

A pointer to the target buffer to which data is copied.

### `NumOfBytesToCopyTo` [in]

The number of bytes to copy to the *TargetBuffer*.

## Return value

**CopyToBuffer** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## See also

- [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)