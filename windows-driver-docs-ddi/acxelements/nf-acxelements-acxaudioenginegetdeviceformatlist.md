## Description

The **AcxAudioEngineGetDeviceFormatList** function retrieves the ACXDATAFORMATLIST object that holds the list of supported formats for the audio engine node. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `AudioEngine`

An ACXAUDIOENGINE object that is used in a render circuit, to represent a DSP.

## Return value

The ACXDATAFORMATLIST object which holds the list of supported formats for the specified ACXAUDIOENGINE object.

## Remarks

### Example

Example usage is shown below.

```cpp
    status = AcxDataFormatCreate(Device, &attributes, &formatCfg, &formatPcm44100c2);
    formatCtx = GetCodecFormatContext(formatPcm44100c2);

    // Get the current audio engine device format list
    formatList = AcxAudioEngineGetDeviceFormatList(audioEngineElement);
    if (formatList == NULL)
    {
        status = STATUS_INSUFFICIENT_RESOURCES;
        goto exit;
    }

    // Add our supported formats to the audio engine device format list
    status = AcxDataFormatListAddDataFormat(formatList, formatPcm44100c2);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)