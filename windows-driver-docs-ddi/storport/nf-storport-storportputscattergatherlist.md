# StorPortPutScatterGatherList function

## Description

The **StorPortPutScatterGatherList** routine releases any resources associated with a scatter/gather list that was previously created by a call to the [StorPortBuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportbuildscattergatherlist) routine.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `ScatterGatherList` [in]

A pointer to a buffer that contains a scatter/gather list that was previously created by a call to the [StorPortBuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportbuildscattergatherlist) routine.

### `WriteToDevice` [in]

A value that indicates the direction of the DMA transfer that has completed. A value of **TRUE** indicates a transfer from the data buffer to the device, and **FALSE** indicates a transfer from the device to the data buffer.

## Return value

**StorPortPutScatterGatherList** returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_SUCCESS** | Indicates that the routine released the scatter/gather list successfully. |
| **STOR_STATUS_INVALID_PARAMETER** | The *HwDeviceExtension* that was passed was **NULL**. |
| **STOR_STATUS_INVALID_IRQL** | The call was made at an invalid IRQL. |

## Remarks

The **StorPortPutScatterGatherList** routine does not free the buffer memory for the scatter/gather list, because the miniport driver allocated this memory.

After the **StorPortPutScatterGatherList** routine returns, the miniport driver can reuse the buffer to create a new scatter/gather list by calling the [StorPortBuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportbuildscattergatherlist) again. If a miniport driver has finished using the buffer for the scatter/gather list, it should free the memory for the buffer after the **StorPortPutScatterGatherList** routine returns. If the miniport driver allocates the buffer memory with the [StorPortAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocatepool) routine, it should free the memory by calling the [StorPortFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreepool) routine.

## See also

[StorPortBuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportbuildscattergatherlist)