# JetGotoSecondaryIndexBookmark Function

_**Applies to:** Windows | Windows Server_

## JetGotoSecondaryIndexBookmark Function

The **JetGotoSecondaryIndexBookmark** function positions a cursor to an index entry that is associated with the specified secondary index bookmark. The secondary index bookmark must be used with the same index over the same table from which it was originally retrieved. The secondary index bookmark for an index entry can be retrieved using **JetGotoSecondaryIndexBookmark**.

**Windows XP:** **JetGotoSecondaryIndexBookmark** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetGotoSecondaryIndexBookmark(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          void* pvSecondaryKey,
      __in          unsigned long cbSecondaryKey,
      __in_opt      void* pvPrimaryBookmark,
      __in          unsigned long cbPrimaryBookmark,
      __in          const JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*pvSecondaryKey*

The buffer that contains the secondary key to use to position the cursor.

*cbSecondaryKey*

The size of the secondary key in the buffer.

*pvPrimaryBookmark*

The buffer that contains the primary key bookmark to use to position the cursor.

*cbPrimaryBookmark*

The size of the primary key bookmark in the buffer.

*grbit*

A group of bits that specifies zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitBookmarkPermitVirtualCurrency

|

In the event that the index entry can no longer be found, the cursor will be left positioned where that index entry was previously found. The operation will still fail with JET_errRecordDeleted; however, it will be possible to move to the next or previous index entry relative to the index entry that is now missing.

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

The operation cannot complete because all activity on the instance that is associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

The operation cannot complete because is because the instance that is associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errInvalidBookmark

|

The secondary index bookmark that was provided was invalid. This error might have occurred because the secondary key is zero or the secondary key buffer pointer is **NULL**. This error occurs because

* The current secondary index does not have a uniqueness constraint and the size of the provided bookmark is zero.
* The bookmark buffer pointer is **NULL**.

|
|

JET_errNoCurrentIndex

|

The cursor is not currently on a secondary index. It is not meaningful to go to a secondary index bookmark when the cursor is not currently using a secondary index. [JetGotoBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294053(v=exchg.10).md) should be used when the cursor is not on a secondary index.

|
|

JET_errNotInitialized

|

The operation cannot complete because the instance that is associated with the session has not yet been initialized.

|
|

JET_errRecordDeleted

|

The index entry that is associated with the secondary index bookmark could not be found.

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

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errTermInProgress

|

The operation cannot complete because the instance that is associated with the session is being shut down.

|

If this function succeeds, the cursor will be positioned at an index entry that is associated with the specified secondary index bookmark. If a record has been prepared for update, that update will be canceled. If an index range is in effect, that index range will be canceled. If a search key has been constructed for the cursor to use, that search key will be deleted. No change to the database state will occur.

If this function fails, the position of the cursor remains unchanged unless JET_errRecordDeleted is returned and JET_bitBookmarkPermitVirtualCurrency is specified. In that case, the cursor will be positioned where the index entry that is associated with the specified secondary index bookmark would have been. The cursor can be moved relative to that position, but is still not on a valid index entry.

If a record has been prepared for update, that update will be canceled. If an index range is in effect, that index range will be canceled. If a search key has been constructed for the cursor to use, that search key will be deleted. In any case, no change to the database state will occur.

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista or Windows XP.

|
|

**Server**

|

Requires Windows Server 2008 or Windows Server 2003.

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
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetGetSecondaryIndexBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetsecondaryindexbookmark-function)
[JetGotoBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgotobookmark-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)