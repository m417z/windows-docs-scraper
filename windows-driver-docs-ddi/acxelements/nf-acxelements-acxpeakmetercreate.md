## Description

The **AcxPeakMeterCreate** function is used to create an ACX peakmeter object that that will be associated with a circuit object parent.

## Parameters

### `Object`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that will be associated with the circuit.

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that are used to set various values and to associate the peakmeter object with the parent circuit object.

### `Config`

An initialized [ACX_PEAKMETER_CONFIG structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_peakmeter_config) that describes the configuration of the audio level peakmeter.

### `PeakMeter`

A pointer to a location that receives the handle to the newly created ACXPEAKMETER object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    WDF_OBJECT_ATTRIBUTES           attributes;

    ACX_PEAKMETER_CALLBACKS         peakmeterCallbacks;
    ACX_PEAKMETER_CONFIG            peakmeterCfg;
    ACXPEAKMETER                    peakmeterElement;
    CODEC_PEAKMETER_ELEMENT_CONTEXT*peakmeterCtx;

    ACX_PEAKMETER_CALLBACKS_INIT(&peakmeterCallbacks);
    peakmeterCallbacks.EvtAcxPeakMeterRetrieveLevel = CodecR_EvtPeakMeterRetrieveLevelCallback;

    ACX_PEAKMETER_CONFIG_INIT(&peakmeterCfg);
    peakmeterCfg.ChannelsCount = MAX_CHANNELS;
    peakmeterCfg.Minimum = PEAKMETER_MINIMUM;
    peakmeterCfg.Maximum = PEAKMETER_MAXIMUM;
    peakmeterCfg.SteppingDelta = PEAKMETER_STEPPING_DELTA;
    peakmeterCfg.Callbacks = &peakmeterCallbacks;

    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, CODEC_PEAKMETER_ELEMENT_CONTEXT);
    attributes.ParentObject = Circuit;

    status = AcxPeakMeterCreate(Circuit, &attributes, &peakmeterCfg, &peakmeterElement);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)