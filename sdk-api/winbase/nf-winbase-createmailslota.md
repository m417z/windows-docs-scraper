# CreateMailslotA function

## Description

Creates a mailslot with the specified name and returns a handle that a mailslot server can use to perform operations on the mailslot. The mailslot is local to the computer that creates it. An error occurs if a mailslot with the specified name already exists.

## Parameters

### `lpName` [in]

The name of the mailslot. This name must have the following form:

\\\\.\mailslot\\[*path*]*name*

The name field must be unique. The name may include multiple levels of pseudo directories separated by backslashes. For example, both \\\\.\mailslot\example_mailslot_name and \\\\.\mailslot\abc\def\ghi are valid names.

### `nMaxMessageSize` [in]

The maximum size of a single message that can be written to the mailslot, in bytes. To specify that the message can be of any size, set this value to zero.

### `lReadTimeout` [in]

The time a read operation can wait for a message to be written to the mailslot before a time-out occurs, in milliseconds. The following values have special meanings.

| Value | Meaning |
| --- | --- |
| 0 | Returns immediately if no message is present. (The system does not treat an immediate return as an error.) |
| **MAILSLOT_WAIT_FOREVER**<br><br>((DWORD)-1) | Waits forever for a message. |

This time-out value applies to all subsequent read operations and all inherited mailslot handles.

### `lpSecurityAttributes` [in, optional]

A pointer to a
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure. The **bInheritHandle** member of the structure determines whether the returned handle can be inherited by child processes. If *lpSecurityAttributes* is **NULL**, the handle cannot be inherited.

## Return value

If the function succeeds, the return value is a handle to the mailslot, for use in server mailslot operations. The handle returned by this function is asynchronous, or overlapped.

If the function fails, the return value is **INVALID_HANDLE_VALUE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The mailslot exists until one of the following conditions is true:

* The last (possibly inherited or duplicated) handle to it is closed using the
  [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.
* The process owning the last (possibly inherited or duplicated) handle exits.

The system uses the second method to destroy mailslots.

To write a message to a mailslot, a process uses the
[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function, specifying the mailslot name by using one of the following formats.

| Format | Usage |
| --- | --- |
| \\.\mailslot\*name* | Retrieves a client handle to a local mailslot. |
| \\*computername*\mailslot\*name* | Retrieves a client handle to a remote mailslot. |
| \\*domainname*\mailslot\*name* | Retrieves a client handle to all mailslots with the specified name in the specified domain. |
| \\*\mailslot\*name* | Retrieves a client handle to all mailslots with the specified name in the system's primary domain. |

If [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) specifies a domain or uses the asterisk format to specify the system's primary domain, the application cannot write more than 424 bytes at a time to the mailslot. If the application attempts to do so, the [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) function fails and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_BAD_NETPATH**.

An application must specify the **FILE_SHARE_READ** flag when using [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) to retrieve a client handle to a mailslot.

If [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) is called to access a non-existent mailslot, the **ERROR_FILE_NOT_FOUND** error code will be set.

#### Examples

For an example, see
[Creating a Mailslot](https://learn.microsoft.com/windows/desktop/ipc/creating-a-mailslot).

> [!NOTE]
> The winbase.h header defines CreateMailslot as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[GetMailslotInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getmailslotinfo)

[Mailslot Functions](https://learn.microsoft.com/windows/desktop/ipc/mailslot-functions)

[Mailslots Overview](https://learn.microsoft.com/windows/desktop/ipc/mailslots)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[SetMailslotInfo](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setmailslotinfo)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)