# IEventDetectorOemAdapter::ComputeAndAddUserModelData

## Description

Adds the user specific model data to an existing model data blob.

## Parameters

### `ModelData`

\[*In*\] - Pointer to IStream bound to model data, updated by this call.

### `EventSelector`

\[*In*\] - The [DETECTIONEVENTELECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/ns-eventdetectoroemadapter-detectioneventselector) that uniquely identifies this model.

### `EventEndBytePos`

\[*In*\] - A pointer to an array byte positions of the end of the audio event in the corresponding UserRecording. A value of -1 indicates the position was unavailable.

### `UserRecordings`

\[*In*\] - Pointer to an array of pointers to the previously verified recordings of the user.

Note that non-standard use of cbSize in WAVEFORMATEX - it is the size of the following PCM data for the user recording.

### `NumUserRecordings`

\[*In*\] - Number of recordings.

## Return value

This method returns HRESULT. It returns S_OK if the function exit successfully. Otherwise it returns:

- E_POINTER- UserModelData pointer is null.
- E_INVALIDARG - the DETECTIONEVENTELECTOR contains an invalid id.
- HRESULT_FROM_WIN32(ERROR_GEN_FAILURE) = unable to complete the processing.

## Remarks

This function is the part of the Event Detector OEM interface to be used for hardware keyword spotters. For more information, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation).

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)