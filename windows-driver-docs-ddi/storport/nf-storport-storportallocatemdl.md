# StorPortAllocateMdl function

## Description

The **StorPortAllocateMdl** routine allocates an MDL to describe the given non-paged pool memory.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `BufferPointer` [in]

A pointer to the base virtual address of the buffer that the MDL is to describe.

### `NumberOfBytes` [in]

This parameter specifies the length, in bytes, of the buffer that the MDL is to describe.

### `Mdl` [out]

A pointer to receive the allocated MDL.

## Return value

StorPortAllocateMdl returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the routine allocated the MDL successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | The pointer to receive the MDL is **NULL**.<br><br>The pointer to the buffer is **NULL**. |
| **STOR_STATUS_INVALID_IRQL** | The call was made at an invalid IRQL. |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | Unable to allocate MDL to describe the given buffer. |

## Remarks

A miniport driver calls the **StorPortAllocateMdl** routine to allocate an MDL to describe a block of memory from the non-paged pool. To free the MDL, the miniport driver calls the [StorPortFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreemdl) routine.