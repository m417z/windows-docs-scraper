# BG_ERROR_CONTEXT enumeration

## Description

Defines constants that specify the context in which the error occurred.

## Constants

### `BG_ERROR_CONTEXT_NONE:0`

An error has not occurred.

### `BG_ERROR_CONTEXT_UNKNOWN:1`

The error context is unknown.

### `BG_ERROR_CONTEXT_GENERAL_QUEUE_MANAGER:2`

The transfer queue manager generated the error.

### `BG_ERROR_CONTEXT_QUEUE_MANAGER_NOTIFICATION:3`

The error was generated while the queue manager was notifying the client of an event.

### `BG_ERROR_CONTEXT_LOCAL_FILE:4`

The error was related to the specified local file. For example, permission was denied, or the volume was unavailable.

### `BG_ERROR_CONTEXT_REMOTE_FILE:5`

The error was related to the specified remote file. For example, the URL was not accessible.

### `BG_ERROR_CONTEXT_GENERAL_TRANSPORT:6`

The transport layer generated the error. These errors are general transport failures (these errors are not specific to the remote file).

### `BG_ERROR_CONTEXT_REMOTE_APPLICATION:7`

The server application to which BITS passed the upload file generated an error while processing the upload file.

**BITS 1.2 and earlier:** Not supported.

## See also

* [IBackgroundCopyError::GetError method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterror)
* [IBackgroundCopyError::GetErrorContextDescription method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterrorcontextdescription)