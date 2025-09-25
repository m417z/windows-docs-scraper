# SPB_TRANSFER_LIST_ENTRY_INIT_SIMPLE function

## Description

The **SPB_TRANSFER_LIST_ENTRY_INIT_SIMPLE** function returns an [SPB_TRANSFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list_entry) structure that is initialized to describe a simple data buffer.

## Parameters

### `Direction` [in]

The direction of the transfer. The function writes this value to the **Direction** member of the **SPB_TRANSFER_LIST_ENTRY** structure.

### `DelayInUs` [in]

An optional delay in microseconds. The function writes this value to the **DelayInUs** member of the **SPB_TRANSFER_LIST_ENTRY** structure.

### `Buffer` [in]

A pointer to a data buffer. The function writes this value to the **Buffer.Simple.Buffer** member of the **SPB_TRANSFER_LIST_ENTRY** structure. For more information, see the description of the **Buffer** member in [SPB_TRANSFER_BUFFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer_list_entry).

### `BufferCb` [in]

The size, in bytes, of the buffer pointed to by _Buffer_. The function writes this value to the **Buffer.Simple.BufferCb** member of the **SPB_TRANSFER_LIST_ENTRY** structure. For more information, see the description of the **BufferCb** member in [SPB_TRANSFER_BUFFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer_list_entry).

## Return value

**SPB_TRANSFER_LIST_ENTRY_INIT_SIMPLE** returns an initialized **SPB_TRANSFER_LIST_ENTRY** structure.

## Remarks

This initialization function returns an unnamed local variable of type **SPB_TRANSFER_LIST_ENTRY**. The storage for this variable is allocated in the caller's stack frame and is valid while the stack frame remains in scope.

**SPB_MDL_TRANSFER_ENTRY** sets the **Buffer.Format** member of the **SPB_TRANSFER_LIST_ENTRY** structure to **SpbTransferBufferFormatSimple**. For more information about buffer formats, see [SPB_TRANSFER_BUFFER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_transfer_buffer_format).

## See also

- [SPB_TRANSFER_BUFFER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_transfer_buffer_format)
- [SPB_TRANSFER_BUFFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_buffer_list_entry)
- [SPB_TRANSFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list_entry)