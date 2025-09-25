# _tagKSAUDIOENGINE_BUFFER_SIZE_RANGE structure

## Description

The **KSAUDIOENGINE_BUFFER_SIZE_RANGE** structure specifies the minimum and maximum buffer size that the hardware audio engine can support at the instance when it is called.

## Members

### `MinBufferBytes`

Specifies the minimum buffer size in bytes that the hardware Audio Engine can support, at the instance when it is called. The minimum size is calculated to be the minimum size of buffer that will not cause frequent audio glitching.

### `MaxBufferBytes`

Specifies the maximum available DMA buffer size in bytes that the hardware Audio Engine can support, at the instance when it is called. The capability and availability of the DMA engine and the internal DSP buffer are all taken into consideration.

## Remarks

The audio stack uses the information about the buffer size limits to determine the optimum buffer size to allocate, to achieve low power playback. The audio stack also takes into account the data format that the caller specified in the [KSDATAFORMAT_WAVEFORMATEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_waveformatex) structure when it called the [KSPROPERTY_AUDIOENGINE_BUFFER_SIZE_RANGE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audioengine-buffer-size-limits) property.

## See also

[KSDATAFORMAT_WAVEFORMATEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_waveformatex)

[KSPROPERTY_AUDIOENGINE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audioengine)

[KSPROPERTY_AUDIOENGINE_BUFFER_SIZE_RANGE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audioengine-buffer-size-limits)