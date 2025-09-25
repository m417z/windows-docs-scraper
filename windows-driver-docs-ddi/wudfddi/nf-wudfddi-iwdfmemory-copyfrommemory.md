# IWDFMemory::CopyFromMemory

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

The **CopyFromMemory** method safely copies data from the specified source buffer and prevents overruns that the copy operation might otherwise cause.

## Parameters

### `Source` [in]

A pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface for the memory object that is the source of the copy operation.

### `SourceOffset` [in, optional]

A pointer to a [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdfmemory_offset) structure that describes the information that is copied from a memory block. This parameter is optional. The driver can pass **NULL** if the entire source buffer is copied.

The **BufferOffset** member of the WDFMEMORY_OFFSET structure, if not **NULL**, indicates the offset into the source buffer to start the copy operation from.

The **BufferLength** member should be set to 0; the framework ignores this member because the amount of data that is copied depends on the length and offset combination of the current destination buffer.

## Return value

**CopyFromMemory** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## See also

- [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)
- [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdfmemory_offset)