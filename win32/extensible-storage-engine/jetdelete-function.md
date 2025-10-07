# JetDelete Function

_**Applies to:** Windows | Windows Server_

## JetDelete Function

The **JetDelete** function deletes the current record in a database table.

```cpp
    JET_ERR JET_API JetDelete(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid
    );
```

### Parameters

*sesid*

The database session context that will be used for the API call.

*tableid*

The cursor on a database table. The current row will be deleted.

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

JET_errCallbackFailed

|

The callback function failed in some manner. For example, access violations in callback functions are caught and translated into JET_errCallbackFailed. This error will only be returned by Windows XP and later.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errIllegalOperation

|

The cursor specified by *tableid* does not support deletion. See the Remarks section.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

|
|

JET_errNoCurrentRecord

|

The cursor specified by *tableid* is not on a record.

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

JET_errPermissionDenied

|

The database engine does not have sufficient permissions to delete the record. This may happen if the database file was opened with read-only access.

|
|

JET_errRollbackError

|

An update buffer (see [JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269339(v=exchg.10).md)) exists, but not all of the changes made to columns of type JET_coltypLongText and/or columns of type JET_coltypLongBinary could be rolled back.

|
|

JET_errSessionSharingViolation

|

It is illegal to use the same session from more than one thread at the same time. This error will only be returned by Windows XP and later releases.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|
|

JET_errTransReadOnly

|

The transaction is a read-only transaction, and does not support deletes.

|
|

JET_errVersionStoreOutOfMemory

|

The operation failed because there is not enough memory to retain transactional information about the update.

|
|

JET_errWriteConflict

|

Another session has previously locked the record for update. The update attempted by this session will fail.

|

On success, the currency is left just before the next record. If the deleted record was the last in the table, the currency is left at the end of the table (that is, after the new last record). If the deleted record was the only record in the table, the currency is set to the beginning.

The appropriate indexes are automatically updated.

If an update is prepared (using [JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetprepareupdate-function)), it will be canceled. The update buffer will be reset.

On failure, the currency remains unchanged. If an update is prepared (see [JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetprepareupdate-function)), the update buffer may be reset.

#### Remarks

Not all tables support deletion of rows. A temporary table does not normally support deletion of rows. Deletion of records may be enabled on temporary tables for many reasons, some of which are:

  - JET_bitTTUpdatable was specified during creation.

  - Large temporary tables can support deletion if they were created with JET_bitTTScrollable or JET_bitTTIndexed. The threshold at which a temporary table becomes "large" is currently 64 kilobytes, but it may be changed in future releases.

Windows XP and later. Callback functions can be invoked by **JetDelete**, including JET_cbtypBeforeDelete and JET_cbtypAfterDelete.

It is important to understand the impact of performing a large number of update operations inside of a single transaction. Each update to the database must be tracked by the database engine in the version store. The version store holds a live record of all the different versions of each record or index entry in the database that can be seen by all active transactions. These versions are used to support the multi-versioned concurrency control in use by the database engine to support transactions using snapshot isolation. Once the database engine has exhausted the resources used to store these versions then it can no longer accept further changes until some transactions have concluded to allow these resources to be reclaimed. When the engine is in this state, all updates will fail with JET_errVersionStoreOutOfMemory. The resources available to the database engine to store these versions can be controlled using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) with *JET_paramMaxVerPages* and *JET_paramGlobalMinVerPages*.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista, Windows XP or Windows 2000 Professional.

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
[JetOpenTempTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentemptable-function)
[JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetprepareupdate-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)