# IMiniportWaveRTStreamNotification::FreeBufferWithNotification

## Description

The `FreeBufferWithNotification` method is used to free an audio buffer previously allocated with a call to [IMiniportWaveRTStreamNotification::AllocateBufferWithNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavertstreamnotification-allocatebufferwithnotification).

## Parameters

### `AudioBufferMdl` [in]

Specifies a memory descriptor list ([MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)) previously allocated with a call to **IMiniportWaveRTStreamNotification::AllocateBufferWithNotification**.

### `BufferSize` [in]

Output pointer for the number of bytes the method has written to the Attributes buffer. This parameter points to a ULONG variable into which the method writes the byte count.

## Remarks

The port driver calls this method to free an audio buffer that was allocated with a previous call to **IMiniportWaveRTStreamNotification::AllocateBufferWithNotification**.

## See also

[IMiniportWaveRTStreamNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertstreamnotification)

[IMiniportWaveRTStreamNotification::AllocateBufferWithNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavertstreamnotification-allocatebufferwithnotification)

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)