## Description

The **AcxCircuitResumeIoActual** function is used to resume circuit I/O after it has been stopped.

## Parameters

### `Circuit`

An existing ACXCIRCUIT circuit object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ObjectTag`

An optional ObjectTag that is a driver-defined value that the framework stores as an identification tag for the ACX driver.

### `Line`

The Line number in the driver code that can be displayed for diagnostic purposes.

### `File`

The file name in the driver code that can be displayed for diagnostic purposes.

## Remarks

It is not recommended to use this version of the stop IO call, but rather [AcxCircuitResumeIoWithTag macro](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitresumeiowithtag) as it provides additional diagnostic information by using a Tag.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)