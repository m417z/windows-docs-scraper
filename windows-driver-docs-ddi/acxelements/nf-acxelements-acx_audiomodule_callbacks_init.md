## Description

The **ACX_AUDIOMODULE_CALLBACKS_INIT** function initializes the [ACX_AUDIOMODULE_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_audiomodule_callbacks) structure.

## Parameters

### `Callbacks`

An [ACX_AUDIOMODULE_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_audiomodule_callbacks) structure.

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_AUDIOMODULE_CALLBACKS       audioModuleCallbacks;
    ACX_AUDIOMODULE_CALLBACKS_INIT(&audioModuleCallbacks);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)