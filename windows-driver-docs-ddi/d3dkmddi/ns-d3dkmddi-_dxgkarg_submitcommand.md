# DXGKARG_SUBMITCOMMAND structure

## Description

The **DXGKARG_SUBMITCOMMAND** structure describes the DMA buffer that a display miniport driver (KMD) submits to the hardware command execution unit during a call to its [**DxgkDdiSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand) function.

## Members

### `hDevice`

[in] If the driver is not multiple-engine aware (that is, the driver does not support context creation), **hDevice** is a handle to the display device (graphics context) that the submission request originated from. A device handle is supplied to the driver's [**DxgkDdiSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand) function in the union that **DXGKARG_SUBMITCOMMAND** contains.

For some paging operations, **hDevice** is NULL (for example, paging operations that evict the content of the entire frame buffer during power management). Paging operations are indicated by the [**Paging**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_submitcommandflags) bit-field flag in the **Flags** member.

### `hContext`

[in] If the driver is multiple-engine aware (that is, the driver supports context creation), a handle to the device context that the submission request originated from. A context handle is supplied to the driver's [**DxgkDdiSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand) function in the union that **DXGKARG_SUBMITCOMMAND** contains.

For some paging operations, **hContext** is NULL (for example, paging operations that evict the content of the entire frame buffer during power management). Paging operations are indicated by the [**Paging**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_submitcommandflags) bit-field flag in the **Flags** member.

### `DmaBufferSegmentId`

[in] The identifier of the memory segment that the DMA buffer was paged into.

The identifier can be zero if the driver indicated not to map the DMA buffer into the segment by setting the **DmaBufferSegmentSet** member of the [**DXGK_CONTEXTINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_contextinfo) structure to 0 in a call to the driver's [**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) function. If **DmaBufferSegmentId** is zero, the DMA buffer was allocated as a contiguous block of system memory.

### `DmaBufferPhysicalAddress`

[in] A PHYSICAL_ADDRESS data type (which is defined as LARGE_INTEGER) that indicates the physical address where the DMA buffer was paged in.

If **DmaBufferSegmentId** is zero, **DmaBufferPhysicalAddress** is the physical address in system memory where the DMA buffer is located.

If **DmaBufferSegmentId** is nonzero, **DmaBufferPhysicalAddress** is the segment physical address for the DMA buffer; that is, the address points to a physical address of the [aperture segment](https://learn.microsoft.com/windows-hardware/drivers/display/linear-aperture-space-segments) which is a contiguous address space defined in physical memory ([**DXGK_SEGMENTDESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor4)**.BaseAddress + DmaBuffer.SegmentOffset**).

Note that **DmaBufferPhysicalAddress** always refers to the beginning of the DMA buffer even though the driver might be required to patch or submit a section of the DMA buffer that does not include the beginning of the DMA buffer (that is, if the **DmaBufferSubmissionStartOffset** member is nonzero).

### `DmaBufferSize`

[in] The size, in bytes, of the DMA buffer.

**DmaBufferSize** represents the entire length of the DMA buffer; however, the request to patch or submit might refer to only a portion of the DMA buffer.

### `DmaBufferSubmissionStartOffset`

[in] The offset, in bytes, from the beginning of the DMA buffer to the start of the portion of the DMA buffer that requires patching or submitting. The offset that is received at patch time matches the offset that is received at submission time.

### `DmaBufferSubmissionEndOffset`

[in] The offset, in bytes, from the beginning of the DMA buffer to the end of the portion of the DMA buffer that requires patching or submitting. The offset that is received at patch time matches the offset that is received at submission time.

### `pDmaBufferPrivateData`

[in] A pointer to the driver-resident private data that is associated with the DMA buffer that was filled during the [**DxgkDdiRender**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render), [**DxgkDdiPresent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present), or [**DxgkDdiPatch**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_patch) function.

For paging operations, a single paging buffer is used for multiple independent submissions. In that scenario, the driver can indicate--by returning the appropriate private driver data pointer in a call to its [**DxgkDdiBuildPagingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer) function--to have either a single driver private data range for all of the submissions or one for each submission.

### `DmaBufferPrivateDataSize`

[in] The size of the private driver data that **pDmaBufferPrivateData** points to, in bytes.

**DmaBufferPrivateDataSize** represents the entire length of the private driver data buffer; however, the portion that is associated with the current submission might be smaller.

KMD shouldn't validate the private data when this member is zero.

### `DmaBufferPrivateDataSubmissionStartOffset`

[in] The offset, in bytes, from the beginning of the DMA buffer private data that **pDmaBufferPrivateData** specifies to the start of the portion of the private data that is associated with the current submission. **DmaBufferPrivateDataSubmissionStartOffset** is always zero for a nonpaging request.

### `DmaBufferPrivateDataSubmissionEndOffset`

[in] The offset, in bytes, from the beginning of the DMA buffer private data that **pDmaBufferPrivateData** specifies to the end of the portion of the private data that is associated with the current submission.

### `SubmissionFenceId`

[in] A unique identifier that the driver can write into the fence command in the ring buffer, which is the buffer where DMA buffers are queued for the graphics processing unit (GPU) to run. For more information about these types of identifiers, see [Supplying Fence Identifiers](https://learn.microsoft.com/windows-hardware/drivers/display/supplying-fence-identifiers).

### `VidPnSourceId`

[in] The zero-based identification number of the video present source in a path of a video present network (VidPN) topology for a flip operation. This member is valid only when the **Flip** or **FlipWithNoWait** bit-field flag is set in the **Flags** member.

### `FlipInterval`

[in] A [**D3DDDI_FLIPINTERVAL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_flipinterval_type)-typed value that indicates the flip interval (that is, if the flip occurs after zero, one, two, three, or four vertical syncs). **FlipInterval** is valid only if the **Flip** bit-field flag is set (that is, **TRUE**) in the **Flags** member.

### `Flags`

[in] A [**DXGK_SUBMITCOMMANDFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_submitcommandflags) structure that identifies information about the DMA buffer to submit.

### `EngineOrdinal`

[in] Reserved for future use.

### `DmaBufferVirtualAddress`

This member is reserved and should be set to zero. Supported starting with Windows 7.

### `NodeOrdinal`

The zero-based index of the node that the context is created for. Identifies the node when the context is NULL. Supported starting with Windows 8.

## Remarks

The display miniport driver's [**DxgkDdiSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand) function must be aware that multiple processes can access the device object that the **hDevice** member specifies at the same time.

## See also

[**D3DDDI_FLIPINTERVAL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_flipinterval_type)

[**DXGK_CONTEXTINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_contextinfo)

[**DXGK_SUBMITCOMMANDFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_submitcommandflags)

[**DxgkCbNotifyDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_dpc)

[**DxgkCbNotifyInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)

[**DxgkDdiBuildPagingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer)

[**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext)

[**DxgkDdiPatch**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_patch)

[**DxgkDdiPresent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)

[**DxgkDdiRender**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_render)

[**DxgkDdiSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand)