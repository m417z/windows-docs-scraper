# JOB\_INFO\_1 structure

The **JOB\_INFO\_1** structure specifies print-job information such as the job-identifier value, the name of the printer for which the job is spooled, the name of the machine that created the print job, the name of the user that owns the print job, and so on.

## Members

**JobId**

A job identifier.

**pPrinterName**

A pointer to a null-terminated string that specifies the name of the printer for which the job is spooled.

**pMachineName**

A pointer to a null-terminated string that specifies the name of the machine that created the print job.

**pUserName**

A pointer to a null-terminated string that specifies the name of the user that owns the print job.

**pDocument**

A pointer to a null-terminated string that specifies the name of the print job (for example, "MS-WORD: Review.doc").

**pDatatype**

A pointer to a null-terminated string that specifies the type of data used to record the print job.

**pStatus**

A pointer to a null-terminated string that specifies the status of the print job. This member should be checked prior to *Status* and, if *pStatus* is **NULL**, the status is defined by the contents of the Status member.

**Status**

The job status. The value of this member can be zero or a combination of one or more of the following values. A value of zero indicates that the print queue was paused after the document finished spooling.

| Value | Meaning |
|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| JOB\_STATUS\_BLOCKED\_DEVQ | The driver cannot print the job. |
| JOB\_STATUS\_COMPLETE | **Windows XP and later:** Job is sent to the printer, but the job may not be printed yet.<br> See Remarks for more information.<br> |
| JOB\_STATUS\_DELETED | Job has been deleted. |
| JOB\_STATUS\_DELETING | Job is being deleted. |
| JOB\_STATUS\_ERROR | An error is associated with the job. |
| JOB\_STATUS\_OFFLINE | Printer is offline. |
| JOB\_STATUS\_PAPEROUT | Printer is out of paper. |
| JOB\_STATUS\_PAUSED | Job is paused. |
| JOB\_STATUS\_PRINTED | Job has printed. |
| JOB\_STATUS\_PRINTING | Job is printing. |
| JOB\_STATUS\_RESTART | Job has been restarted. |
| JOB\_STATUS\_RETAINED | **Windows Vista and later:** Job has been retained in the print queue and cannot be deleted. This can be caused by the following:<br> 1) The job was manually retained by a call to SetJob and the spooler is waiting for the job to be released.<br> 2) The job has not finished printing and must finish printing before it can be automatically deleted.<br> See [**SetJob**](https://learn.microsoft.com/windows/win32/printdocs/setjob) for more information about print job commands.<br> |
| JOB\_STATUS\_SPOOLING | Job is spooling. |
| JOB\_STATUS\_USER\_INTERVENTION | Printer has an error that requires the user to do something. |

**Priority**

The job priority. This member can be one of the following values or in the range between 1 through 99 (MIN\_PRIORITY through MAX\_PRIORITY).

| Value | Meaning |
|---------------|-------------------|
| MIN\_PRIORITY | Minimum priority. |
| MAX\_PRIORITY | Maximum priority. |
| DEF\_PRIORITY | Default priority. |

**Position**

The job's position in the print queue.

**TotalPages**

The total number of pages that the document contains. This value may be zero if the print job does not contain page delimiting information.

**PagesPrinted**

The number of pages that have printed. This value may be zero if the print job does not contain page delimiting information.

**Submitted**

A [**SYSTEMTIME**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that specifies the time that this document was spooled.

This time value is in Universal Time Coordinate (UTC) format. You should convert it to a local time value before displaying it. You can use the [**FileTimeToLocalFileTime**](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-filetimetolocalfiletime) function to perform the conversion.

## Remarks

Port monitors that do not support TrueEndOfJob will set the job as JOB\_STATUS\_PRINTED right after the job is submitted to the printer.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_JOB\_INFO\_1W** (Unicode) and **\_JOB\_INFO\_1A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**EnumJobs**](https://learn.microsoft.com/windows/win32/printdocs/enumjobs)

[**GetJob**](https://learn.microsoft.com/windows/win32/printdocs/getjob)

[**SetJob**](https://learn.microsoft.com/windows/win32/printdocs/setjob)

