# KSDATAFORMAT_WAVEFORMATEX structure

## Description

The KSDATAFORMAT_WAVEFORMATEX structure provides detailed information about the data format of an audio stream consisting of wave data.

## Members

### `DataFormat`

Specifies the general features of the stream's data format. This member is a structure of type [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat).

### `WaveFormatEx`

Describes the wave-specific details of the audio stream's data format. This member contains an initialized [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) structure.

## Remarks

In response to an input *DataRange* parameter that specifies a WAVEFORMATEX format (see example in [PCM Stream Data Range](https://learn.microsoft.com/windows-hardware/drivers/audio/pcm-stream-data-range)), the [IMiniport::DataRangeIntersection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-datarangeintersection) method checks to see if the specified pin supports a compatible WAVEFORMATEX format. If so, the method outputs a KSDATAFORMAT_WAVEFORMATEX structure (see example in [PCM Stream Data Format](https://learn.microsoft.com/windows-hardware/drivers/audio/pcm-stream-data-format)) to the buffer that its *ResultantFormat* parameter points to.

Note that the **WaveFormatEx** member of the KSDATAFORMAT_WAVEFORMATEX structure can be extended to include additional format information (for example, a channel configuration mask). For more information, see [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-waveformatextensible).

## See also

[IMiniport::DataRangeIntersection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-datarangeintersection)

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)

[WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex)

[WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-waveformatextensible)