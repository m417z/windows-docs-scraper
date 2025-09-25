# IEventDetectorOemAdapter::GetCapabilitiesForLanguage

## Description

Returns the events supported by the specific language.

## Parameters

### `LangId`

\[*In*\] - Language ID for this displayspeech language for example, 0x0409 is used for English (United States). Language changes should be viewed as re-initialization.

### `EventIds`

\[*Out*\] - Pointer to an array of [DETECTIONEVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/ns-eventdetectoroemadapter-detectionevent) structures supported by this detector.

### `NumEvents`

\[*Out*\] - Pointer to the number of [DETECTIONEVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/ns-eventdetectoroemadapter-detectionevent) structures in the array.

## Return value

This method returns HRESULT. It returns S_OK if the function exit successfully. It can return E_POINTER if one of the out parameter pointers is NULL.

## Remarks

This function is the part of the Event Detector OEM interface to be used for hardware keyword spotters. For more information, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation).

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)