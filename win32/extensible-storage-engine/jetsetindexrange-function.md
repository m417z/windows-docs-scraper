# JetSetIndexRange Function

_**Applies to:** Windows | Windows Server_

## JetSetIndexRange Function

The **JetSetIndexRange** function temporarily limits the set of index entries that the cursor can walk using [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function) to those starting from the current index entry and ending at the index entry that matches the search criteria specified by the search key in that cursor and the specified bound criteria. A search key must have been previously constructed using [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmakekey-function).

```cpp
    JET_ERR JET_API JetSetIndexRange(
      __in          JET_SESID sesid,
    __in          JET_TABLEID tableidSrc,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableidSrc*

The cursor to use for this call.

*grbit*

A group of bits that contain the options to be used for this call, which include zero or more of the following:

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitRangeInclusive

|

This presence or absence of this option indicates the boundary criteria of the index range. When present, this option indicates that the limit of the index range is inclusive. When absent, this option indicates that the limit of the index range is exclusive. When the limit of the index range is inclusive then any index entries exactly matching the search criteria are included in the range.

|
|

JET_bitRangeInstantDuration

|

This option requests that the index range be removed as soon as it has been established. All other aspects of the operation remain unchanged. This is useful for testing for the existence of index entries that match the search criteria.

|
|

JET_bitRangeRemove

|

This option requests that an existing index range on the cursor be canceled. Once the index range is canceled, it will be possible to move beyond the end of the index range using [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294117(v=exchg.10).md). If an index range is not already in effect, then **JetSetIndexRange** will fail with JET_errInvalidOperation.

When this option is specified, all other options are ignored.

|
|

JET_bitRangeUpperLimit

|

If this option is used, then the search key in the cursor represents the search criteria for the index entry closest to the end of the index that will match the index range. The index range will be established between the current position of the cursor and this index entry so that all matches can be found by walking forward on the index using [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294117(v=exchg.10).md) with JET_MoveNext or a positive offset.

It is not meaningful to use this option with a search key that was constructed using [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269329(v=exchg.10).md) using a wildcard option intended to find index entries closest to the start of the index.

If this option is omitted, then the search key in the cursor represents the search criteria for the index entry closest to the start of the index that will match the index range. The index range will be established between the current position of the cursor and this index entry so that all matches can be found by walking backward on the index using [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294117(v=exchg.10).md) with JET_MovePrevious or a negative offset.

It is not meaningful to omit this option with a search key that was constructed using [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269329(v=exchg.10).md) using a wildcard option intended to find index entries closest to the end of the index.

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

For **JetSetIndexRange**, this means that either an existing index range was canceled or that there is at least one index entry inside of the index range.

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

JET_errInvalidOperation

|

This error will be returned by **JetSetIndexRange** when JET_bitRangeRemove was specified and no index range was in effect.

|
|

JET_errKeyNotMade

|

There is no current search key for the cursor. **JetSetIndexRange** requires that the cursor have a valid search key because it will use that for the search criteria used to find index entries.

|
|

JET_errNoCurrentIndex

|

There is no current index for the cursor. This will happen for **JetSetIndexRange** if the cursor is on the clustered index of a table, a primary index has not been defined. Setting an index range over such an index is not supported.

|
|

JET_errNoCurrentRecord

|

This error will be returned by **JetSetIndexRange** to indicate that there are no index entries inside the index range.

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

On success, if JET_bitRangeRemove is specified, then the index range that is currently in effect is canceled. If JET_bitRangeRemove is not specified and JET_bitRangeInstantDuration is specified, then no index range is in effect. If neither JET_bitRangeRemove nor JET_bitRangeInstantDuration is specified, then a new index range is in effect. This index range will temporarily limit the set of index entries that the cursor can walk using [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function) to those starting from the current index entry and ending at the index entry that matches the search criteria. The position of the cursor will remain unchanged. If a search key has been constructed for the cursor, then that search key will be deleted. No change to the database state will occur.

On failure, if JET_errNoCurrentRecord is not returned, then no index range is in effect. If JET_errNoCurrentRecord is returned, then a new index range is in effect. This index range will temporarily limit the set of index entries that the cursor can walk using [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function) to those starting from the current index entry and ending at the index entry that matches the search criteria. The position of the cursor will remain unchanged. If JET_errNoCurrentRecord was returned and a search key has been constructed for the cursor, then that search key will be deleted. No change to the database state will occur.

#### Remarks

An index range is volatile and will automatically be canceled if any navigation other than [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function) is performed on the cursor.

Index ranges only work in one direction. If an upper limit is established then only forward motion using [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function) with JET_MoveNext or a positive offset will be prevented once the end of the index range has been reached. It is still possible to leave the index range in this case using [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function) with JET_MovePrevious or a negative offset. An analogous situation occurs for a lower limit.

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
[JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function)
[JetSetIndexRange]()
[JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetstopservice-function)