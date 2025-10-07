# JetStopBackup Function

_**Applies to:** Windows | Windows Server_

## JetStopBackup Function

The **JetStopBackup** function prevents any streaming backup-related activity from continuing on a specific running instance, thus ending the streaming backup in a predictable way.

**Windows XP:** This function is introduced in Windows XP.

[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function) is the legacy call when only one instance is allowed. In this case, the only active instance is the one being prepared for termination.

```cpp
JET_ERR JET_API JetStopBackup(void);
```

### Parameters

This function has no parameters.

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

JET_errRunningInMultiInstanceMode

|

It is not clear which instance to prepare for termination when using [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md) with multiple instance mode.

**Windows XP:** This return value is introduced in Windows XP.

|

If this function succeeds, the instance will start failing any new streaming backup APIs.

If this function fails, no steps to prepare for the backup termination on the instance will be taken and no change to the instance state will occur.

#### Remarks

Backup is usually triggered by an event outside the process mechanism and by using this API, the ESENT application itself will make any further calls to the streaming backup APIs to fail. The majority of streaming backup APIs will start failing with JET_errBackupAbortByServer. As such, any streaming backup progress (like [JetReadFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfileinstance-function)) will return an error. Backup operations which are part of the backup termination (such as [JetEndExternalBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendexternalbackupinstance-function)) will still be allowed.

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

[JetEndExternalBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendexternalbackupinstance-function)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetReadFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfileinstance-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)