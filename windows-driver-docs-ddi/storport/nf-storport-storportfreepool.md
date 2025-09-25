# StorPortFreePool function

## Description

The **StorPortFreePool** routine frees a block of memory that was previously allocated by a call to the [StorPortAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatepool) routine.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `BufferPointer` [in]

A pointer to the block of memory to free. This must be a pointer that was returned by a previous call to the [StorPortAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatepool) routine.

## Return value

StorPortFreePool returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the routine freed the memory block successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | The pointer to the memory block to be freed is **NULL**. |
| **STOR_STATUS_INVALID_IRQL** | The call was made at an invalid IRQL. |

## See also

[StorPortAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatepool)