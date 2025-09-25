# PFND3DDDI_SUBMITCOMMANDCB callback function

## Description

**pfnSubmitCommandCb** is used to submit command buffers on contexts that support graphics processing unit (GPU) virtual addressing. These contexts generate commands directly from user mode, manage their own command buffer pool and don’t make use of allocation or patch location list.

**pfnSubmitCommandCb** replaces the old [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) for such contexts and must be used in its place. Contexts that operate in legacy patch mode must continue to use the old *pfnRenderCb*.

Although the user mode driver doesn’t generate patch locations it must still generate a list of the primaries that are being written to. The video memory manager uses the allocation list to determine which primary allocations are being referenced for write by each command buffer. This information is used to synchronize rendering to the primaries with *Flip* operations.

Some kernel mode drivers need information from their user mode driver on how to submit a particular direct memory access (DMA) buffer to their GPU. In Windows Display Driver Model (WDDM) 1.0, this information was sent by the user mode driver to the kernel mode driver through the command buffer. Since DMA buffer are built directly by the user mode driver and submitted to the GPU without modification they can’t be used to send information to the kernel driver anymore. As a result, we are adding an explicit private driver data buffer to be sent along with a submission. Note that this private driver data is unidirectional and the kernel mode driver can’t return information to the user mode driver through this buffer.

## Parameters

### `hDevice`

A handle to the display device.

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_SUBMITCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_submitcommand) structure that describes the operation to perform.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[D3DDDICB_SUBMITCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_submitcommand)

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)