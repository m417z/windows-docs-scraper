# _HDAUDIO_BUFFER_DESCRIPTOR structure

## Description

The HDAUDIO_BUFFER_DESCRIPTOR structure specifies a buffer descriptor, which is an entry in a buffer descriptor list (BDL).

## Members

### `Address`

Specifies the start address of a physically contiguous fragment of the buffer. In the case of a 32-bit address, the address should be right-justified and the 32 most significant bits (MSBs) of the member should be zero.

### `Length`

Specifies the size in bytes of the buffer fragment.

### `InterruptOnCompletion`

Specifies whether the DMA engine should generate an interrupt on completing the transfer of the buffer fragment. A value of 1 enables the interrupt. A value of 0 disables it.

## Remarks

A BDL is an array of HDAUDIO_BUFFER_DESCRIPTOR structures. Each structure specifies a physically contiguous fragment of the buffer. A BDL specifies all the fragments that make up the buffer.

The **Address** member contains the physical memory address of the start of the buffer fragment. The **Length** member specifies the number of bytes of physically contiguous memory that the fragment contains.

If the **InterruptOnCompletion** bit is set during a DMA transfer to or from the buffer fragment, the DMA engine generates an interrupt on completion of the transfer.

This structure is used by the [AllocateContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_contiguous_dma_buffer) and [SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl) routines.

For more information about BDLs, see the Intel High Definition Audio Specification at the [Intel HD Audio](https://go.microsoft.com/fwlink/p/?linkid=42508) website.

## See also

[AllocateContiguousDmaBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pallocate_contiguous_dma_buffer)

[SetupDmaEngineWithBdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl)