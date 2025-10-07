# JetDupSession Function

_**Applies to:** Windows | Windows Server_

## JetDupSession Function

The **JetDupSession** function starts a session, and initializes and returns an ESE session handle ([JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)). Sessions control all access to the database and are used to control the scope of transactions. The session can be used to begin, commit, or abort transactions. The session is also used to attach, create, or open a database. The session is used as the context for all DDL and DML operations. To increase concurrency and parallel access to the database, multiple sessions can be begun.

**Note** This API will act in all ways as a [JetBeginSession](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginsession-function) called on the instance of the session passed in. This function is not recommended, [JetBeginSession](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginsession-function) is preferred.

```cpp
    JET_ERR JET_API JetDupSession(
      __in          JET_SESID sesid,
      __out         JET_SESID* psesid
    );
```

### Parameters

*sesid*

The session to use as the source for duplicating or beginning the session.

*psesid*

A pointer to the variable that the session handle initializes on successful return.

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

The number of sessions the engine will allow the client to start is limited. This value can be changed using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with the *JET_paramMaxSessions* constant. The default number of sessions is 16. See [System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294139(v=exchg.10).md) for details about *JET_paramMaxSessions*.

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

[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetBeginSession](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbeginsession-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)