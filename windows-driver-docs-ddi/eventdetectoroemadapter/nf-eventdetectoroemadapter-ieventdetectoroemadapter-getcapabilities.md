# IEventDetectorOemAdapter::GetCapabilities

## Description

Returns languages and detector features supported by the object.

## Parameters

### `GlobalFeatureSupport`

\[*Out*\] - Pointer to EVENTFEATURES indicating what features are supported.

### `LangIds`

\[*Out*\] - Pointer to an array of LANGIDs supported by the object.

### `NumLanguages`

\[*Out*\] - Pointer to the number of LANGIDs in the array.

### `NumUserRecordings`

\[*Out*\] - Pointer to the number of user recordings required for training.

### `ppFormat`

\[*Out*\] - Pointer to a pointer to the media type required by the object for user training and user customization.

## Return value

This method returns HRESULT. It returns S_OK if the function exit successfully. It can return E_POINTER if one of the out parameter pointers is NULL.

## Remarks

This function is the part of the Event Detector OEM interface to be used for hardware keyword spotters. For more information, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation).

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)