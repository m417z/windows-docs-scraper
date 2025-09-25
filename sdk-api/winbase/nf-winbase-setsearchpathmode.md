# SetSearchPathMode function

## Description

Sets the per-process mode that the [SearchPath](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-searchpathw)
function uses when locating files.

## Parameters

### `Flags` [in]

The search mode to use.

| Value | Meaning |
| --- | --- |
| **BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE**<br><br>0x00000001 | Enable safe process search mode for the process. |
| **BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE**<br><br>0x00010000 | Disable safe process search mode for the process. |
| **BASE_SEARCH_PATH_PERMANENT**<br><br>0x00008000 | Optional flag to use in combination with **BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE** to make this mode permanent for this process. This is done by bitwise **OR** operation:<br><br>`(BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE | BASE_SEARCH_PATH_PERMANENT)`<br><br>This flag cannot be combined with the **BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE** flag. |

## Return value

If the operation completes successfully, the
**SetSearchPathMode** function returns a nonzero
value.

If the operation fails, the **SetSearchPathMode**
function returns zero. To get extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

If the **SetSearchPathMode** function fails because a
parameter value is not valid, the value returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function will be
**ERROR_INVALID_PARAMETER**.

If the **SetSearchPathMode** function fails because
the combination of current state and parameter value is not valid, the value returned by the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function will be
**ERROR_ACCESS_DENIED**. For more information, see the Remarks section.

## Remarks

If the **SetSearchPathMode** function has not been
successfully called for the current process, the search mode used by the
[SearchPath](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-searchpathw) function is obtained from the system registry. For
more information, see [SearchPath](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-searchpathw).

After the **SetSearchPathMode** function has been
successfully called for the current process, the setting in the system registry is ignored in favor of the mode
most recently set successfully.

If the **SetSearchPathMode** function has been
successfully called for the current process with *Flags* set to
`(BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE | BASE_SEARCH_PATH_PERMANENT)`,
safe mode is set permanently for the calling process. Any subsequent calls to the
**SetSearchPathMode** function from within that process
that attempt to change the search mode will fail with **ERROR_ACCESS_DENIED** from the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

**Note** Because setting safe search mode permanently cannot be disabled for the life of the process for which is was
set, it should be used with careful consideration. This is particularly true for DLL development, where the user
of the DLL will be affected by this process-wide setting.

It is not possible to permanently disable safe search mode.

This function does not modify the system registry.

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

## See also

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[SearchPath](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-searchpathw)