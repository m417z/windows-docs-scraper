# JetBackup Function

_**Applies to:** Windows | Windows Server_

## JetBackup Function

The **JetBackup** function creates a backup of the database while the database is online. This function is primarily for backwards compatibility with Windows 2000 and earlier database engines, where only one instance of a database is allowed. In this case, the active instance is the instance that is backed up.

```cpp
    JET_ERR JET_API JetBackup(
      __in          JET_PCSTR szBackupPath,
      __in          JET_GRBIT grbit,
      __in          JET_PFNSTATUS pfnStatus
    );
```

### Parameters

*szBackupPath*

The directory where the backup is stored. If the backup path is NULL, the function will truncate the logs, if possible.

*grbit*

A group of bits specifying zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitBackupAtomic

|

Creates a full backup of the database. This allows the preservation of an existing backup in the same directory if the new backup fails.

|
|

JET_bitBackupIncremental

|

Creates an incremental backup as opposed to a full backup. This means that only the log files since the last full or incremental backup will be backed up.

|

*pfnStatus*

Pointer to the [JET_PFNSTATUS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-pfnstatus-callback-function) callback function, which provides notification information about the progress of the backup operation.

### Return Value

The function returns one of the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) error codes. The following are the most commonly returned. (For a complete list of errors for this API, see [Extensible Storage Engine Error Codes](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-error-codes).)

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

A backup is already in progress for the same instance. Multiple backups are not allowed at the same time.

|
|

JET_errBackupNotAllowedYet

|

The instance is not ready yet for backup as it is initializing.

|
|

JET_errClientRequestToStopJetService

|

The operation cannot complete because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

The operation cannot complete because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errInvalidBackup

|

An incremental backup is not allowed if circular logging is on.

|
|

JET_errInvalidGrbit

|

The specified options are invalid.

|
|

JET_errInvalidParameter

|

An invalid parameter was passed into the API.

|
|

JET_errInvalidPath

|

The destination path does not exist.

|
|

JET_errLoggingDisabled

|

The instance is running without logging. No backup is allowed.

|
|

JET_errLogReadVerifyFailure

|

There was a checksum verification error on a log file.

|
|

JET_errLogWriteFail

|

The logging for the instance is temporary or permanently disabled due to an unexpected error.

|
|

JET_errNotInitialized

|

The operation cannot complete because the instance associated with the session has not been initialized yet.

|
|

JET_errReadVerifyFailure

|

There was a checksum verification error on a database page.

|
|

JET_errRestoreInProgress

|

The operation cannot complete because a restore operation is in progress on the instance associated with the session.

|
|

JET_errSessionSharingViolation

|

The same session cannot be used for more than one thread at the same time.

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errTermInProgress

|

The operation cannot complete because the instance associated with the session is being shut down.

|

If the function succeeds, all the files needed for a restore up to the moment of the backup will be contained in the backup directory. If this is a full backup, the files will be the database files and the log files needed to bring the database to a consistent state. If this is an incremental backup, only log files will be added to the directories, but the already existing files (databases and log files), together with the new log files, will be able to be restored to bring the database back to the state it was in at the moment that the backup began.

As a side effect of the backup, the log files which are no longer needed will be truncated.

In the same time, the database headers will be updated with the information when the last backup took place.

If the function fails, there will not be any files in the backup directory destination so no restore will be possible. In the same time, the current log files will not be truncated.

#### Remarks

The different steps of the backup will have Event Log entries generated, including the file names, the log truncation, and the final result of the backup.

Incremental backups are possible only after a full backup was taken. Also, incremental backups are possible only if circular logging is turned off. It is recommended that the backup directory should not contain any files other than the one used in the backup or added by a previous successful backup.

The backup directory should exist unless the parameter *JET_paramCreatePathIfNotExist* is set for the instance. For information, see [System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters).

The backup will do a checksum verification on all the used database pages and starting with Windows Server 2003, on the log files as well. This gives an opportunity to estimate the health of the database, even for pages which are not read during normal operations. If any such corruption is encountered, the backup will fail.

During the backup, the current log file will be finished and a new log will be generated. This way, all of the necessary log files can be copies, because the current log will not be in use anymore.

It is strongly recommended that the backup not be used for any purpose other than the backup and restore at the engine level. This will minimize the chance of getting errors during the backup and restore operations.

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

Implemented as **JetBackupW** (Unicode) and **JetBackupA** (ANSI).

|

#### See Also

[Extensible Storage Engine Files](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-files)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JET_PFNSTATUS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-pfnstatus-callback-function)
[JetRestore](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrestore-function)
[JetRestore2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrestore2-function)
[JetRestoreInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrestoreinstance-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)