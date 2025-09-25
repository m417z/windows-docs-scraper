## Description

The **AcxMuteChangeStateNotification** function sends a notification of a mute state change on an ACXMUTE object so that acx can generate a corresponding event.

## Parameters

### `Mute`

An ACXMUTE object whose mute state has changed. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Remarks

### Example

Example usage is shown below.

```cpp
    PCODEC_MUTE_TIMER_CONTEXT timerCtx = GetCodecMuteTimerContext(Timer);
    PCODEC_MUTE_ELEMENT_CONTEXT muteCtx = GetCodecMuteElementContext(timerCtx->MuteElement);

    // update settings 0 <-> 1
    for (ULONG i = 0; i < MAX_CHANNELS; ++i)
    {
        muteCtx->MuteState[i] = !muteCtx->MuteState[i];
    }

    AcxMuteChangeStateNotification(timerCtx->MuteElement);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)