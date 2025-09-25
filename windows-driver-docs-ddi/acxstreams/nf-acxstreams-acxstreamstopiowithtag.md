## Description

The **AcxStreamStopIoWithTag** function is used to signal to the operating system to temporarily stop stream IO. This allows the driver a short period of time to run time sensitive tasks, and then resume IO after the execution of time sensitive code is complete.

## Parameters

### `Stream`

An existing ACXSTREAM Object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Flags`

Set to AcxStopIoNoFlags.

### `Tag`

An optional Tag that is a driver-defined value that the framework includes with diagnostic tracing.

## Remarks

Do not call AcxStreamStopIoWithTag from an I/O dispatched thread. This will cause a deadlock.

### Example

Example usage is shown below.

```cpp

    //
    // Temporarily disable this stream's I/Os. This thread cannot be an I/O dispatched thread else we deadlock.
    //
    status = AcxStreamStopIoWithTag(stream, AcxStopIoNoFlags, (PVOID)this);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)