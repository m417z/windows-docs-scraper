# IWDFMemory::SetBuffer

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetBuffer** method assigns a specified buffer to a memory object that a driver created by calling [IWDFDriver::CreatePreallocatedWdfMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createpreallocatedwdfmemory).

## Parameters

### `Buffer` [in]

A pointer to a driver-supplied buffer.

### `BufferSize` [in]

The nonzero size, in bytes, of the buffer that *Buffer* points to.

## Remarks

The **SetBuffer** method can assign a buffer to a memory object that [IWDFDriver::CreatePreallocatedWdfMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createpreallocatedwdfmemory) created, but not to a memory object that [IWDFDriver::CreateWdfMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdriver-createwdfmemory) created.

## See also

[IWDFIoQueue::RetrieveNextRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfioqueue-retrievenextrequest)

[IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)