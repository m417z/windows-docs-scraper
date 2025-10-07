# JetEscrowUpdate Function

_**Applies to:** Windows | Windows Server_

## JetEscrowUpdate Function

The **JetEscrowUpdate** function performs an atomic addition operation on one column. This function allows multiple sessions to update the same record concurrently without conflicts.

```cpp
    JET_ERR JET_API JetEscrowUpdate(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          JET_COLUMNID columnid,
      __in          void* pv,
      __in          unsigned long cbMax,
      __out_opt     void* pvOld,
      __in          unsigned long cbOldMax,
      __out_opt     unsigned long* pcbOldActual,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*columnid*

The *columnid* of the column to be updated.

*pv*

A pointer to a buffer containing the addend for the column.

*cbMax*

The size of the buffer containing the addend.

*pvOld*

The output buffer that will receive the current value of the column as stored in the database (versioning is ignored).

*cbOldMax*

The maximum size of the output buffer that will receive the current value of the column. Currently only JET_coltypLong is supported, so the buffer must either be 4 bytes or 0 bytes in length. If *pvOld* is NULL then *cbOldMax* should be 0.

*pcbOldActual*

Receives the actual amount of raw value data received in the output buffer.

*grbit*

A group of bits specifying zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitEscrowNoRollback

|

Even if the session performing the escrow update has its transaction rollback this update will not be undone. Note that as the log records may not be flushed to disk, recent escrow updates done with this flag may be lost if there is a crash.

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

JET_errAlreadyPrepared

|

The cursor has an update prepared with [JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269339(v=exchg.10).md).

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

JET_errInvalidBufferSize

|

An invalid buffer size has been passed in. Currently only JET_coltypLong is supported, so the buffer must be 4 bytes.

|
|

JET_errInvalidOperation

|

An invalid column has been specified. The column must be created with JET_bitColumnEscrowUpdate specified. Only fixed columns of JET_coltypLong can be specified as escrow updateable.

|
|

JET_errNoCurrentRecord

|

Cursor must be on a record in order to update a column.

|
|

JET_errNotInTransaction

|

Escrow updates can only be performed by sessions in a transaction.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errPermissionDenied

|

Cursor cannot be read only and update a record.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_errSessionSharingViolation

|

The same session cannot be used from more than one thread at the same time. This error will only be returned by Windows XP and later releases.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|
|

JET_errTransReadOnly

|

Session must have write permissions to update a record.

|
|

JET_errWriteConflict

|

The error returned when a conflicting update is requested.

|

#### Remarks

Normally, if two sessions attempt to update a record simultaneously, the second session will receive a JET_errWriteConflict error unless the sessions are completely serialized. To serialize two sessions that update the same record, the second session must start its transaction after the first transaction commits its transaction. See [JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction-function) for more information.

Multiple columns in the same record can be escrow updated. The updates do not affect each other.

Only **JetEscrowUpdate** operations are compatible with each other. If two different sessions try to prepare updates or delete the same record, a write conflict will be generated.

|||

Session B\
**JetEscrowUpdate**

|

[JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269339(v=exchg.10).md)

|

[JetDelete](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269315(v=exchg.10).md)

|
|---------|---------|--------------------------------------------------------|---------------------------------------------------------------|--------------------------------------------------------|
||

**JetEscrowUpdate**

|

JET_errSuccess

|

JET_errWriteConflict

|

JET_errWriteConflict

|
||

[JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269288(v=exchg.10).md)

|

JET_errWriteConflict

|

JET_errWriteConflict

|

JET_errWriteConflict

|
|

Session A

|

[JetDelete](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269315(v=exchg.10).md)

|

JET_errWriteConflict

|

JET_errWriteConflict

|

JET_errWriteConflict

|

Escrow operations are versioned and are undone using [JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function) (unless JET_bitEscrowNoRollback was specified). **JetEscrowUpdate** returns the raw value of the column stored in the database, because an application may want to perform a special action when a sentinel value is hit. [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function) returns the correctly versioned view of the column, ignoring updates made by concurrent sessions.

Given two sessions operating on the same column of the same record, we can see how this works. Assume the column starts with a value of 0.

|

Session

|

Operation

|

Stored value

|

Returned value

|
|----------------|------------------|---------------------|-----------------------|
|

A

|

[JetBeginTransation](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294083(v=exchg.10).md)

|||
|

A

|

[JetBeginTransation](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294083(v=exchg.10).md)

||

0

|
|

A

|

**JetEscrowUpdate** (4)

|

4

|

0

|
|

A

|

[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269198(v=exchg.10).md)

||

4

|
|

B

|

[JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294083(v=exchg.10).md)

|||
|

B

|

[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269198(v=exchg.10).md)

||

0

|
|

B

|

**JetEscrowUpdate** (3)

|

7

|

4

|
|

B

|

[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269198(v=exchg.10).md)

||

3

|
|

A

|

**JetEscrowUpdate** (2)

|

9

|

7

|
|

A

|

**JetEscrowUpdate** (-7)

|

2

|

9

|
|

B

|

[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269198(v=exchg.10).md)

||

3

|
|

A

|

[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269198(v=exchg.10).md)

||

-1

|
|

B

|

[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269273(v=exchg.10).md)

|

-1

||
|

A

|

[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269198(v=exchg.10).md)

||

-1

|

Replacing a record in the same transaction that performs escrow updates to a record is not recommended. In particular, if an update on a record is prepared with one [JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid) and a different [JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid) is used to escrow update the record then the escrow updated will be lost when [JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetupdate-function) is called. This happens even if the escrow column was not set during the update.

When an escrow updateable column has a value of zero, special behavior can be triggered. This behavior only happens if a **JetEscrowUpdate** operation causes the column to have a value of zero. The action does not happen immediately, but occurs sometime after the transaction which caused the column to have a value of zero commits. The column must still have a value of zero (that is, if no other sessions have modified the column). If the column was created with JET_bitColumnDeleteOnZero, the record containing the column will be deleted. If the column was created with JET_bitColumnFinalize then a callback will be issued. A crash may cause these actions not to happen, but online maintenance (using the [JetDefragment](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdefragment-function) function) will correctly redo the actions.

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

[JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetBeginTransaction](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetbegintransaction-function)
[JetDefragment](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdefragment-function)
[JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetprepareupdate-function)
[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function)
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)
[JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetupdate-function)