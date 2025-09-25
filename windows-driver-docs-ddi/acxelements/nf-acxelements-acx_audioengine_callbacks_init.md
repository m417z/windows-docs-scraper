## Description

The **ACX_AUDIOENGINE_CALLBACKS_INIT** function initializes a driver's [ACX_AUDIOENGINE_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_audioengine_callbacks) structure.

## Parameters

### `Callbacks`

An [ACX_AUDIOENGINE_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_audioengine_callbacks) structure.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_AUDIOENGINE_CALLBACKS       audioEngineCallbacks;
    ACX_AUDIOENGINE_CALLBACKS_INIT(&audioEngineCallbacks);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)