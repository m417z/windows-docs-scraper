## Description

The **AcxAudioModuleCreate** function is used to create an audio module that that will be associated with an ACX circuit object parent.

## Parameters

### `Object`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that that will be associated with the circuit.

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that are used to set various values and to associate the audio module with the ACX circuit object.

### `Config`

An initialized [ACX_AUDIOMODULE_CONFIG structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_audiomodule_config) that describes the configuration of the audio module.

### `AudioModule`

A pointer to a location that receives the handle to the new ACXMODULE object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    NTSTATUS                        status;
    WDF_OBJECT_ATTRIBUTES           attributes;
    ACX_AUDIOMODULE_CALLBACKS       audioModuleCallbacks;
    ACX_AUDIOMODULE_CONFIG          audioModuleCfg;
    ACXAUDIOMODULE                  audioModuleElement;

    // Now add audio modules to the circuit
    // module 0

    ACX_AUDIOMODULE_CALLBACKS_INIT(&audioModuleCallbacks);
    audioModuleCallbacks.EvtAcxAudioModuleProcessCommand = CodecR_EvtProcessCommand0;

    ACX_AUDIOMODULE_CONFIG_INIT(&audioModuleCfg);

    audioModuleCfg.Name = &AudioModule0Id;
    audioModuleCfg.Descriptor.ClassId = AudioModule0Id;
    audioModuleCfg.Descriptor.InstanceId = AUDIOMODULE_INSTANCE_ID(0,0);
    audioModuleCfg.Descriptor.VersionMajor = AUDIOMODULE0_MAJOR;
    audioModuleCfg.Descriptor.VersionMinor = AUDIOMODULE0_MINOR;
    wcsncpy_s(audioModuleCfg.Descriptor.Name,
                ACX_AUDIOMODULE_MAX_NAME_CCH_SIZE,
                AUDIOMODULE0DESCRIPTION,
                wcslen(AUDIOMODULE0DESCRIPTION));
    audioModuleCfg.Callbacks = &audioModuleCallbacks;

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, CODEC_AUDIOMODULE0_CONTEXT);
    attributes.ParentObject = Circuit;

    status = AcxAudioModuleCreate(Circuit, &attributes, &audioModuleCfg, &audioModuleElement);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)