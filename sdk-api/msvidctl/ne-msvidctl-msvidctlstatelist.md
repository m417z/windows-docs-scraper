# MSVidCtlStateList enumeration

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows XP or later.

The **MSVidCtlStateList** enumeration defines the possible state values of the Video Control or the underlying filter graph.

## Constants

### `STATE_UNBUILT:-1`

Indicates that there is no filter graph.

### `STATE_STOP`

Indicates that the Video Control is stopped.

### `STATE_PAUSE`

Indicates that the Video Control is paused.

### `STATE_PLAY`

Indicates that the Video Control is playing.

## See also

[IMSVidDeviceEvent::StateChange](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsviddeviceevent-statechange)

[Video Control Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/video-control-enumerations)

[_IMSVidCtlEvents::StateChange](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd695367(v=vs.85))