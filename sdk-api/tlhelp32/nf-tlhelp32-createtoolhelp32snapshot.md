# CreateToolhelp32Snapshot function

## Description

Takes a snapshot of the specified processes, as well as the heaps, modules, and threads used by these processes.

## Parameters

### `dwFlags` [in]

The portions of the system to be included in the snapshot. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **TH32CS_INHERIT**<br><br>0x80000000 | Indicates that the snapshot handle is to be inheritable. |
| **TH32CS_SNAPALL** | Includes all processes and threads in the system, plus the heaps and modules of the process specified in *th32ProcessID*. Equivalent to specifying the **TH32CS_SNAPHEAPLIST**, **TH32CS_SNAPMODULE**, **TH32CS_SNAPPROCESS**, and **TH32CS_SNAPTHREAD** values combined using an OR operation ('|'). |
| **TH32CS_SNAPHEAPLIST**<br><br>0x00000001 | Includes all heaps of the process specified in *th32ProcessID* in the snapshot. To enumerate the heaps, see [Heap32ListFirst](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32listfirst). |
| **TH32CS_SNAPMODULE**<br><br>0x00000008 | Includes all modules of the process specified in *th32ProcessID* in the snapshot. To enumerate the modules, see [Module32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-module32first). If the function fails with **ERROR_BAD_LENGTH**, retry the function until it succeeds.<br><br>**64-bit Windows:** Using this flag in a 32-bit process includes the 32-bit modules of the process specified in *th32ProcessID*, while using it in a 64-bit process includes the 64-bit modules. To include the 32-bit modules of the process specified in *th32ProcessID* from a 64-bit process, use the **TH32CS_SNAPMODULE32** flag. |
| **TH32CS_SNAPMODULE32**<br><br>0x00000010 | Includes all 32-bit modules of the process specified in *th32ProcessID* in the snapshot when called from a 64-bit process. This flag can be combined with **TH32CS_SNAPMODULE** or **TH32CS_SNAPALL**. If the function fails with **ERROR_BAD_LENGTH**, retry the function until it succeeds. |
| **TH32CS_SNAPPROCESS**<br><br>0x00000002 | Includes all processes in the system in the snapshot. To enumerate the processes, see [Process32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-process32first). |
| **TH32CS_SNAPTHREAD**<br><br>0x00000004 | Includes all threads in the system in the snapshot. To enumerate the threads, see [Thread32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-thread32first).<br><br>To identify the threads that belong to a specific process, compare its process identifier to the **th32OwnerProcessID** member of the [THREADENTRY32](https://learn.microsoft.com/windows/desktop/api/tlhelp32/ns-tlhelp32-threadentry32) structure when enumerating the threads. |

### `th32ProcessID` [in]

The process identifier of the process to be included in the snapshot. This parameter can be zero to indicate the current process. This parameter is used when the **TH32CS_SNAPHEAPLIST**, **TH32CS_SNAPMODULE**, **TH32CS_SNAPMODULE32**, or **TH32CS_SNAPALL** value is specified. Otherwise, it is ignored and all processes are included in the snapshot.

If the specified process is the Idle process or one of the CSRSS processes, this function fails and the last error code is **ERROR_ACCESS_DENIED** because their access restrictions prevent user-level code from opening them.

If the specified process is a 64-bit process and the caller is a 32-bit process, this function fails and the last error code is **ERROR_PARTIAL_COPY** (299).

## Return value

If the function succeeds, it returns an open handle to the specified snapshot.

If the function fails, it returns **INVALID_HANDLE_VALUE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error codes include **ERROR_BAD_LENGTH**.

## Remarks

The snapshot taken by this function is examined by the other tool help functions to provide their results. Access to the snapshot is read only. The snapshot handle acts as an object handle and is subject to the same rules regarding which processes and threads it is valid in.

To enumerate the heap or module states for all processes, specify **TH32CS_SNAPALL** and set *th32ProcessID* to zero. Then, for each additional process in the snapshot, call
**CreateToolhelp32Snapshot** again, specifying its process identifier and the **TH32CS_SNAPHEAPLIST** or **TH32_SNAPMODULE** value.

When taking snapshots that include heaps and modules for a process other than the current process, the **CreateToolhelp32Snapshot** function can fail or return incorrect information for a variety of reasons. For example, if the loader data table in the target process is corrupted or not initialized, or if the module list changes during the function call as a result of DLLs being loaded or unloaded, the function might fail with **ERROR_BAD_LENGTH** or other error code. Ensure that the target process was not started in a suspended state, and try calling the function again. If the function fails with **ERROR_BAD_LENGTH** when called with **TH32CS_SNAPMODULE** or **TH32CS_SNAPMODULE32**, call the function again until it succeeds.

The **TH32CS_SNAPMODULE** and **TH32CS_SNAPMODULE32** flags do not retrieve handles for modules that were loaded with the **LOAD_LIBRARY_AS_DATAFILE** or similar flags. For more information, see [LoadLibraryEx](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa).

To destroy the snapshot, use the
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

Note that you can use the [QueryFullProcessImageName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryfullprocessimagenamea) function to retrieve the full name of an executable image for both 32- and 64-bit processes from a 32-bit process.

#### Examples

For an example, see
[Taking a Snapshot and Viewing Processes](https://learn.microsoft.com/windows/desktop/ToolHelp/taking-a-snapshot-and-viewing-processes).

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[Heap32ListFirst](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-heap32listfirst)

[Module32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-module32first)

[Process32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-process32first)

[Snapshots of the System](https://learn.microsoft.com/windows/desktop/ToolHelp/snapshots-of-the-system)

[Thread32First](https://learn.microsoft.com/windows/desktop/api/tlhelp32/nf-tlhelp32-thread32first)

[Tool Help Functions](https://learn.microsoft.com/windows/desktop/ToolHelp/tool-help-functions)