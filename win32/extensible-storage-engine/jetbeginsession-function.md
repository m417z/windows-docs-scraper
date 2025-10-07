# JetBeginSession Function

_**Applies to:** Windows | Windows Server_

## JetBeginSession Function

The **JetBeginSession** function starts a session and initializes and returns an ESE session handle ([JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)). Sessions control all access to the database and are used to control the scope of transactions. The session can be used to begin, commit, or abort transactions. The session is also used to attach, create, or open a database. The session is used as the context for all DDL and DML operations. To increase concurrency and parallel access to the database, multiple sessions can be begun.

```cpp
    JET_ERR JET_API JetBeginSession(
      __in          JET_INSTANCE instance,
      __out         JET_SESID* psesid,
      __in_opt      JET_PCSTR szUserName,
      __in_opt      JET_PCSTR szPassword
    );
```

### Parameters

*instance*

The database instance to use for this call.

*psesid*

Pointer to the variable that the session handle initializes on successful return.

*szUserName*

This parameter is reserved.

*szPassword*

This parameter is reserved.

### Return Value

This function allows for the return of any [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)s that are defined in this API. For more information about Jet errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

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

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errOutOfMemory

|

The operation failed because memory could not be allocated.

|
|

JET_errOutOfSessions

|

The number of sessions the engine will allow the client to start is limited. This value can be changed using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with the JET_paramMaxSessions constant. The default number of sessions is 16. See [System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294139(v=exchg.10).md) for details about JET_paramMaxSessions.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|

On success, the session handle is initialized, and may be used for database operations.

On failure, there are no available sessions or a new session was unable to be initialized.

#### Remarks

Careful attention must be used when using sessions across different threads. A session tracks which thread it was used on during [JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction-function), [JetCommitTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcommittransaction-function), or [JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function), and it will throw an error if used on multiple threads with an open transaction. The [JetResetSessionContext](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetresetsessioncontext-function), [JetSetSessionContext](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsessioncontext-function) can change this behavior. Since the session is still a serialized context, and multiple database operations cannot be performed on a single session concurrently, only serially. However, you can use multiple sessions to achieve concurrent database access. Sessions can be used inside a transaction across threads by setting and resetting the session contexts.

The session handle should be closed with [JetEndSession](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendsession-function).

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

Implemented as **JetBeginSessionW** (Unicode) and **JetBeginSessionA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_INSTANCE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-instance)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction-function)
[JetCommitTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcommittransaction-function)
[JetDupSession](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupsession-function)
[JetEndSession](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetendsession-function)
[JetResetSessionContext](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetresetsessioncontext-function)
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)
[JetSetSessionContext](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsessioncontext-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)