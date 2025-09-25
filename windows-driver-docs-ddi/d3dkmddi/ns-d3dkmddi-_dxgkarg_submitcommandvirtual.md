# DXGKARG_SUBMITCOMMANDVIRTUAL structure

## Description

The **DXGKARG_SUBMITCOMMANDVIRTUAL** structure is passed to [**DxgkDdiSubmitCommandVirtual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommandvirtual) to submit a DMA buffer to a context that supports virtual addressing.

## Members

### `hContext`

The handle returned from [**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext).

### `DmaBufferVirtualAddress`

The virtual address for the DMA buffer in the context of the submitting process.

### `DmaBufferSize`

The size of the DMA buffer in bytes.

### `pDmaBufferPrivateData`

A pointer to the driver's private data buffer.

### `DmaBufferPrivateDataSize`

The size of the driver's private data buffer in bytes.

### `DmaBufferUmdPrivateDataSize`

Size of the private driver data, in bytes, that was set by the user mode driver (UMD) in **SubmitCommandCb**. When **SubmitCommandCb** is called, *Dxgkrnl* allocates a buffer for the private driver data with the size equal to [**DXGK_CONTEXTINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_contextinfo)::**DmaBufferPrivateDataSize**. This size was reported by the kernel mode driver (KMD) in its [**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext) call. *Dxgkrnl* copies the driver's private data from the **SubmitCommandCb** to the allocated buffer.

### `SubmissionFenceId`

A unique identifier that the driver can write into the fence command in the ring buffer, which is the buffer where DMA buffers are queued for the GPU to run. For more information about these types of identifiers, see [Supplying Fence Identifiers](https://learn.microsoft.com/windows-hardware/drivers/display/supplying-fence-identifiers).

### `VidPnSourceId`

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology for a flip operation. This member is valid only when the **Flip** or **FlipWithNoWait** bit-field flag is set in the **Flags** member.

### `FlipInterval`

A [**D3DDDI_FLIPINTERVAL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_flipinterval_type)-typed value that indicates the flip interval (that is, if the flip occurs after zero, one, two, three, or four vertical syncs). **FlipInterval** is valid only if the **Flip** bit-field flag is set (that is, TRUE) in the **Flags** member.

### `Flags`

A [**DXGK_SUBMITCOMMANDFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_submitcommandflags) structure that identifies information about the DMA buffer to submit.

### `EngineOrdinal`

Reserved for future use.

### `NodeOrdinal`

The zero-based index of the node that the context is created for. Identifies the node when the context is NULL.

## See also

[**D3DDDI_FLIPINTERVAL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_flipinterval_type)

[**DXGK_CONTEXTINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_contextinfo)

[**DxgkDdiCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext)

[**DxgkDdiSubmitCommandVirtual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommandvirtual)