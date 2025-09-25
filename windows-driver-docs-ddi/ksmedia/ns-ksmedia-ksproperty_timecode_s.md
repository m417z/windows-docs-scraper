# KSPROPERTY_TIMECODE_S structure

## Description

The KSPROPERTY_TIMECODE_S structure describes a timecode.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `TimecodeSamp`

Specifies the timecode sample. Timecode, absolute track number (ATN) and relative time counter (RTC) are in the **TimecodeSamp.timecode.dwFrames** member.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_TIMECODE_NODE_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_timecode_node_s)

[TIMECODE_SAMPLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagtimecode_sample)