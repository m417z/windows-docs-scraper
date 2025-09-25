# EVENTACTIONTYPE enumeration

## Description

Enumeration that defines actions to take on a detection.

## Constants

### `EVENTACTIONTYPE_Accept`

0 - Event detection should be processed by the OS

### `EVENTACTIONTYPE_Reject`

1 - Event detection should be rejected by OS - data collection should occur

### `EVENTACTIONTYPE_Error`

3 - Error occurred, failing HR expected in EVENTACTION return

## Remarks

This enumeration is the part of the Event Detector OEM interface to be used for hardware keyword spotters. For more information, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation).

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)