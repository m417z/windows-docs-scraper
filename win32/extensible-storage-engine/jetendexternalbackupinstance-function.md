# JetEndExternalBackupInstance Function

_**Applies to:** Windows | Windows Server_

## JetEndExternalBackupInstance Function

The **JetEndExternalBackupInstance** function ends an external backup session. This API is the last API in a series of APIs that must be called to execute a successful online (non-VSS based) backup.

**Windows XP: JetEndExternalBackupInstance** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetEndExternalBackupInstance(
      __in          JET_INSTANCE instance
    );
```

### Parameters

*instance*

The instance to use for this call.

**Windows 2000:** For Windows 2000, the API variant that accepts this parameter is not available because only one instance is supported. The use of this one global instance is implied in this case.

**Windows XP:** For Windows XP and later releases, the API variant that does not accept this parameter can only be called when the engine is in legacy mode (Windows 2000 compatibility mode) where only one instance is supported. Otherwise, the operation will fail with JET_errRunningInMultiInstanceMode.

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

JET_errBackupAbortByCaller

|

**Windows XP:** This return value is introduced in Windows XP.

The caller terminated a backup in the middle of the backup sequence without signaling the intention with [JetStopBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294067(v=exchg.10).md). This error is the result of a bug in the backup client in Windows Server 2003 and later. On Windows XP this error is returned for an intentional termination of the external backup sequence.

|
|

JET_errBackupAbortByServer

|

**Windows Server 2003:** This return value is introduced in Windows Server 2003.

The operation failed because the current external backup has been aborted by a call to [JetStopBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294067(v=exchg.10).md).

|
|

JET_errClientRequestToStopJetService

|

The operation cannot complete because all activity on the instance that is associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

**Windows XP:** This return value is introduced in Windows XP.

The operation cannot complete because the instance that is associated with the session encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

|
|

JET_errNoBackup

|

The operation failed because no external backup is in progress.

|
|

JET_errNotInitialized

|

The operation cannot complete because the instance that is associated with the session has not yet been initialized.

|
|

JET_errRestoreInProgress

|

The operation cannot complete because a restore operation is in progress on the instance that is associated with the session.

|
|

JET_errRunningInMultiInstanceMode

|

The operation failed because an attempt was made to use the engine in legacy mode (Windows 2000 compatibility mode) where only one instance is supported, when in fact multiple instances already exist.

|
|

JET_errTermInProgress

|

The operation cannot complete because the instance that is associated with the session is being shut down.

|

If the function succeeds, the external backup was a success. Success indicates that all files (for example, databases and logs) that are appropriate for the type of backup (specified in [JetBeginExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackup-function)) were retrieved from the backup engine. The backed up files can be recovered with hard recovery ([JetExternalRestore](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetexternalrestore-function)).

If this function fails, the external backup usually ends. Failure means that the backup is invalid because of a client or an application usage error. It is important to check the return code for this API to verify that the backup sequence was successful.

#### Remarks

If the engine is configured to log events, an event is logged to indicate the resolution of the external backup.

If the backup sequence is not completed in order and with a successful call to [JetEndExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendexternalbackup-function), subsequent incremental backups might contain more data than the application anticipated.

For more information about the external backup API sequence, see [JetBeginExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackup-function).

Before Windows Vista, if the log truncation was not done, the engine considered that the backup was a copy backup. However, the backup might be a normal backup for which truncation was not done (for example, if there are detached databases). The JET_bitBackupTruncateDone option can be used to inform the engine about this and allow proper database header modifications.

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

[Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters)
[Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors)
[JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function)
[JetBeginExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackup-function)
[JetBeginExternalBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackupinstance-function)
[JetCloseFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosefile-function)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JetExternalRestore](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetexternalrestore-function)
[JetGetAttachInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetattachinfo-function)
[JetGetLogInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetloginfo-function)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfile-function)
[JetReadFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfile-function)
[JetStopBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopbackup-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)
[JetTruncateLog](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jettruncatelog-function)