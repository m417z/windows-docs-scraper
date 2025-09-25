## Description

The **AcxVolumeChangeLevelNotification** function sends a notification of a volume level change on an ACXVOLUME object so that ACX can generate a corresponding event.

## Parameters

### `Volume`

An ACXVOLUME object whose volume level has changed. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Remarks

### Example

Example usage is shown below.

```cpp
    PCODEC_VOLUME_TIMER_CONTEXT timerCtx = GetCodecVolumeTimerContext(Timer);
    PCODEC_VOLUME_ELEMENT_CONTEXT volumeCtx = GetCodecVolumeElementContext(timerCtx->VolumeElement);

    // Toggle volume between max and min
    for (ULONG i = 0; i < MAX_CHANNELS; ++i)
    {
        volumeCtx->VolumeLevel[i] = volumeCtx->VolumeLevel[i] == VOLUME_LEVEL_MAXIMUM ? VOLUME_LEVEL_MINIMUM : VOLUME_LEVEL_MAXIMUM;
    }

    AcxVolumeChangeLevelNotification(timerCtx->VolumeElement);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)