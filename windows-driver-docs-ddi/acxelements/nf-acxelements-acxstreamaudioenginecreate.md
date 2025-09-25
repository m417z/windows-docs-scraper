## Description

The **AcxStreamAudioEngineCreate** function is used to create an ACX stream audio engine object that will be associated with an ACX stream object parent. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `Stream`

An ACXSTREAM object that represents an audio stream on a specific circuit's hardware. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `AudioEngine`

An ACXAUDIOENGINE object that is used in a render circuit, to represent a DSP. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that are used to set various values and to associate the stream audio engine with the parent stream object.

### `Config`

An initialized [ACX_STREAMAUDIOENGINE_CONFIG structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_streamaudioengine_config) that describes the configuration of the stream audio engine.

### `StreamAudioEngine`

A pointer to a location that receives the handle to the newly created ACXSTREAMAUDIOENGINE object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    NTSTATUS                        status;
    WDF_OBJECT_ATTRIBUTES           attributes;
    ACXSTREAM                       stream;
    ACXELEMENT                      elements[2] = {0};
    ACX_STREAMAUDIOENGINE_CONFIG    audioEngineCfg;

        ACX_STREAMAUDIOENGINE_CONFIG_INIT(&audioEngineCfg);
        audioEngineCfg.VolumeElement = volumeElement;
        audioEngineCfg.MuteElement = muteElement;
        audioEngineCfg.PeakMeterElement = peakmeterElement;
        audioEngineCfg.Callbacks = &streamAudioEngineCallbacks;

        WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, CODEC_STREAMAUDIOENGINE_CONTEXT);
        attributes.ParentObject = stream;

        status = AcxStreamAudioEngineCreate(stream, circuitCtx->AudioEngineElement, &attributes, &audioEngineCfg, (ACXSTREAMAUDIOENGINE*)&elements[0]);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)