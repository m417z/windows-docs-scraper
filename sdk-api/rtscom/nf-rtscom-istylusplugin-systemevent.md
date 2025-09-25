# IStylusPlugin::SystemEvent

## Description

Notifies the implementing plug-in that a system event is available.

## Parameters

### `piRtsSrc` [in]

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) (RTS) object that sent the notification.

### `tcid` [in]

The tablet context identifier for the event.

### `sid` [in]

The security identifier.

### `event` [in]

The system event sent by the RTS object

### `eventdata` [in]

The
[SYSTEM_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/tpcshrd/ns-tpcshrd-system_event_data) structure containing information about the system event, *event*.

## Return value

For a description of return values, see [Classes and Interfaces - Ink Analysis](https://learn.microsoft.com/windows/desktop/tablet/classes-and-interfaces---ink-analysis).

## Remarks

When a system event is being processed the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object provides real time stylus events on a specific window handle within a specific window input rectangle.

Use the [IRealTimeStylus::GetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-getdesiredpacketdescription) method to determine what packet properties are sent in the events.

## See also

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85))

[IRealTimeStylus::SetDesiredPacketDescription Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-setdesiredpacketdescription)

[IRealTimeStylus::WindowInputRectangle Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-irealtimestylus-get_windowinputrectangle)

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[IStylusPlugin::DataInterest Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-datainterest)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)