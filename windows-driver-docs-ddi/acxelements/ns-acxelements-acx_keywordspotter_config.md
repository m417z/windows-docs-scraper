## Description

The **ACX_KEYWORDSPOTTER_CONFIG** structure is used to define the acx keyword spotter configuration.

## Members

### `Size`

The length, in bytes, of this structure.

### `Id`

A number that represents the element ID.

### `Name`

A pointer to a GUID that represents the name of the element. Can be used for debugging and will default to GUID_NULL if not provided.

### `Flags`

Acx keyword spotter configuration flags defined by the [ACX_KEYWORDSPOTTER_CONFIG_FLAGS enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ne-acxelements-acx_keywordspotter_config_flags). No flag bits are currently defined. Set this member to zero - AcxKeywordSpotterConfigNoFlags.

### `Pattern`

The keyword spotter pattern format, expressed as a GUID.

### `Callbacks`

The [ACX_KEYWORDSPOTTER_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_keywordspotter_callbacks) that identifies the driver callbacks for the keyword spotter operations.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_KEYWORDSPOTTER_CONFIG       keywordSpotterCfg;
    PCODEC_KEYWORDSPOTTER_CONTEXT   keywordSpotterCtx;
    ACX_PNPEVENT_CONFIG             keywordEventCfg;
    ACXPNPEVENT                     keywordEvent;

    ACX_KEYWORDSPOTTER_CALLBACKS_INIT(&keywordSpotterCallbacks);
    keywordSpotterCallbacks.EvtAcxKeywordSpotterRetrieveArm = CodecC_EvtAcxKeywordSpotterRetrieveArm;
    keywordSpotterCallbacks.EvtAcxKeywordSpotterAssignArm = CodecC_EvtAcxKeywordSpotterAssignArm;
    keywordSpotterCallbacks.EvtAcxKeywordSpotterAssignPatterns = CodecC_EvtAcxKeywordSpotterAssignPatterns;
    keywordSpotterCallbacks.EvtAcxKeywordSpotterAssignReset = CodecC_EvtAcxKeywordSpotterAssignReset;

    ACX_KEYWORDSPOTTER_CONFIG_INIT(&keywordSpotterCfg);
    keywordSpotterCfg.Pattern = &CONTOSO_KEYWORDCONFIGURATION_IDENTIFIER2;
    keywordSpotterCfg.Callbacks = &keywordSpotterCallbacks;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)