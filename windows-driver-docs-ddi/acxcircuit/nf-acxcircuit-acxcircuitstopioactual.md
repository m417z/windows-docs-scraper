## Description

The **AcxCircuitStopIoActual** function is used to signal to the operating system to temporarily stop circuit I/O. This allows the driver a short period of time to run time sensitive tasks, and then resume IO after the execution of time sensitive code is complete.

## Parameters

### `Circuit`

An existing ACXCIRCUIT object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Flags`

Stop IO flags defined by the [ACX_STOP_IO_FLAGS enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/ne-acxcircuit-acx_stop_io_flags).
Currently no flags are defined, so set this to `AcxStopIoNoFlags`.

### `ObjectTag`

An optional ObjectTag that is a driver-defined value that the framework stores as an identification tag for the ACX driver.

### `Line`

The Line number in the driver code that can be displayed for diagnostic purposes.

### `File`

The file name in the driver code that can be displayed for diagnostic purposes.

## Return value

## Remarks

Use the [AcxCircuitStopIoWithTag macro](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitstopiowithtag) version of the stop IO call instead of this one.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [AcxCircuitStopIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitstopio)
- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)