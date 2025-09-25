## Description

The **AcxAudioEngineCreate** function is used to create an audio engine that that will be associated with a circuit WDFDEVICE device object parent.

## Parameters

### `Object`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that will be associated with the circuit.

### `Attributes`

A [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that is used to associate the AcxAudioEngine with the parent circuit object. Note that additional WDF attributes such as WDF_EXECUTION_LEVEL or WDF_SYNCHRONIZATION_SCOPE, should not be set using the *Attributes* parameter as they are a managed by ACX.

### `Config`

An initialized [ACX_AUDIOENGINE_CONFIG structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_audioengine_config) that describes the configuration of the audio engine.

### `AudioEngine`

A pointer to a location that receives the handle to the new ACXAUDIOENGINE object that is used in a render circuit, to represent a DSP. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    NTSTATUS                        status;
    WDF_OBJECT_ATTRIBUTES           attributes;
    ACX_AUDIOENGINE_CONFIG          audioEngineCfg;

    ACX_AUDIOENGINE_CONFIG_INIT(&audioEngineCfg);

    audioEngineCfg.HostPin = Pins[HostPin];
    audioEngineCfg.OffloadPin = Pins[OffloadPin];
    audioEngineCfg.LoopbackPin = Pins[LoopbackPin];
    audioEngineCfg.VolumeElement = volumeElement;
    audioEngineCfg.MuteElement = muteElement;
    audioEngineCfg.PeakMeterElement = peakmeterElement;
    audioEngineCfg.Callbacks = &audioEngineCallbacks;

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, CODEC_ENGINE_CONTEXT);
    attributes.ParentObject = Circuit;

    status = AcxAudioEngineCreate(Circuit, &attributes, &audioEngineCfg, AudioEngine);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)