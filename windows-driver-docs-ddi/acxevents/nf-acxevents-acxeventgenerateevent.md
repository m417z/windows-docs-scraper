## Description

The **AcxEventGenerateEvent** function generates an ACX event.

## Parameters

### `Event`

The ACXEVENT object (described in [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects)).

## Remarks

An ACXEVENT represents an asynchronous notification available at the driver level. Events can be added to ACXCIRCUITs, ACXSTREAMs, ACXELEMENTs and ACXPINs. Internally they are exposed as KS events to upper layers. For more information about KS Events, see [KS Events](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-events).

### Example

This sample shows the use of AcxEventGenerateEvent.

```cpp
    PCODEC_MUTE_TIMER_CONTEXT timerCtx = GetCodecMuteTimerContext(Timer);
    PCODEC_MUTE_ELEMENT_CONTEXT muteCtx = GetCodecMuteElementContext(timerCtx->MuteElement);

    // Testing: update settings 0 <-> 1
    muteCtx->MuteState[0] = !muteCtx->MuteState[0];
    muteCtx->MuteState[1] = !muteCtx->MuteState[1];

    AcxEventGenerateEvent(timerCtx->Event);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxevents.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxevents/)