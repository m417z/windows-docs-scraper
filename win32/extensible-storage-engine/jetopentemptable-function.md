# JetOpenTempTable Function

_**Applies to:** Windows | Windows Server_

## JetOpenTempTable Function

The **JetOpenTempTable** function creates a temporary table with a single index. A temporary table stores and retrieves records just like an ordinary table created using [JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function). However, temporary tables are much faster than ordinary tables due to their volatile nature. They can also be used to very quickly sort and perform duplicate removal on record sets when accessed in a purely sequential manner.

```cpp
    JET_ERR JET_API JetOpenTempTable(
      __in          JET_SESID sesid,
      __in          const JET_COLUMNDEF* prgcolumndef,
      __in          unsigned long ccolumn,
      __in          JET_GRBIT grbit,
      __out         JET_TABLEID* ptableid,
      __out         JET_COLUMNID* prgcolumnid
    );
```

### Parameters

*sesid*

The session to use.

*prgcolumndef*

Column definitions for the columns created in the temporary table.

**Important** limitations exist for the column definition options that are used with a temporary table. See the Remarks section for more information.

In addition to the usual column definition options, zero or more of the following options can also be specified that are relevant only in the context of a temporary table.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitColumnTTDescending

|

The sort order of the key column for the temporary table should be descending rather than ascending. If this option is specified without JET_bitColumnTTKey then this option is ignored.

|
|

JET_bitColumnTTKey

|

The column will be a key column for the temporary table.

The order of the column definitions with this option specified in the input array will determine the precedence of each key column for the temporary table. The first column definition in the array that has this option set will be the most significant key column and so on. If more key columns are requested than can be supported by the database engine then this option is ignored for the unsupportable key columns.

|

*ccolumn*

See *prgcolumndef*.

*grbit*

A group of bits specifying zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitTTErrorOnDuplicateInsertion

|

Any attempt to insert a record with the same index key as a previously inserted record will immediately fail with JET_errKeyDuplicate. If this option is not requested then a duplicate is detected immediately and fails, or is silently removed later, depending on the strategy chosen by the database engine to implement the temporary table, based on the requested functionality.

If this functionality it not required then it is best to not request it. If this functionality is not requested then the temporary table manager may be able to choose a strategy for managing the temporary table that will result in improved performance.

|
|

JET_bitTTForceMaterialization

|

Forces the temporary table manager to abandon the search for the best strategy to use managing the temporary table that will result in enhanced performance.

|
|

JET_bitTTForwardOnly

|

The temporary table is only created if the temporary table manager can use the implementation that is optimized for intermediate query results. If any characteristic of the temporary table would prevent the use of this optimization then the operation will fail with JET_errCannotMaterializeForwardOnlySort.

A side effect of this option is to allow the temporary table to contain records with duplicate index keys. See JET_bitTTUnique for more information.

This option is only available on Windows Server 2003 and later releases.

|
|

JET_bitTTIndexed

|

This option requests that the temporary table be flexible enough to permit the use of [JetSeek](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294103(v=exchg.10).md) to look up records by index key.

If this functionality it not required then it is best to not request it. If this functionality is not requested then the temporary table manager may be able to choose a strategy for managing the temporary table that will result in improved performance.

|
|

JET_bitTTUnique

|

Requests that records with duplicate index keys be removed from the final set of records in the temporary table.

Prior to Windows Server 2003, the database engine always assumed this option to be in effect due to the fact that all clustered indexes must also be a primary key and thus must be unique. As of Windows Server 2003, it is now possible to create a temporary table that does not remove duplicates when the JET_bitTTForwardOnly option is also specified.

It is not possible to know which duplicate will succeed and which duplicates will be discarded, in general. However, when the JET_bitTTErrorOnDuplicateInsertion option is requested then the first record with a given index key to be inserted into the temporary table will always succeed.

|
|

JET_bitTTUpdatable

|

Requests that the temporary table be flexible enough to allow records that have previously been inserted to be subsequently changed. If this functionality it not required then it is best to not request it.

If this functionality is not requested then the temporary table manager may be able to choose a strategy for managing the temporary table that will result in improved performance.

|
|

JET_bitTTScrollable

|

Requests that the temporary table be flexible enough to allow records to be scanned in arbitrary order and direction using [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294117(v=exchg.10).md).

If this functionality is not required then it is best to not request it. If this functionality is not requested then the temporary table manager may be able to choose a strategy for managing the temporary table that will result in improved performance.

|
|

JET_bitTTSortNullsHigh

|

Requests that NULL key column values sort closer to the end of the index than non-NULL key column values.

|
|

JET_bitTTIntrinsicLVsOnly

|

Requests to permit only intrinsic long values.

**Windows 7**: **JET_bitTTIntrinsicLVsOnly** is introduced in Windows 7.

|

*ptableid*

The output buffer that receives the new cursor opened on the newly created temporary table.

*prgcolumnid*

