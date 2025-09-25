## Description

The **ACX_STREAM_BRIDGE_TYPE** enumeration describes the Acx Stream Bridge Type.

## Constants

### `AcxStreamBridgeInvalidType`

The Acx Stream Bridge is an InvalidType.

### `AcxStreamBridgeMux`

The Acx Stream Bridge is an Mux. This bridge type accepts multiple input streams and allows only one output stream.

### `AcxStreamBridgeMaximumType`

The AcxStreamBridgeMaximumType is used internally for validation. Do not use.

### `AcxStreamBridgeDefaultType`

The default type is associated with one of the valid types for this field. This is the type used if the driver does not override this value.

## Remarks

AcxStreamBridge is used by a circuit to propagate stream creation, the stream’s states transitions and DRM settings between the endpoint's circuit stream segments. This object is only used in a multi-circuit (audio composite) scenario.

### Example

Example usage is shown below.

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