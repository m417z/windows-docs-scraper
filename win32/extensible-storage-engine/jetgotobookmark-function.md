# JetGotoBookmark Function

_**Applies to:** Windows | Windows Server_

## JetGotoBookmark Function

The **JetGotoBookmark** function positions a cursor to an index entry for the record that is associated with the specified bookmark. The bookmark can be used with any index defined over a table. The bookmark for a record can be retrieved using [JetGetBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetbookmark-function).

```cpp
    JET_ERR JET_API JetGotoBookmark(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          void* pvBookmark,
      __in          unsigned long cbBookmark
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*pvBookmark*

The buffer that contains the bookmark to use to position the cursor.

*cbBookmark*

The size of the bookmark in the buffer.

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

The operation cannot complete because all activity on the instance that is associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

The operation cannot complete because the instance that is associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This return value was introduced in Windows XP.

|
|

JET_errInvalidBookmark

|

The bookmark that was provided is invalid. This might have occurred because the size of the bookmark is zero or the bookmark buffer pointer is **NULL**.

|
|

JET_errNoCurrentRecord

|

The cursor is on a secondary index and no index entry could be found for the record that is associated with the bookmark.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance that is associated with the session has not been initialized yet.

|
|

JET_errRecordDeleted

|

The record that is associated with the bookmark could not be found.

|
|

JET_errRestoreInProgress

|

The operation cannot complete because a restore operation is in progress on the instance that is associated with the session.

|
|

JET_errSessionSharingViolation

|

The same session cannot be used for more than one thread at the same time.

**Windows XP:** This return value was introduced in Windows XP.

|
|

JET_errTermInProgress

|

The operation cannot complete because the instance associated with the session is being shut down.

|

If this function succeeds, the cursor will be positioned at an index entry for the record that is associated with the specified bookmark. If a record has been prepared for update, that update will be canceled. If an index range is in effect, that index range will be canceled. If a search key has been constructed for the cursor, that search key will be deleted. No change to the database state will occur.

If this function fails, the position of the cursor will remain unchanged. If a record has been prepared for update, that update will be canceled. If an index range is in effect, that index range will be canceled. If a search key has been constructed for the cursor, that search key will be deleted. No change to the database state will occur.

#### Remarks

There are two ways to use a bookmark to position a cursor on an index. The first is to use the bookmark to position on the record directly. This occurs when the current index of the cursor is the primary index. This technique works because an ESENT bookmark is the same as the associated record's primary key.

The second way to use a bookmark is to position it on an entry in a secondary index that corresponds to the record that is associated with that bookmark. During this process, the engine looks up the actual record using the bookmark on the primary index. It then uses the record data and the secondary index definition to compute a key into the secondary index that points to the record. It then positions the cursor on the index entry for that key. If the cursor is currently on a secondary index over one or more multi-valued key columns, the cursor will be positioned on the index entry corresponding to the first multi-value of each of those key columns.

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
[JetGetBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetbookmark-function)