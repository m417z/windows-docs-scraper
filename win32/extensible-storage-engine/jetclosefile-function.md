# JetCloseFile Function

_**Applies to:** Windows | Windows Server_

## JetCloseFile Function

The **JetCloseFile** function closes a file that was opened with [JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfile-function) after the data from that file has been extracted using [JetReadFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfile-function).

```cpp
    JET_ERR JET_API JetCloseFile(
      __in          JET_HANDLE hfFile
    );
```

### Parameters

*hfFile*

The handle of the file to be read.

### Return Value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) datatype with one of the following return codes. For more information about the possible ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

|

Return code

|

Description

|
|--------------------|--------------------|
|

JET_errSuccess

|

The operation completed successfully.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This can happen for **JetCloseFile** when:

* The specified instance handle is invalid (Windows XP and later releases),
* The specified file handle is invalid.

|
|

JET_errNoBackup

|

The operation failed because no external backup is in progress.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_errRunningInMultiInstanceMode

|

The operation failed because an attempt was made to use the engine in legacy mode (Windows 2000 compatibility mode) where only one instance is supported when in fact multiple instances already exist.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|

On success, the file handle is closed. If a database file was closed then the associated database patch file (if any) is destroyed.

On failure, no change occurs.

#### Remarks

The database engine currently only supports one open file through [JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfile-function) at a time. If a file handle is opened using [JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfile-function) then it must be closed using **JetCloseFile** before another file can be opened.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista, Windows XP, or Windows 2000 Professional.

|
|

**Server**

|

Requires Windows Server 2008, Windows Server 2003, or Windows 2000 Server.

|
|

**Header**

|

Declared in Esent.h.

|
|

**Library**

|

Use ESENT.lib.

|
|

**DLL**

|

Requires ESENT.dll.

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JET_HANDLE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-handle)
[JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfile-function)
[JetReadFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfile-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)