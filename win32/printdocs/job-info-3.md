# JOB\_INFO\_3 structure

The **JOB\_INFO\_3** structure is used to link together a set of print jobs.

## Members

**JobId**

The print job identifier.

**NextJobId**

The print job identifier for the next print job in the linked set of print jobs.

**Reserved**

This value is reserved for future use. You must set it to zero.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**EnumJobs**](https://learn.microsoft.com/windows/win32/printdocs/enumjobs)

[**GetJob**](https://learn.microsoft.com/windows/win32/printdocs/getjob)

[**SetJob**](https://learn.microsoft.com/windows/win32/printdocs/setjob)

