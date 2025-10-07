# JetGetBookmark Function

_**Applies to:** Windows | Windows Server_

## JetGetBookmark Function

The **JetGetBookmark** function retrieves the bookmark for the record that is associated with the index entry at the current position of a cursor. This bookmark can then be used to reposition that cursor back to the same record using [JetGoToBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgotobookmark-function).

```cpp
    JET_ERR JET_API JetGetBookmark(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __out_opt     void* pvBookmark,
      __in          unsigned long cbMax,
      __out_opt     unsigned long* pcbActual
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*pvBookmark*

The output buffer that receives the bookmark.

*cbMax*

The maximum size, in bytes, of the output buffer.

*pcbActual*

The actual size, in bytes, of the bookmark.

If this parameter is **NULL** then the actual size of the bookmark will not be returned.

If the output buffer is too small, the actual size of the bookmark will still be returned. That means that this number will be larger than the size of the output buffer.

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

The operation completed successfully, but the output buffer was too small to receive the entire bookmark. The output buffer has been filled with as much of the bookmark as would fit. The actual size of the bookmark has also been returned, if requested.

|
|

JET_errClientRequestToStopJetService

|

The operation cannot complete because all activity on the instance that is associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

The operation cannot complete because the instance that is associated with the session encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This return values is introduced in Windows XP.

|
|

JET_errNoCurrentRecord

|

The cursor is not positioned on a record. This can happen for many different reasons. For example, this will happen if the cursor is positioned after the last record on the current index.

|
|

JET_errNotInitialized

|

The operation cannot complete because the instance that is associated with the session has not yet been initialized.

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

If this function succeeds, the bookmark for the record that is associated with the index entry at the current position of a cursor will be returned in the output buffer. No change to the database state will occur.

If this function fails, the state of the output buffer and the actual size of the bookmark will be undefined unless JET_errBufferTooSmall was returned. In the event that JET_errBufferTooSmall is returned, the output buffer will contain as much of the bookmark as will fit in the space provided and the actual size of the bookmark will be accurate. No change to the database state will occur.

#### Remarks

Bookmarks should generally be treated as opaque chunks of data. No attempt should be made to exploit the internal structure of this data. However, the following conditions are true of all ESENT bookmarks:

  - A bookmark uniquely identifies a record in a given table.

  - The bookmark of a record will not change for the lifetime of that record.

  - The bookmark of a record is the same as the key of that record on the primary index over the table containing that record. If no primary index is defined over that table the database engine will create its own bookmark for the record.

  - Bookmarks can be compared against each other using the [memcmp](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-6.0/aa246467(v=vs.60)) function to establish their relative ordering in the primary index over the table of the source records. If no primary index is defined over that table, it is not meaningful to use the relative ordering of bookmarks from that table.

  - It is meaningless to compare bookmarks of records from different tables against each other.

  - A bookmark is always less than or equal to JET_cbBookmarkMost (256) bytes in length, prior to Windows Vista.
**Windows Vista:** On Windows Vista and later releases, bookmarks can be larger than JET_cbBookmarkMost (256) bytes. The maximum size of a bookmark is equal to the current value of JET_paramKeyMost + 1.

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
[JetGoToBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgotobookmark-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)
[memcmp](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-6.0/aa246467(v=vs.60))