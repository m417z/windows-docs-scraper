# JetGetLock Function

_**Applies to:** Windows | Windows Server_

## JetGetLock Function

The **JetGetLock** function provides a means to explicitly reserve the ability to update a row, write lock, or to explicitly prevent a row from being updated by any other session, read lock. Normally, row write locks are acquired implicitly as a result of updating rows. Read locks are usually not required because of record versioning. However, in some cases a transaction may desire to explicitly lock a row to enforce serialization, or to ensure that a subsequent operation will succeed by virtue that required locks have already been taken.

```cpp
JET_ERR JET_API JetGetLock(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid,
  __in          JET_GRBIT grbit
);
```

### Parameters

*sesid*

The session that will be used for this call.

*tableid*

The cursor that will be used for this call.

*grbit*

A group of bits that contain the options to be used for this call, which include zero or more of the following:

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitReadLock

|

This flag causes a read lock to be acquired on the current record. Read locks are incompatible with write locks already held by other sessions but are compatible with read locks held by other sessions.

|
|

JET_bitWriteLock

|

This flag causes a write lock to be acquired on the current record. Write locks are not compatible with write or read locks held by other sessions but are compatible with read locks held by the same session.

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

JET_errInvalidgrbit

|

The given *grbit* is neither JET_bitReadLock or JET_bitWriteLock. It must be one of these two flags.

|
|

JET_errNoCurrentRecord

|

Cursor must be on a record in order to acquire a lock. Locks are always on records.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errNotInTransaction

|

Locks can only be acquired by sessions in a transaction.

|
|

JET_errPermissionDenied

|

Cursor cannot be read only and acquire a write lock.

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

JET_errTransReadOnly

|

Session must have write permissions to acquire write lock.

|
|

JET_errWriteConflict

|

The error returned when a conflicting lock is requested.

|

On success, session has acquired requested lock.

On failure, session has not acquired requested lock.

#### Remarks

Write locks cannot be acquired with sessions or cursors that have read-only permissions, even if the session and cursor ultimately do not perform an update operation. Both the session and the cursor must have write privileges in order to acquire a write lock.

Read and write locks are a means of pessimistic locking. Pessimistic locking expects multiple concurrent sessions to conflict and acquire locks in advance to ensure that their operations succeed.

Most operations will be serializable by virtue of locks implicitly taken. However, some operations will not. To illustrate this, consider the two transactions,

T1 : R(A), U(B)

T2 : R(B), U(A)

Record level versioning will ensure that each transaction when executed concurrently will see the original values for A and B. There is no serial order of execution that could produce the same results for A and B in the case that the results are dependent upon the data read. In order for the application to make this transaction serializable, it should acquire an explicit read lock on A and B in each transaction when the value is read.

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
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetprepareupdate-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)
[JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetupdate-function)