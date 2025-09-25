## Description

The **EVT_ACX_AUDIOENGINE_RETRIEVE_BUFFER_SIZE_LIMITS** callback is implemented by the driver and is called when the buffer size limits for a given data format are requested for the specified audio engine.

## Parameters

### `AudioEngine`

The ACXAUDIOENGINE object for which the buffer size limits have been requested. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Format`

The ACXDATAFORMAT for which the callback is determining the min and max buffer sizes the audio engine can accommodate it with.

### `MinBufferSizeInBytes`

The minimum size of buffer that the hardware audio engine can support for the given data format, at the instance when it is called. The buffer size is specified in bytes.

### `MaxBufferSizeInBytes`

The maximum size of buffer that the hardware audio engine can support for the given data format, at the instance when it is called. The buffer size is specified in bytes.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
EVT_ACX_AUDIOENGINE_RETRIEVE_BUFFER_SIZE_LIMITS CodecR_EvtAcxAudioEngineRetrieveBufferSizeLimits;

NTSTATUS
CodecR_EvtAcxAudioEngineRetrieveBufferSizeLimits(
    _In_    ACXAUDIOENGINE  AudioEngine,
    _In_    ACXDATAFORMAT   DataFormat,
    _Out_   PULONG          MinBufferBytes,
    _Out_   PULONG          MaxBufferBytes
    )
{
    PAGED_CODE();

    ULONG bytesPerSecond = AcxDataFormatGetAverageBytesPerSec(DataFormat);

    *MinBufferBytes = (ULONG) (MIN_AUDIOENGINE_BUFFER_DURATION_IN_MS * bytesPerSecond / 1000);
    *MaxBufferBytes = (ULONG) (MAX_AUDIOENGINE_BUFFER_DURATION_IN_MS * bytesPerSecond / 1000);

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)