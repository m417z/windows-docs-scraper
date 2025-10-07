# JetSetSessionContext Function

_**Applies to:** Windows | Windows Server_

## JetSetSessionContext Function

The **JetSetSessionContext** function associates a session with the current thread using the given context handle. This association overrides the default engine requirement that a transaction for a given session must occur entirely on the same thread.

```cpp
    JET_ERR JET_API JetSetSessionContext(
      __in          JET_SESID sesid,
      __in          JET_API_PTR ulContext
    );
```

### Parameters

*sesid*

The session to use for this call.

*ulContext*

A unique identifier to which this session will be associated.

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

JET_errClientRequestToStopJetService

|

The operation cannot complete because all activity on the instance that is associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

The operation cannot complete because the instance that is associated with the session encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errInvalidParameter

|

One of the parameters that was provided contained an unexpected value, or the combination of several parameter values yielded an unexpected result. This error will be returned by **JetSetSessionContext** under the following conditions:

* *ulContext* is NULL
* *ulContext* is -1

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

JET_errSessionContextAlreadySet

|

The session could not be associated with the current thread because it has already been associated with a thread.

|
|

JET_errTermInProgress

|

The operation cannot complete because the instance that is associated with the session is being shut down.

|

If this function succeeds, the session will be associated with the current thread. No change to the database state will occur.

If this function fails, the session state will remain unchanged. No change to the database state will occur.

#### Remarks

A session is usually bound to a specific thread for the duration of a transaction. This behavior is designed to help applications detect and prevent the conceptually ill-advised sharing of a single session amongst multiple threads. Sometimes, this simple check does not work with the application's architecture. For example, if the application is hosting server-side objects using a thread pool and transactions span multiple server calls to a given object then this protection may cause some of those calls to fail with JET_errSessionSharingViolation even though the usage pattern is correct. This situation is common for COM object servers.

**JetSetSessionContext** and [JetResetSessionContext](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetresetsessioncontext-function) solve this problem by making this session sharing check a little more flexible. When the application starts to make a series of ESE API calls using a particular session, it first sets the session context to a given value. This action associates the session to the calling thread. In the given example, this context could be the address of the object that contains the JET session handle. Once the ESE API calls have been made, the application resets the session context. This action disassociates the session from the calling thread. The object and its session can then be used by another thread even if the session has an active transaction.

It is important to note that **JetSetSessionContext** must be called prior to opening a transaction on that session or the association will not work.

**JetSetSessionContext** is thread safe. Multiple threads can try to set a thread context on the same session at the same time and only one will win. This fact can be used by the application as a means to allocate a session from a pool without storing external state about its allocation.

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

[JET_API_PTR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-api-ptr)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JetResetSessionContext](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetresetsessioncontext-function)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)