# CreatePipe function

## Description

Creates an anonymous pipe, and returns handles to the read and write ends of the pipe.

## Parameters

### `hReadPipe` [out]

A pointer to a variable that receives the read handle for the pipe.

### `hWritePipe` [out]

A pointer to a variable that receives the write handle for the pipe.

### `lpPipeAttributes` [in, optional]

A pointer to a
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that determines whether the returned handle can be inherited by child processes. If *lpPipeAttributes* is **NULL**, the handle cannot be inherited.

The **lpSecurityDescriptor** member of the structure specifies a security descriptor for the new pipe. If *lpPipeAttributes* is **NULL**, the pipe gets a default security descriptor. The ACLs in the default security descriptor for a pipe come from the primary or impersonation token of the creator.

### `nSize` [in]

The size of the buffer for the pipe, in bytes. The size is only a suggestion; the system uses the value to calculate an appropriate buffering mechanism. If this parameter is zero, the system uses the default buffer size.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**CreatePipe** creates the pipe, assigning the specified pipe size to the storage buffer.
**CreatePipe** also creates handles that the process uses to read from and write to the buffer in subsequent calls to the [ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile) and [WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile) functions.

To read from the pipe, a process uses the read handle in a call to the [ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile) function. **ReadFile** returns when one of the following is true: a write operation completes on the write end of the pipe, the number of bytes requested has been read, or an error occurs.

When a process uses [WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile) to write to an anonymous pipe, the write operation is not completed until all bytes are written. If the pipe buffer is full before all bytes are written, **WriteFile** does not return until another process or thread uses [ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile) to make more buffer space available.

Anonymous pipes are implemented using a named pipe with a unique name. Therefore, you can often pass a handle to an anonymous pipe to a function that requires a handle to a named pipe.

If **CreatePipe** fails, the contents of the output parameters are indeterminate. No assumptions should be made about their contents in this event.

To free resources used by a pipe, the application should always close handles when they are no longer needed, which is accomplished either by calling the [CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle) function or when the process associated with the instance handles ends. Note that an instance of a pipe may have more than one handle associated with it. An instance of a pipe is always deleted when the last handle to the instance of the named pipe is closed.

#### Examples

For an example, see
[Creating a Child Process with Redirected Input and Output](https://learn.microsoft.com/windows/win32/ProcThread/creating-a-child-process-with-redirected-input-and-output).

## See also

[Pipe Functions](https://learn.microsoft.com/windows/win32/ipc/pipe-functions)

[Pipes Overview](https://learn.microsoft.com/windows/win32/ipc/pipes)

[ReadFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-readfile)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[WriteFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-writefile)