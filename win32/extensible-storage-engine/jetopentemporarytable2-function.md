# JetOpenTemporaryTable2 Function

_**Applies to:** Windows | Windows Server_

## JetOpenTemporaryTable2 Function

The **JetOpenTemporaryTable2** function creates a volatile table with a single index that can be used to store and retrieve records, just like an ordinary table that is created via [JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function).

**Windows Vista:** **JetOpenTemporaryTable2** is introduced in Windows Vista.

Temporary tables are faster than ordinary tables due to their volatile nature. They can quickly sort and perform duplicate removal on record sets when they are accessed in a purely sequential manner.

```cpp
    JET_ERR JET_API JetOpenTemporaryTable2(
      __in          JET_SESID sesid,
      __in          JET_OPENTEMPORARYTABLE* popentemporarytable
    );
```

### Parameters

*sesid*

The session that will be used for this call.

*popentemporarytable*

A pointer to a [JET_OPENTEMPORARYTABLE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-opentemporarytable-structure) structure that contains the description of the temporary table to create on input. After a successful call, the structure contains the handle to the temporary table and column identifications.

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

JET_errOutOfMemory

|

The operation failed because not enough memory could be allocated to complete it.

**JetOpenTemporaryTable2** can return JET_errOutOfMemory if the address space of the host process becomes too fragmented. The temporary table manager will allocates a 1 MB chunk of address space for every temporary table created regardless of the amount of data is stored.

|
|

JET_errInvalidParameter

|

One of the provided parameters contained an unexpected value or the combination of several parameter values resulted in an unexpected result.

This error is returned by **JetOpenTemporaryTable2** under the following conditions:

* The **cbStruct** member of the [JET_OPENTEMPORARYTABLE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269206(v=exchg.10).md) structure does not correspond to a version of this structure that is supported by that version of the database engine
* The **cbKeyMost** member of the [JET_OPENTEMPORARYTABLE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269206(v=exchg.10).md) structure is less than JET_cbKeyMostMin.
* The **cbKeyMost** member of the [JET_OPENTEMPORARYTABLE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269206(v=exchg.10).md) structure is larger than the largest supported value for the database page size for the instance (JET_paramDatabasePageSize). See the JET_paramKeyMost parameter in the list of [Informational Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269241(v=exchg.10).md) for more information.
* The cbVarSegMac member of the [JET_OPENTEMPORARYTABLE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269206(v=exchg.10).md) structure is larger than The **cbKeyMost** member.

|
|

JET_errNotInitialized

|

The operation cannot complete because the instance that was associated with the session has not yet been initialized.

|
|

JET_errClientRequestToStopJetService

|

The operation cannot complete because all activity on the instance that is associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errInstanceUnavailable

|

The operation cannot complete because the instance that is associated with the session has encountered a fatal error that requires that access to all data be revoked to protect the integrity of that data.

**Windows XP:** This error will only be returned by Windows XP and later releases.

|
|

JET_errTermInProgress

|

The operation cannot complete because the instance that is associated with the session is being shut down.

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

**Windows XP:** This error will only be returned by Windows XP and later releases.

|
|

JET_errInvalidSesid

|

The session handle is invalid or refers to a closed session.

**Note** This error is not returned under all circumstances. Handles are validated on a best effort basis only.

|
|

JET_errOutOfCursors

|

The operation failed because the engine cannot allocate the resources that are required to open a new cursor. Cursor resources are configured using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with [JET_paramMaxCursors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269201(v=exchg.10).md).

|
|

JET_errTooManySorts

|

The operation failed because the engine cannot allocate the resources that are required to create a temporary table. Temporary table resources are configured using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with [JET_paramMaxTemporaryTables](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294140(v=exchg.10).md).

|
|

JET_errCannotMaterializeForwardOnlySort

|

**JetOpenTemporaryTable2** failed because JET_bitTTForwardOnly was specified and the temporary table that was specified could not be created using the forward-only optimization.

**Windows Server 2003:** This error will only be returned by Windows Server 2003 and later releases.

|
|

JET_errTooManyColumns

|

An attempt was made to add too many columns to the table. A table can have no more than JET_ccolFixedMost fixed columns, no more than JET_ccolVarMost variable-length columns, and no more than JET_ccolTaggedMost tagged columns.

|
|

JET_errTooManyOpenTables

|

