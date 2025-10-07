# JetStopBackupInstance Function

_**Applies to:** Windows | Windows Server_

## JetStopBackupInstance Function

The **JetStopBackupInstance** function prevents streaming backup-related activity from continuing on a specific running instance, thus ending the streaming backup in a predictable way.

**Windows XP:** **JetStopBackupInstance** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetStopBackupInstance(
      __in          JET_INSTANCE instance
    );
```

### Parameters

*instance*

Identifies the running instance to use for the API call.

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

The specified instance parameter has an invalid value (not an instance that is currently running).

**Windows XP:** This return value is introduced in Windows XP.

|

If this function succeeds, the instance that was specified will start failing any new streaming backup APIs.

If this function fails, no steps to prepare for the backup termination on the instance will be taken and no change to the instance state will occur.

#### Remarks

Backup is usually triggered by an event outside the process mechanism and by using this API, the ESENT application itself will make any further calls to the streaming backup APIs to fail. The majority of streaming backup APIs will start failing with JET_errBackupAbortByServer. As such, any streaming backup progress (such as [JetReadFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfileinstance-function)) will return an error. Backup operations which are part of the backup termination (like [JetEndExternalBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendexternalbackupinstance-function)) will still be allowed.

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

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetEndExternalBackupInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendexternalbackupinstance-function)
[JetReadFileInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetreadfileinstance-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)