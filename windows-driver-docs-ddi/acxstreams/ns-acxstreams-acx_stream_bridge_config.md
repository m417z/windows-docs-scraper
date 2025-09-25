## Description

The **ACX_STREAM_BRIDGE_CONFIG** structure is used to configure attributes, such as the AUDIO_SIGNALPROCESSINGMODEs, and the ACX_STREAM_BRIDGE_TYPE for the AcxStreamBridge. The AcxStreamBridge is used by a circuit to propagate stream creation, the stream’s states transitions and DRM settings between the endpoint's circuit stream segments. For information about ACX streaming, see [ACX streaming](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-streaming).

## Members

### `Size`

The length, in bytes, of this structure.
### `Flags`

Bitwise OR of [ACX_STREAM_BRIDGE_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ne-acxstreams-acx_stream_bridge_config_flags) enum.

### `Type`

The [ACX_STREAM_BRIDGE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ne-acxstreams-acx_stream_bridge_type) enum that defines the type of bridge.

### `InModesCount`

The number of AUDIO_SIGNALPROCESSINGMODEs listed in InModes. These are the signal processing modes accepted as input by ACXSTREAMBRIDGE. For more information about audio modes, see [Audio Signal Processing Modes](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-signal-processing-modes).

This field can be zero only if the InModes field is set to NULL.

### `InModes`

A pointer to a list of AUDIO_SIGNALPROCESSINGMODE pointers supported by ACXSTREAMBRIDGE.

- This field can be set to a specific mode, such as AUDIO_SIGNALPROCESSINGMODE_DEFAULT or AUDIO_SIGNALPROCESSINGMODE_RAW.
- A `NULL_GUID` is a wild card value and it matches any AUDIO_SIGNALPROCESSINGMODE(s).
- If the input signal processing modes are not defined at all, the ACXSTREAMBRIDGE does not automatically match any mode. In this case, it is up to the driver to manually add the input stream to the stream bridge, after the stream bridge is created.

### `OutMode`

A pointer to an AUDIO_SIGNALPROCESSINGMODE that defines the audio signal processing mode of the output stream.

- If this field is not specified (set to NULL), the AUDIO_SIGNALPROCESSINGMODE_DEFAULT is used if supported by the associated ACXPIN, else the AUDIO_SIGNALPROCESSINGMODE_RAW is used. If AUDIO_SIGNALPROCESSINGMODE_RAW is also not supported, the output stream is created without specifying an audio signal processing mode.
- If this field is set to `NULL_GUID`, ACX uses the MODE associated with the input stream.
- See the remarks section for additional information on the behavior of audio signal processing modes.

### `OutStreamVarArguments`

An ACXOBJECTBAG object that is used to provide variable arguments for the output stream. This is an optional setting and can be NULL. For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `TargetStreamAttributes`

