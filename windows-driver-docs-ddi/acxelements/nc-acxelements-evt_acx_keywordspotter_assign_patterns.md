## Description

The **EVT_ACX_KEYWORDSPOTTER_ASSIGN_PATTERNS** callback assigns detection patterns for keyword detection to be used by the keyword spotter.

## Parameters

### `KeywordSpotter`

An existing, initialized, ACXKEYWORDSPOTTER object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects). Also see the [AcxKeywordSpotterCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nf-acxelements-acxkeywordspottercreate) function.

### `EventId`

A pointer to a GUID that represents the EventId.

### `Pattern`

A GUID identifying the keyword spotter detection pattern.

### `PatternSize`

The length, in bytes, of the keyword detection pattern.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

For general information about keyword detection, see [Voice Activation](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation) and [Multiple Voice Assistant](https://learn.microsoft.com/windows-hardware/drivers/audio/voice-activation-mva).

### Example

Example usage is shown below.

```cpp
EVT_ACX_KEYWORDSPOTTER_ASSIGN_PATTERNS  CodecC_EvtAcxKeywordSpotterAssignPatterns;

NTSTATUS
NTAPI
CodecC_EvtAcxKeywordSpotterAssignPatterns(
    _In_    ACXKEYWORDSPOTTER   KeywordSpotter,
    _In_    GUID *              EventId,
    _In_    PVOID               Pattern,
    _In_    ULONG               PatternSize
    )
{
    KSMULTIPLE_ITEM *               itemsHeader = nullptr;
    SOUNDDETECTOR_PATTERNHEADER *   patternHeader;
    CONTOSO_KEYWORDCONFIGURATION *  pattern;
    ULONG                           cbRemaining = 0;
    PCODEC_KEYWORDSPOTTER_CONTEXT   keywordSpotterCtx;
    CKeywordDetector *              keywordDetector = NULL;

    PAGED_CODE();

    keywordSpotterCtx = GetCodecKeywordSpotterContext(KeywordSpotter);

    keywordDetector = (CKeywordDetector*)keywordSpotterCtx->KeywordDetector;

    cbRemaining = PatternSize;

    // The SYSVADPROPERTY_ITEM for this property ensures the value size is at
    // least sizeof KSMULTIPLE_ITEM.
    if (cbRemaining < sizeof(KSMULTIPLE_ITEM))
    {
        return STATUS_INVALID_PARAMETER;
    }

    itemsHeader = (KSMULTIPLE_ITEM*)Pattern;

    // Verify property value is large enough to include the items
    if (itemsHeader->Size > cbRemaining)
    {
        return STATUS_INVALID_PARAMETER;
    }

    // No items so clear the configuration.
    if (itemsHeader->Count == 0)
    {
        keywordDetector->ResetDetector(*EventId);
        return STATUS_SUCCESS;
    }

    // This sample supports only 1 pattern type.
    if (itemsHeader->Count > 1)
    {
        return STATUS_NOT_SUPPORTED;
    }

    // Bytes remaining after the items header
    cbRemaining = itemsHeader->Size - sizeof(*itemsHeader);

    // Verify the property value is large enough to include the pattern header.
    if (cbRemaining < sizeof(SOUNDDETECTOR_PATTERNHEADER))
    {
        return STATUS_INVALID_PARAMETER;
    }

    patternHeader = (SOUNDDETECTOR_PATTERNHEADER*)(itemsHeader + 1);

    // Verify the pattern type is supported.
    if (patternHeader->PatternType != CONTOSO_KEYWORDCONFIGURATION_IDENTIFIER2)
    {
        return STATUS_NOT_SUPPORTED;
    }

    // Verify the property value is large enough for the pattern.
    if (cbRemaining < patternHeader->Size)
    {
        return STATUS_INVALID_PARAMETER;
    }

    // Verify the pattern is large enough.
    if (patternHeader->Size != sizeof(CONTOSO_KEYWORDCONFIGURATION))
    {
        return STATUS_INVALID_PARAMETER;
    }

    pattern = (CONTOSO_KEYWORDCONFIGURATION*)(patternHeader);

    return keywordDetector->DownloadDetectorData(*EventId, pattern->ContosoDetectorConfigurationData);
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)