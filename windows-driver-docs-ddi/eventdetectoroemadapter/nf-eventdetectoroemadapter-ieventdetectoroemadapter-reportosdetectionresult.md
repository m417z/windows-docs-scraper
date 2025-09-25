# IEventDetectorOemAdapter::ReportOSDetectionResult

## Description

Called to provide second stage result to OEM dll.

## Parameters

### `EventSelector`

\[*In*\] - Pointer to IStream bound to model data for the arming pattern (Optional).

### `EventAction`

\[*In*\] - Pointer to the [SOUNDDETECTOR_PATTERNHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/ns-eventdetectoroemadapter-sounddetector_patternheader) from the DDI.

## Remarks

This function is the part of the Event Detector OEM interface to be used for hardware keyword spotters. For more information, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation).

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)