An [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that is used to define the ACXTARGETSTREAM object attributes.

## Remarks

AcxStreamBridge is used by a circuit to propagate stream creation, the stream’s states transitions and DRM settings between the endpoint's circuit stream segments. This object is only used in a multi-circuit (audio composite) scenario.

The ACXSTREAMBRIDGE must be parented to an object that has ACXCIRCUIT as an ancestor.

A pin can be associated with zero, one, or more ACXSTREAMBRIDGEs. ACX searches the associated ACXPIN's signal processing mode list for a stream signal processing mode match. The search stops at the first match.

ACX creates a default ACXSTREAMBRIDGE for a ACXCIRCUIT to ACXCIRCUIT bridge if the driver doesn't create one, and the driver didn't disable the default stream bridge handling with the [AcxCircuitInitDisableDefaultStreamBridgeHandling function](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitinitdisabledefaultstreambridgehandling).

If the associated ACXPIN supports the specified audio signal processing mode, the default data-format for that audio signal processing mode is used when creating the output stream.

If the associated ACXPIN doesn't support the specified audio signal processing mode, the input stream's data format is used when creating the output stream.

If the stream bridge does not specify a mode, ACX will attempt to use AUDIO_SIGNALPROCESSINGMODE_DEFAULT mode (and its default format), or RAW (and its default format). If neither of these are present, it will not use a mode.

The stream bridge only allows one stream out, and the first stream configuration is is used. Thus, adding a COMMUNICATION and RAW, you will have a COMMUNICATION mode out. If you add RAW and the COMMUNICATION, you will have RAW out.

### InModes and OutModes being set to NULL

Example usage is shown below. This first example shows the InModes and OutModes being set to NULL. In this case, ACX will use whatever the incoming mode is.

```cpp
        ACXSTREAMBRIDGE             bridge          = NULL;
        ACX_STREAM_BRIDGE_CONFIG    bridgeCfg;

        ACX_STREAM_BRIDGE_CONFIG_INIT(&bridgeCfg);
        bridgeCfg.InModesCount = 0;     // no in-modes. this stream-bridge is manually managed.
        bridgeCfg.InModes      = NULL;
        bridgeCfg.OutMode      = NULL;  // no mode, i.e., default (1st), raw (2nd) or no mode (3rd).
        bridgeCfg.Flags       |= AcxStreamBridgeInvertChangeStateSequence;

        WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
        attributes.ParentObject = pin;

        status = AcxStreamBridgeCreate(Circuit, &attributes, &bridgeCfg, &bridge);
```

### InModes and OutModes not being set at bridge creation

This example shows not setting the InModes for a capture circuit, as they will be later added manually.

```cpp
    // Do not specify InModes for capture - this will prevent the ACX framework from adding created streams to this stream
    // bridge automatically. We want to add the stream bridges manually since we don't want KWS streams added.
    StreamCfg.OutMode = &AUDIO_SIGNALPROCESSINGMODE_RAW;
    StreamCfg.OutStreamVarArguments = objBag;

     ACXSTREAMBRIDGE streamBridge = NULL;
    RETURN_NTSTATUS_IF_FAILED(AcxStreamBridgeCreate(Circuit, &attributes, &StreamCfg, &streamBridge));
```

### InModes and OutModes being set to NULL_GUID

This example shows InModes and OutModes being set to the NULL_GUID.

```cpp
        #define NULL_GUID { 0x00000000, 0x0000, 0x0000, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} }

                PCGUID  inModes[] =
        {
            &NULL_GUID, // Match every mode.
        };

        WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
        attributes.ParentObject = pin;

        ACX_STREAM_BRIDGE_CONFIG bridgeCfg;
        ACX_STREAM_BRIDGE_CONFIG_INIT(&bridgeCfg);

        bridgeCfg.Flags |= AcxStreamBridgeForwardInStreamVarArguments;
        bridgeCfg.InModesCount = ARRAYSIZE(inModes);
        bridgeCfg.InModes = inModes;
        bridgeCfg.OutMode = &NULL_GUID; // Use the MODE associated the in-stream.
```

### InModes and OutModes being set for AUDIO_SIGNALPROCESSINGMODE_DEFAULT and AUDIO_SIGNALPROCESSINGMODE_RAW

This example shows how to set a stream BRIDGE for DEFAULT and RAW modes.

```cpp
    //
    // Add a stream BRIDGE for RAW and DEFAULT modes.
    //
    PCGUID  inModes[] =
    {
        &AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
        &AUDIO_SIGNALPROCESSINGMODE_RAW,
    };

    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.ParentObject = pin;

    ACXSTREAMBRIDGE bridge = NULL;
    ACX_STREAM_BRIDGE_CONFIG bridgeCfg;

    ACX_STREAM_BRIDGE_CONFIG_INIT(&bridgeCfg);
    streamCfg.InModesCount = 2;
    streamCfg.InModes      = inModes;
    streamCfg.OutMode      = &AUDIO_SIGNALPROCESSINGMODE_DEFAULT;

    status = AcxStreamBridgeCreate(circuit, &attributes, &bridgeCfg, &bridge);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)