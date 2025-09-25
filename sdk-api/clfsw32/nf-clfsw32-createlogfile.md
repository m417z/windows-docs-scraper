# CreateLogFile function

## Description

Creates or opens a log. The log can be dedicated or multiplexed, and that depends on
the log name. Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the
log.

## Parameters

### `pszLogFileName` [in]

The name of the log.

This name is specified when creating the log by using
**CreateLogFile**. The following example identifies the
format to use.

**log :<***LogName***>[::<***LogStreamName***>]**

For example: The path "LOG:c:\MyDirectory\MyLog" creates the file
"c:\MyDirectory\MyLog.blf". The path
"\??\LOG:\HarddiskVolume1\MyDirectory\MyLog" creates the file
"\\.\HarddiskVolume1\MyDirectory\MyLog.blf", as does the path
"\clfs\Device\HarddiskVolume1\MyDirectory\MyLog".

<*LogName*> corresponds to a valid file path in the file system, and
<*LogStreamName*> is the unique name of a log stream in the log. For more
information, see [Log Types](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/log-types).

### `fDesiredAccess` [in]

The type of access that the returned handle has to the log object.

| Value | Meaning |
| --- | --- |
| **GENERIC_READ** | Specifies read access to the object. |
| **GENERIC_WRITE** | Specifies write access to the object. |
| **DELETE** | Specify log deletion access |

A bitwise **OR** of two or more of these flags allows combinations of read, write, and delete access to the object.

**Note** You must specify **DELETE** access to be able to delete the log.

**Windows Server 2003 R2:** This parameter must be set to **GENERIC_WRITE**.

### `dwShareMode` [in]

The sharing mode of a file.

A client cannot request a sharing mode that conflicts with any mode that is specified in any previous open
request that has an open handle.

If this parameter is zero and the function succeeds, the object cannot be shared and cannot be opened
again until the handle is closed.

This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **FILE_SHARE_DELETE** | Enables open operations on the object to request delete access. Without this value, other processes cannot open the object if delete access is requested. |
| **FILE_SHARE_READ** | Enables open operations on the object to request read access. Without this value, other processes cannot open the object if read access is requested. |
| **FILE_SHARE_WRITE** | Enables open operations on the object to request write access. Without this value, other processes cannot open the object if write access is requested. |

### `psaLogFile` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)
structure that specifies the security attributes of a log.

It determines whether the returned handle can be
inherited by child processes. If this parameter is **NULL**, the handle cannot be
inherited.

The **lpSecurityDescriptor** member of
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) specifies a
[security descriptor](https://learn.microsoft.com/windows/desktop/winstation/desktop-security-and-access-rights) for the new log
handle. If *psaLogFile* is **NULL**, the object gets a default
security descriptor. The access control lists (ACL) in the default security descriptor for a log come from the
primary or impersonation token of the creator.

### `fCreateDisposition` [in]

An action to be taken.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CREATE_NEW** | Creates a new file and fails if the file already exists. |
| **OPEN_EXISTING** | Opens an existing file and fails if the file does not exist. |
| **OPEN_ALWAYS** | Opens an existing file or creates the file if it does not exist. |

### `fFlagsAndAttributes` [in]

The file attributes and flags for the file.

This parameter can take the following values.

| Value | Meaning |
| --- | --- |
| **FILE_ATTRIBUTE_ARCHIVE** | This non-ephemeral log should be archived.<br><br>If this flag is not supplied, the log does not need to be archived, and an archival tail is not maintained for recycling log containers. |
| **FILE_FLAG_OVERLAPPED** | If the **FILE_FLAG_OVERLAPPED** flag is set, all other flag values are ignored.<br><br>Specifying **FILE_FLAG_OVERLAPPED** means that a file is opened for overlapped I/O, which enables more than one I/O operation to be performed on the log handle. If this flag is set when creating a log, all asynchronous I/O calls to that log must specify an overlapped structure and synchronize with the deferred completion of the call. |

## Return value

If the function succeeds, the return value is a handle to the log.

If the function fails, the return value is **INVALID_HANDLE_VALUE**. To get extended
error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The following list identifies the possible error codes:

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask)

[AddLogContainer](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainer)

[AddLogContainerSet](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-addlogcontainerset)

[CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_container_information)

[Common Log File System Functions](https://learn.microsoft.com/previous-versions/windows/desktop/clfs/common-log-file-system-functions)

[CreateLogMarshallingArea](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-createlogmarshallingarea)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)