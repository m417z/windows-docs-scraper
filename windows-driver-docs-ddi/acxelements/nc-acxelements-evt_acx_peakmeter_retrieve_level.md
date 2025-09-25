## Description

The **EVT_ACX_PEAKMETER_RETRIEVE_LEVEL** callback function is implemented by the driver and is called when the level of a specified channel on a peakmeter node is requested.

## Parameters

### `PeakMeter`

An existing, initialized, ACXPEAKMETER object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Channel`

A ULONG referring to a channel on the specified peakmeter node. If this value is -1, then it refers to the master channel which sets the level for all channels on the peakmeter node.

### `Level`

A LONG value that indicates the maximum audio signal level that occurred for the specified channel on the peakmeter node since the last time the peakmeter node was reset.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
typedef struct _CODEC_PEAKMETER_ELEMENT_CONTEXT {
    LONG            PeakMeterLevel[MAX_CHANNELS];
} CODEC_PEAKMETER_ELEMENT_CONTEXT, *PCODEC_PEAKMETER_ELEMENT_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(CODEC_PEAKMETER_ELEMENT_CONTEXT, GetCodecPeakMeterElementContext)

EVT_ACX_PEAKMETER_RETRIEVE_LEVEL    CodecR_EvtPeakMeterRetrieveLevelCallback;

NTSTATUS
NTAPI
CodecR_EvtPeakMeterRetrieveLevelCallback(
    _In_    ACXPEAKMETER    PeakMeter,
    _In_    ULONG           Channel,
    _Out_   LONG *          PeakMeterLevel
    )
{
    PAGED_CODE();

    ASSERT(PeakMeter);
    PCODEC_PEAKMETER_ELEMENT_CONTEXT peakmeterCtx = GetCodecPeakMeterElementContext(PeakMeter);
    ASSERT(peakmeterCtx);

    if (Channel == ALL_CHANNELS_ID)
    {
        Channel = 0;
    }

    *PeakMeterLevel = peakmeterCtx->PeakMeterLevel[Channel];

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)