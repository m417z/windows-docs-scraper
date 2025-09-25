## Description

The **AcxCircuitResumeIoWithTag** function is used to resume circuit I/O after it has been stopped. It is different from [AcxCircuitResumeIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/nf-acxcircuit-acxcircuitresumeio) in that it can contain additional Tag parameter that is used to display diagnostic information.

## Parameters

### `Circuit`

An existing ACXCIRCUIT object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Tag`

An optional ObjectTag that is a driver-defined value that the framework stores as an identification tag for the ACX driver.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)