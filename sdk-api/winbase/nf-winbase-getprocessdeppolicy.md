# GetProcessDEPPolicy function

## Description

Gets the data execution prevention (DEP) and DEP-ATL thunk emulation settings for the specified 32-bit process.**Windows XP with SP3:** Gets the DEP and DEP-ATL thunk emulation settings for the current process.

## Parameters

### `hProcess` [in]

A handle to the process. **PROCESS_QUERY_INFORMATION** privilege is required to get the DEP policy of a process.

**Windows XP with SP3:** The *hProcess* parameter is ignored.

### `lpFlags` [out]

A **DWORD** that receives one or more of the following flags.

| Value | Meaning |
| --- | --- |
| 0 | DEP is disabled for the specified process. |
| **PROCESS_DEP_ENABLE**<br><br>0x00000001 | DEP is enabled for the specified process. |
| **PROCESS_DEP_DISABLE_ATL_THUNK_EMULATION**<br><br>0x00000002 | DEP-ATL thunk emulation is disabled for the specified process. For information about DEP-ATL thunk emulation, see [SetProcessDEPPolicy](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setprocessdeppolicy). |

### `lpPermanent` [out]

**TRUE** if DEP is enabled or disabled permanently for the specified process; otherwise **FALSE**. If *lpPermanent* is **TRUE**, the current DEP setting persists for the life of the process and cannot be changed by calling [SetProcessDEPPolicy](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setprocessdeppolicy).

## Return value

If the function succeeds, it returns **TRUE**.

If the function fails, it returns **FALSE**. To retrieve error values defined for this function, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**GetProcessDEPPolicy** is supported for 32-bit processes only. If this function is called on a 64-bit process, it fails with **ERROR_NOT_SUPPORTED**.

To compile an application that calls this function, define **_WIN32_WINNT** as 0x0600 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Data Execution Prevention](https://learn.microsoft.com/windows/desktop/Memory/data-execution-prevention)

[GetSystemDEPPolicy](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getsystemdeppolicy)

[SetProcessDEPPolicy](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setprocessdeppolicy)