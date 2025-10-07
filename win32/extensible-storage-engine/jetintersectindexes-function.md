# JetIntersectIndexes Function

_**Applies to:** Windows | Windows Server_

## JetIntersectIndexes Function

The **JetIntersectIndexes** function computes the intersection between multiple sets of index entries from different secondary indices over the same table. This operation is useful for finding the set of records in a table that match two or more criteria that can be expressed using index ranges.

```cpp
    JET_ERR JET_API JetIntersectIndexes(
      __in          JET_SESID sesid,
      __in          JET_INDEXRANGE* rgindexrange,
      __in          unsigned long cindexrange,
      __in_out      JET_RECORDLIST* precordlist,
      __in          JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The session to use for this call.

*rgindexrange*

A pointer to an array of [JET_IndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexrange-structure) structures. Each structure includes a [JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid) that has been set up to hold one of the index ranges to be intersected. For more information, see [JET_IndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexrange-structure).

*cindexrange*

The number of [JET_IndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexrange-structure) structures in the array that is contained in the *rgindexrange* parameter.

*precordlist*

Pointer to a [JET_RECORDLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-recordlist-structure) structure. This structure will be populated with enough information to traverse the temporary table with the results from **JetIntersectIndexes**.

The output buffer that receives a [JET_RECORDLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-recordlist-structure) structure. The structure contains a description of the result set of the intersection.

*grbit*

Reserved for future use.

### Return Value

This function returns the [JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err) datatype with one of the following return codes. For more information about ESE errors, see [Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors) and [Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters).

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

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errInvalidgrbit

|

One of the options requested was invalid, used incorrectly, or not implemented.

This error is returned by **JetIntersectIndexes** when:

The *grbit* contained in the [JET_IndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269335(v=exchg.10).md) structure pointed to by any element in the *rgindexrange* array is not equal to JET_bitRecordInIndex.

|
|

JET_errInvalidParameter

|

One of the parameters provided contains an unexpected value or a value that is inconsistent when combined with the value of another parameter.

This error is returned by **JetIntersectIndexes** for of the following reasons:

* The *precordlist* parameter is NULL.
* The **cbStruct** member of the [JET_RECORDLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269287(v=exchg.10).md) structure specified in the *precordlist* parameter is not equal to size of the [JET_RECORDLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269287(v=exchg.10).md) structure.
* The *cindexrange* parameter is zero.
* The *cindexrange* parameter is greater than 64.
* The **cbStruct** member for any element in the array specified by the *rgindexrange* parameter is not equal to the size of the [JET_IndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269335(v=exchg.10).md) structure.
* The elements in the *rgindexrange* array contain [JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269182(v=exchg.10).md)s from different tables.
* An element in the *rgindexrange* array contains a [JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269182(v=exchg.10).md) that is not positioned on a secondary index.
* One or more of the elements in the *rgindexrange* array contain [JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269182(v=exchg.10).md)s positioned on the same secondary index.

|
|

JET_errInvalidSesid

|

The session handle is invalid or refers to a closed session.

This error is not returned under all circumstances. Handles are validated on a best effort basis only.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized.

|
|

JET_errOutOfCursors

|

The operation failed because the engine could not allocate the resources required to open a new cursor. Cursor resources are configured by calling [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with *JET_paramMaxCursors* specified in the *paramid* parameter.

|
|

JET_errOutOfMemory

|

The operation failed because not enough memory could be allocated to complete it.

**JetIntersectIndexes** can return JET_errOutOfMemory if the address space of the host process becomes too fragmented. The temporary table manager will always allocate a 1MB chunk of address space for every temporary table created regardless of the amount of data to be stored. **JetIntersectIndexes** will create one temporary table for each [JET_IndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269335(v=exchg.10).md) specified in the *rgindexrange* parameter, and one temporary table for the output in [JET_RECORDLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269287(v=exchg.10).md).

|
|

JET_errRestoreInProgress

|

It is not possible to complete the operation because a restore operation is in progress on the instance associated with the session.

|
|

JET_errSessionSharingViolation

|

It is illegal to use the same session from more than one thread at the same time.

**Windows XP:** This return value is introduced in Windows XP.

|
|

JET_errTermInProgress

|

It is not possible to complete the operation because the instance associated with the session is being shut down.

|
|

JET_errTooManyOpenIndexes

|

The operation failed because the engine could not allocate the resources required to cache the indices of the table. The number of indices whose schema can be cached is configured using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with *JET_paramMaxOpenTables* specified in the *paramid* parameter.

|
|

JET_errTooManyOpenTables

|

The operation failed because the engine could not allocate the resources required to cache the schema of the table. The number of tables whose schema can be cached is configured using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with *JET_paramMaxOpenTables* specified in the *paramid* parameter.

|
|

JET_errTooManySorts

|

The operation failed because the engine could not allocate the resources required to create a temporary table. Temporary table resources are configured using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with JET_paramMaxTemporaryTables specified in the *paramid* parameter.

|

On success, a new temporary table is returned that contains the bookmarks of the records that match the criteria represented by each of the input index range descriptions.

On failure, the temporary table containing the results will not be created. The state of the temporary database may be changed. The state of any ordinary databases in use by the database engine will remain unchanged. The current position of the [JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)s provided to this function may be changed.

#### Remarks

**JetIntersectIndexes** can be used to efficiently filter the records in a table by multiple criteria if those criteria can be expressed in terms of the secondary indices over that table. For example, consider that you have a very large table containing people. The table can have columns for their user id, first name, last name, and so on. Suppose that each of these columns is indexed separately and that the primary index of the table is over user id. If you wanted to find everyone whose first name starts with an A and whose last name starts with G, you would perform the following steps:

1. Open a new cursor on the table, and set that cursor to use the index over the "first name" column. Then setup an index range for all people whose "first name" started with 'A', and build a [JET_IndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexrange-structure) struct that contains this cursor.

2. Repeat step 1 with a new cursor on the "last name" index for all people whose "last name" started with 'G'.

3. Pass these criteria to **JetIntersectIndexes** to compute the result into a temporary table.

4. Traverse the temporary table and retrieve each of the records that pass the criteria by bookmark.

The temporary table containing the result set is a simple table with one column that contains the bookmark of each record that passed all the criteria used to compute the intersection. The result set is sorted in the same order as the primary index and contains no duplicate entries. The application can enumerate the results of the intersection by enumerating the rows in the temporary table, retrieving the bookmark for each result using [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function), and then visiting the record in the database by calling [JetGotoBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgotobookmark-function) with that bookmark on a cursor positioned on the primary index.

The temporary table returned by **JetIntersectIndexes** can only be scanned in a forward direction. It should also be closed via [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function) when the scan has been completed. For more information about temporary tables and how they work, see [JetOpenTemporaryTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentemporarytable-function).

**JetIntersectIndexes** is generally an efficient and convenient way to filter records based on multiple indexed criteria. However, there are some important tips that should be followed to maximize the usefulness of this feature. If you know that one of the criteria is so restrictive that the resulting index range has very few records then it is probably better to simply walk that index range and filter the records at the application level. Further, if you know that you have criteria that are much less restrictive than other criteria in your intersection then you might consider dropping those much less restrictive criteria from the intersection. Finally, if you know that one of the criteria is not at all restrictive such that the resulting index range is almost as large as the primary index then it is unlikely that intersecting with that index range will benefit (reduce the size of) the result set. In all cases, you should be selecting criteria in a manner that will take the fewest possible index entries on input and generate the most specific set of bookmarks on output for maximum performance.

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
[JET_IndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-indexrange-structure)
[JET_RECORDLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-recordlist-structure)
[JetGotoBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgotobookmark-function)
[JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function)
[JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function)