# NtClose function

## Description

Deprecated. Closes the specified handle. **NtClose** is superseded by [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle).

## Parameters

### `Handle` [in]

The handle being closed.

## Return value

The various NTSTATUS values are defined in NTSTATUS.H, which is distributed with the Windows DDK.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The handle was closed. |

## Remarks

The **NtClose** function closes handles to the following objects.

* Access token
* Communications device
* Console input
* Console screen buffer
* Event
* File
* File mapping
* Job
* Mailslot
* Mutex
* Named pipe
* Process
* Semaphore
* Socket
* Thread

Because there is no import library for this function, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress).