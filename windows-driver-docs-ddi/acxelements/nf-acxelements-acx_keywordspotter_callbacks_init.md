## Description

The **ACX_KEYWORDSPOTTER_CALLBACKS_INIT** function initializes a [ACX_KEYWORDSPOTTER_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_keywordspotter_callbacks).

## Parameters

### `Callbacks`

A pointer to an initialized [ACX_KEYWORDSPOTTER_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_keywordspotter_callbacks).

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_KEYWORDSPOTTER_CALLBACKS    keywordSpotterCallbacks;

    ACX_KEYWORDSPOTTER_CALLBACKS_INIT(&keywordSpotterCallbacks);

    keywordSpotterCallbacks.EvtAcxKeywordSpotterRetrieveArm = CodecC_EvtAcxKeywordSpotterRetrieveArm;
    keywordSpotterCallbacks.EvtAcxKeywordSpotterAssignArm = CodecC_EvtAcxKeywordSpotterAssignArm;
    keywordSpotterCallbacks.EvtAcxKeywordSpotterAssignPatterns = CodecC_EvtAcxKeywordSpotterAssignPatterns;
    keywordSpotterCallbacks.EvtAcxKeywordSpotterAssignReset = CodecC_EvtAcxKeywordSpotterAssignReset;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)