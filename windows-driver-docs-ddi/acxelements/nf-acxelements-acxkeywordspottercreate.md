## Description

The **AcxKeywordSpotterCreate** function is used to create an ACX keyword spotter object that that will be associated with a circuit device object parent.

## Parameters

### `Object`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that will be associated with the circuit.

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that are used to set various values and to associate the KeywordSpotter object with the parent WDF device object.

### `Config`

An initialized [ACX_KEYWORDSPOTTER_CONFIG structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_keywordspotter_config) that describes the configuration of the keyword spotter.

### `KeywordSpotter`

A pointer to a location that receives the handle to the newly created ACXKEYWORDSPOTTER object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_KEYWORDSPOTTER_CALLBACKS_INIT(&keywordSpotterCallbacks);
    keywordSpotterCallbacks.EvtAcxKeywordSpotterRetrieveArm = CodecC_EvtAcxKeywordSpotterRetrieveArm;
    keywordSpotterCallbacks.EvtAcxKeywordSpotterAssignArm = CodecC_EvtAcxKeywordSpotterAssignArm;
    keywordSpotterCallbacks.EvtAcxKeywordSpotterAssignPatterns = CodecC_EvtAcxKeywordSpotterAssignPatterns;
    keywordSpotterCallbacks.EvtAcxKeywordSpotterAssignReset = CodecC_EvtAcxKeywordSpotterAssignReset;

    ACX_KEYWORDSPOTTER_CONFIG_INIT(&keywordSpotterCfg);
    keywordSpotterCfg.Pattern = &CONTOSO_KEYWORDCONFIGURATION_IDENTIFIER2;
    keywordSpotterCfg.Callbacks = &keywordSpotterCallbacks;

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, CODEC_KEYWORDSPOTTER_CONTEXT);
    attributes.ParentObject = Circuit;

    status = AcxKeywordSpotterCreate(Circuit, &attributes, &keywordSpotterCfg, Element);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)