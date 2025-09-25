# FILE_IO_PRIORITY_HINT_INFO structure

## Description

Specifies the priority hint for a file I/O operation.

## Members

### `PriorityHint`

The priority hint. This member is a value from the
[PRIORITY_HINT](https://learn.microsoft.com/windows/desktop/api/winbase/ne-winbase-priority_hint) enumeration.

## Remarks

The [SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle) function
can be used with this structure to associate a priority hint with I/O operations on a file-handle basis. In
addition to the idle priority (very low), this function allows normal priority and low priority. Whether these
priorities are supported and honored by the underlying drivers depends on their implementation (which is why they
are called hints). For more information, see the
[I/O Prioritization in Windows Vista](https://www.microsoft.com/whdc/driver/priorityio.mspx)
white paper on the Windows Hardware Developer Central (WHDC) website.

This structure must be aligned on a **LONGLONG** (8-byte) boundary.

## See also

[PRIORITY_HINT](https://learn.microsoft.com/windows/desktop/api/winbase/ne-winbase-priority_hint)

[SetFileInformationByHandle](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-setfileinformationbyhandle)