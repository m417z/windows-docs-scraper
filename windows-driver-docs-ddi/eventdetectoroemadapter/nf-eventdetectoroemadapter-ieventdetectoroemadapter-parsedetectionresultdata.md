# IEventDetectorOemAdapter::ParseDetectionResultData

## Description

Uses the input model data and [SOUNDDETECTOR_PATTERNHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/ns-eventdetectoroemadapter-sounddetector_patternheader) to determine the DETECTIONEVENTID,LANGID and USER detected.

## Parameters

### `UserModelData`

\[*In*\] - Pointer to IStream bound to model data for the arming pattern (Optional).

### `Result`

\[*In*\] - Pointer to the [SOUNDDETECTOR_PATTERNHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/ns-eventdetectoroemadapter-sounddetector_patternheader) from DDI.

### `AssistantContext`

\[*In*\] - AssistantContext - Data to be provided to the assistant.

### `EventSelector`

\[*Out*\] - The DETECTIONEVENTELECTOR associated with this detection.

### `EventAction`

\[*Out*\] - Action for the system to take, along with associated context.

### `EventStartPerformanceCounterValue`

\[*Out*\] - Event start time, if available, else zero.

### `EventEndPerformanceCounterValue`

\[*Out*\] - Event end time, if available, else zero.

### `DebugOutput`

\[*Out*\] - Optional string to provide open detail, used for logging and telemetry.

## Return value

Returns S_OK if the function exit successfully. Otherwise it returns:

- E_INVALIDARG - If called inconsistently w.r.t. the model data and its header.
- E_POINTER - One or more of the out parameter pointers is null.
- HRESULT_FROM_WIN32(ERROR_GEN_FAILURE) = unable to complete the processing.

## Remarks

This function is the part of the Event Detector OEM interface to be used for hardware keyword spotters. For more information, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation).

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)