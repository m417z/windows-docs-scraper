## Description

The **AcxMuteCreate** function is used to create an ACX mute object that that will be associated with a circuit object parent.

## Parameters

### `Object`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that will be associated with the circuit.

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that are used to set various values and to associate the mute object with the parent circuit object.

### `Config`

An initialized [ACX_MUTE_CONFIG structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_mute_config) that describes the configuration of the mute behavior.

### `Mute`

A pointer to a location that receives the handle to the newly created ACXMUTE object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    NTSTATUS                        status;
    WDF_OBJECT_ATTRIBUTES           attributes;

    ACX_MUTE_CALLBACKS              muteCallbacks;
    ACX_MUTE_CONFIG                 muteCfg;
    ACXMUTE                         muteElement;

    ACX_MUTE_CALLBACKS_INIT(&muteCallbacks);
    muteCallbacks.EvtAcxMuteAssignState = CodecR_EvtMuteAssignState;
    muteCallbacks.EvtAcxMuteRetrieveState = CodecR_EvtMuteRetrieveState;

    ACX_MUTE_CONFIG_INIT(&muteCfg);
    muteCfg.ChannelsCount = MAX_CHANNELS;
    muteCfg.Name = &KSAUDFNAME_WAVE_MUTE;
    muteCfg.Callbacks = &muteCallbacks;

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, CODEC_MUTE_ELEMENT_CONTEXT);
    attributes.ParentObject = Circuit;

    status = AcxMuteCreate(Circuit, &attributes, &muteCfg, &muteElement);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)