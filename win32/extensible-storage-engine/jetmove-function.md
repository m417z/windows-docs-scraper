# JetMove Function

_**Applies to:** Windows | Windows Server_

## JetMove Function

The **JetMove** function positions a cursor at the start or end of an index and traverses the entries in that index either forward or backward. It is also possible to move the cursor forward or backward on the current index by a specified number of index entries. Another approach is to artificially limit the index entries that can be enumerated using **JetMove** by setting up an index range on the cursor using [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function).

```cpp
    JET_ERR JET_API JetMove(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          long cRow,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*tableid*

The cursor to use for this call.

*cRow*

An arbitrary offset that indicates the desired movement of the cursor on the current index.

In addition to standard offsets, this parameter can also be set with one of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_MoveFirst

|

Moves the cursor to the first index entry in the index (if one exists). This resets any index range set with [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function).

**Note** The literal value of -2147483648 is used to denote this option. Do not use this value as an ordinary offset or unintended behavior may result.

|
|

JET_MoveLast

|

Moves the cursor to the last index entry in the index (if one exists). This resets any index range set with [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function).

**Note** The literal value of 2147483647 is used to denote this option. Do not use this value as an ordinary offset or unintended behavior may result.

|
|

JET_MoveNext

|

Moves the cursor to the next index entry in the index (if one exists). This value is exactly equal to an ordinary offset of +1. It respects index ranges set with [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function).

|
|

JET_MovePrevious

|

Moves the cursor to the previous index entry in the index (if one exists). It respects index ranges set with [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function).

This value is exactly equal to an ordinary offset of -1, or 0 (Zero).

The cursor remains at the current logical position and the existence of the index entry that corresponds to that logical position will be tested.

|

*grbit*

A group of bits that specify zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitMoveKeyNE

|

Moves the cursor forward or backward by the number of index entries required to skip the requested number of index key values encountered in the index. This has the effect of collapsing index entries with duplicate key values into a single index entry. Ordinarily, an offset will move the cursor by the specified number of index entries regardless of their key values.

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

The operation completed successfully. For **JetMove**, this means that an index entry was found at the requested location or offset on the current index.

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

The cursor is not currently positioned on an index entry. For **JetMove**, this means that an index entry was not found at the requested location or offset on the current index.

|
|

JET_errNotInitialized

|

The operation cannot complete because the instance that is associated with the session has not yet been initialized.

|
|

JET_errRecordDeleted

|

The cursor is currently logically positioned on an index entry that corresponds to a record that has been deleted.

|
|

JET_errRestoreInProgress

|

The operation cannot complete because a restore operation is in progress on the instance associated with the session.

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

If this function succeeds, the cursor will be positioned at an index entry that matches the requested location or offset. If a record has been prepared for update, that update will be canceled. If an index range is in effect and JET_MoveFirst or JET_MoveLast was specified, that index range will be canceled. No change to the database state will occur.

If this function fails, the position of the cursor will remain unchanged unless JET_errNoCurrentRecord was returned. In that case, the cursor will be positioned where the index entry that matches the requested location or offset would have been. The cursor can be moved relative to that position but is still not on a valid index entry. If a record has been prepared for update, that update will be canceled. If an index range is in effect and JET_MoveFirst or JET_MoveLast was specified, that index range will be canceled. No change to the database state will occur.

#### Remarks

A cursor can be moved to two special positions using **JetMove**, Before First and After Last. If the cursor is on the first index entry in the table and **JetMove** is called with JET_MovePrevious, the call will fail with JET_errNoCurrentRecord and the cursor will be logically positioned before the first entry in the index. This logical position is maintained even if another index entry is inserted prior to the first entry in the index. An analogous situation occurs for After Last relative to the end of the index. Before First and After Last are most useful when setting up a range of index entries to be iterated using **JetMove**, using an iterator model that expects to always move to the next (or previous) element prior to using that element.

The set of index entries that can be visited by **JetMove** can be limited by setting up an index range on the cursor. This is useful for applications that enumerate a set of index entries that match simple criteria that can be expressed through a pair of search keys built for that index. For more information, see [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function).

On releases prior to Windows Server 2003 SP1, there is a problem in **JetMove** that occurs in some specific cases, that affects the correct enforcement of an index range as set up by the [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function) function. If the cursor is currently before the first index entry and an index range is set with an upper limit that is less than the first index entry, the next call to **JetMove** will erroneously go to that index entry instead of failing with JET_errNoCurrentRecord, as expected. The same error will happen for the analogous situation starting from the end of the index. This situation can occur in an application that sets up an index range and navigates it using an iterator that expects to start before the first index entry that is a member of the set of entries to enumerate, rather than starting on the first index entry of that set. This situation also occurs on the analogous case starting from the end of the index. The workaround is for the application to manually verify that the index entry acquired is inside the index range by comparing the key for the current index entry (retrieved using [JetRetrieveKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievekey-function)) with the key representing the end of the current index range (retrieved using [JetRetrieveKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievekey-function) using JET_bitRetrieveCopy).

It is important to be careful when passing computed offsets to **JetMove**. If the computed offset is less than or equal to JET_MoveFirst, that offset must be broken up into multiple pieces, each of which is passed to **JetMove** separately but within a single transaction to get the desired effect. The same is true for offsets greater than or equal to JET_MoveNext. It is unlikely that an application would undergo this in the real world, but it is good to have a defense against this case given the very different semantics of JET_MoveFirst and JET_MoveLast from an ordinary offset.

When **JetMove** is called with a very large offset, such as when the cRow parameter is set to 1000, **JetMove** traverses all 1000 index entries to reach the final position. Currently, the ESE API does not provide an efficient way to move directly to a given index entry by offset without traversing each index entry.

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
[JetRetrieveKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievekey-function)
[JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function)