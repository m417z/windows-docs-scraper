# JetBeginTransaction2 Function

_**Applies to:** Windows | Windows Server_

## JetBeginTransaction2 Function

The **JetBeginTransaction2** function causes a session to enter a transaction and create a new save point. This function can be called more than once in a single session to create additional save points. These save points can be used to selectively to keep or discard changes to the database.

```cpp
    JET_ERR JET_API JetBeginTransaction2(
      __in          JET_SESID sesid,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*grbit*

A group of bits that contain the options to be used for this call, which include zero or more of the following.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitTransactionReadOnly

|

The transaction will not modify the database. If an update is attempted, that operation will fail with JET_errTransReadOnly. This option is ignored unless it is requested when the given session is not already in a transaction. This option is only available as of Windows XP.

|

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

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_errSessionSharingViolation

|

The same session cannot be used for more than one thread at the same time. This error will only be returned by Windows XP and later releases.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|
|

JET_errTransTooDeep

|

A new transaction cannot be started because the session is already at the maximum save point depth allowable by the database engine.

|

On success, the provided session will be inside a transaction. If the session was previously inside of a transaction then a new save point will be created.

On failure, the transactional state of the session will remain unchanged. No change to the database state will occur.

#### Remarks

For more information about how transactions work, see [JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction-function).

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
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction-function)
[JetCommitTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcommittransaction-function)
[JetGetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetsystemparameter-function)
[JetResetSessionContext](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetresetsessioncontext-function)
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)
[JetSetSessionContext](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsessioncontext-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)