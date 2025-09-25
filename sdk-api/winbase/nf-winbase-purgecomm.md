# PurgeComm function

## Description

Discards all characters from the output or input buffer of a specified communications resource. It can also terminate pending read or write operations on the resource.

## Parameters

### `hFile` [in]

A handle to the communications resource. The
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function returns this handle.

### `dwFlags` [in]

This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **PURGE_RXABORT**<br><br>0x0002 | Terminates all outstanding overlapped read operations and returns immediately, even if the read operations have not been completed. |
| **PURGE_RXCLEAR**<br><br>0x0008 | Clears the input buffer (if the device driver has one). |
| **PURGE_TXABORT**<br><br>0x0001 | Terminates all outstanding overlapped write operations and returns immediately, even if the write operations have not been completed. |
| **PURGE_TXCLEAR**<br><br>0x0004 | Clears the output buffer (if the device driver has one). |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a thread uses
**PurgeComm** to flush an output buffer, the deleted characters are not transmitted. To empty the output buffer while ensuring that the contents are transmitted, call the
[FlushFileBuffers](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-flushfilebuffers) function (a synchronous operation). Note, however, that **FlushFileBuffers** is subject to flow control but not to write time-outs, and it will not return until all pending write operations have been transmitted.

## See also

[Communications Functions](https://learn.microsoft.com/windows/desktop/DevIO/communications-functions)

[Communications Resources](https://learn.microsoft.com/windows/desktop/DevIO/communications-resources)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)