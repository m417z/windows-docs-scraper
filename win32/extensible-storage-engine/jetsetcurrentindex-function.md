# JetSetCurrentIndex Function

_**Applies to:** Windows | Windows Server_

## JetSetCurrentIndex Function

The **JetSetCurrentIndex** function can be used to set the current index of a cursor. The current index of a cursor defines which records in a table are visible to that cursor and the order in which they appear by selecting the set of index entries to use to expose those records.

```cpp
    JET_ERR JET_API JetSetCurrentIndex(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in_opt      const tchar* szIndexName
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*szIndexName*

The name of the index to be selected for the cursor.

If this parameter is NULL or an empty string then the clustered index will be selected. If a primary index is defined for the table then that index will be selected because it is the same as the clustered index. If no primary index is defined for the table then the sequential index will be selected. The sequential index has no index definition. See [JetCreateIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex-function) for more information.

If *pindexid* is not NULL then the index name will be ignored and the index will be selected by its index ID.

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

JET_errBadItagSequence

|

A secondary index is being selected with the JET_bitNoMove option and there is no value for the first multi-valued key column in the new index's definition that corresponds to the specified sequence number.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInvalidIndexId

|

The contents of the index ID were not valid or have expired and need to be refreshed. This can happen for **JetSetCurrentIndex** when:

* pindexid->cbStruct is not of the expected size (Windows Server 2003 and later releases).
* The engine has been shut down since the index ID was fetched.
* All cursors referencing the table containing the index corresponding to the index ID have been closed and the engine has evicted that index's definition from the schema cache.
* The index ID is being used with a cursor opened on the wrong table.
* The index has been dropped or is not yet visible to the session.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidName

|

One of the specified object names was invalid. All object names must conform to the same set of rules. These rules are as follows:

* Object names must be composed of ASCII characters.
* Object names must be at least one character in length.
* Object names may not exceed JET_cbNameMost (64) characters in length.
* Object names may not begin with a space.
* Object names may not contain ASCII control characters (0x00 through 0x1F).
* Object names may not contain an exclamation point (!), period (.), left bracket ([), or right bracket (]) character.
* Once validated, only the portion of the string up to the first space (if any) will be used for the object name. This effectively means that object names may not contain a space either.

|
|

JET_errInvalidParameter

|

One of the parameters provided contained an unexpected value or contained a value that did not make sense when combined with the value of another parameter. This can happen for **JetSetCurrentIndex** when *pindexid* is not NULL and pindexid->cbStruct is not of the expected size (Windows XP and earlier releases).

|
|

JET_errNoCurrentRecord

|

A secondary index is being selected with the JET_bitNoMove option and there is no index entry in the new index that corresponds to the record associated with the index entry at the current position of the cursor on the old index.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errOutOfCursors

|

The engine has exhausted its pool of resources used to open cursors. The maximum number of cursors that can be opened at any one time is controlled using [JET_paramMaxCursors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269201(v=exchg.10).md). See [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) for more information. This can happen for **JetSetCurrentIndex** when a secondary index has been selected and the engine cannot open an internal cursor to use that index.

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

This error will only be returned by Windows XP and later releases.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|

On success, the current index of the cursor is set to the requested index. Index entries may now be sought using [JetSeek](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetseek-function) according to the index definition of the requested index. Index entries may also be enumerated using [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function) in the order specified by that index definition. The current position of the cursor is either set to the first index entry on the index (JET_bitMoveFirst) or to a specific index entry that is related to the current position of the cursor on the old index (JET_bitNoMove). No change to the database state will occur.

On failure, the current index and current position of the cursor are in an undefined state. No change to the database state will occur.

#### Remarks

If the index ID hint is stale then the API simply fails. There is no fallback to the text name of the index in this case as one might expect. This fallback must be done manually by the caller of the API.

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
|

**Unicode**

|

Implemented as **JetSetCurrentIndexW** (Unicode) and **JetSetCurrentIndexA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_INDEXID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexid-structure)
[JetCreateIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex-function)
[JetGetCurrentIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetcurrentindex-function)
[JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function)
[JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function)
[JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function)
[JetSeek](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetseek-function)
[JetSetCurrentIndex]()
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)