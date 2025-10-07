# JetGetCursorInfo Function

_**Applies to:** Windows | Windows Server_

## JetGetCursorInfo Function

The **JetGetCursorInfo** function is used to determine whether an update of the current record of a cursor will result in a write conflict, based on the current update status of the record. It is possible that a write conflict will ultimately be returned even if **JetGetCursorInfo** returns JET_errSuccess, because another session may update the record before the current session is able to update the same record.

```cpp
    JET_ERR JET_API JetGetCursorInfo(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __out         void* pvResult,
      __in          unsigned long cbMax,
      __in          unsigned long InfoLevel
    );
```

### Parameters

*sesid*

The session that will be used for this call.

*tableid*

The cursor that will be used for this call.

*pvResult*

Reserved for future use.

*cbMax*

Must be set to 0 (zero), otherwise unused. It is present for future functionality.

*InfoLevel*

Must be set to 0 (zero), otherwise unused. It is present for future functionality.

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

JET_errInvalidParameter

|

Either *cbMax* is not 0 (zero) or *InfoLevel* is not 0 (zero).

|
|

JET_errNoCurrentRecord

|

The cursor is not currently on a record and information on a logical record cannot be returned as a result.

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

JET_errWriteConflict

|

The current record of the cursor has been updated by another session and an update of this record by this session will result in a write conflict.

|

On success, this operation has no effect on the location of the cursor but only indicates that no other session has currently updated this record.

On failure, if a negative error code is returned there are no effects to the cursor or the database.

#### Remarks

This operation does not affect the state of the cursor or the data. It only returns an error code describing whether an update to the current record by the calling session is known to result in a JET_errWriteConflict, or is unknown to return JET_errWriteConflict. If another session has already updated this record to use it is certain that an update of this record by this session will result in a write conflict. This will be true until this session commits or rolls back its transactions to transaction level 0 (zero). However, if **JetGetCursorInfo** returns JET_errSuccess, it is still possible for another session to update this record before the current session and thus it is still possible that an update of the current record by this session in its current transaction will result in a write conflict.

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
[JetGetLock](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetlock-function)
[JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetprepareupdate-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)
[JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetupdate-function)