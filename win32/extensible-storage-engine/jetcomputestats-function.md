# JetComputeStats Function

_**Applies to:** Windows | Windows Server_

## JetComputeStats Function

The **JetComputeStats** function walks each index of a table to exactly compute the number of entries in an index, and the number of distinct keys in an index. This information, together with the number of database pages allocated for an index and the current time of the computation is stored in index metadata in the database. This data can be subsequently retrieved with information operations.

```cpp
    JET_ERR JET_API JetComputeStats(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor that will be used for this call. Describes the table to compute statistics on.

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

JET_errRollbackError

|

An error occurred requiring this operation to rollback all changes, but the transaction rollback itself failed.

|
|

JET_errSessionSharingViolation

|

The same session cannot be used for more than one thread at the same time.

This error will only be returned by Windows XP and later releases.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|

On success, up-to-date statistics are stored in the database catalogs for the table described with the given cursor.

On failure, no updates of any kind are made to the database.

#### Remarks

This operation can be resource consuming since each index in a table must be walked in its entirety. [JetGetRecordPosition](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetrecordposition-function) can be used to get a rough estimate of the number of entries in an index, but it cannot by itself estimate the number of distinct values in an index.

The data computed by this operation begins to become out of date and the table is subsequently updated.

Updates to the database made by **JetComputeStats** are made in a lazy fashion. This means that no log flush will be accompanied by this operation and a system crash subsequent to a return of JET_errSuccess by **JetComputeStats** can still cause these updates to be lost.

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
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetGetRecordPosition](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetrecordposition-function)
[JetGetTableInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableinfo-function)
[JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)