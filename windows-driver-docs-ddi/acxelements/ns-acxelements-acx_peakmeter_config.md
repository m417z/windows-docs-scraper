## Description

The **ACX_PEAKMETER_CONFIG** structure is used to define the ACX peakmeter configuration.

## Members

### `Size`

The length, in bytes, of this structure.

### `Id`

A number that represents the element ID.

### `Name`

A pointer to a GUID that represents the name of the element. It defaults to KSAUDFNAME_PEAKMETER if not present.

### `Flags`

ACX peakmeter configuration flags defined by the [ACX_PEAKMETER_CONFIG_FLAGS enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ne-acxelements-acx_peakmeter_config_flags).

No flag bits are currently defined. Set this member to zero - AcxPeakMeterConfigNoFlags.

### `ChannelsCount`

The number of channels. This is a one based count.

### `Maximum`

The maximum value for the peakmeter. SignedMaximum must be set to LONG_MAX.

### `Minimum`

The minimum value for the peakmeter. SignedMinimum must be set to LONG_MIN.

### `SteppingDelta`

The stepping value for the peakmeter.

### `Callbacks`

The [ACX_PEAKMETER_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_peakmeter_callbacks) that identifies the driver callbacks for ACX audio engine streaming operations.

## Remarks

For example, you have a waveform with negative and positive peaks at -1 and +1 respectively (on a scale that goes from -1 to +1), then a peak meter value of LONG_MAX accurately reports the maximum waveform value for a given time window. Conversely, a peak meter value of zero (0) should be used to report silence, where all the waveform’s values are zero. But in the case of a waveform whose peak values are between zero (0) and LONG_MAX, the reported waveform values would be linearly reduced from the originals.

Therefore, in the case of the waveform that swings between -0.5 and +0.5 (on a scale that goes from -1 to +1), the peak meter value must be set to LONG_MAX/2.

The driver handles this property request synchronously. If the request succeeds, it resets the peakmeter, which initializes the accumulated peak value to zero. If the request does not succeed, the peakmeter is not changed.

See also [KSPROPERTY_AUDIO_PEAKMETER2](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-peakmeter2).

### Example

Example usage is shown below.

```cpp
// Default peak meter settings
#define PEAKMETER_STEPPING_DELTA    0x1000
#define PEAKMETER_MAXIMUM           LONG_MAX
#define PEAKMETER_MINIMUM           LONG_MIN

    ACX_PEAKMETER_CONFIG            peakmeterCfg;

        ACX_PEAKMETER_CALLBACKS peakmeterCallbacks;
        ACX_PEAKMETER_CALLBACKS_INIT(&peakmeterCallbacks);
        peakmeterCallbacks.EvtAcxPeakMeterRetrieveLevel = CodecR_EvtPeakMeterRetrieveLevelCallback;

        ACX_PEAKMETER_CONFIG peakmeterCfg;
        ACX_PEAKMETER_CONFIG_INIT(&peakmeterCfg);
        peakmeterCfg.ChannelsCount = MAX_CHANNELS;
        peakmeterCfg.Minimum = PEAKMETER_MINIMUM;
        peakmeterCfg.Maximum = PEAKMETER_MAXIMUM;
        peakmeterCfg.SteppingDelta = PEAKMETER_STEPPING_DELTA;
        peakmeterCfg.Callbacks = &peakmeterCallbacks;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)