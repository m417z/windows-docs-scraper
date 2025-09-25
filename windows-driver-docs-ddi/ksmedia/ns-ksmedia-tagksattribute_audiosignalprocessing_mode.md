# tagKSATTRIBUTE_AUDIOSIGNALPROCESSING_MODE structure

## Description

The KSATTRIBUTE_AUDIOSIGNALPROCESSING_MODE structure specifies an audio signal processing mode.

This structure is used to by mode aware drivers with [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) which contain a [KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item) of [KSATTRIBUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksattribute) structures that reference a KSATTRIBUTE_AUDIOSIGNALPROCESSING_MODE.

The KSATTRIBUTE_AUDIOSIGNALPROCESSING_MODE AttributeHeader.Attribute member is set to KSATTRIBUTEID_AUDIOSIGNALPROCESSING_MODE, and the KSATTRIBUTE_AUDIOSIGNALPROCESSING_MODE SignalProcessingMode member is set to AUDIO_SIGNALPROCESSINGMODE_DEFAULT or other processing modes that the driver supports. For more information, see [KS Data Formats and Data Ranges](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-data-formats-and-data-ranges).

## Members

### `AttributeHeader`

The AttributeHeader member specifies the attribute header using a [KSATTRIBUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksattribute) data type.

### `SignalProcessingMode`

The SignalProcessingMode member specifies the unique GUIDs of the SignalProcessingMode. For more information, see [Audio Signal Processing Modes](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-signal-processing-modes).