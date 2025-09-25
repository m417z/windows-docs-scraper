## Description

The **ACX_MUTE_CALLBACKS_INIT** function initializes a [ACX_MUTE_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_mute_callbacks).

## Parameters

### `Callbacks`

A pointer to an initialized [ACX_MUTE_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_mute_callbacks).

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_MUTE_CALLBACKS              muteCallbacks;

    ACX_MUTE_CALLBACKS_INIT(&muteCallbacks);

    muteCallbacks.EvtAcxMuteAssignState = CodecR_EvtMuteAssignState;
    muteCallbacks.EvtAcxMuteRetrieveState = CodecR_EvtMuteRetrieveState;
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)