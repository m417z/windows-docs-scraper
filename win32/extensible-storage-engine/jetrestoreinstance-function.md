# JetRestoreInstance Function

_**Applies to:** Windows | Windows Server_

## JetRestoreInstance Function

The **JetRestoreInstance** function restores and recovers a streaming backup of an instance including all the attached databases. It is designed to work with a backup created with the [JetBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbackupinstance-function) function. This is the simplest and most encapsulated one restore function.

**Windows XP:** **JetRestoreInstance** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetRestoreInstance(
      __in          JET_INSTANCE instance,
      __in          JET_PCSTR sz,
      __in_opt      JET_PCSTR szDest,
      __in          JET_PFNSTATUS pfn
    );
```

### Parameters

*instance*

Specifies the instance to use for this call.

For Windows XP and later releases, the use of this parameter depends on the operating mode of the engine. If the engine is operating in legacy mode (Windows 2000 compatibility mode) where only one instance is supported then this parameter may either be NULL or it may be set to a valid output buffer containing NULL or JET_instanceNil that will return the global instance handle created as a side effect of the initialization. This instance handle can then be passed to any other API that takes an instance. If the engine is operating in multi-instance mode then this parameter must be set to a valid input buffer that contains the instance handle returned by [JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function) that is being initialized.

*sz*

The folder where the backup is located. The backup should have been generated using the [JetBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbackup-function) APIs.

*szDest*

Name of the folder where the database files from the backup set will be copied and recovered. If this is set to NULL (which is the case for the legacy [JetRestore](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrestore-function)), the database files will be copied and recovered to their original location.

*pfn*

The optional pointer to the function which will be called as notification information about the progress of the restore operation.

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

JET_errAlreadyInitialized

|

The operation failed because the engine is already initialized for this instance.

|
|

JET_errInvalidLogSequence

|

The set of log files from the backup set and from the current log path do not match.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This error will be returned by **JetRestoreInstance** when the engine is in multi-instance mode and pinstance refers to an invalid instance Windows XP and later releases.

|
|

JET_errInvalidPath

|

The operation failed because some of paths provided are invalid (the backup path, the destination path, the log or system path for the instance).

|
|

JET_errPageSizeMismatch

|

The operation failed because the engine is configured to use a database page size (using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) for [JET_paramDatabasePageSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269337(v=exchg.10).md)) that does not match the database page size used to create the transaction log files or the databases associated with the transaction log files.

|
|

JET_errRunningInMultiInstanceMode

|

The operation failed because the parameters implied single instance mode (Windows 2000 compatibility mode) and the engine is already in multi-instance mode.

|

On success, database files from the backup set will be restored over to their location and recovery will be run such that the databases will be in a clean transactional consistency state. Recovery will replay the log files from the backup set and the log files from the log path if such files do exists. This recovery will result in changes to the checkpoint file, the transaction log files, and any databases referenced by those transaction log files.

On failure, the instance remains in an uninitialized state. The state of the transaction log files and any databases referenced by those transaction log files will likely have been changed in the attempt to initialize the restore and recover the databases.

#### Remarks

The recovery process will reconstruct the databases attached to the instance during the backup and save the changes back to the database files. The result will be databases that are transaction consistent. If possible, it will also save to the database the changes done since the backup was taken until the most recent change found in the transaction logs. This would be possible if the transaction logs generated since the backup was taken are still present in the transaction log directory. Note that if circular logging was enabled for the instance, the transaction logs generated are reused such that the recovery will be able to save the changes which took place up to the backup moment. In any case, it is possible for this process to take quite some time if the number of transaction log files to replay against the databases is large.

**JetRestoreInstance** must be called on an instance which was already created using [JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function).

Because during recovery a significant number of database pages and transaction logs will be used, there is an entire series of error which might be returned by these functions. Such errors can be from temporary resource allocation failures like Jet_errOutOfMemory to errors representing physical corruptions like JET_errReadVerifyFailure, JET_errLogFileCorrupt or JET_errBadPageLink. These errors are almost always caused by hardware problems and thus cannot be avoided. File mismanagement will manifest itself most often as JET_errMissingLogFile or JET_errAttachedDatabaseMismatch or JET_errDatabaseSharingViolation or JET_errInvalidLogSequence. These errors are preventable by the application. The application must be careful to protect the repository of these files from manipulation by outside forces such as the user or other applications. If the application desires to destroy an instance entirely then all the files associated with the instance must be deleted. These include the checkpoint file, the transaction log files, and any database files attached to the instance.

The different steps of the recovery will have Event Log entries generated including the transaction log replay progress and the final result of the restore.

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

Implemented as **JetRestoreInstanceW** (Unicode) and **JetRestoreInstanceA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbackup-function)
[JetBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbackupinstance-function)
[JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)