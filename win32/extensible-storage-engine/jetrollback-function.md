# JetRollback Function

_**Applies to:** Windows | Windows Server_

## JetRollback Function

The **JetRollback** function undoes the changes made to the state of the database and returns to the last save point. **JetRollback** will also close any cursors opened during the save point. If the outermost save point is undone, the session will exit the transaction.

```cpp
    JET_ERR JET_API JetRollback(
      __in          JET_SESID sesid,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*grbit*

A group of bits that contain the options to be used for this call, which include zero or more of the following:

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitRollbackAll

|

This option requests that all changes made to the state of the database during all save points be undone. As a result, the session will exit the transaction.

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

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errNotInTransaction

|

The operation failed because the given session is not in a transaction.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_errRollbackError

|

It was not possible to rollback the changes due to a fatal error.

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

On success, any changes made to the database during the current save point for the given session will be undone and that save point will be ended. If the last save point for the session was ended then the session will exit the transaction.

On failure, the transactional state of the session will remain unchanged. No change to the database state will occur. A failure during rollback is considered to be a catastrophic database error.

#### Remarks

There must be one call to [JetCommitTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcommittransaction-function) or **JetRollback** to match every call to [JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction-function) for a given session.

If any cursors were opened (using [JetOpenTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentable-function), for example) during a save point that is being rolled back then that cursor will be closed.

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