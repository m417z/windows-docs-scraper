# JetIndexRecordCount2 Function

_**Applies to:** Windows | Windows Server_

## JetIndexRecordCount2 Function

The **JetIndexRecordCount2** function counts the number of entries in the current index from the current position forward. The current position is included in the count. The count can be greater than the total number of records in the table if the current index is over a multi-valued column and instances of the column have multiple-values. If the table is empty, then 0 will be returned for the count.

```cpp
    JET_ERR JET_API JetIndexRecordCount2(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __out         unsigned long* pcrec,
      __in          unsigned long crecMax
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*pcrec*

The pointer to an unsigned long value to receive the count.

*crecMax*

The maximum number of records to count. A *crecMax* value of 0 indicates that the count is unlimited.

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

The operation cannot complete because the instance that is associated with the session encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errNoCurrentRecord

|

The cursor is not currently on a record and the table is not empty.

**Windows XP, Windows Server 2003, Windows 2000 Server, and Windows 2000 Professional:** If the cursor is positioned on an empty index or index range then **JetIndexRecordCount2** erroneously returns JET_errNoCurrentRecord.

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

If this function succeeds, the exact number of index entries including the current position and up to *crecMax* (if it is not 0), is returned in the unsigned long pointed to by *pcrec*.

If this function fails, no changes are made to memory allocated at *precpos*.

#### Remarks

If the table is not empty, then the cursor should be positioned onto the record from which to begin the count. The count will include this record, and count forward up to the given limit in *crecMax*. If *crecMax* is 0 then the operation will continue counting until the end of the index.

Index ranges can be used to construct artificial end-of-index limitations for the count. In this way, subranges of an index can be counted exactly. The cursor should be positioned to the first row in the range. The end of the range key should be made and then [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function) should be used to set the upper range, either inclusively or exclusively. Lastly, **JetIndexRecordCount2** should be called to exactly count the range.

**JetIndexRecordCount2** obeys transaction semantics and returns a count that is accurate for this particular session in its current transactional state.

**JetIndexRecordCount2** accesses index leaf pages in order to exactly count entries. Consequently, it can perform a great deal of I/O and can be slow. The *crecMax* limitation should be used to prevent excessive load. If a range is large, then it might be possible to count the range in an approximated fashion using [JetGetRecordPosition](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetrecordposition-function).

**Windows XP, Windows Server 2003, Windows 2000 Server, and Windows 2000 Professional:** If the cursor is positioned on an empty index or index range then **JetIndexRecordCount2** erroneously returns JET_errNoCurrentRecord rather than returning a record count of zero. The application should check to see if the index or index range is empty in this case.

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
[JetGetRecordPosition](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetrecordposition-function)
[JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)