## Description

The **EVT_ACX_KEYWORDSPOTTER_ASSIGN_ARM** callback sets the arm state of the keyword spotter.

## Parameters

### `KeywordSpotter`

An existing, initialized, ACXKEYWORDSPOTTER object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects). Also see the [AcxKeywordSpotterCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nf-acxelements-acxkeywordspottercreate) function.

### `EventId`

A pointer to a GUID that represents the EventId.

### `Arm`

A boolean value indicating if the keyword detection is armed.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

For general information about keyword detection, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation) and [Multiple Voice Assistant](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation-mva).

### Example

Example usage is shown below.

```cpp
EVT_ACX_KEYWORDSPOTTER_ASSIGN_ARM       DspC_EvtAcxKeywordSpotterAssignArm;

PAGED_CODE_SEG
NTSTATUS DspC_EvtAcxKeywordSpotterAssignArm(
    _In_    ACXKEYWORDSPOTTER   KeywordSpotter,
    _In_    GUID *              EventId,
    _In_    BOOLEAN             Arm
)
{
    PAGED_CODE();
    PDSP_KEYWORDSPOTTER_CONTEXT     keywordSpotterCtx;
    CKeywordDetector *              keywordDetector = NULL;

    keywordSpotterCtx = GetDspKeywordSpotterContext(KeywordSpotter);

    keywordDetector = (CKeywordDetector*)keywordSpotterCtx->KeywordDetector;

    RETURN_NTSTATUS_IF_FAILED(keywordDetector->SetArmed(*EventId, Arm));

    // the following code is for example only, after arming the
    // requested keyword we immediately trigger a detection
    // so that the automated tests do not block.
    if (Arm)
    {
        CONTOSO_KEYWORDDETECTIONRESULT detectionResult;

        // notify the keyword detector that we have a notification, to populate
        // timestamp information for this detection.
        keywordDetector->NotifyDetection();

        // fill in the detection specific information
        detectionResult.EventId = *EventId;
        detectionResult.Header.Size = sizeof(CONTOSO_KEYWORDDETECTIONRESULT);
        detectionResult.Header.PatternType = CONTOSO_KEYWORDCONFIGURATION_IDENTIFIER2;
        detectionResult.KeywordStartTimestamp = keywordDetector->GetStartTimestamp();
        detectionResult.KeywordStopTimestamp = keywordDetector->GetStopTimestamp();
        keywordDetector->GetDetectorData(*EventId, &(detectionResult.ContosoDetectorResultData));

        RETURN_NTSTATUS_IF_FAILED(AcxPnpEventGenerateEvent(keywordSpotterCtx->Event, &detectionResult, sizeof(CONTOSO_KEYWORDDETECTIONRESULT)));
    }

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)