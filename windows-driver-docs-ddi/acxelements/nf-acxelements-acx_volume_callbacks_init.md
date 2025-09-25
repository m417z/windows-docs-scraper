## Description

The **ACX_VOLUME_CALLBACKS_INIT** function initializes a [ACX_VOLUME_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_volume_callbacks).

## Parameters

### `Callbacks`

A pointer to an initialized [ACX_VOLUME_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_volume_callbacks).

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_VOLUME_CALLBACKS            volumeCallbacks;
    ACX_VOLUME_CALLBACKS_INIT(&volumeCallbacks);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)