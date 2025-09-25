# KSPROPERTY_EXTXPORT_S structure

## Description

The KSPROPERTY_EXTXPORT_S structure describes an external transport and its capabilities.

## Members

### `Property`

Specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `u`

### `u.Capabilities`

Specifies the capabilities of the external transport. For example ED_TRANSCAP_CAN_EJECT, ED_TRANSCAP_CAN_PLAY_BACKWARDS, or ED_TRANSCAP_CAN_BUMP_PLAY. See Remarks.

### `u.SignalMode`

Specifies the signal mode of the external transport. For example ED_TRANSBASIC_SIGNAL_525_60_SD, ED_TRANSBASIC_SIGNAL_MPEG2TS or ED_TRANSBASIC_SIGNAL_0625_50_MPEG. See Remarks

### `u.LoadMedium`

Specifies load medium. For example eject, open tray, close tray.

### `u.MediumInfo`

Describes the medium info.

### `u.XPrtState`

Describes the external transports state.

### `u.Timecode`

Specifies the timecode, in hour:minute:second:frame format. This member is defined for future use.

### `u.Timecode.frame`

Specifies the frame. This member is defined for future use.

### `u.Timecode.second`

Specifies the second. This member is defined for future use.

### `u.Timecode.minute`

Specifies the minute. This member is defined for future use.

### `u.Timecode.hour`

Specifies the hour. This member is defined for future use.

### `u.dwTimecode`

Specifies the timecode, in hour:minute:second:frame format. This member is defined for future use.

### `u.dwAbsTrackNumber`

Specifies the absolute track number. This member is defined for future use.

### `u.RawAVC`

### `u.RawAVC.PayloadSize`

Specifies the payload size.

### `u.RawAVC.Payload`

Describes the payload

## Remarks

Any ED_TRANSCAP_Xxx or ED_TRANSBASIC_Xxx tokens are defined in *xprtdefs.h* in the Microsoft DirectX SDK.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_EXTXPORT_NODE_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_extxport_node_s)

[MEDIUM_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-medium_info)

[TRANSPORT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-transport_state)