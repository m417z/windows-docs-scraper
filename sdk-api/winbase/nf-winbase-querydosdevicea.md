# QueryDosDeviceA function

## Description

Retrieves information about MS-DOS device names. The function can obtain the current
mapping for a particular MS-DOS device name. The function can also obtain a list of all existing MS-DOS device
names.

MS-DOS device names are stored as junctions in the object namespace. The code that converts an MS-DOS path into
a corresponding path uses these junctions to map MS-DOS devices and drive letters. The
**QueryDosDevice** function enables an application to query
the names of the junctions used to implement the MS-DOS device namespace as well as the value of each specific
junction.

## Parameters

### `lpDeviceName` [in, optional]

An MS-DOS device name string specifying the target of the query. The device name cannot have a trailing
backslash; for example, use "C:", not "C:\\".

This parameter can be **NULL**. In that case, the
**QueryDosDevice** function will store a list of all
existing MS-DOS device names into the buffer pointed to by *lpTargetPath*.

### `lpTargetPath` [out]

A pointer to a buffer that will receive the result of the query. The function fills this buffer with one or
more null-terminated strings. The final null-terminated string is followed by an additional
**NULL**.

If *lpDeviceName* is non-**NULL**, the function retrieves
information about the particular MS-DOS device specified by *lpDeviceName*. The first
null-terminated string stored into the buffer is the current mapping for the device. The other null-terminated
strings represent undeleted prior mappings for the device.

If *lpDeviceName* is **NULL**, the function retrieves a list of
all existing MS-DOS device names. Each null-terminated string stored into the buffer is the name of an existing
MS-DOS device, for example, \Device\HarddiskVolume1 or \Device\Floppy0.

### `ucchMax` [in]

The maximum number of **TCHARs** that can be stored into the buffer pointed to by
*lpTargetPath*.

## Return value

If the function succeeds, the return value is the number of **TCHARs** stored into
the buffer pointed to by *lpTargetPath*.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the buffer is too small, the function fails and the last error code is
**ERROR_INSUFFICIENT_BUFFER**.

## Remarks

The [DefineDosDevice](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-definedosdevicew) function enables an application
to create and modify the junctions used to implement the MS-DOS device namespace.

**Windows Server 2003 and Windows XP:** **QueryDosDevice** first searches the Local MS-DOS
Device namespace for the specified device name. If the device name is not found, the function will then search
the Global MS-DOS Device namespace.

When all existing MS-DOS device names are queried, the list of device names that are returned is dependent on
whether it is running in the "LocalSystem" context. If so, only the device names included in the Global MS-DOS
Device namespace will be returned. If not, a concatenation of the device names in the Global and Local MS-DOS
Device namespaces will be returned. If a device name exists in both namespaces,
**QueryDosDevice** will return the entry in the Local MS-DOS
Device namespace.

For more information on the Global and Local MS-DOS Device namespaces and changes to the accessibility of
MS-DOS device names, see
[Defining an MS DOS Device Name](https://learn.microsoft.com/windows/desktop/FileIO/defining-an-ms-dos-device-name).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |

SMB does not support volume management functions.

#### Examples

For an example, see
[Obtaining a File Name From a File Handle](https://learn.microsoft.com/windows/desktop/Memory/obtaining-a-file-name-from-a-file-handle)
or [Displaying Volume Paths](https://learn.microsoft.com/windows/desktop/FileIO/displaying-volume-paths).

## See also

[DefineDosDevice](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-definedosdevicew)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)