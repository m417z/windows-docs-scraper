## Description

The **EVT_ACX_KEYWORDSPOTTER_ASSIGN_RESET** callback resets the keyword spotter detector to an unarmed state with no pattern set.

## Parameters

### `KeywordSpotter`

An existing, initialized, ACXKEYWORDSPOTTER object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects). Also see the [AcxKeywordSpotterCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nf-acxelements-acxkeywordspottercreate) function.

### `EventId`

A pointer to a GUID that represents the EventId.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

For general information about keyword detection, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation) and [Multiple Voice Assistant](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation-mva).

### Example

Example usage is shown below.

```cpp
EVT_ACX_KEYWORDSPOTTER_ASSIGN_RESET     CodecC_EvtAcxKeywordSpotterAssignReset;

NTSTATUS
NTAPI
CodecC_EvtAcxKeywordSpotterAssignReset(
    _In_    ACXKEYWORDSPOTTER   KeywordSpotter,
    _In_    GUID *              EventId
    )
{
    PAGED_CODE();
    PCODEC_KEYWORDSPOTTER_CONTEXT keywordSpotterCtx;
    CKeywordDetector *            keywordDetector = NULL;

    keywordSpotterCtx = GetCodecKeywordSpotterContext(KeywordSpotter);

    keywordDetector = (CKeywordDetector*)keywordSpotterCtx->KeywordDetector;

    return keywordDetector->ResetDetector(*EventId);
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)