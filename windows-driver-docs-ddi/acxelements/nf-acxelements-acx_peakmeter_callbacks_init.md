## Description

The **ACX_PEAKMETER_CALLBACKS_INIT** function initializes a [ACX_PEAKMETER_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_peakmeter_callbacks).

## Parameters

### `Callbacks`

A pointer to an initialized [ACX_PEAKMETER_CALLBACKS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ns-acxelements-acx_peakmeter_callbacks).

## Remarks

### Example

Example usage is shown below.

```cpp
    ACX_PEAKMETER_CALLBACKS         peakmeterCallbacks;
    ACX_PEAKMETER_CALLBACKS_INIT(&peakmeterCallbacks);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)