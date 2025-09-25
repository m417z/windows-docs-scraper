## Description

The **EVT_ACX_VOLUME_ASSIGN_LEVEL** callback function is implemented by the driver and is called when the volume level of a channel is set for a volume node.

## Parameters

### `Volume`

An existing, initialized, ACXVOLUME object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Channel`

A ULONG referring to a channel on the specified volume node. If this value is -1, then it refers to the master channel which represents the volume level for all channels on the volume node.

### `VolumeLevel`

A LONG value that specifies the volume level of a channel in a volume node. If the channel value is -1 (referring to the master channel), then all channels on this volume node will be set to this volume level. Volume level values use the following scale:

-2147483648 is -infinity decibels (attenuation),

-2147483647 is -32767.99998474 decibels (attenuation), and

+2147483647 is +32767.99998474 decibels (gain).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
typedef struct _VOLUME_ELEMENT_CONTEXT {
    LONG            VolumeLevel[MAX_CHANNELS];
} VOLUME_ELEMENT_CONTEXT, *PVOLUME_ELEMENT_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(VOLUME_ELEMENT_CONTEXT, GetVolumeElementContext)

EVT_ACX_VOLUME_ASSIGN_LEVEL         CodecC_EvtVolumeAssignLevelCallback;

NTSTATUS
CodecC_EvtVolumeAssignLevelCallback(
    _In_    ACXVOLUME   Volume,
    _In_    ULONG       Channel,
    _In_    LONG        VolumeLevel
)
{
    PAGED_CODE();

    ASSERT(Volume);
    PVOLUME_ELEMENT_CONTEXT volumeCtx = GetVolumeElementContext(Volume);
    ASSERT(volumeCtx);

    if (Channel != ALL_CHANNELS_ID)
    {
        volumeCtx->VolumeLevel[Channel] = VolumeLevel;
    }
    else
    {
        for (ULONG i = 0; i < MAX_CHANNELS; ++i)
        {
            volumeCtx->VolumeLevel[i] = VolumeLevel;
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