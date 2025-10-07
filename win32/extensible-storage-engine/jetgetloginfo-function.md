# JetGetLogInfo Function

_**Applies to:** Windows | Windows Server_

## JetGetLogInfo Function

The **JetGetLogInfo** function is used during a backup initiated by [JetBeginExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackup-function) to query an instance for the names of database patch files and transaction log files that should become part of the backup file set. These files may subsequently be opened using [JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfile-function) and read using [JetReadFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfile-function).

```cpp
    JET_ERR JET_API JetGetLogInfo(
      __out_opt     tchar* szz,
      __in          unsigned long cbMax,
      __out_opt     unsigned long* pcbActual
    );
```

### Parameters

*szz*

The output buffer that will receive the list of null terminated strings describing the set of database patch files and transaction log files that should be a part of the backup file set.

The list of strings returned in this buffer is in the same format as a multi-string used by the registry. Each null terminated string is returned in sequence followed by a final null terminator.

*cbMax*

The maximum size in bytes of the output buffer.

*pcbActual*

Receives the actual amount of string data received in the output buffer.

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

The operation failed because the current external backup has been aborted by a call to [JetStopBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294067(v=exchg.10).md). This error will only be returned by Windows XP and later releases.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidBackupSequence

|

The backup operation failed because it was called out of sequence. **JetGetLogInfo** will return this error if there are any outstanding file handles created using [JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269249(v=exchg.10).md) for the instance.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This can happen for **JetGetLogInfo** when the specified instance handle is invalid (Windows XP and later releases).

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

On success, the requested information on the set of database patch files and transaction log files that should be part of the backup file set will be placed in the output buffers where provided. The backup state machine will be advanced such that the backup of database files is no longer allowed. Only database patch files and transaction log files are permitted to be opened for backup beyond this point.

On failure, the state of the output buffers is undefined. The failure will result in the cancellation of the entire backup process for the instance.

#### Remarks

It is important to note that this API does not return an error or warning if the output buffer is too small to accept the full list of files that should be part of the backup file set. The application should always provide a buffer to receive the actual size of this list and use that information to determine if the list was truncated.

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
|

**Unicode**

|

Implemented as **JetGetLogInfoW** (Unicode) and **JetGetLogInfoA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JET_LOGINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-loginfo-structure)
[JetBeginExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackup-function)
[JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfile-function)
[JetReadFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfile-function)
[JetStopBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopbackup-function)