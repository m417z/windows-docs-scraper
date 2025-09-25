## Description

The **ACX_MUTE_CONFIG_INIT** function initializes an [ACX_MUTE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_mute_config) structure.

## Parameters

### `cfg`

An [ACX_MUTE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_mute_config) structure.

## Remarks

### Example

Example usage is shown below.

```cpp
        //
        // Create Mute element
        //
        ACX_MUTE_CONFIG muteCfg;
        ACX_MUTE_CONFIG_INIT(&muteCfg);
        muteCfg.ChannelsCount = MAX_CHANNELS;
        muteCfg.Name = &KSAUDFNAME_WAVE_MUTE;
        muteCfg.Callbacks = &muteCallbacks;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)