## Description

The **EVT_ACX_MUTE_ASSIGN_STATE** callback function is implemented by the driver and is called when the state of a specified channel on a mute node is set. The state of the channel can be set to 0 (FALSE) or 1 (TRUE), where 0 indicates the channel is not muted and 1 indicates the channel is muted.

## Parameters

### `Mute`

An existing, initialized, ACXMUTE object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Channel`

A ULONG referring to a channel on the specified mute node. If this value is -1, then it refers to the master channel which represents the state for all channels on the mute node.

### `State`

A ULONG indicating the state of the specified channel on the mute node (i.e. whether or not the channel is muted). A value of 0 (FALSE) indicates the channel is not muted. A value of 1 (TRUE) indicates that the channel is muted. If the channel value is -1 (referring to the master channel), then all channels on this mute node will be set to this state.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
typedef struct _CODEC_MUTE_ELEMENT_CONTEXT {
    BOOL            MuteState[MAX_CHANNELS];
} CODEC_MUTE_ELEMENT_CONTEXT, *PCODEC_MUTE_ELEMENT_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(CODEC_MUTE_ELEMENT_CONTEXT, GetCodecMuteElementContext)

EVT_ACX_MUTE_ASSIGN_STATE           CodecR_EvtMuteAssignState;

NTSTATUS
NTAPI
CodecR_EvtMuteAssignState(
    _In_ ACXMUTE    Mute,
    _In_ ULONG      Channel,
    _In_ ULONG      State
    )
{
    PCODEC_MUTE_ELEMENT_CONTEXT muteCtx;
    ULONG                       i;

    PAGED_CODE();

    muteCtx = GetCodecMuteElementContext(Mute);
    ASSERT(muteCtx);

    // use first channel for all channels setting.
    if (Channel != ALL_CHANNELS_ID)
    {
        muteCtx->MuteState[Channel] = State;
    }
    else
    {
        for (i = 0; i < MAX_CHANNELS; ++i)
        {
            muteCtx->MuteState[i] = State;
        }
    }

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)