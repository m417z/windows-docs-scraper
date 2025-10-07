# JetBeginExternalBackupInstance Function

_**Applies to:** Windows | Windows Server_

## JetBeginExternalBackupInstance Function

The **JetBeginExternalBackupInstance** function initiates an external backup while the engine and database are online and active.

**Windows XP: JetBeginExternalBackupInstance** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetBeginExternalBackupInstance(
      __in          JET_INSTANCE instance,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*instance*

The database instance to use for this call.

For Windows 2000, the API variant that accepts this parameter is not available because only one instance is supported. The use of this one global instance is implied in this case.

For Windows XP and later releases, the API variant that does not accept this parameter may only be called when the engine is in legacy mode (Windows 2000 compatibility mode) where only one instance is supported. Otherwise, the operation will fail with JET_errRunningInMultiInstanceMode.

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

The system may generate success or failure codes as a result of a call to this function. For a complete list of errors for this API, see [Extensible Storage Engine Error Codes](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-error-codes).

See [JetBeginExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackup-function).

#### Remarks

**JetBeginExternalBackupInstance** is the first function in a series of functions that must be called to execute a successful online (non-VSS based) backup. See also [JetBeginExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackup-function) and [JetStopBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopbackupinstance-function).

An external backup can be used to implement full, incremental, or differential backups.

The backup will be fuzzy, in that the backup will be consistent to a single point in time in the transaction history, but controlling the exact point in time is not possible at this time.

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
[JetBeginExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginexternalbackup-function)
[JetCloseFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosefile-function)
[JetEndExternalBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendexternalbackup-function)
[JetEndExternalBackupInstance2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendexternalbackupinstance2-function)
[JetGetAttachInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetattachinfo-function)
[JetGetLogInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetloginfo-function)
[JetOpenFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopenfile-function)
[JetReadFile](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfile-function)
[JetStopBackup](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopbackup-function)
[JetTruncateLog](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jettruncatelog-function)