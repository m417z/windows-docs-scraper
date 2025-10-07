# JetGetRecordPosition Function

_**Applies to:** Windows | Windows Server_

## JetGetRecordPosition Function

The **JetGetRecordPosition** function returns the fractional position of the current record in the current index in the form of a [JET_RECPOS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-recpos-structure) structure. This structure describes fractional positions in terms of an approximate number of index entries before the current record and an approximate total number of entries in the index.

```cpp
    JET_ERR JET_API JetGetRecordPosition(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __out         JET_RECPOS* precpos,
      __in          unsigned long cbRecpos
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*precpos*

The description of the fraction to use in getting the position of the current record in the current index.

*cbRecpos*

The size of memory allocated at *precpos*.

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

JET_errNotInitialized

|

It is not possible to complete the operation because the instance that is associated with the session has not been initialized yet.

|
|

JET_errClientRequestToStopJetService

|

The operation cannot complete because all activity on the instance that is associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

This operation cannot complete because the instance, associated with the session, encountered a fatal error. It is required that access to all data be revoked in order to protect the integrity of that data.

**Windows 2000:** This error will not be returned by the Windows 2000 operating system.

|
|

JET_errInvalidParameter

|

The size of the allocated memory at *precpos* is not a sufficient size.

|
|

JET_errNoCurrentRecord

|

The cursor is not currently on a record and cannot return a position.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance that is associated with the session.

|
|

JET_errSessionSharingViolation

|

The same session cannot be used for more than one thread at the same time.

**Windows 2000:** This error will not be returned by the Windows 2000 operating system.

|
|

JET_errTermInProgress

|

The operation cannot complete because the instance associated with the session is being shut down.

|

On success, the approximate number of index entries preceding the current record in the index are returned in precpos-\>centriesLT. 1 is returned in precpos-\>centriesInRange. The approximate number of entries in the index is returned in precpos-\>centriesTotal.

On failure, no changes are made to memory allocated at *precpos*.

#### Remarks

This operation returns varying data when updates occur continuously on the table. The changes in the values will not always match expectations based on knowledge of the updates, since the values are approximations based on physical properties of the index. Transactional isolation does not apply to positions from **JetGetRecordPosition** since the values depend on physical properties of the index that are not transaction isolated.

[JET_RECPOS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-recpos-structure) should not be used to describe a record within a table or to reposition a record close to an existing record. Instead, bookmarks for an existing record should be retrieved and then used to reposition the same record.

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
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_RECPOS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-recpos-structure)
[JET_SETINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-setinfo-structure)
[JetGotoPosition](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgotoposition-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)