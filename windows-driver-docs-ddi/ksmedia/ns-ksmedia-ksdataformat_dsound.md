# KSDATAFORMAT_DSOUND structure

## Description

The KSDATAFORMAT_DSOUND structure provides detailed information about a DirectSound audio stream.

## Members

### `DataFormat`

Specifies the stream's data format. This member is a structure of type [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat).

### `BufferDesc`

Describes the DirectSound buffer. This member is a structure of type [KSDSOUND_BUFFERDESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdsound_bufferdesc).

## Remarks

In response to an input *DataRange* parameter that specifies a DirectSound format (see example in [DirectSound Stream Data Range](https://learn.microsoft.com/windows-hardware/drivers/audio/directsound-stream-data-range)), the [IMiniport::DataRangeIntersection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-datarangeintersection) method checks to see if the specified pin supports a compatible DirectSound format. If so, the method outputs a KSDATAFORMAT_DSOUND structure (see example in [DirectSound Stream Data Format](https://learn.microsoft.com/windows-hardware/drivers/audio/directsound-stream-data-format)) to the buffer that its *ResultantFormat* parameter points to.

## See also

[IMiniport::DataRangeIntersection](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiport-datarangeintersection)

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)

[KSDSOUND_BUFFERDESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksdsound_bufferdesc)