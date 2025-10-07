# JetOpenFileInstance Function

_**Applies to:** Windows | Windows Server_

## JetOpenFileInstance Function

The **JetOpenFileInstance** function opens an attached database, database patch file, or transaction log file of an active instance for the purpose of performing a streaming fuzzy backup. The data from these files can subsequently be read through the returned handle using [JetReadFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfileinstance-function). The returned handle must be closed using [JetCloseFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosefileinstance-function). An external backup of the instance must have been previously initiated using [JetBeginExternalBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackupinstance-function).

**Windows XP:** **JetOpenFileInstance** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetOpenFileInstance(
      __in          JET_INSTANCE instance,
      __in          JET_PCSTR szFileName,
      __out         JET_HANDLE* phfFile,
      __out         unsigned long* pulFileSizeLow,
      __out         unsigned long* pulFileSizeHigh
    );
```

### Parameters

*instance*

The instance to use for this call.

For Windows 2000, the API variant that accepts this parameter is not available because only one instance is supported. The use of this one global instance is implied in this case.

For Windows XP and later releases, the API variant that does not accept this parameter may only be called when the engine is in legacy mode (Windows 2000 compatibility mode) where only one instance is supported. Otherwise, the operation will fail with JET_errRunningInMultiInstanceMode.

*szFileName*

The relative or absolute path to an attached database, database patch file, or transaction log file managed by the instance that is read for backup.

*phfFile*

Pointer to the output buffer that receives a handle to the file to be read.

*pulFileSizeLow*

Pointer to the output buffer that receives the least significant 32 bits of the size of the file.

*pulFileSizeHigh*

Pointer to the output buffer that receives the most significant 32 bits of the size of the file.

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

JET_errFileAccessDenied

|

The operation failed because it could not open the requested file due to a sharing violation or insufficient privileges.

|
|

JET_errFileNotFound

|

The operation failed because it could not open the requested file because it could not be found at the specified path. This error will only be returned by Windows 2000.

|
|

JET_errInvalidBackupSequence

|

The backup operation failed because it was called out of sequence.

|
|

JET_errInvalidPath

|

The operation failed because the specified path could not be found.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This can happen for **JetOpenFileInstance** when:

* The specified instance handle is invalid (Windows XP and later releases).
* The specified filename parameter is NULL or a zero length string (Windows XP and later releases).

|
|

JET_errMissingFileToBackup

|

The requested file could not be opened for backup because it could not be found. This error will only be returned by Windows XP and later releases.

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

JET_errOutOfMemory

|

The operation failed because not enough memory could be allocated to complete it. **JetOpenFileInstance** will return JET_errOutOfMemory if an attempt is made to open another file before the previous file opened using **JetOpenFileInstance** has been closed by [JetCloseFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269270(v=exchg.10).md). Only one outstanding file handle is currently supported.

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

On success, a handle to the requested file is returned. If the handle is for a database file, that database file will be prepared for a streaming backup which may result in the creation of a database patch file in the same location as the database file. The database patch file has the exact same path and filename as the database file but with a .PAT extension. The size of the file will also be returned.

On failure, the state of the output buffers will be undefined. A database patch file may be temporarily created on disk and any existing file at the patch file location may be deleted. The failure will result in the cancellation of the entire backup process for the instance. On Windows XP and later releases, the backup will not be canceled if an attempt was made to backup a database that was not attached to the instance at the time of the call.

**Warning** For security reasons, it is important to note that **JetOpenFileInstance** does not verify that the requested file path is associated with the set of files that are backed up for the instance. As a result, it is possible to use this function to access any file that can be opened by the current security context of the thread. It is imperative that the application restrict the paths passed to this function to a known set of good file paths or a disclosure of information attack could be made possible.

#### Remarks

The handle and file size output buffers are required to be present. If they are not present then the engine will crash because the output buffer parameters are not validated.

At this time, only one file can be open for backup at any one time.

**JetOpenFileInstance** does not assert the backup privilege prior to opening the requested file.

The size of the file to be read as reported by this function may not match the size of the file on disk. On Windows XP and later releases, extra information may be appended to a database file which is used by the database engine during a restore operation. As such, the application should only rely on the file size returned by **JetOpenFileInstance** or on the actual number of bytes of data returned by [JetReadFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfileinstance-function).

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

Implemented as **JetOpenFileInstanceW** (Unicode) and **JetOpenFileInstanceA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_HANDLE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-handle)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetAttachDatabase](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetattachdatabase-function)
[JetBeginExternalBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackupinstance-function)
[JetCloseFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosefileinstance-function)
[JetGetAttachInfoInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetattachinfoinstance-function)
[JetGetLogInfoInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetloginfoinstance-function)
[JetReadFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfileinstance-function)
[JetStopBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopbackupinstance-function)
[JetTruncateLogInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jettruncateloginstance-function)