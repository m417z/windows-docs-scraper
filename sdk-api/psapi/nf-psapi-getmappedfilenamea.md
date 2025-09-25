# GetMappedFileNameA function

## Description

Checks whether the specified address is within a memory-mapped file in the address space of the specified process. If so, the function returns the name of the memory-mapped file.

## Parameters

### `hProcess` [in]

A handle to the process. The handle must have the **PROCESS_QUERY_INFORMATION** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `lpv` [in]

The address to be verified.

### `lpFilename` [out]

A pointer to the buffer that receives the name of the memory-mapped file to which the address specified by *lpv* belongs.

### `nSize` [in]

The size of the *lpFilename* buffer, in characters.

## Return value

If the function succeeds, the return value specifies the length of the string copied to the buffer, in characters.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Starting with Windows 7 and Windows Server 2008 R2, Psapi.h establishes
version numbers for the PSAPI functions. The PSAPI version number affects the name used to call the function and
the library that a program must load.

If **PSAPI_VERSION** is 2 or greater, this function is defined as
**K32GetMappedFileName** in Psapi.h and exported in
Kernel32.lib and Kernel32.dll. If **PSAPI_VERSION** is 1, this
function is defined as **GetMappedFileName** in
Psapi.h and exported in Psapi.lib and Psapi.dll as a wrapper that calls
**K32GetMappedFileName**.

Programs that must run on earlier versions of Windows as
well as Windows 7 and later versions should always call this function as
**GetMappedFileName**. To ensure correct resolution of symbols,
add Psapi.lib to the **TARGETLIBS** macro and compile the program with
**-DPSAPI_VERSION=1**. To use run-time dynamic linking, load Psapi.dll.

In Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

#### Examples

For an example, see
[Obtaining a File Name From a File Handle](https://learn.microsoft.com/windows/desktop/Memory/obtaining-a-file-name-from-a-file-handle).

> [!NOTE]
> The psapi.h header defines GetMappedFileName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumProcesses](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-enumprocesses)

[Memory-Mapped File Information](https://learn.microsoft.com/windows/desktop/psapi/memory-mapped-file-information)

[PSAPI Functions](https://learn.microsoft.com/windows/desktop/psapi/psapi-functions)