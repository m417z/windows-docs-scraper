## Description

Streams use the **StreamClassStreamNotification** routine to notify the class driver that it has completed a stream request, or that an event has occurred.

## Parameters

### `NotificationType` [in]

This is an enumeration value that contains the type of notification that the minidriver is sending.

#### StreamRequestComplete

Indicates that the minidriver has completed its handling of the stream-oriented stream request block that is pointed to by an optional argument of this routine.

#### ReadyForNextStreamDataRequest

Indicates that this stream is ready to receive another data request.

#### ReadyForNextStreamControlRequest

Indicates that this stream is ready to receive another control request.

#### SignalStreamEvent

Signals that the event specified by an optional argument has occurred.

#### SignalMultipleStreamEvents

Signals that all events that match the criteria specified in optional arguments have occurred.

#### DeleteStreamEvent

Deletes the event specified by an optional parameter.

### `StreamObject` [in]

Points to the stream object of the stream that the class driver is being notified about.

### `...`

## Remarks

The minidriver uses this routine for requests or events that apply to the minidriver as a whole. Stream-specific requests or events use [StreamClassDeviceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassdevicenotification).

## See also

[StreamClassDeviceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassdevicenotification)