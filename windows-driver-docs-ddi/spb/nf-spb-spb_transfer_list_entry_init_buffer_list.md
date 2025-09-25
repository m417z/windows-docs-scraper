# SPB_TRANSFER_LIST_ENTRY_INIT_BUFFER_LIST function

## Description

The **SPB_TRANSFER_LIST_ENTRY_INIT_BUFFER_LIST** function returns an [SPB_TRANSFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list_entry) structure that is initialized to describe a scatter-gather list.

## Parameters

### `Direction` [in]

The direction of the transfer. The function writes this value to the **Direction** member of the **SPB_TRANSFER_LIST_ENTRY** structure.

### `DelayInUs` [in]

An optional delay in microseconds. The function writes this value to the **DelayInUs** member of the **SPB_TRANSFER_LIST_ENTRY** structure.

### `BufferList` [in]

A pointer to an array of [SPB_TRANSFER_BUFFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer_list_entry) structures that describes a scatter-gather list. The function writes this value to the **Buffer.BufferList.List** member of the **SPB_TRANSFER_LIST_ENTRY** structure. For more information, see the description of the **BufferList.List** member in [SPB_TRANSFER_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer).

### `BufferListCe` [in]

The number of buffers in the scatter-gather list pointed to by _BufferList_. The function writes this value to the **Buffer.BufferList.ListCe** member of the **SPB_TRANSFER_LIST_ENTRY** structure. For more information, see the description of the **BufferList.ListCe** member in [SPB_TRANSFER_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer).

## Return value

**SPB_TRANSFER_LIST_ENTRY_INIT_BUFFER_LIST** returns an initialized **SPB_TRANSFER_LIST_ENTRY** structure.

## Remarks

This initialization function returns an unnamed local variable of type **SPB_TRANSFER_LIST_ENTRY**. The storage for this variable is allocated in the caller's stack frame and is valid while the stack frame remains in scope.

**SPB_TRANSFER_LIST_ENTRY_INIT_BUFFER_LIST** sets the **Buffer.Format** member of the **SPB_TRANSFER_LIST_ENTRY** structure to **SpbTransferBufferFormatList**. For more information about buffer formats, see [SPB_TRANSFER_BUFFER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_transfer_buffer_format).

## See also

- [SPB_TRANSFER_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer)
- [SPB_TRANSFER_BUFFER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_transfer_buffer_format)
- [SPB_TRANSFER_BUFFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer_list_entry)
- [SPB_TRANSFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list_entry)