# IEventDetectorOemAdapter::BuildArmingPatternData

## Description

Builds the pattern data to be used on a subsequent arm request - this is done once for each pin instance.
The GUID in the SOUNDDETECTOR_PATTERNHEADER can be used to provide additional context to allow optional model use but the expectation is that the individual DETECTIONEVENTS can be armed and disarmed given appropriate feature support.

## Parameters

### `UserModelData`

\[*In*\] - Pointer to IStream bound to model data (optional).

### `EventSelectors`

\[*In*\] - Pointer to the array of [DETECTIONEVENTSELECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/ns-eventdetectoroemadapter-detectioneventselector) structs to be detected - associated with this BurstID.

### `NumEventSelectors`

\[*In*\] - Number of [DETECTIONEVENTSELECTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/ns-eventdetectoroemadapter-detectioneventselector) structs passed.

### `PatternData`

\[*Out*\] - Pattern data created to reflect the input eventlanguageuser sets for an arm.

## Return value

This method returns HRESULT. It returns S_OK if the function exit successfully. Otherwise it returns E_INVALIDARG - UserModelData pointer is null or one or more of the DETECTIONEVENTELECTOR contains invalid ids.

HRESULT_FROM_WIN32(ERROR_GEN_FAILURE) = unable to complete the processing.

## Remarks

This function is the part of the Event Detector OEM interface to be used for hardware keyword spotters. For more information, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation).

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)