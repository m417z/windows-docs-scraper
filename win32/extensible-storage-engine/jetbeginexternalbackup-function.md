# JetBeginExternalBackup Function

_**Applies to:** Windows | Windows Server_

## JetBeginExternalBackup Function

The **JetBeginExternalBackup** function initiates an external backup while the engine and database is online and active. **JetBeginExternalBackup** is the first in a series of functions that must be called to execute a successful online (non-VSS based) backup.

An external backup can be used to implement full, incremental, or differential backups.

The backup will be fuzzy, in that the backup will be consistent to a single point in time in the transaction history, but controlling the exact point in time is not possible.

```cpp
    JET_ERR JET_API JetBeginExternalBackup(
      __in          JET_GRBIT grbit
    );
```

### Parameters

*grbit*

A group of bits that specify zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitBackupAtomic

|

This flag is deprecated. Usage of this bit will result in JET_errInvalidgrbit being returned.

|
|

JET_bitBackupIncremental

|

Creates an incremental backup as opposed to a full backup. This means that only the log files since the last full or incremental backup will be backed up.

|
|

JET_bitBackupSnapshot

|

Reserved for future use. Defined for Windows XP.

|

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

JET_errBackupInProgress

|

If an external backup or snapshot backup is already in process, this error will be returned, until **JetBeginExternalBackup** (or one of the variants of it) is called. ESE allows only one online backup at a time.

|
|

JET_errBackupNotAllowedYet

|

The instance or database engine is either in recovery or in a shutdown or termination phase.

|
|

JET_errCheckpointCorrupt

|

On a full backup, the checkpoint file could not be read, or the file could not be verified.

|
|

JET_errCheckpointFileNotFound

|

On a full backup, the checkpoint file could not be found.

|
|

JET_errClientRequestToStopJetService

|

The operation cannot complete because all activity on the instance that is associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

The operation cannot complete because the instance that is associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errInvalidBackup

|

Circular logging is enabled and the backup type specified is JET_bitBackupIncremental. See [JET_paramCircularLog](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269235(v=exchg.10).md) in the **Transaction Log Errors** for information about how to control circular or non-circular logging.

|
|

JET_errInvalidgrbit

|

One or more of the *grbit* members was invalid.

|
|

JET_errLoggingDisabled

|

Recovery or logging is disabled. You cannot do an online backup if logging is disabled. For more information about logging and recovery, see [JET_paramRecovery](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269235(v=exchg.10).md).

|
|

JET_errLogWriteFail

|

The engine has stopped writing to the log drive, due to log being full or disk IO errors.

|
|

JET_errMissingFullBackup

|

The incremental backup was specified (with JET_bitBackupIncremental), and never was a full backup taken for one of the attached databases for the logging set.

|
|

JET_errNotInitialized

|

The operation cannot complete because the instance that is associated with the session has not yet been initialized.

|
|

JET_errOutOfMemory

|

The operation failed because not enough memory could be allocated to complete it.

|
|

JET_errRestoreInProgress

|

The operation cannot complete because a restore operation is in progress on the instance associated with the session.

|
|

JET_errRunningInMultiInstanceMode

|

The operation failed because an attempt was made to use the engine in legacy mode (Windows 2000 compatibility mode) where only one instance is supported when in fact multiple instances already exist.

|
|

JET_errTermInProgress

|

The operation cannot complete because the instance that is associated with the session is being shut down.

|

If the function succeeds, an external backup is initiated and the backup state engine is initialized. Subsequent APIs can now be called to complete the external backup sequence and stream or read off the database file, the database patch file (if supported), and the log file. An event can be logged that an external backup has begun.

If the function fails, the backup session will not be initiated. If another backup session is in progress, it will not be cancelled.

#### Remarks

The external backup process (as started by **JetBeginExternalBackup**) is designed to allow a fuzzy transaction online backup of the entire instance to a target device as a stream. The backup will contain all the database files that are attached to the instance using [JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function) (for a full backup), followed by their associated database patch files (if supported), and finally by the transaction log files that were generated during the backup process. The end result will be a set of files that can be restored from the stream, possibly combined with existing database and log files, and finally recovered to a consistent state.

The general order of operations for a full backup consists of the following calls. First, **JetBeginExternalBackup** is called to start the backup process. Then, [JetGetAttachInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetattachinfo-function) is called to get the list of databases that are attached to the instance that needs to be backed up. For each of these databases, [JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfile-function) is called, followed by a number of [JetReadFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfile-function) calls, and then by a call to [JetCloseFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosefile-function). Then, [JetGetLogInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetloginfo-function) is called to get a list of database patch and log files to be backed up. For each of these files, another sequence of [JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfile-function), [JetReadFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfile-function), and [JetCloseFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosefile-function) calls are made. Then, any undesired transaction log files are deleted using [JetTruncateLog](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jettruncatelog-function). Finally, the backup is ended by a call to [JetEndExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendexternalbackup-function).

It is also possible to modify this set of steps to perform an incremental backup of the instance. An incremental backup enumerates and backs up log files. Incremental backups are only possible if circular logging is not enabled.

It is also possible to modify this set of steps to allow subsequent differential backups of the instance to be performed. To perform a differential backup, do not call [JetTruncateLog](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jettruncatelog-function) in the previous full or incremental backup. By not calling [JetTruncateLog](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jettruncatelog-function), you enable subsequent backups to be differential with respect to the last full or incremental backup. Differential backups are only possible if circular logging is not enabled.

The database patch file is a special auxiliary file that is used to store database page images under certain circumstances during the backup. This file must be present in the same location as its associated database during a restore operation. This file is only used in Windows 2000. As a result, any application that is written to work against Windows 2000 and other releases must support database patch files, if they are present, but also must not fail if they are not present.

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
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function)
[JetBeginExternalBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackupinstance-function)
[JetCloseFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosefile-function)
[JetEndExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendexternalbackup-function)
[JetEndExternalBackupInstance2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendexternalbackupinstance2-function)
[JetGetAttachInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetattachinfo-function)
[JetGetLogInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetloginfo-function)
[JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfile-function)
[JetReadFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfile-function)
[JetStopBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopbackup-function)
[JetTruncateLog](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jettruncatelog-function)