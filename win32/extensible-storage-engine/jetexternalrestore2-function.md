# JetExternalRestore2 Function

_**Applies to:** Windows | Windows Server_

## JetExternalRestore2 Function

The **JetExternalRestore2** function restores an external backup that was taken with the external backup APIs and provides checkpoints to use for circular logging operations. This is known as hard recovery, which is similar but different than soft recovery as performed by the [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function) function.

**Windows XP: JetExternalRestore2** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetExternalRestore2(
      __in          JET_PSTR szCheckpointFilePath,
      __in          JET_PSTR szLogPath,
      __in_opt      JET_RSTMAP* rgrstmap,
      __in          long crstfilemap,
      __in          JET_PSTR szBackupLogPath,
      __in_out      JET_LOGINFO* pLogInfo,
      __in_opt      JET_PSTR szTargetInstanceName,
      __in_opt      JET_PSTR szTargetInstanceLogPath,
      __in_opt      JET_PSTR szTargetInstanceCheckpointPath,
      __in          JET_PFNSTATUS pfn
    );
```

### Parameters

*szCheckpointFilePath*

The path for the checkpoint file to use during recovery if *szTargetInstanceCheckpointPath* is not specified or that path has an active or running instance.

*szLogPath*

The path or directory for the logs for the final phase (undo) of the recovery and possibly for the roll forward logs. This path may be the same as the *szBackupLogPath*.

*rgrstmap*

This is an array of [JET_RSTMAP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-rstmap-structure) structures. This is a map of old and new database paths or filenames. This is used because the databases may need to be recovered to a location other than the location they were backed up from. In the case where multiple databases are attached to a single logging set, the restore map can specify a subset of the databases to restore.

*crstfilemap*

The number of entries in the *rgrstmap* array parameter.

*szBackupLogPath*

The path to the directory where the log files are restored. These are the logs that were read off during the external backup sequence. This path may be the same as the *szLogPath*.

*pLogInfo*

The *pLogInfo* describes several aspects of the backup logs to recovery, this parameter allows **JetExternalRestore2** to take the explicit *genLow* and *genHigh* parameters that **JetExternalRestore2** has, as well as the base log name, instead of a presumed log base name of "edb".

*szTargetInstanceName*

This parameter is deprecated and cannot be used in your application.

*szTargetInstanceLogPath*

The path for the roll forward logs if the location of the logs you would like to roll forward are in an active logging set or instance. This should not be specified if the target instance is using circular logging.

*szTargetInstanceCheckpointPath*

The path for the checkpoint during recovery if there is no active instance running at this target. This should not be specified if the target instance is using circular logging.

*pfn*

The status callback, which reports the progress of the recovery.

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

JET_errBadRestoreTargetInstance

|

The *szTargetInstanceLogPath* specified does not belong to an initialized instance. This error will only be returned in Windows XP and later.

|
|

JET_errDatabaseCorrupted

|

This indicates the database was corrupted, or an unrecognized file.

|
|

JET_errEndingRestoreLogTooLow

|

This error is returned if one for the log files in the *szBackupLogPath*, has a log generation above that specified in *genHigh* or *pLogInfo.ulGenHigh*.

|
|

JET_errFileNotFound

|

The operation failed because it could not open the requested file because it could not be found at the specified path.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This can happen for [JetExternalRestore](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294088(v=exchg.10).md), and so on when the *szTargetCheckpointPath* and the *szTargetInstanceLogPath* are either not both specified or not both unspecified. That is, they must match, and be both specified or both unspecified.

|
|

JET_errInvalidPath

|

The operation failed because the specified path could not be found.

|
|

JET_errOutOfMemory

|

The operation failed because not enough memory could be allocated to complete it.

|
|

JET_errRestoreOfNonBackupDatabase

|

This error is returned if the database file specified during restore is not a database that was backed up with external backup.

|
|

JET_errRunningInOneInstanceMode

|

The database engine cannot run external restore or hard recovery in single instance mode. This error will only be returned in Windows XP and later.

|
|

JET_errStartingRestoreLogTooHigh

|

This error is returned if one of the log files in the *szBackupLogPath*, has a log generation below that specified by the *genLow* or *pLogInfo.ulGenLow*.

|

On success, all databases from the *rgrstmap* are completely recovered and in a clean or consistent state. At this point the database can be remounted to an existing instance.

On failure, the engine could not recover the database. The database is in an invalid state, and in order to retry hard recovery the entire database must be restored again. Typically, the source of such a situation is disk or log corruption, or some other form of log mismanagement, or a non-continuous log set.

#### Remarks

See [JetExternalRestore](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetexternalrestore-function).

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

Implemented as **JetExternalRestore2W** (Unicode) and **JetExternalRestore2A** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_LOGINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-loginfo-structure)
[JET_PFNSTATUS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-pfnstatus-callback-function)
[JET_RSTMAP](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-rstmap-structure)
[JetBeginExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackup-function)
[JetExternalRestore](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetexternalrestore-function)
[JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function)