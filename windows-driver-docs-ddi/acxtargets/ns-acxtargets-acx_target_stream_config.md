## Description

The **ACX_TARGET_STREAM_CONFIG** structure is used to define the target stream configuration.

## Members

### `Size`

The length, in bytes, of this structure.

### `Flags`

Target stream configuration flags defined by the [ACX_TARGET_STREAM_CONFIG_FLAGS enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/ne-acxtargets-acx_target_stream_config_flags).

No flag bits are currently defined. Set this member to zero - AcxTargetStreamConfigNoFlags

### `TargetCircuit`

An ACXTARGETCIRCUIT object representing the target circuit.

### `PinId`

The remote pin ID number of the remote target.

### `DataFormat`

An ACXDATAFORMAT ACX object that defines the target stream data format.

### `SignalProcessingMode`

A GUID identifying the audio signal processing mode of the new stream circuit.For more information about
audio modes, see [Audio Signal Processing Modes](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-signal-processing-modes).

### `OptionalParameters`

An optional ACXOBJECTBAG ACX object describing optional parameters.

## Remarks

### Example

```cpp
    ACX_TARGET_STREAM_CONFIG targetStreamCfg;

    ACX_TARGET_STREAM_CONFIG_INIT(&targetStreamCfg);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)