The output buffer that receives the array of column IDs generated during the creation of the temporary table.

The column IDs in this array will exactly correspond to the input array of column definitions. As a result, the size of this buffer must correspond to the size of the input array.

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

JET_errCannotMaterializeForwardOnlySort

|

**JetOpenTempTable** failed because JET_bitTTForwardOnly was specified and the temporary table as specified could not be created using the forward-only optimization. This error will only be returned by Windows Server 2003 and later releases.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errIndexInvalidDef

|

The index could not be created because an invalid index definition was specified.

**JetOpenTempTable** will return this error when:

* The Language Neutral locale is specified.
* An invalid set of normalization flags is specified.

This error will only be returned by Windows 2000.

|
|

JET_errInstanceUnavailable

|

It is not possible to complete the operation because the instance associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data. This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidCodePage

|

The cp field of the [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294130(v=exchg.10).md) was not set to a valid code page. The only valid values for text columns are English (1252) and Unicode (1200). A value of 0 means the default will be used (English, 1252).

|
|

JET_errInvalidColumnType

|

The *coltyp* field of the [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294130(v=exchg.10).md) was not set to a valid column type.

|
|

JET_errInvalidLanguageId

|

The index could not be created because an attempt was made to use an invalid locale ID. The locale ID may either be completely invalid or the associated language pack may not be installed.

|
|

JET_errInvalidLCMapStringFlags

|

The index could not be created because an attempt was made to use an invalid set of normalization flags. This error will only be returned by Windows XP and later releases. On Windows 2000, invalid normalization flags will result in JET_errIndexInvalidDef instead.

|
|

JET_errInvalidSesid

|

The session handle is invalid or refers to a closed session.

**Note** This error is not returned under all circumstances. Handles are validated on a best effort basis only.

|
|

JET_errNotInitialized

|

It is not possible to complete the operation because the instance associated with the session has not been initialized yet.

|
|

JET_errOutOfCursors

|

The operation failed because the engine cannot allocate the resources required to open a new cursor. Cursor resources are configured using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with [JET_paramMaxCursors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269201(v=exchg.10).md).

|
|

JET_errOutOfMemory

|

The operation failed because not enough memory could be allocated to complete it.

**JetOpenTempTable** can return JET_errOutOfMemory if the address space of the host process becomes too fragmented. The temporary table manager will always allocate a 1MB chunk of address space for every temporary table created regardless of the amount of data to be stored.

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
|

JET_errTooManyColumns

|

An attempt was made to add too many columns to the table. A table can have no more than JET_ccolFixedMost fixed columns, no more than JET_ccolVarMost variable-length columns, and no more than JET_ccolTaggedMost tagged columns.

|
|

JET_errTooManyOpenIndexes

|

The operation failed because the engine cannot allocate the resources required to cache the indexes of the table. The number of indexes whose schema can be cached is configured using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with [JET_paramMaxOpenTables](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269201(v=exchg.10).md).

|
|

JET_errTooManyOpenTables

|

The operation failed because the engine cannot allocate the resources required to cache the schema of the table. The number of tables whose schema can be cached is configured using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with [JET_paramMaxOpenTables](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269201(v=exchg.10).md).

|
|

JET_errTooManySorts

|

The operation failed because the engine cannot allocate the resources required to create a temporary table. Temporary table resources are configured using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with [JET_paramMaxTemporaryTables](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294140(v=exchg.10).md).

|

On success, a cursor opened on the newly created temporary table will be returned. The state of the temporary database will be prepared to contain the new temporary table. The state of any ordinary databases in use by the database engine will remain unchanged.

On failure, the temporary table will not be created and a cursor will not be returned. The state of the temporary database may be changed. The state of any ordinary databases in use by the database engine will remain unchanged.

#### Remarks

Temporary tables do not support the full complement of column definition options that are ordinarily supported by the database engine. In fact, only JET_bitColumnFixed and JET_bitColumnTagged are supported. This means that it is not possible to create an auto-increment, version, or multi-valued column in a temporary table. Finally, escrow update columns are not supported because they are not useful in a temporary table since they can only be used by one session at a time. If any of these options are requested then they will be ignored.

Temporary tables do not support default values. If a column definition is provided that contains a default value specification then that specification will be ignored.

Temporary tables are returned to the caller as a result of many different ESE functions. For example, [JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function) with the JET_IdxInfo option set in the *InfoLevel* parameter will return a temporary table containing a list of all the key columns in a given index. The temporary tables follow the same lifecycle rules as ordinary temporary tables as described here.

Temporary tables are also used internally by the database engine for many tasks. The most important of these tasks is the creation of an index over an existing table. A temporary table will be used to sort the index keys used to construct that index.

