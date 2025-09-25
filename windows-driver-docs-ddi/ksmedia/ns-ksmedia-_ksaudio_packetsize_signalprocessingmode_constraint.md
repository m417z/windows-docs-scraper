# _KSAUDIO_PACKETSIZE_SIGNALPROCESSINGMODE_CONSTRAINT structure

## Description

The **KSAUDIO_PACKETSIZE_PROCESSINGMODE_CONSTRAINT** structure describes the constraints specific to any signal processing mode.

## Members

### `ProcessingMode`

The signal processing mode that this constraint applies to.

### `SamplesPerProcessingPacket`

The processing frame size for the processing mode, expressed in number of samples. If this value is 0, the constraint is expressed by the **ProcessingPacketDurationInHns** field.

### `ProcessingPacketDurationInHns`

The processing frame size for the processing mode, expressed in hundred-nanosecond (HNS) units. This field is ignored if **SamplesPerProcessingPacket** is nonzero.

## See also

[KSAUDIO_PACKETSIZE_CONSTRAINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ksaudio_packetsize_constraints)