The operation failed because the engine cannot allocate the resources that are required to cache the schema of the table. To configure the number of tables that have schemas that can be cached, use [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with [JET_paramMaxOpenTables](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269201(v=exchg.10).md).

|
|

JET_errInvalidCodePage

|

The **cp** member of the [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294130(v=exchg.10).md) structure was not set to a valid code page. The only valid values for text columns are English (1252) and Unicode (1200). A value of 0 means the default will be used (English, 1252).

|
|

JET_errInvalidColumnType

|

The **coltyp** member of the [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294130(v=exchg.10).md) was not set to a valid column type.

|
|

JET_errInvalidLanguageId

|

The index could not be created because an attempt was made to use an invalid locale ID. The locale ID might be either completely invalid or the associated language pack might not be installed.

|
|

JET_errInvalidLCMapStringFlags

|

The index could not be created because an attempt was made to use an invalid set of normalization flags.

**Windows XP:** This error will only be returned by Windows XP and later releases.

**Windows 2000:** On Windows 2000, invalid normalization flags will result in JET_errIndexInvalidDef.

|
|

JET_errIndexInvalidDef

|

The index could not be created because an invalid index definition was specified. **JetOpenTemporaryTable2** will return this error under the following conditions:

* The Language Neutral locale is specified.
* An invalid set of normalization flags is specified.

**Windows 2000:** This error will only be returned by Windows 2000.

|
|

JET_errTooManyOpenIndexes

|

The operation failed because the engine cannot allocate the resources that are required to cache the indexes of the table. To configure the number of indexes that have schemas that can be cached, use [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294044(v=exchg.10).md) with [JET_paramMaxOpenTables](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269201(v=exchg.10).md).

|

On success, a cursor opened on the newly created temporary table will be returned. The state of the temporary database will be prepared to contain the new temporary table. The state of any ordinary databases in use by the database engine will remain unchanged.

On failure, the temporary table will not be created and a cursor will not be returned. The state of the temporary database can be changed. The state of any ordinary databases in use by the database engine will remain unchanged.

#### Remarks

Temporary tables do not support the full complement of column definition options that are ordinarily supported by the database engine. In fact, only JET_bitColumnFixed and JET_bitColumnTagged are supported. This means that it is not possible to create an auto-increment, version, or multi-valued column in a temporary table. Finally, escrow update columns are not supported because they can only be used by one session at a time. If any of these options are requested then they will be ignored.

Temporary tables do not support default values. If a column definition is provided that contains a default value specification then that specification will be ignored.

Temporary tables are returned to the caller as a result of many different ESE functions. For example, [JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function) with the JET_IdxInfo option set will return a temporary table containing a list of all the key columns in a given index. The temporary tables follow the same lifecycle rules as ordinary temporary tables as described here.

Temporary tables are also used internally by the database engine for many tasks. The most important of these tasks is the creation of an index over an existing table. A temporary table will be used to sort the index keys that are used to construct that index.

All temporary tables are stored in the temporary database. The temporary database is a special database file that is maintained during the lifetime of an ESE instance and is deleted when that instance is shut down or restarted. The location of the temporary database can be configured using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) with [JET_paramTempPath](https://learn.microsoft.com/windows/win32/extensible-storage-engine/temporary-database-parameters). Placement of the temporary database on disk relative to your transaction log files and database files may be important if your application makes heavy use of temporary tables or creates indexes frequently.

The lifecycle of a temporary table is tied to the cursors that reference it. If all the cursors that reference a temporary table are closed, either implicitly or explicitly, then the temporary table will be deleted. If a temporary table is created inside a transaction and that transaction is subsequently rolled back then the temporary table will be deleted because any cursors that referenced it at this time will be implicitly closed. New cursors can reference a temporary table only through the use of [JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupcursor-function). In this case, the new cursors will be positioned on the first index entry of the temporary table. [JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupcursor-function) will only work during certain phases of use for the temporary table. See the remarks concerning temporary table cursor capabilities for more information. It is not possible to reference a temporary table from more than one session at a time.

**Caution** There is an important problem in [JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupcursor-function) that affects temporary tables. If an attempt is made to duplicate a temporary table that is in forward-only mode then the resulting cursor will not be created properly and will malfunction. It is still safe to duplicate a cursor over a materialized temporary table.

The temporary table manager can implement a temporary table in three ways. The first method is to maintain an in-memory table. This strategy is the fastest but can only be used for small, simple, temporary tables. The second method is to create a disk-based sort that can be driven using a forward-only iterator. This strategy can only be used under certain circumstances and is the fastest way to sort and remove duplicates from a very large data set. The third method is to create a B+ Tree in the temporary database to hold the temporary table. This strategy is the slowest, but the most versatile, and is referred to as a materialized temporary table. These strategies can be used in combination to ultimately achieve the functionality that is requested of the temporary table.

When the temporary table is not materialized then it is used primarily in two major phases. The first phase is the insertion phase where the table is populated with its initial data set. During this phase, only data insertion is allowed. This phase ends when an attempt is made to move the cursor using [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function) or [JetSeek](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetseek-function). The second phase is the data extraction phase. During this phase, the data that is stored in the temporary table can be extracted according to the capabilities that were requested when the temporary table was created.

**Temporary Table Cursor Capabilities**

When the temporary table is materialized, the cursor has the following capabilities but might be further limited by the options that are requested:

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

When the temporary table is not materialized and is in the insert phase, the cursor has the following capabilities but might be further limited by the options that are requested:

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

When the temporary table is not materialized and is in the extract phase, the cursor has the following capabilities but may be further limited by the options that are requested:

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

Requires Windows Vista.

|
|

**Server**

|

Requires Windows Server 2008.

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
[JET_OPENTEMPORARYTABLE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-opentemporarytable-structure)
[JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function)
[JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function)
[JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupcursor-function)
[JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetmove-function)
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)
[JetSeek](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetseek-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[Informational Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/informational-parameters)
[Temporary Database Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/temporary-database-parameters)