## Description

The **DMA_FLAGS** enumeration specifies flags for the [**VideoPortLockPages**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportlockpages) or [**VideoPortDoDma**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportdodma) functions.

## Constants

### `VideoPortUnlockAfterDma`

Tells the video port to unlock the pages after the miniport signals that the DMA is complete via the **pDmaCompletionEvent** in [**HwStartDma**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_start_dma). Failure to set this event at DMA completion can cause the memory to be unlocked at random times. This flag is best used when one wants to do one DMA transfer that occurs infrequently. It allows locking, DMAing, and unlocking to be performed in the context of one IOCTL.

### `VideoPortKeepPagesLocked`

Tells the video port to leave the pages locked if possible.

### `VideoPortDmaInitOnly`

Tells the video port to lock the pages but not call the miniport's [**HwStartDma**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_start_dma) routine. This flag isn't applicable to [**VideoPortDoDma**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportdodma).

## See also

[**HwStartDma**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_start_dma)

[**VideoPortDoDma**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportdodma)

[**VideoPortLockPages**](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportlockpages)