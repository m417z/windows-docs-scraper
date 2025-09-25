## Description

The **ACX_TARGET_STREAM_CONFIG_INIT** function initializes an ACX target stream config structure.

## Parameters

### `Config`

A pointer to the [ACX_TARGET_STREAM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/ns-acxtargets-acx_target_stream_config) structure that will be initialized.

## Remarks

### Example

```cpp
    ACX_TARGET_STREAM_CONFIG targetStreamCfg;

    ACX_TARGET_STREAM_CONFIG_INIT(&targetStreamCfg);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxtargets.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxtargets/)