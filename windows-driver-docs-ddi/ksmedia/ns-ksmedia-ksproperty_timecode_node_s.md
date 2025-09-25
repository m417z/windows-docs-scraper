# KSPROPERTY_TIMECODE_NODE_S structure

## Description

The KSPROPERTY_TIMECODE_NODE_S structure describes a timecode.

## Members

### `NodeProperty`

Specifies an initialized [KSP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksp_node) structure that describes the property set, property ID, request type, and node ID.

### `TimecodeSamp`

Specifies the timecode sample. Timecode, absolute track number (ATN) and relative time counter (RTC) are in the **TimecodeSamp.timecode.dwFrames** member.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TIMECODE_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_timecode_s)

[TIMECODE_SAMPLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagtimecode_sample)