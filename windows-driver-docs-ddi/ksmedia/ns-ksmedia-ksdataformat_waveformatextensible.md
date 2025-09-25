# KSDATAFORMAT_WAVEFORMATEXTENSIBLE structure

## Description

The KSDATAFORMAT_WAVEFORMATEXTENSIBLE structure is a convenient wrapper structure for the case in which the WaveFormatExt is known not to contain extra data.

## Members

### `DataFormat`

Specifies the general features of the stream's data format. This member is a structure of type [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat).

### `WaveFormatExt`

Describes the wave-specific details of the audio stream's data format. This member contains an initialized [WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-waveformatextensible) structure.

## Remarks

For information refer to the [KSDATAFORMAT_WAVEFORMATEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_waveformatex) structure.

## See also

[IMiniport::DataRangeIntersection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-datarangeintersection)

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)

[WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex)

[WAVEFORMATEXTENSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-waveformatextensible)

[KSDATAFORMAT_WAVEFORMATEX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdataformat_waveformatex)