# JetBeginTransaction3 Function

_**Applies to:** Windows | Windows Server_

The **JetBeginTransaction3** function causes a session to enter a transaction and create a new save point. This function can be called more than once in a single session to create additional save points. These save points can be used to selectively to keep or discard changes to the database.

The **JetBeginTransaction3** function was introduced in the Windows 8 operating system.

``` c++
JET_ERR JET_API JetBeginTransaction3(
  __in          JET_SESID sesid,
  __in          int64 trxid,
  __in          JET_GRBIT grbit
);
```

### Parameters

*sesid*

The session to use for this call.

*trxid*

An optional identifier supplied by the user to identify the transaction.

*grbit*

A group of bits that specifies zero or more of the call option values listed in the following table.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitTransactionReadOnly

|

The transaction will not modify the database. If an update is attempted, that operation will fail with JET_errTransReadOnly response code. This option is ignored unless it is requested when the given session is not already in a transaction. This option is available in versions of the Windows operating system starting with Windows XP.

|

### Return value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) data type with one of the return codes listed in the following table. For more information about the possible Extensible Storage Engine (ESE) errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

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

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to the [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md) function.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

This return code is returned by versions of Windows starting with Windows XP.

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

The same session cannot be used for more than one thread at the same time. This error is returned by versions of Windows starting with Windows XP.

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

On success, the provided session will be inside a transaction. If the session was previously inside a transaction, a new save point will be created.

On failure, the transactional state of the session will remain unchanged. No change to the database state will occur.

#### Remarks

For more information about how transactions work, see [JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction-function).

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows 8.

|
|

**Server**

|

Requires Windows Server 2012.

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

#### See also

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