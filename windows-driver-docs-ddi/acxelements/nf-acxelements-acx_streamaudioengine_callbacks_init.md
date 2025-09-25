## Description

The **ACX_STREAMAUDIOENGINE_CALLBACKS_INIT** function initializes a [ACX_STREAMAUDIOENGINE_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_streamaudioengine_callbacks).

## Parameters

### `Callbacks`

A pointer to an initialized [ACX_STREAMAUDIOENGINE_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_streamaudioengine_callbacks).

## Remarks

### Example

Example usage is shown below.

```cpp
        ACX_STREAMAUDIOENGINE_CALLBACKS streamAudioEngineCallbacks;
        ACX_STREAMAUDIOENGINE_CALLBACKS_INIT(&streamAudioEngineCallbacks);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)