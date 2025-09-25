# IEventDetectorOemAdapterVtbl structure

## Description

IEventDetectorOemAdapterVtbl structure is an artifact created by the IDL. It is reserved for Microsoft use.

## Members

### `b`

Reserved for Microsoft use.

### `QueryInterface`

Standard COM QueryInterface method.

### `AddRef`

Standard COM AddRef method.

### `Release`

Standard COM Release method.

### `GetCapabilities`

Returns languages and detector features supported by the object. For more information, see [IEventDetectorOemAdapter::GetCapabilities method](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/nf-eventdetectoroemadapter-ieventdetectoroemadapter-getcapabilities).

### `GetCapabilitiesForLanguage`

Returns the events supported by the specific language. For more information, see [IEventDetectorOemAdapter::GetCapabilitiesForLanguage method](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/nf-eventdetectoroemadapter-ieventdetectoroemadapter-getcapabilitiesforlanguage).

### `VerifyUserEventData`

Verifies the user recording for the given EVENTID. For more information, see [IEventDetectorOemAdapter::VerifyUserEventData method](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/nf-eventdetectoroemadapter-ieventdetectoroemadapter-verifyusereventdata).

### `ComputeAndAddUserModelData`

Adds the user specific model data to an existing model data blob. For more information, see [IEventDetectorOemAdapter::ComputeAndAddUserModelData method](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/nf-eventdetectoroemadapter-ieventdetectoroemadapter-computeandaddusermodeldata).

### `BuildArmingPatternData`

Builds the pattern data to be used on a subsequent arm request - this is done once for each pin instance. For more information, see [IEventDetectorOemAdapter::BuildArmingPatternData method](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/nf-eventdetectoroemadapter-ieventdetectoroemadapter-buildarmingpatterndata).

### `ParseDetectionResultData`

Uses the input model data and SOUNDDETECTOR_PATTERNHEADER to determine the DETECTIONEVENTID,LANGID and USER detected.
For more information, see [IEventDetectorOemAdapter::ParseDetectionResultData method](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/nf-eventdetectoroemadapter-ieventdetectoroemadapter-parsedetectionresultdata).

### `ReportOSDetectionResult`

Called to provide second stage result to OEM dll. For more information, see [IEventDetectorOemAdapter::ReportOSDetectionResult method](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/nf-eventdetectoroemadapter-ieventdetectoroemadapter-reportosdetectionresult).

## Remarks

This structure is an artifact created by the IDL. It is reserved for Microsoft use.

## See also

- [eventdetectoroemadapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/eventdetectoroemadapter/)

- [Audio](https://learn.microsoft.com/windows-hardware/drivers/ddi/_audio/)