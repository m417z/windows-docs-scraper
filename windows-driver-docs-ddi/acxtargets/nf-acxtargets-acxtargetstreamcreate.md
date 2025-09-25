## Description

The **AcxTargetStreamCreate** function is used to create a target stream.

## Parameters

### `Device`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that is associated with the current ACXCIRCUIT.

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that are used to set various object's values: cleanup and destroy callbacks, context type, and to specify its parent object.

### `Config`

An initialized [ACX_TARGET_STREAM_CONFIG structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/ns-acxtargets-acx_target_stream_config) that describes the configuration of the target stream.

### `TargetStream`

A pointer to a location that receives a handle to the new ACXTARGETSTREAM Object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

Drivers should use the ACXSTREAMBRIDGE to automatically propagate an audio stream down-level to the other connected circuits.

### Example

```cpp

    WDF_OBJECT_ATTRIBUTES               attributes;
    PAGGREGATOR_PIN_CONTEXT             pinCtx;
    ACXSTREAM                           stream;
    AGGREGATOR_STREAM_CONTEXT*          streamCtx;
    ACX_TARGET_STREAM_CONFIG            targetStreamCfg;

    streamCtx = GetAggregatorStreamContext(stream);
    ASSERT(streamCtx);
    streamCtx->StreamState = AcxStreamStateStop;

    pinCtx = GetAggregatorPinContext(Pin);

    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.ParentObject = stream;

...

        ACX_TARGET_STREAM_CONFIG_INIT(&targetStreamCfg);
        targetStreamCfg.TargetCircuit = pinCtx->TargetPins[i]->TargetCircuit;
        targetStreamCfg.PinId = pinCtx->TargetPins[i]->TargetPinId;
        targetStreamCfg.DataFormat = StreamFormat;
        targetStreamCfg.SignalProcessingMode = SignalProcessingMode;
        targetStreamCfg.OptionalParameters = VarArguments;

...

        status = AcxTargetStreamCreate(Device, &attributes, &targetStreamCfg, &streamCtx->TargetStreams[i]);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)