# EVENTACTIONCONTEXTTYPE enumeration

## Description

Enumeration the types of context associated with an action.

## Constants

### `EVENTACTIONCONTEXTTYPE_None`

0 - no additional context provided

### `EVENTACTIONCONTEXTTYPE_Confidence`

1 - Value between 0.0 and 1.0

### `EVENTACTIONCONTEXTTYPE_Scale`

2 - High, Medium, Low

### `EVENTACTIONCONTEXTTYPE_ErrorCode`

3 - OEM defined

## Remarks

This enumeration is the part of the Event Detector OEM interface to be used for hardware keyword spotters. For more information, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation).

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)