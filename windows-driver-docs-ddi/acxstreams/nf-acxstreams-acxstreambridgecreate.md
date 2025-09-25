## Description

The **AcxStreamBridgeCreate** function uses a ACX_STREAM_BRIDGE_CONFIG to create a StreamBridge for a circuit.

An ACXSTREAMBRIDGE is used by a circuit to propagate a stream creation, stream's states transitions and DRM settings between the endpoint's circuit stream segments. This object is only used in a multi-circuit (audio composite) scenario.

## Parameters

### `AcxCircuit`

A pointer to a location that receives a handle to the associated ACXCIRCUIT Object. For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) that are used to set the various object's values: cleanup and destroy callbacks, context type, and to specify its parent object. For more information, see [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure and the remarks section of this topic.

### `Config`

An [ACX_STREAM_BRIDGE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_stream_bridge_config) structure that defines the configuration. This structure contains AUDIO_SIGNALPROCESSINGMODEs, InModes and OutModes that are used to control audio signal processing mode of the output stream.

### `StreamBridge`

A pointer to a location that receives a handle to the new ACXSTREAMBRIDGE Object.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

An audio endpoint is a collection of one or more audio circuits (ACXCIRCUIT objects) which are assembled to create a complete audio path. An ACX driver normally creates audio circuits for different audio endpoints, although ACX doesn't prohibit circuits created by the same driver to be part of the same audio endpoint's collection, as long as they belong to a different device stack. An audio endpoint is a collection of audio circuits created by the same or different audio drivers.

By default, the new ACXSTREAMBRIDGE object's parent is the specified ACXCIRCUIT. You can use the ParentObject member of the WDF_OBJECT_ATTRIBUTES structure to specify a different parent with ACXCIRCUIT as ancestor. The framework deletes the ACXSTREAMBRIDGE object when it deletes the parent object.

Your driver can delete the ACXSTREAMBRIDGE object when it has finished using the object; otherwise, the object will remain until the parent is deleted, which is the case when it is created during the ACXCIRCUIT initialization/creation.

A pin can be associated with zero, one or more ACXSTREAMBRIDGEs. ACX searches the associated ACXPIN's signal processing mode list for a stream signal processing mode match. The search stops at the first match.

ACX creates a default ACXSTREAMBRIDGE for a ACXCIRCUIT to ACXCIRCUIT bridge if the driver doesn't create one, and the driver didn't disable the default stream bridge handling with the [AcxCircuitInitDisableDefaultStreamBridgeHandling function](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitdisabledefaultstreambridgehandling).

### Example

Example usage is shown below.

```cpp
    ACX_STREAM_BRIDGE_CONFIG bridgeCfg;
    ACXSTREAMBRIDGE          bridge = NULL;

    ACX_STREAM_BRIDGE_CONFIG_INIT(&bridgeCfg);
    bridgeCfg.InModesCount = 1;
    bridgeCfg.InModes      = inModes;
    bridgeCfg.OutMode      = &AUDIO_SIGNALPROCESSINGMODE_DEFAULT;

    status = AcxStreamBridgeCreate(circuit, &attributes, &bridgeCfg, &bridge);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)