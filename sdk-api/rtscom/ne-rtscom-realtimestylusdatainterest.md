# RealTimeStylusDataInterest enumeration

## Description

Defines the values used by plug-ins to specify which event notifications the plug-ins receive.

## Constants

### `RTSDI_AllData:0xffffffff`

The plug-in receives notifications for all stylus data.

### `RTSDI_None:0`

The plug-in receives no notifications for any stylus data.

### `RTSDI_Error:0x1`

An error has been added to the input queue.

### `RTSDI_RealTimeStylusEnabled:0x2`

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object has been enabled.

### `RTSDI_RealTimeStylusDisabled:0x4`

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object has been disabled.

### `RTSDI_StylusNew:0x8`

A [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object encounters a new Stylus object.

### `RTSDI_StylusInRange:0x10`

The Stylus object is in range of the digitizer. Notifies the implementing plug-in that the stylus is entering the input area of the [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object or is entering the detection range of the digitizer above the input area of the **RealTimeStylus Class** object.

### `RTSDI_InAirPackets:0x20`

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object is within range of, but not touching, the digitizer and is moving.

### `RTSDI_StylusOutOfRange:0x40`

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) object is out of range of the digitizer. Informs the implementing plug-in that the stylus is leaving the input area of the **RealTimeStylus Class** object or is leaving the detection range of the digitizer above the input area of the **RealTimeStylus Class** object.

### `RTSDI_StylusDown:0x80`

The stylus is in contact with the digitizer.

### `RTSDI_Packets:0x100`

The stylus is moving and is in contact with the digitizer.

### `RTSDI_StylusUp:0x200`

The stylus has broken physical contact with the digitizer.

### `RTSDI_StylusButtonUp:0x400`

A user has released a stylus button.

### `RTSDI_StylusButtonDown:0x800`

A user has pressed a stylus button.

### `RTSDI_SystemEvents:0x1000`

A system event has been detected.

### `RTSDI_TabletAdded:0x2000`

A new tablet device has been detected by the system. Notifies the implementing plug-in when a Microsoft.Ink.Tablet object is added to the system.

### `RTSDI_TabletRemoved:0x4000`

A tablet device has been removed from the system. Notifies the implementing plug-in when a Microsoft.Ink.Tablet object is removed from the system.

### `RTSDI_CustomStylusDataAdded:0x8000`

A plug-in has added data to a queue. You can identify the kind of custom data by either the GUID or Type.

### `RTSDI_UpdateMapping:0x10000`

A tablet mapping to the screen has been changed or set.

### `RTSDI_DefaultEvents`

The plug-in receives the default stylus data.

## Remarks

The **RealTimeStylusDataInterest Enumeration** values are used in a bitwise combination that defines the set of data notifications. Use the **RealTimeStylusDataInterest Enumeration** to specify only the events for which you would like to receive notification. Thus, improving performance.

The [RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class) notifies plug-ins when it is retrieving packet data by calling into the respective plug-ins in a specified sequence. You control the sequence and types of plug-ins that receive these notifications. The packet data in the events can be modified by the plug-ins the **RealTimeStylus Class** object calls into.

You can control which methods are called on your plug-in by implementing the [IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin):: [IStylusPlugin::DataInterest Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-datainterest) method.

The following events are the default events:

* RTSDI_RealTimeStylusEnabled
* RTSDI_RealTimeStylusDisabled
* RTSDI_StylusDown
* RTSDI_Packets
* RTSDI_StylusUp
* RTSDI_SystemEvents
* RTSDI_CustomStylusDataAdded

## See also

[IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin)

[IStylusSyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylussyncplugin)

[RealTimeStylus Class](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-class)