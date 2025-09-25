## Description

The **EVT_ACX_AUDIOENGINE_ASSIGN_ENGINE_FORMAT** callback function is implemented by the driver and is called when the internal mix format is set for an audio engine node.

## Parameters

### `AudioEngine`

An ACXAUDIOENGINE object that is used in a render circuit to represent a DSP. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Format`

An ACXDATAFORMAT object that describes the mix format for the specified audio engine.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
EVT_ACX_AUDIOENGINE_ASSIGN_ENGINE_FORMAT        DspR_EvtAcxAudioEngineAssignEngineDeviceFormat;

NTSTATUS
DspR_EvtAcxAudioEngineAssignEngineDeviceFormat(
    ACXAUDIOENGINE,
    ULONG
)
{
    PAGED_CODE();

    // Custom Code goes here

    return STATUS_SUCCESS;
}

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)