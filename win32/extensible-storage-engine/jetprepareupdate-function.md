# JetPrepareUpdate Function

_**Applies to:** Windows | Windows Server_

## JetPrepareUpdate Function

The **JetPrepareUpdate** function is the first operation in performing an update, for the purposes of inserting a new record or replacing an existing record with new values. Updates are done by calling **JetPrepareUpdate**, then calling [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function) or [JetSetColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumns-function) zero or more times and finally by calling [JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetupdate-function) to complete the operation. **JetPrepareUpdate** and [JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetupdate-function) set the boundaries for an update operation and are important in having only the final update state of a record entered into indexes. This is both more efficient, but also required in cases where data must match a valid state through more than on set column operation.

There are a few different options for inserting or replacing records and they are described in more detail below.

```cpp
    JET_ERR JET_API JetPrepareUpdate(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          unsigned long prep
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*prep*

The options that can be used to prepare for an update, which include the following.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_prepCancel

|

This flag causes **JetPrepareUpdate** to cancel the update for this cursor.

|
|

JET_prepInsert

|

This flag causes the cursor to prepare for an insert of a new record. All the data is initialized to the default state for the record. If the table has an auto-increment column, then a new value is assigned to this record regardless of whether the update ultimately succeeds, fails or is cancelled.

|
|

JET_prepInsertCopy

|

This flag causes the cursor to prepare for an insert of a copy of the existing record. There must be a current record if this option is used. The initial state of the new record is copied from the current record. Long values that are stored off-record are virtually copied.

|
|

JET_prepInsertCopyDeleteOriginal

|

This flag causes the cursor to prepare for an insert of the same record, and a delete or the original record. It is used in cases in which the primary key has changed.

|
|

JET_prepReplace

|

This flag causes the cursor to prepare for a replace of the current record. If the table has a version column, then the version column is set to the next value in its sequence. If this update does not complete, then the version value in the record will be unaffected. An update lock is taken on the record to prevent other sessions from updating this record before this session completes.

|
|

JET_prepReplaceNoLock

|

This flag is similar to JET_prepReplace, but no lock is taken to prevent other sessions from updating this record. Instead, this session may receive JET_errWriteConflict when it calls [JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269288(v=exchg.10).md) to complete the update.

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

**JetPrepareUpdate** was called with a valid flag for prep but not JET_prepCancel and the cursor was already in the prepared state.

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

The given prep flag is not a valid flag.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errNotInTransaction

|

**JetPrepareUpdate** was called to replace a record which had SLV columns. SLV columns. Please note that SLV columns are a feature not intended for general usage. This feature is used to support the Microsoft Exchange infrastructure and is not intended to be used in your application.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_errRollbackError

|

**JetPrepareUpdate** was called with JET_prepCancel but could not rollback all of the changes made to columns of type JET_coltypLongText and/or columns of type JET_coltypLongBinary.

|
|

JET_errSessionSharingViolation

|

This flag cannot be used with the same session from more than one thread at the same time. This error will only be returned by Windows XP and later releases.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|
|

JET_errUpdateNotPrepared

|

**JetPrepareUpdate** was called with JET_prepCancel but the cursor was not in the prepared state.

|

On success, the cursor is changed to the prepared state for the purpose of the desired update, or in the case of JET_prepCancel, the cursor is reverted to the non-prepared state and any changes are discarded.

On failure, the cursor state is left unchanged. If the failure was JET_errRollbackError then the cursor state is changed to the non-prepared state but not all of the changes have been reverted.

#### Remarks

Inserting a copy of a record is an important optimization when records share data of type JET_coltypLongText and/or JET_coltypLongBinary. This data is stored off-record when large and it is possible for multiple records to share the same physical representation of the data. In this case, the data can be updated from either record, but doing so will cause the data to be burst such that each record has its own copy. It is not possible to change data in one record by a modification from another record. Also, it is not possible to block an update of one record by an update of another record. This is a central feature to ESE and is known as Record Level Locking.

[JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetupdate-function) operations which fail leave the cursor in the update prepared state. This is to permit correction to some errors, such as a wrong column value, without requiring the update state to be recreated. This means that in all cases where a cursor abandons an update, it must explicitly call **JetPrepareUpdate** with JET_prepCancel.

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
[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function)
[JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function)
[JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetupdate-function)