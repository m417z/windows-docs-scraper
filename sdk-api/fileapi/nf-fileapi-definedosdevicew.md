# DefineDosDeviceW function

## Description

Defines, redefines, or deletes MS-DOS device names.

## Parameters

### `dwFlags` [in]

The controllable aspects of the **DefineDosDevice** function. This parameter
can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **DDD_EXACT_MATCH_ON_REMOVE**<br><br>0x00000004 | If this value is specified along with **DDD_REMOVE_DEFINITION**, the function will use an exact match to determine which mapping to remove. Use this value to ensure that you do not delete something that you did not define. |
| **DDD_NO_BROADCAST_SYSTEM**<br><br>0x00000008 | Do not broadcast the [WM_SETTINGCHANGE](https://learn.microsoft.com/windows/desktop/winmsg/wm-settingchange) message. By default, this message is broadcast to notify the shell and applications of the change. |
| **DDD_RAW_TARGET_PATH**<br><br>0x00000001 | Uses the *lpTargetPath* string as is. Otherwise, it is converted from an MS-DOS path to a path. |
| **DDD_REMOVE_DEFINITION**<br><br>0x00000002 | Removes the specified definition for the specified device. To determine which definition to remove, the function walks the list of mappings for the device, looking for a match of *lpTargetPath* against a prefix of each mapping associated with this device. The first mapping that matches is the one removed, and then the function returns.<br><br>If *lpTargetPath* is **NULL** or a pointer to a **NULL** string, the function will remove the first mapping associated with the device and pop the most recent one pushed. If there is nothing left to pop, the device name will be removed.<br><br>If this value is not specified, the string pointed to by the *lpTargetPath* parameter will become the new mapping for this device. |

### `lpDeviceName` [in]

A pointer to an MS-DOS device name string specifying the device the function is defining, redefining, or
deleting. The device name string must not have a colon as the last character, unless a drive letter is being
defined, redefined, or deleted. For example, drive C would be the string "C:". In no case is a
trailing backslash (\\) allowed.

### `lpTargetPath` [in, optional]

A pointer to a path string that will implement this device. The string is an MS-DOS path string unless the
**DDD_RAW_TARGET_PATH** flag is specified, in which case this string is a path
string.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

MS-DOS device names are stored as junctions in the object namespace. The code that converts an MS-DOS path
into a corresponding path uses these junctions to map MS-DOS devices and drive letters. The
**DefineDosDevice** function enables an application to modify the junctions used to
implement the MS-DOS device namespace.

To retrieve the current mapping for a particular MS-DOS device name or to obtain a list of all MS-DOS devices
known to the system, use the [QueryDosDevice](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-querydosdevicew)
function.

To define a drive letter assignment that is persistent across boots and not a network share, use the
[SetVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setvolumemountpointa) function. If the volume to
be mounted already has a drive letter assigned to it, use the
[DeleteVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletevolumemountpointw) function to remove the
assignment.

Drive letters and device names defined at system boot time are protected from redefinition and deletion unless
the user is an administrator.

Starting with Windows XP, this function creates a device name for a caller that is not running in
the "LocalSystem" context in its own Local MS-DOS device namespace. If the caller is running in
the "LocalSystem" context, the function creates the device name in the Global MS-DOS device
namespace. For more information, see
[Defining an MS DOS Device Name](https://learn.microsoft.com/windows/desktop/FileIO/defining-an-ms-dos-device-name) and
[File Names, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | No |
| SMB 3.0 Transparent Failover (TFO) | No |
| SMB 3.0 with Scale-out File Shares (SO) | No |
| Cluster Shared Volume File System (CsvFS) | No |
| Resilient File System (ReFS) | No |

SMB does not support volume management functions. For CsvFs, a new name will not be replicated to the other nodes on the cluster.

#### Examples

For an example, see
[Editing Drive Letter Assignments](https://learn.microsoft.com/windows/desktop/FileIO/editing-drive-letter-assignments).

## See also

[DeleteVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletevolumemountpointw)

[QueryDosDevice](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-querydosdevicew)

[SetVolumeMountPoint](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setvolumemountpointa)

[Volume Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-functions)