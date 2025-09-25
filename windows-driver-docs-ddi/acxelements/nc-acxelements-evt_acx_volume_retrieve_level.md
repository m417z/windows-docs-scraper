## Description

The **EVT_ACX_VOLUME_RETRIEVE_LEVEL** callback function is implemented by the driver and is called when the volume level of a specified channel on a volume node is requested.

## Parameters

### `Volume`

An existing, initialized, ACXVOLUME object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Channel`

A ULONG referring to a channel on the specified volume node. If this value is -1, then it refers to the master channel which sets the level for all channels on the volume node.

### `VolumeLevel`

A LONG value that specifies the volume level of a channel in a given stream. Volumelevel values use the following scale:

-2147483648 is -infinity decibels (attenuation),

-2147483647 is -32767.99998474 decibels (attenuation), and

+2147483647 is +32767.99998474 decibels (gain).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
typedef struct _CODEC_VOLUME_ELEMENT_CONTEXT {
    LONG            VolumeLevel[MAX_CHANNELS];
} CODEC_VOLUME_ELEMENT_CONTEXT, *PCODEC_VOLUME_ELEMENT_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(CODEC_VOLUME_ELEMENT_CONTEXT, GetCodecVolumeElementContext)

EVT_ACX_VOLUME_RETRIEVE_LEVEL       CodecR_EvtVolumeRetrieveLevel;

NTSTATUS
NTAPI
CodecR_EvtVolumeRetrieveLevel(
    _In_  ACXVOLUME Volume,
    _In_  ULONG     Channel,
    _Out_ LONG *    VolumeLevel
)
{
    PCODEC_VOLUME_ELEMENT_CONTEXT   volumeCtx;

    PAGED_CODE();

    volumeCtx = GetCodecVolumeElementContext(Volume);
    ASSERT(volumeCtx);

    if (Channel != ALL_CHANNELS_ID)
    {
        *VolumeLevel = volumeCtx->VolumeLevel[Channel];
    }
    else
    {
        *VolumeLevel = volumeCtx->VolumeLevel[0];
    }

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)