# GetNumaNodeNumberFromHandle function

## Description

Retrieves the NUMA node associated with the file or I/O device represented by the specified file handle.

## Parameters

### `hFile` [in]

A handle to a file or I/O device. Examples of I/O devices include files, file streams, volumes, physical disks, and sockets. For more information, see the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `NodeNumber` [out]

A pointer to a variable to receive the number of the NUMA node associated with the specified file handle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, use [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the specified handle does not have a node associated with it, the function returns FALSE. The value of the *NodeNumber* parameter is undetermined and should not be used.

To compile an application that uses this function, set _WIN32_WINNT >= 0x0601. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[NUMA Support](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support)