# GetJob function

The **GetJob** function retrieves information about a specified print job.

## Parameters

*hPrinter* \[in\]

A handle to the printer for which the print-job data is retrieved. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*JobId* \[in\]

Identifies the print job for which to retrieve data. Use the [**AddJob**](https://learn.microsoft.com/windows/win32/printdocs/addjob) function or [**StartDoc**](https://learn.microsoft.com/windows/desktop/api/Wingdi/nf-wingdi-startdoca) function to get a print job identifier.

*Level* \[in\]

The type of information returned in the *pJob* buffer. If *Level* is 1, *pJob* receives a [**JOB\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/job-info-1) structure. If *Level* is 2, *pJob* receives a [**JOB\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/job-info-2) structure.

*pJob* \[out\]

A pointer to a buffer that receives a [**JOB\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/job-info-1) or a [**JOB\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/job-info-2) structure containing information about the job. The buffer must be large enough to store the strings pointed to by the structure members.

To determine the required buffer size, call **GetJob** with *cbBuf* set to zero. **GetJob** fails, [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR\_INSUFFICIENT\_BUFFER, and the *pcbNeeded* parameter returns the size, in bytes, of the buffer required to hold the array of structures and their data.

*cbBuf* \[in\]

The size, in bytes, of the array.

*pcbNeeded* \[out\]

A pointer to a value that specifies the number of bytes copied if the function succeeds or the number of bytes required if *cbBuf* is too small.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **GetJobW** (Unicode) and **GetJobA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddJob**](https://learn.microsoft.com/windows/win32/printdocs/addjob)

[**JOB\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/job-info-1)

[**JOB\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/job-info-2)

[**ScheduleJob**](https://learn.microsoft.com/windows/win32/printdocs/schedulejob)

[**SetJob**](https://learn.microsoft.com/windows/win32/printdocs/setjob)

