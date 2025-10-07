# JetSeek Function

_**Applies to:** Windows | Windows Server_

## JetSeek Function

The **JetSeek** function efficiently positions a cursor to an index entry that matches the search criteria specified by the search key in that cursor and the specified inequality. A search key must have been previously constructed using [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmakekey-function).

```cpp
    JET_ERR JET_API JetSeek(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*grbit*

A group of bits that contain the options to be used for this call. *Grbit* must be nonzero and must include one or more of the values listed in the following table.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitCheckUniqueness

|

A special error code, JET_wrnUniqueKey, will be returned if it can be cheaply determined that there is exactly one index entry that matches the search key.

This option is ignored unless JET_bitSeekEQ is also specified.

This option is only available on Windows Server 2003 and later releases.

|
|

JET_bitSeekEQ

|

The cursor will be positioned at the index entry closest to the start of the index that exactly matches the search key. The start of the index is the index entry that is found when moving to the first record in that index. The start of the index is not the same as the low end of the index, which can change depending on the sort order of the key columns in the index.

It is not meaningful to use this option with a search key that was constructed using [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269329(v=exchg.10).md) using a wildcard option.

|
|

JET_bitSeekGE

|

The cursor will be positioned at the index entry closest to the start of the index that is greater than or equal to an index entry that would exactly match the search criteria. The start of the index is the index entry that is found when moving to the first record in that index. The start of the index is not the same as the low end of the index, which can change depending on the sort order of the key columns in the index.

It is not meaningful to use this option with a search key that was constructed using [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269329(v=exchg.10).md) using a wildcard option intended to find index entries closest to the end of the index.

|
|

JET_bitSeekGT

|

The cursor will be positioned at the index entry closest to the start of the index that is greater than an index entry that would exactly match the search criteria. The start of the index is the index entry that is found when moving to the first record in that index. The start of the index is not the same as the low end of the index, which can change depending on the sort order of the key columns in the index.

It is not meaningful to use this option with a search key that was constructed using [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269329(v=exchg.10).md) using a wildcard option intended to find index entries closest to the start of the index.

|
|

JET_bitSeekLE

|

The cursor will be positioned at the index entry closest to the end of the index that is less than or equal to an index entry that would exactly match the search criteria. The end of the index is the index entry that is found when moving to the last record in that index. The end of the index is not the same as the high end of the index, which can change depending on the sort order of the key columns in the index.

It is not meaningful to use this option with a search key that was constructed using [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269329(v=exchg.10).md) using a wildcard option intended to find index entries closest to the start of the index.

|
|

JET_bitSeekLT

|

The cursor will be positioned at the index entry closest to the end of the index that is less than an index entry that would exactly match the search criteria. The end of the index is the index entry that is found when moving to the last record in that index. The end of the index is not the same as the high end of the index, which can change depending on the sort order of the key columns in the index.

It is not meaningful to use this option with a search key that was constructed using [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269329(v=exchg.10).md) using a wildcard option intended to find index entries closest to the end of the index.

|
|

JET_bitSetIndexRange

|

An index range will automatically be setup for all keys that exactly match the search key. The resulting index range is identical to one that would have otherwise been created by a call to [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294112(v=exchg.10).md) with the JET_bitRangeInclusive and JET_bitRangeUpperLimit options. See [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294112(v=exchg.10).md) for more information.

This is a convenient method for discovering all the index entries that match the same search criteria.

This option is ignored unless JET_bitSeekEQ is also specified.

|

### Return Value

This function allows for the return of any [JET_ERRs](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) that are defined in this API. For more information about Jet errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

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

For **JetSeek**, this means that an index entry was found that exactly matched the search criteria.

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

JET_errKeyNotMade

|

There is no current search key for the cursor. **JetSeek** requires that the cursor have a valid search key because it will use that for the search criteria used to find index entries.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errRecordNotFound

|

No index entry was found that matched the search criteria.

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_wrnSeekNotEqual

|

An index entry was found that matched the search criteria. However, that index entry was not an exact match.

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
|

JET_wrnUniqueKey

|

Exactly one index entry was found that exactly matched the search criteria. This error will only be returned if JET_bitSeekCheckUniqueness was specified and it was cheap to determine that the matching index entry was the only index entry that exactly matches the search criteria.

This error will only be returned by Windows Server 2003 and later releases.

|

On success, the cursor will be positioned at an index entry that matches the search criteria. If a record has been prepared for update, then that update will be canceled. If an index range is in effect, that index range will be canceled. If a search key has been constructed for the cursor, then that search key will be deleted. No change to the database state will occur. When multiple index entries have the same value, the entry closest to the start of the index is always selected.

On failure, the position of the cursor will remain unchanged unless JET_errRecordNotFound was returned. In that case, the cursor will be positioned where the index entry that matched the search criteria specified by the search key in that cursor and the specified inequality would have been. The cursor can be moved relative to that position but is still not on a valid index entry. If a record has been prepared for update, then that update will be canceled. If an index range is in effect, that index range will be canceled. If a search key has been constructed for the cursor, then that search key will be deleted. No change to the database state will occur.

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
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmakekey-function)
[JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function)
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)