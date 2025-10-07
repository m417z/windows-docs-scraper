# EnumJobs function

The **EnumJobs** function retrieves information about a specified set of print jobs for a specified printer.

## Parameters

*hPrinter* \[in\]

A handle to the printer object whose print jobs the function enumerates. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*FirstJob* \[in\]

The zero-based position within the print queue of the first print job to enumerate. For example, a value of 0 specifies that enumeration should begin at the first print job in the print queue; a value of 9 specifies that enumeration should begin at the tenth print job in the print queue.

*NoJobs* \[in\]

The total number of print jobs to enumerate.

*Level* \[in\]

The type of information returned in the *pJob* buffer.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------|
|

**1**

| *pJob* receives an array of [**JOB\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/job-info-1) structures<br> |
|

**2**

| *pJob* receives an array of [**JOB\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/job-info-2) structures<br> |
|

**3**

| *pJob* receives an array of [**JOB\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/job-info-3) structures<br> |

*pJob* \[out\]

A pointer to a buffer that receives an array of [**JOB\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/job-info-1), [**JOB\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/job-info-2), or [**JOB\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/job-info-3) structures. The buffer must be large enough to receive the array of structures and any strings or other data to which the structure members point.

To determine the required buffer size, call **EnumJobs** with *cbBuf* set to zero. **EnumJobs** fails, [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR\_INSUFFICIENT\_BUFFER, and the *pcbNeeded* parameter returns the size, in bytes, of the buffer required to hold the array of structures and their data.

*cbBuf* \[in\]

The size, in bytes, of the *pJob* buffer.

*pcbNeeded* \[out\]

A pointer to a variable that receives the number of bytes copied if the function succeeds. If the function fails, the variable receives the number of bytes required.

*pcReturned* \[out\]

A pointer to a variable that receives the number of [**JOB\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/job-info-1), [**JOB\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/job-info-2), or [**JOB\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/job-info-3) structures returned in the *pJob* buffer.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The [**JOB\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/job-info-1) structure contains general print-job information; the [**JOB\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/job-info-2) structure has much more detailed information. The [**JOB\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/job-info-3) structure contains information about how jobs are linked.

To determine the number of print jobs in the printer queue, call the [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter) function with the *Level* parameter set to 2.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **EnumJobsW** (Unicode) and **EnumJobsA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**GetJob**](https://learn.microsoft.com/windows/win32/printdocs/getjob)

[**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter)

[**JOB\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/job-info-1)

[**JOB\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/job-info-2)

[**JOB\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/job-info-3)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**SetJob**](https://learn.microsoft.com/windows/win32/printdocs/setjob)

