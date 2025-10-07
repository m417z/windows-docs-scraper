# JetTerm Function

_**Applies to:** Windows | Windows Server_

## JetTerm Function

The **JetTerm** function initiates the shutdown of an instance that has been initialized by [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function).

**JetTerm** can also be used to destroy an uninitialized instance that was created by [JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function).

```cpp
    JET_ERR JET_API JetTerm(
      __in          JET_INSTANCE instance
    );
```

### Parameters

*instance*

Specifies the instance to use for this call.

**Windows 2000:** This parameter is ignored and should always be **NULL**.

**Windows XP and later releases:** This parameter is overloaded. If the engine is operating in legacy mode (Windows 2000 compatibility mode) where only one instance is supported, then this parameter might be **NULL** or might contain the actual instance that is returned by [JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function). If the engine is operating in multi-instance mode, then this parameter must be a pointer to an instance that was created using [JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function).

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

One of the parameters that was provided contained an unexpected value, or the combination of several parameters yielded an unexpected result. This error will be returned by **JetTerm** when the engine is in multi-instance mode and when *pinstance* refers to an invalid instance.

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errNotInitialized

|

The operation cannot complete because the instance has not yet been initialized.

|
|

JET_errTermInProgress

|

The operation cannot complete because the instance is being shut down.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance.

|
|

JET_errBackupInProgress

|

The operation cannot complete because a backup operation is in progress on the instance.

|
|

JET_errTooManyActiveUsers

|

The instance cannot be shut down because there are currently sessions with active transactions for the specified instance. This error occurs only if the JET_bitTermComplete is used.

|

If this function succeeds, the specified instance will be shut down. The instance handle will also be closed and made unavailable to any API that takes an instance handle. All other objects that are associated with the instance, such as sessions, will also be closed. The state of the checkpoint file, transaction log files, and the database files attached to the instance will be modified during the shutdown process.

If this function fails as the result of a usage error, then the instance remains in an initialized state and nothing changes. Otherwise, the instance is still shut down as per the success case. The difference is that the instance will need to go through crash recovery when it is next initialized. The engine will try to flush as much data as possible to minimize the amount of recovery that is required. Conceptually, such a failure of **JetTerm** is no different than a process crash.

#### Remarks

If the host process of an instance quits for any reason before **JetTerm** is successfully called on that instance then the instance is considered to be in a crashed state. Crash recovery will occur on the next attempt to initialize that instance.

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

[Extensible Storage Engine Files](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-files)
[JetCreateInstance](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateinstance-function)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JetInit](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetinit-function)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JetTerm2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetterm2-function)