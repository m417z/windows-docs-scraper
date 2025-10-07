# JOB\_INFO\_4 structure

Describes a full set of values associated with a job and supports large spool files with sizes expressed with 64 bits.

## Members

**JobId**

A job identifier value.

**pPrinterName**

A pointer to a null-terminated string that specifies the name of the printer for which the job is spooled.

**pMachineName**

A pointer to a null-terminated string that specifies the name of the machine that created the print job.

**pUserName**

A pointer to a null-terminated string that specifies the name of the user who owns the print job.

**pDocument**

A pointer to a null-terminated string that specifies the name of the print job (for example, "MS-WORD: Review.doc").

**pNotifyName**

A pointer to a null-terminated string that specifies the name of the user who should be notified when the job has been printed, or when an error occurs while printing the job.

**pDatatype**

A pointer to a null-terminated string that specifies the type of data used to record the print job.

**pPrintProcessor**

A pointer to a null-terminated string that specifies the name of the print processor that should be used to print the job.

**pParameters**

A pointer to a null-terminated string that specifies print-processor parameters.

**pDriverName**

A pointer to a null-terminated string that specifies the name of the printer driver that should be used to process the print job.

**pDevMode**

A pointer to a [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure that contains device-initialization and environment data for the printer driver.

**pStatus**

A pointer to a null-terminated string that specifies the status of the print job. This member should be checked prior to **Status** and, if **pStatus** is **NULL**, the status is defined by the contents of the Status member.

**pSecurityDescriptor**

The value of this member is **NULL**. Retrieval and setting of document security descriptors is not supported in this release.

**Status**

The job status. This member can be one or more of the following values:

| Value | Meaning |
|---------------------------------|--------------------------------------------------------------|
| JOB\_STATUS\_BLOCKED\_DEVQ | The driver cannot print the job. |
| JOB\_STATUS\_DELETED | Job has been deleted. |
| JOB\_STATUS\_DELETING | Job is being deleted. |
| JOB\_STATUS\_ERROR | An error is associated with the job. |
| JOB\_STATUS\_OFFLINE | Printer is offline. |
| JOB\_STATUS\_PAPEROUT | Printer is out of paper. |
| JOB\_STATUS\_PAUSED | Job is paused. |
| JOB\_STATUS\_PRINTED | Job has printed. |
| JOB\_STATUS\_PRINTING | Job is printing. |
| JOB\_STATUS\_RESTART | Job has been restarted. |
| JOB\_STATUS\_SPOOLING | Job is spooling. |
| JOB\_STATUS\_USER\_INTERVENTION | Printer has an error that requires the user to do something. |

In Windows XP and later versions of Windows, the following values can also be used:

| Value | Meaning |
|-----------------------|-----------------------------------------------------------------------------------------------|
| JOB\_STATUS\_COMPLETE | The job is sent to the printer, but may not be printed yet. See Remarks for more information. |
| JOB\_STATUS\_RETAINED | The job has been retained in the print queue following printing. |

**Priority**

The job priority. This member can be one of the following values, or in the range between 1 through 99 (MIN\_PRIORITY through MAX\_PRIORITY).

| Value | Meaning |
|---------------|-------------------|
| MIN\_PRIORITY | Minimum priority. |
| MAX\_PRIORITY | Maximum priority. |
| DEF\_PRIORITY | Default priority. |

**Position**

The job's position in the print queue.

**StartTime**

The earliest time that the job can be printed.

**UntilTime**

The latest time that the job can be printed.

**TotalPages**

The number of pages required for the job. This value may be zero if the print job does not contain page delimiting information.

**Size**

The lower four bytes of the size, in bytes, of the job. See also the **SizeHigh** member below.

**Submitted**

A [**SYSTEMTIME**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that specifies the time when the job was submitted.

This time value is in Universal Time Coordinate (UTC) format. You should convert it to a local time value before displaying it. You can use the [**FileTimeToLocalFileTime**](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-filetimetolocalfiletime) function to perform the conversion.

**Time**

The total time, in milliseconds, that has elapsed since the job began printing.

**PagesPrinted**

The number of pages that have printed. This value may be zero if the print job does not contain page delimiting information.

**SizeHigh**

The higher four bytes of the size, in bytes, of the job. See also the **Size** member above.

## Remarks

Port monitors that do not support TrueEndOfJob will set the job as JOB\_STATUS\_PRINTED immediately after the job is submitted to the printer.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h |
| Unicode and ANSI names<br> | **\_JOB\_INFO\_4W** (Unicode) and **\_JOB\_INFO\_4A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[**EnumJobs**](https://learn.microsoft.com/windows/win32/printdocs/enumjobs)

[**GetJob**](https://learn.microsoft.com/windows/win32/printdocs/getjob)

[**SetJob**](https://learn.microsoft.com/windows/win32/printdocs/setjob)

