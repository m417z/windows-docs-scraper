## Description

The **EVT_ACX_MUTE_RETRIEVE_STATE** callback function is implemented by the driver and is called when the state of a specified channel on a mute node is requested.

## Parameters

### `Mute`

An existing, initialized, ACXMUTE object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Channel`

A ULONG referring to a channel on the specified mute node. If this value is -1, then it refers to the master channel which represents the state of all channels on the mute node.

### `State`

A ULONG indicating the state of the specified channel on the mute node (i.e. whether or not the channel is muted). A value of 0 (FALSE) indicates the channel is not muted. A value of 1 (TRUE) indicates that the channel is muted.

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

EVT_ACX_MUTE_RETRIEVE_STATE         CodecR_EvtMuteRetrieveState;

NTAPI
CodecR_EvtMuteRetrieveState(
    _In_  ACXMUTE   Mute,
    _In_  ULONG     Channel,
    _Out_ ULONG *   State
    )
{
    PCODEC_MUTE_ELEMENT_CONTEXT muteCtx;

    PAGED_CODE();

    muteCtx = GetCodecMuteElementContext(Mute);
    ASSERT(muteCtx);

    // use first channel for all channels setting.
    if (Channel != ALL_CHANNELS_ID)
    {
        *State = muteCtx->MuteState[Channel];
    }
    else
    {
        *State = muteCtx->MuteState[0];
    }

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)