## Description

This function initializes a new live kernel dump telemetry report, and returns an opaque handle of the report to the caller for use with subsequent LkmdTel functions.

## Parameters

### `ReportType`

This parameter defines the report type string. For example, for xHCI, this value is defined as L”USBXHCI”. For a Silicon partner developing a collection of drivers, only one *ReportType* string should be used.

The maximum report type name length is 16 Unicode characters, including the terminating NULL.

### `BugCheckCode`

This value is the kernel live dump code. For example, SoC subsystem restart would use SOC_SUBSYSTEM_FAILURE_LIVEDUMP (0x15d)

### `BugCheckParam1`

Defined per component, this supplies the first parameter to set in the dump.

### `BugCheckParam2`

Defined per component, this supplies the second parameter to set in the dump.

### `BugCheckParam3`

Defined per component, this supplies the third parameter to set in the dump.

### `BugCheckParam4`

Defined per component, this supplies the fourth parameter to set in the dump.

## Return value

This function returns an opaque handle to the telemetry data which can be used with the [LkmdTelSubmitReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelsubmitreport), [LkmdTelSetSecondaryData](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelsetsecondarydata), and [LkmdTelInsertTriageDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelinserttriagedatablock) functions. This handle is closed using [LkmdTelCloseHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelclosehandle).

In the case of failure, the handle returns *NULL*.

## Remarks

- This function must be called first, since it allocates the data structure used to store the telemetry data. It returns the telemetry handle.
- The Telemery Report handle is closed using [LkmdTelCloseHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelclosehandle).

## See also

- [LkmdTelSubmitReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelsubmitreport)
- [LkmdTelSetSecondaryData](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelsetsecondarydata)
- [LkmdTelInsertTriageDataBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelinserttriagedatablock)
- [LkmdTelCloseHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/lkmdtel/nf-lkmdtel-lkmdtelclosehandle)