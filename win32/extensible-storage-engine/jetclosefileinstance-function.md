# JetCloseFileInstance Function

_**Applies to:** Windows | Windows Server_

## JetCloseFileInstance Function

The **JetCloseFileInstance** function closes a file that was opened with [JetOpenFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfileinstance-function) after the data from that file has been extracted using [JetReadFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfileinstance-function).

**Windows XP: JetCloseFileInstance** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetCloseFileInstance(
      __in          JET_INSTANCE instance,
      __in          JET_HANDLE hfFile
    );
```

### Parameters

*instance*

The instance to use for this call.

For Windows 2000, the API variant that accepts this parameter is not available because only one instance is supported. The use of this one global instance is implied in this case.

For Windows XP and later releases, the API variant that does not accept this parameter may only be called when the engine is in legacy mode (Windows 2000 compatibility mode) where only one instance is supported. Otherwise, the operation will fail with JET_errRunningInMultiInstanceMode.

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

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopServiceInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294108(v=exchg.10).md).

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

One of the parameters that was provided contained an unexpected value, or the combination of several parameter values yielded an unexpected result. This can happen for **JetCloseFileInstance** when:

* The specified instance handle is invalid (Windows XP and later releases)
* The specified file handle is invalid

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

The database engine currently only supports one open file through [JetOpenFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfileinstance-function) at a time. If a file handle is opened using [JetOpenFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfileinstance-function) then it must be closed using **JetCloseFileInstance** before another file can be opened.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista or Windows XP.

|
|

**Server**

|

Requires Windows Server 2008 or Windows Server 2003.

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
[JET_HANDLE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-handle)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetOpenFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfileinstance-function)
[JetReadFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfileinstance-function)
[JetStopServiceInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopserviceinstance-function)