# EVENTACTION structure

## Description

Structure used to provide detail from ParseDetectionResults.

## Members

### `EventdActionType`

Actions to take on a detection. This is a value from the [EventActionType](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/ne-eventdetectoroemadapter-eventactiontype) enumeration.

### `EventActionContextType`

The types of context associated with an action. This is a value from the [EventActionContextType](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/ne-eventdetectoroemadapter-eventactioncontexttype) enumeration.

### `Confidence`

The confidence level is a number between 0.0 and 1.0 that represents how confident the algorithm is that the keyword was detected.

### `Scale`

The scale as defined in the [EVENTACTIONSCALE](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/ne-eventdetectoroemadapter-eventactionscale) enumeration. The scale defines the quality associated with a specific detection can be used for telemetry when no confidence is available or confidence is confusing to report.

### `ErrorCode`

An HRESULT error code from ParseDetectionResults.

## Remarks

This structure is the part of the Event Detector OEM interface to be used for hardware keyword spotters. For more information, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation).

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)