All temporary tables are stored in the temporary database. The temporary database is a special database file that is maintained during the lifetime of an ESE instance and is deleted when that instance is shut down or restarted. The location of the temporary database can be configured using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) with [JET_paramTempPath](https://learn.microsoft.com/windows/win32/extensible-storage-engine/temporary-database-parameters). Placement of the temporary database on disk relative to your transaction log files and database files may be important if your application makes heavy use of temporary tables or creates indexes frequently.

The lifecycle of a temporary table is tied to the cursors that reference it. If all the cursors that reference a temporary table are closed, either implicitly or explicitly, then the temporary table will be deleted. If a temporary table is created inside a transaction and that transaction is subsequently rolled back then the temporary table will be deleted because any cursors that referenced it at this time will be implicitly closed. New cursors may reference a temporary table only through the use of [JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupcursor-function). In this case, the new cursors will be positioned on the first index entry of the temporary table. [JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupcursor-function) will only work during certain phases of use for the temporary table. See the remarks concerning temporary table cursor capabilities for more information. It is not possible to reference a temporary table from more than one session at a time.

There is an important problem in [JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupcursor-function) that affects temporary tables. If an attempt is made to duplicate a temporary table that is in forward-only mode then the resulting cursor will not be created properly and will malfunction. It is still safe to duplicate a cursor over a materialized temporary table.

The temporary table manager may choose to implement a temporary table in three ways. The first method is to maintain an in-memory table. This strategy is the fastest but can only be used for small, simple temporary tables. The second method is to create a disk-based sort that can be driven using a forward-only iterator. This strategy can only be used under certain circumstances and is the fastest way to sort and remove duplicates from a very large data set. The third method is to create a B+ Tree in the temporary database to hold the temporary table. This strategy is the slowest, but the most versatile, and is referred to as a materialized temporary table. These strategies may be used in combination to ultimately achieve the functionality requested of the temporary table.

When the temporary table is not materialized then it is used in primarily two major phases. The first phase is the insertion phase where the table is populated with its initial data set. During this phase, only data insertion is allowed. This phase ends when an attempt is made to move the cursor using [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function) or [JetSeek](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetseek-function). The second phase is the data extraction phase. During this phase, the data stored in the temporary table may be extracted according to the capabilities requested when the temporary table was created.

**Temporary Table Cursor Capabilities**

When the temporary table is materialized, the cursor has the following capabilities but may be further limited by the options requested:

  - [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function)

  - [JetDelete](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdelete-function)

  - [JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupcursor-function)

  - [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function)

  - [JetEscrowUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetescrowupdate-function)

  - [JetGetBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetbookmark-function)

  - [JetGetCursorInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetcursorinfo-function)

  - [JetGetLS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetls-function)

  - [JetGetRecordSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetrecordsize-function)

  - [JetGetTableInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableinfo-function)

  - [JetGotoBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgotobookmark-function)

  - [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmakekey-function)

  - [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function)

  - [JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetprepareupdate-function)

  - [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function)

  - [JetRetrieveColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumns-function)

  - [JetRetrieveKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievekey-function)

  - [JetSeek](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetseek-function)

  - [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function)

  - [JetSetColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumns-function)

  - [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function)

  - [JetSetLS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetls-function)

  - [JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetupdate-function)

When the temporary table is not materialized and is in the insert phase, the cursor has the following capabilities but may be further limited by the options requested:

  - [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function)

  - [JetEscrowUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetescrowupdate-function)

  - [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmakekey-function)

  - [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function)
    **Note** Causes transition to the extract phase.

  - [JetPrepareUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetprepareupdate-function)

  - [JetRetrieveKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievekey-function)

  - [JetSeek](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetseek-function)
    **Note** Causes transition to the extract phase.

  - [JetSetColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumn-function)

  - [JetSetColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetcolumns-function)

  - [JetUpdate](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetupdate-function)

When the temporary table is not materialized and is in the extract phase, the cursor has the following capabilities but may be further limited by the options requested:

  - [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function)

  - [JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupcursor-function)
    **Note** If an attempt is made to duplicate a temporary table that is in forward-only mode then the resulting cursor will not be created properly and will malfunction. It is still safe to duplicate a cursor over a materialized temporary table.

  - [JetEnumerateColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetenumeratecolumns-function)

  - [JetGetBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetbookmark-function)

  - [JetGetLS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetls-function)

  - [JetGetRecordSize](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetrecordsize-function)

  - [JetGetTableInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableinfo-function)

  - [JetGotoBookmark](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgotobookmark-function)

  - [JetMakeKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmakekey-function)

  - [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function)

  - [JetRetrieveColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumn-function)

  - [JetRetrieveColumns](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievecolumns-function)

  - [JetRetrieveKey](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetretrievekey-function)

  - [JetSeek](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetseek-function)

  - [JetSetIndexRange](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetindexrange-function)

  - [JetSetLS](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetls-function)

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

[JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columndef-structure)
[JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_UNICODEINDEX](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-unicodeindex-structure)
[JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function)
[JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function)
[JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupcursor-function)
[JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function)
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)
[JetSeek](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetseek-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[Temporary Database Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/temporary-database-parameters)