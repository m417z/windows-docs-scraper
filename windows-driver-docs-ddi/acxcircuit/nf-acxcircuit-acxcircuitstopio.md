## Description

The **AcxCircuitStopIo** function is used to signal to the operating system to temporarily stop circuit I/O. This allows the driver a short period of time to run time sensitive task, and resume IO after the execution of time sensitive code is complete.

## Parameters

### `Circuit`

An existing ACXCIRCUIT circuit object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Flags`

Stop IO flags defined by the [ACX_STOP_IO_FLAGS enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ne-acxcircuit-acx_stop_io_flags).
Currently no flags are defined, so set this to `AcxStopIoNoFlags`.

## Remarks

It is not recommended to use this version of the stop IO call, but rather [AcxCircuitStopIoWithTag macro](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitstopiowithtag) as it provides additional diagnostic information by using a Tag.

### Example

Example usage is shown below.

```cpp
    // Temporarily disable this circuit's I/Os while we are updating the
    // formats. This thread cannot be an I/O dispatched thread else we deadlock.
    //
    status = AcxCircuitStopIo(circuit, AcxStopIoNoFlags);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxCircuitStopIoWithTag macro](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitstopiowithtag)
- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)