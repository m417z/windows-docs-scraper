# PHDAUDIO_BDL_ISR callback function

## Description

The HDAudioBdlIsr routine is the ISR that the HD Audio bus driver calls each time an IOC interrupt occurs on the stream. It is a function pointer of type PHDAUDIO_BDL_ISR, which is defined as follows.

## Parameters

### `Context` [in]

The HD Audio bus driver calls the ISR with the same context value that the client specified in the context parameter of the preceding SetupDmaEngineWithBdl call. For more information, see [PSETUP_DMA_ENGINE_WITH_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl).

### `InterruptBitMask` [in]

The interruptBitMask parameter contains the bits from the HD Audio controller device's stream status register that indicate the reason for the interrupt. The following table shows the meaning of the individual bits in interruptBitMask.

|Bit Numbers |Meaning |
|------------|--------|
|31:5|Unused.|
|4|Descriptor Error (DESE). If an error occurs during the fetch of a buffer descriptor, then the HD Audio controller sets the DESE bit to 1.|
|3|FIFO Error (FIFOE). If a FIFO error occurs (an overrun on an output stream or an underrun on an input stream), then the HD Audio controller sets the FIFOE bit to 1.|
|2|Buffer Completion Interrupt Status (BCIS). If the IOC bit is set to 1 in the command byte of the buffer descriptor, then the HD Audio controller sets the BCIS bit to 1 after the last sample of a buffer is processed.|
|1:0|Unused.|

The HD Audio bus driver sets the unused bits to zero. Instead of assuming that an IOC interrupt has occurred, the ISR must always check the interruptBitMask parameter to determine whether a stream error has occurred. For more information about the interrupt status bits shown in the preceding table, see the description of the stream status registers in the Intel High Definition Audio Specification.

The FIFO size is the maximum number of bytes that the DMA engine can hold in its internal buffer at any one time .

Depending on the hardware implementation, a DMA engine's FIFO size can either be static or vary dynamically with changes in the stream format. For more information about the FIFO size, see the Intel High Definition Audio Specification.

## Remarks

The caller must allocate the buffer memory and BDL from the nonpaged pool.

## See also

[PSETUP_DMA_ENGINE_WITH_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-psetup_dma_engine_with_bdl)

[hdaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/)