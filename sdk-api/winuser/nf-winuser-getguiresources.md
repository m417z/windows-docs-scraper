## Description

Retrieves the count of handles to graphical user interface (GUI) objects in use by the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. The handle must refer to a process in the current session, and must have the **PROCESS_QUERY_LIMITED_INFORMATION** access right (see [Process security and access rights](https://learn.microsoft.com/windows/win32/procthread/process-security-and-access-rights)).

If this parameter is the special value **GR_GLOBAL**, then the resource usage is reported across all processes in the current session.

**Windows Server 2008, Windows Vista, Windows Server 2003, and Windows XP:** The **GR_GLOBAL** value is not supported until Windows 7 and Windows Server 2008 R2.

**Windows Server 2003 and Windows XP:** The handle must have the **PROCESS_QUERY_INFORMATION** access right.

### `uiFlags` [in]

The GUI object type. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GR_GDIOBJECTS**<br><br>0 | Return the count of GDI objects. |
| **GR_GDIOBJECTS_PEAK**<br><br>2 | Return the peak count of GDI objects.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows 7 and Windows Server 2008 R2. |
| **GR_USEROBJECTS**<br><br>1 | Return the count of USER objects. |
| **GR_USEROBJECTS_PEAK**<br><br>4 | Return the peak count of USER objects.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows 7 and Windows Server 2008 R2. |

## Return value

If the function succeeds, the return value is the count of handles to GUI objects in use by the process. If no GUI objects are in use, the return value is zero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A process without a graphical user interface does not use GUI resources, therefore,
**GetGuiResources** will return zero.

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess)

[OpenProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocess)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)