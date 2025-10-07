# JetGetTruncateLogInfoInstance Function

_**Applies to:** Windows | Windows Server_

## JetGetTruncateLogInfoInstance Function

The **JetGetTruncateLogInfoInstance** function is used during a backup that is initiated by [JetBeginExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackup-function) to query an instance for the names of the transaction log files that can be safely deleted after the backup has successfully completed.

**Windows XP:** **JetGetTruncateLogInfoInstance** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetGetTruncateLogInfoInstance(
      __in          JET_INSTANCE instance,
      __out_opt     tchar* szz,
      __in          unsigned long cbMax,
      __out_opt     unsigned long* pcbActual
    );
```

### Parameters

*instance*

The instance to use for this call.

*szz*

The output buffer that receives the list of null-terminated strings describing the set of transaction log files that can be safely deleted after the backup has been completed successfully.

The list of strings that are returned in this buffer is in the same format as a multi-string that is used by the registry. Each null-terminated string is returned in sequence and followed by a final null terminator.

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

JET_errInvalidParameter

|

One of the provided parameters contained an unexpected value or the combination of several parameter values resulted in an unexpected result.

**Windows XP and later:** This can happen for **JetGetTruncateLogInfoInstance** when the specified instance handle is invalid.

|
|

JET_errNotInitialized

|

The operation cannot complete because the instance that is associated with the session has not been initialized yet.

|
|

JET_errClientRequestToStopJetService

|

The operation cannot complete because all activity on the instance that is associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

The operation cannot complete because the instance that is associated with the session encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This return value was introduced in Windows XP.

|
|

JET_errBackupAbortByServer

|

The operation failed because the current external backup has been aborted by a call to [JetStopBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294067(v=exchg.10).md).

**Windows XP:** This return value was introduced in Windows XP.

|
|

JET_errInvalidBackupSequence

|

The backup operation failed because it was called out of sequence.

|
|

JET_errNoBackup

|

The operation failed because no external backup is in progress.

|
|

JET_errRestoreInProgress

|

The operation cannot complete because a restore operation is in progress on the instance that is associated with the session.

|
|

JET_errTermInProgress

|

The operation cannot complete because the instance that is associated with the session is being shut down.

|
|

**JetGetTruncateLogInfoInstance**

|

There are outstanding file handles that were created using [JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269249(v=exchg.10).md) for the instance.

|

If this function succeeds, the requested information about the set of transaction log files that can be safely deleted after the backup has been completed successfully will be placed in the output buffers where they are provided. The backup state machine will be advanced such that the backup of database files is no longer allowed. Only database patch files and transaction log files can be opened for backup beyond this point.

If this function fails, the state of the output buffers is undefined. The failure will result in the cancellation of the entire backup process for the instance.

#### Remarks

This API does not return an error or warning if the output buffer is too small to accept the full list of files that should be part of the backup file set. The application should always provide a buffer to receive the actual size of this list and use that information to determine if the list was truncated.

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

Implemented as **JetGetTruncateLogInfoInstanceW** (Unicode) and **JetGetTruncateLogInfoInstanceA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetBeginExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackup-function)
[JetCloseDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosedatabase-function)
[JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function)
[JetEndSession](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendsession-function)
[JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfile-function)
[JetResetSessionContext](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetresetsessioncontext-function)
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)
[JetStopBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopbackup-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)
[JetTerm](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm-function)
[JetTerm2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm2-function)