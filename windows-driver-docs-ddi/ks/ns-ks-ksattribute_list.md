# KSATTRIBUTE_LIST structure

## Description

The KSATTRIBUTE_LIST structure contains an attribute defined in a [KSATTRIBUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksattribute) structure.

This structure is used to by mode aware drivers with [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)). The KSATTRIBUTE_LIST has a single element, which is a [KSATTRIBUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksattribute). The Attribute member of the **KSATTRIBUTE** structure is set to KSATTRIBUTEID_AUDIOSIGNALPROCESSING_MODE.

## Members

### `Count`

Specifies the number of attributes in the list.

### `Attributes`

 A [KSATTRIBUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksattribute) structure who's Attribute member is set to *KSATTRIBUTEID_AUDIOSIGNALPROCESSING_MODE*. For more information, see [Audio Signal Processing Modes](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-signal-processing-modes).