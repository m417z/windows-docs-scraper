## Description

The **AcxStreamInitSetAcxRtStreamSupportsNotifications** function is used to indicate that buffer notifications are supported.

## Parameters

### `StreamInit` [in]

Address of a ACXSTREAM_INIT object used to define the stream initialization parameters. For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Remarks

### Example

Example usage is shown below.

```cpp
    //
    // Buffer notifications are supported.
    //
    AcxStreamInitSetAcxRtStreamSupportsNotifications(StreamInit);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)