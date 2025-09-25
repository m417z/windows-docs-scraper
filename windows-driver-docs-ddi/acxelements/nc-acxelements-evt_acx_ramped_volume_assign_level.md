## Description

The **EVT_ACX_RAMPED_VOLUME_ASSIGN_LEVEL** callback is implemented by the driver and is called when the volume level of a channel is set for a volume node.

## Parameters

### `Volume`

An existing, initialized, ACXVOLUME object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Channel`

A ULONG referring to a channel on the specified volume node. If this value is -1, then it refers to the master channel which represents the volume level for all channels on the volume node.

### `VolumeLevel`

A LONG value that specifies the desired final volume level for the given channel. If the channel value is -1 (referring to the master channel), then all channels on this volume node will be set to this volume level. Volume level values use the following scale:

-2147483648 is -infinity decibels (attenuation),

-2147483647 is -32767.99998474 decibels (attenuation), and

+2147483647 is +32767.99998474 decibels (gain).

### `CurveType`

Uses the [AUDIO_CURVE_TYPE enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-audio_curve_type) to specify the curve algorithm to apply over the duration specified, in order to reach the desired level. The curve begins at the current volume level and ends at the target volume level specified in the Volume parameter.

### `CurveDuration`

Specifies the duration, in hundreds of nanoseconds, over which the volume curve must take effect.

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

EVT_ACX_RAMPED_VOLUME_ASSIGN_LEVEL              CodecR_EvtRampedVolumeAssignLevel;

NTSTATUS
NTAPI
CodecR_EvtRampedVolumeAssignLevel(
    _In_ ACXVOLUME              Volume,
    _In_ ULONG                  Channel,
    _In_ LONG                   VolumeLevel,
    _In_ ACX_VOLUME_CURVE_TYPE  CurveType,
    _In_ ULONGLONG              CurveDuration
    )
{
    PCODEC_VOLUME_ELEMENT_CONTEXT   volumeCtx;
    ULONG                           i;

    PAGED_CODE();

    UNREFERENCED_PARAMETER(CurveType);
    UNREFERENCED_PARAMETER(CurveDuration);

    volumeCtx = GetCodecVolumeElementContext(Volume);
    ASSERT(volumeCtx);

    if (Channel != ALL_CHANNELS_ID)
    {
        volumeCtx->VolumeLevel[Channel] = VolumeLevel;
    }
    else
    {
        for (i = 0; i < MAX_CHANNELS; ++i)
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