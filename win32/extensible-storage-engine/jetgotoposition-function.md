# JetGotoPosition Function

_**Applies to:** Windows | Windows Server_

## JetGotoPosition Function

The **JetGotoPosition** function moves a cursor to a new location that is a fraction of the way through the current index. The fraction is approximately equal to the following:

precpos-\>centriesLT/precpos-\>centriesTotal

This operation is performed in response to user scroll box input that is received when the user attempts to show data that starts part way through a data set.

```cpp
    JET_ERR JET_API JetGotoPosition(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          JET_RECPOS* precpos
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*precpos*

The description of the fraction to use in positioning the cursor in the current index.

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

The operation could not complete because all activity on the instance that is associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

The operation could not complete because the instance that is associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errInvalidParameter

|

The given precpos->cbStruct is not a valid size for the [JET_RECPOS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269308(v=exchg.10).md) structure, or precpos->centriesLT is greater than precpos->centriesTotal.

|
|

JET_errNotInitialized

|

The operation cannot complete because the instance that is associated with the session has not yet been initialized.

|
|

JET_errRecordNotFound

|

This error will be returned if the index is empty.

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

If this function succeeds, the cursor is moved to a current record that is a fraction of the way through the index where the fraction is precpos-\>centriesLT divided by precpos-\>centriesTotal.

If this function fails, the cursor location is left unchanged.

#### Remarks

This operation moves the cursor through the table to a position at the following approximate point: precpos-\>centriesLT divided by precpos-\>centriesTotal.

When updates are occurring continuously on the table, subsequent calls with the same [JET_RECPOS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-recpos-structure) can move the cursor to different positions in the index, both before and after the previous position. Transactional isolation does not apply to positioning through [JET_RECPOS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-recpos-structure) since it depends on physical properties of the index that are not transaction isolated.

[JET_RECPOS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-recpos-structure) should not be used to describe a record within a table or to reposition a record close to an existing record. Instead, bookmarks for an existing record should be retrieved after an initial **JetGotoPosition** and then used to reposition the same record.

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