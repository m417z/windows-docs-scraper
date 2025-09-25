# DavFlushFile function

## Description

Flushes the data from the local version of a remote file to the WebDAV server.

## Parameters

### `hFile` [in]

A handle to an open file on a WebDAV server.

The file handle must have the GENERIC_WRITE access right. For more information, see
[File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights).

## Return value

If the function succeeds, or if *hFile* is a handle to an encrypted file, the return value is ERROR_SUCCESS.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

When an application creates or opens a remote file on a WebDAV server, the WebDAV service downloads the file to the local computer, and the application receives a handle to the open file on the server. Any changes that the application makes to the local file have no effect on the remote file until the file handle is closed and the local version of the file is uploaded to the server. Because the file handle is closed at the same time that the file is saved to the server, the application cannot check whether the file was saved successfully.

To avoid this problem, use the **DavFlushFile** function to flush the data from the local version of the file to the remote file on the WebDAV server. If the function succeeds, this means that the file was saved successfully.

This function does not flush encrypted files. If *hFile* is a handle to an encrypted file, **DavFlushFile** returns ERROR_SUCCESS without flushing the file data.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[FlushFileBuffers](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-flushfilebuffers)

[OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)