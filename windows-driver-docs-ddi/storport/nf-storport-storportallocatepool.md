# StorPortAllocatePool function

## Description

The **StorPortAllocatePool** routine allocates a block of non-contiguous, non-paged pool memory.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `NumberOfBytes` [in]

The size, in bytes, of the block of memory being allocated.

### `Tag` [in]

The pool tag for the allocated memory. Drivers specify the pool tag as a string of four ASCII characters, delimited by single quotation marks. The string is usually specified in reverse order.

### `BufferPointer` [out]

A pointer to the address of the allocated memory block or **NULL** if not successful.

## Return value

StorPortAllocatePool returns one of the following status codes:

| Return code | Description |
| ----------- | ----------- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the routine successfully allocated a memory block of the requested size. |
| **STOR_STATUS_INVALID_PARAMETER** | The pointer to receive the buffer address is **NULL**. |
| **STOR_STATUS_INVALID_IRQL** | The call was made at an invalid IRQL. |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | Unable to allocate memory of the requested size. |

## Remarks

A miniport driver calls the **StorPortAllocatePool** routine to allocate a block of non-contiguous memory from the non-paged pool. To free the block of memory, the miniport driver calls [**StorPortFreePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreepool). If the request fails, *BufferPointer* will be set to **NULL**.

## See also

[**StorPortFreePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreepool)