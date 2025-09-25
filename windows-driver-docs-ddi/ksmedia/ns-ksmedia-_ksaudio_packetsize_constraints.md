# _KSAUDIO_PACKETSIZE_CONSTRAINTS structure

## Description

The **KSAUDIO_PACKETSIZE_CONSTRAINTS** structure describes the physical hardware constraints. It includes an array of 0 or more [KSAUDIO_PACKETSIZE_PROCESSINGMODE_CONSTRAINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ksaudio_packetsize_signalprocessingmode_constraint) structures describing constraints specific to any signal processing modes.
The driver sets this property before calling [PcRegisterSubdevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregistersubdevice) or otherwise enabling its KS filter interface for its streaming pins.

## Members

### `MinPacketPeriodInHns`

The absolute minimum processing period supported by the driver expressed in hundred-nanosecond (HNS) units. This value can be 0 if the driver has no specific minimum processing period.

### `PacketSizeFileAlignment`

The byte size alignment requirement. Use one of these defined file alignment values:

#### FILE_BYTE_ALIGNMENT

#### FILE_WORD_ALIGNMENT

#### FILE_LONG_ALIGNMENT

#### FILE_QUAD_ALIGNMENT

#### FILE_OCTA_ALIGNMENT

#### FILE_32_BYTE_ALIGNMENT

#### FILE_64_BYTE_ALIGNMENT

#### FILE_128_BYTE_ALIGNMENT

#### FILE_256_BYTE_ALIGNMENT

#### FILE_512_BYTE_ALIGNMENT

### `Reserved`

Unused.

### `NumProcessingModeConstraints`

The number of additional constraints for specific processing modes. This value can be 0.

### `ProcessingModeConstraints`

An array of 0 or more processing mode constraints.

## Remarks

The driver sets this variable length data structure as the value of the DEVPKEY_KsAudio_PacketSize_Constraints property on the PnP interface of the KS filter that has the streaming pins with the constraints.

For WaveRT drivers, this data structure describes the constraints for a WaveRT packet. Several WaveRT packets (typically 2) are concatenated to form the WaveRT buffer.

## See also

[KSAUDIO_PACKETSIZE_PROCESSINGMODE_CONSTRAINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_ksaudio_packetsize_signalprocessingmode_constraint)

[PcRegisterSubdevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcregistersubdevice)