## Description

The ACX_KEYWORDSPOTTER_CALLBACKS structure identifies the driver callbacks for keyword spotter operations.

## Members

### `Size`

The length, in bytes, of this callbacks structure.

### `EvtAcxKeywordSpotterRetrieveArm`

The [ACX_KEYWORDSPOTTER_RETRIEVE_ARM](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_keywordspotter_retrieve_arm) callback.

### `EvtAcxKeywordSpotterAssignArm`

The [ACX_KEYWORDSPOTTER_ASSIGN_ARM](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_keywordspotter_assign_arm) callback.

### `EvtAcxKeywordSpotterAssignPatterns`

The [ACX_KEYWORDSPOTTER_ASSIGN_PATTERNS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_keywordspotter_assign_patterns) callback.

### `EvtAcxKeywordSpotterAssignReset`

The [ACX_KEYWORDSPOTTER_ASSIGN_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/nc-acxelements-evt_acx_keywordspotter_assign_reset) callback.

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