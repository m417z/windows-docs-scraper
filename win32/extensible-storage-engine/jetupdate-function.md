# JetUpdate Function

_**Applies to:** Windows | Windows Server_

## JetUpdate Function

The **JetUpdate** function performs an update operation including inserting a new row into a table or updating an existing row. Deleting a table row is performed by calling [JetDelete](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdelete-function).

**JetUpdate** is the final step in performing an insert or an update. The update is begun by calling [JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetprepareupdate-function) and then by calling [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function) or [JetSetColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumns-function) one or more times to set the record state. Finally, **JetUpdate** is called to complete the update operation. Indexes are updated only by **JetUpdate** or [JetUpdate2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetupdate2-function), and not during [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function) or [JetSetColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumns-function).

```cpp
    JET_ERR JET_API JetUpdate(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __out_opt     void* pvBookmark,
      __in          unsigned long cbBookmark,
      __out_opt     unsigned long* pcbActual
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*pvBookmark*

Pointer to a returned bookmark for an inserted row.

*cbBookmark*

Size of the buffer pointed to by *pvBookmark*.

*pcbActual*

The returned size of the bookmark for the inserted row returned in *pvBookmark*.

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

JET_errBufferTooSmall

|

The given buffer for the record bookmark is not sufficiently large enough to store the record bookmark.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errColumnIllegalNull

|

Same as JET_errNullInvalid.

|
|

JET_errDiskFull

|

The update operation requires database file growth, or log file allocation, but the disk drive where the database file or log series resides is full. Alternatively, the database file is on a FAT32 formatted volume and the database file is already 4GBytes, the per file limit for FAT32.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidParameter

|

The given *prep* parameter in the [JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269339(v=exchg.10).md) function is not a valid flag.

|
|

JET_errKeyDuplicate

|

An index key for this record is a duplicate of another index key for another record already in the table and the index does not allow duplicates.

|
|

JET_errKeyTruncated

|

The inserted or updated record has one or more indices for which the generated key would have exceeded the maximum allowable size. As a result, the operation has failed to prevent key truncation.

|
|

JET_errMultiValuedIndexViolation

|

The inserted or updated record has an indexed multi-value column with two or more values that are identical within the maximum length key size set for the index. As a result, the record has two identical entries in the index which is invalid.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errNullInvalid

|

One or more columns in the record to be inserted or in the updated state of a record being replace is **NULL** which violates the defined constraint for those columns.

|
|

JET_errNullKeyDisallowed

|

One or more indexes are defined not to allow a **NULL** key and the inserted or updated state of a record being replaced violates this defined constraint.

|
|

JET_errRecordPrimaryChanged

|

A record replacement operation has updated the primary key. Updates to primary key columns must be done through deleting the existing record and inserting a new record with the desired data.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_errSessionSharingViolation

|

The same session cannot be used for more than one thread at the same time.

**Windows XP:** This error will only be returned by Windows XP and later releases.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|
|

JET_errTransReadOnly

|

It is illegal to attempt an update when inside the scope of a read only transaction. A read only transaction is a transaction that has been started using a call to [JetBeginTransaction2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269268(v=exchg.10).md) with JET_bitTransactionReadOnly.

**Windows XP:** This error will only be returned by Windows XP and later releases.

|
|

JET_errUpdateNotPrepared

|

[JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269339(v=exchg.10).md) was called with JET_prepCancel but the cursor was not in the prepared state.

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

On success, the open update operation on the cursor is completed. If an auto-increment column is defined for the table, then this value is set for inserted records. If a version column is defined for the table, then its value is initialized for newly inserted records, or incremented each time a record is replaced. All indexes, including clustered and non-clustered indexes are updated.

On failure, no changes of any kind are made to the database. Before insert and before replace callback functions may have been called, but after insert and after replace callbacks will not have been called, since the latter cannot cause an update to fail. The cursor copy buffer is left in its prepared state, so that the opportunity exists to incrementally correct the problems that caused errors and retry the update operation.

#### Remarks

Callback functions can be registered to be called before or after insert, and before or after update.

Record size limitations are enforced by [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function), and not in general by **JetUpdate**.

It is important to understand the impact of performing a large number of update operations inside of a single transaction. Each update to the database must be tracked by the database engine in the version store. The version store holds a live record of all the different versions of each record or index entry in the database that can be seen by all active transactions. These versions are used to support the multi-versioned concurrency control in use by the database engine to support transactions using snapshot isolation. Once the database engine has exhausted the resources used to store these versions then it can no longer accept further changes until some transactions have concluded to allow these resources to be reclaimed. When the engine is in this state, all updates will fail with JET_errVersionStoreOutOfMemory. The resources available to the database engine to store these versions can be controlled using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) with [JET_paramMaxVerPages](https://learn.microsoft.com/windows/win32/extensible-storage-engine/resource-parameters) and [JET_paramGlobalMinVerPages](https://learn.microsoft.com/windows/win32/extensible-storage-engine/resource-parameters).

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
[JetDelete](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdelete-function)
[JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetprepareupdate-function)
[JetRegisterCallback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetregistercallback-function)
[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function)
[JetRetrieveColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumns-function)
[JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function)
[JetSetColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumns-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)