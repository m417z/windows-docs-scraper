# DETECTIONEVENTSELECTOR structure

## Description

A structure to reference a specific detection event.

## Members

### `Event`

A [DETECTIONEVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/ns-eventdetectoroemadapter-detectionevent) event.

### `LangId`

The language ID.

### `UserId`

Specifies the User. 0 if no user indicated.

### `Armed`

A BOOL that specifies if the keyword is currently armed.

## Remarks

This structure is the part of the Event Detector OEM interface to be used for hardware keyword spotters. For more information, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation).

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)