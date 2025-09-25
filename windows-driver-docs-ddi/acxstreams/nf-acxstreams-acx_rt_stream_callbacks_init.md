## Description

The **ACX_RT_STREAM_CALLBACKS_INIT** function initializes the ACX RT stream callbacks.

## Parameters

### `Callbacks`

An [ACX_RT_STREAM_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_rt_stream_callbacks) structure.

## Remarks

### Example

```cpp
    //
    // Init RT streaming callbacks.
    //
    ACX_RT_STREAM_CALLBACKS rtCallbacks;
    ACX_RT_STREAM_CALLBACKS_INIT(&rtCallbacks);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)