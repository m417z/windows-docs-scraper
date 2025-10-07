# JetGetAttachInfoInstance Function

_**Applies to:** Windows | Windows Server_

## JetGetAttachInfoInstance Function

The **JetGetAttachInfoInstance** function is used during a backup initiated by [JetBeginExternalBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackupinstance-function) to query an instance for the names of database files that should become part of the backup file set. Only databases that are currently attached to the instance using [JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function) will be considered. These files may subsequently be opened using [JetOpenFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfileinstance-function) and read using [JetReadFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfileinstance-function).

**Windows XP: JetGetAttachInfoInstance** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetGetAttachInfoInstance(
      __in          JET_INSTANCE instance,
      __out_opt     tchar* szz,
      __in          unsigned long cbMax,
      __out_opt     unsigned long* pcbActual
    );
```

### Parameters

*instance*

The instance to use for this call.

For Windows 2000, the API variant that accepts this parameter is not available because only one instance is supported. The use of this one global instance is implied in this case.

For Windows XP and later releases, the API variant that does not accept this parameter may only be called when the engine is in legacy mode (Windows 2000 compatibility mode) where only one instance is supported. Otherwise, the operation will fail with JET_errRunningInMultiInstanceMode.

*szz*

The output buffer that receives the list of null terminated strings describing the set of database files that should be a part of the backup file set. The list of strings returned in this buffer is in the same format as a multi-string used by the registry. Each null-terminated string is returned in sequence followed by a final null terminator.

*cbMax*

The maximum size in bytes of the output buffer.

*pcbActual*

Pointer to the output buffer that receives the actual amount of string data.

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

JET_errBackupAbortByServer

|

The operation failed because the current external backup has been aborted by a call to [JetStopBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269309(v=exchg.10).md). This error will only be returned by Windows XP and later releases.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopServiceInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294108(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidBackupSequence

|

The backup operation failed because it was called out of sequence. **JetGetAttachInfoInstance** will return this error if the current backup is not a full backup.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This can happen for **JetGetAttachInfoInstance** when the specified instance handle is invalid (Windows XP and later releases).

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

On success, the requested information on the set of database files that should be part of the backup file set will be placed in the output buffers where provided.

On failure, the state of the output buffers is undefined. The failure will result in the cancellation of the entire backup process for the instance.

#### Remarks

It is important to note that this API does not return an error or warning if the output buffer is too small to accept the full list of files that should be part of the backup file set. The application should always provide a buffer to receive the actual size of this list and use that information to determine if the list was truncated.

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
|

**Unicode**

|

Implemented as **JetGetAttachInfoInstanceW** (Unicode) and **JetGetAttachInfoInstanceA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function)
[JetBeginExternalBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackupinstance-function)
[JetOpenFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfileinstance-function)
[JetReadFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfileinstance-function)
[JetStopBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopbackupinstance-function)
[JetStopServiceInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopserviceinstance-function)