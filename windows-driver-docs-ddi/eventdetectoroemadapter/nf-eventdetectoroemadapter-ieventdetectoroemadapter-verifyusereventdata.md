# IEventDetectorOemAdapter::VerifyUserEventData

## Description

Verifies the user recording for the given EVENTID.

## Parameters

### `ModelData`

\[*In*\] - ModelData- Pointer to IStream bound to model data for a given stored model (optional).

### `UserRecording`

\[*In*\] - Pointer to the buffer containing the raw data in the appropriate format. Note that non-standard use of cbSize in WAVEFORMATEX. It is the size of the following: (PCM data for the user recording).

### `EventSelector`

\[*In*\] - The [DETECTIONEVENTELECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/ns-eventdetectoroemadapter-detectioneventselector) associated with this UserRecording.

### `EventEndBytePos`

\[*In*\] - Byte position of the end of the sound pattern in the UserRecording. A value of -1 indicates the position was unavailable.

## Return value

It returns S_OK if the function exit successfully. Otherwise it returns:

- E_INVALIDARG- UserModelData pointer is null or Keyword Id or LangId are invalid
- E_NO_MATCH- The user recording didn't contain the keyword

Optional return values that may be implemented:

- E_VOICE_TOO_SOFT- User recording isn't loud enough
- E_VOICE_TOO_LOUD- User recording is too loud
- E_VOICE_TOO_SLOW- User was speaking too slowly for recognition
- E_VOICE_TOO_FAST- User was speaking too fast for recognition
- E_VOICE_PROCESSING_ERROR - An unrecoverable error occurred

## Remarks

This function is the part of the Event Detector OEM interface to be used for hardware keyword spotters. For more information, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation).

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)