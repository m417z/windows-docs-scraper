# JetOpenTempTable3 Function

_**Applies to:** Windows | Windows Server_

## JetOpenTempTable3 Function

The **JetOpenTempTable3** function creates a temporary table with a single index that can be used to store and retrieve records just like an ordinary table created using [JetCreateTableColumnIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreatetablecolumnindex-function). However, temporary tables are much faster than ordinary tables due to their volatile nature. They can also be used to very quickly sort and perform duplicate removal on record sets when accessed in a purely sequential manner.

```cpp
    JET_ERR JET_API JetOpenTempTable3(
      __in          JET_SESID sesid,
      __in          const JET_COLUMNDEF* prgcolumndef,
      __in          unsigned long ccolumn,
      __in_opt      JET_UNICODEINDEX* pidxunicode,
      __in          JET_GRBIT grbit,
      __out         JET_TABLEID* ptableid,
      __out         JET_COLUMNID* prgcolumnid
    );
```

### Parameters

*sesid*

The session to use for this call.

*prgcolumndef*

Identifies the column definitions of the columns to be created in the temporary table.

Important limitations exist to the column definition options that may be used with a temporary table. See the Remarks section for more information.

In addition to the usual column definition options, zero or more of the following options may also be specified that are relevant only in the context of a temporary table.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitColumnTTDescending

|

This option indicates that the sort order of the key column for the temporary table should be descending rather than ascending. If this option is specified without JET_bitColumnTTKey then this option is ignored.

|
|

JET_bitColumnTTKey

|

This option indicates that the column will be a key column for the temporary table.

The order of the column definitions with this option specified in the input array will determine the precedence of each key column for the temporary table. The first column definition in the array with this option set will be the most significant key column and so on. If more key columns are requested than can be supported by the database engine then this option is ignored for the unsupportable key columns.

|

*ccolumn*

See *prgcolumndef*.

*pidxunicode*

The Locale ID and normalization flags that will be used to compare any Unicode key column data in the temporary table.

When this parameter is not present then the default LCID will be used to compare any Unicode key columns in the temporary table. The default LCID is the U.S. English locale.

When this parameter is not present then the default normalization flags will be used to compare any Unicode key column data in the temp table. The default normalization flags are: NORM_IGNORECASE, NORM_IGNOREKANATYPE, and NORM_IGNOREWIDTH.

*grbit*

A group of bits that contain the options to be used for this call, which include zero or more of the following.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitTTErrorOnDuplicateInsertion

|

This option requests that any attempt to insert a record with the same index key as a previously inserted record will immediately fail with JET_errKeyDuplicate. If this option is not requested then a duplicate may be detected immediately and fail or may be silently removed later depending on the strategy chosen by the database engine to implement the temporary table based on the requested functionality.

If this functionality it not required then it is best to not request it. If this functionality is not requested then the temporary table manager may be able to choose a strategy for managing the temporary table that will result in improved performance.

|
|

JET_bitTTForceMaterialization

|

This option forces the temporary table manager to abandon any attempt to choose a clever strategy for managing the temporary table that will result in enhanced performance.

|
|

JET_bitTTForwardOnly

|

This option requests that the temporary table only be created if the temporary table manager can use the implementation optimized for intermediate query results. If any characteristic of the temporary table would prevent the use of this optimization then the operation will fail with JET_errCannotMaterializeForwardOnlySort.

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

This option requests that records with duplicate index keys be removed from the final set of records in the temporary table.

Prior to Windows Server 2003, the database engine always assumed this option to be in effect due to the fact that all clustered indexes must also be a primary key and thus must be unique. As of Windows Server 2003, it is now possible to create a temporary table that does NOT remove duplicates when the JET_bitTTForwardOnly option is also specified.

It is not possible to know which duplicate will win and which duplicates will be discarded in general. However, when the JET_bitTTErrorOnDuplicateInsertion option is requested then the first record with a given index key to be inserted into the temporary table will always win.

|
|

JET_bitTTUpdatable

|

This option requests that the temporary table be flexible enough to allow records that have previously been inserted to be subsequently changed. If this functionality it not required then it is best to not request it.

If this functionality is not requested then the temporary table manager may be able to choose a strategy for managing the temporary table that will result in improved performance.

|
|

JET_bitTTScrollable

|

This option requests that the temporary table be flexible enough to allow records to be scanned in arbitrary order and direction using [JetMove](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294117(v=exchg.10).md).

If this functionality it not required then it is best to not request it. If this functionality is not requested then the temporary table manager may be able to choose a strategy for managing the temporary table that will result in improved performance.

|
|

JET_bitTTSortNullsHigh

|

This option requests that NULL key column values sort closer to the end of the index than non-NULL key column values.

|
|

JET_bitTTIntrinsicLVsOnly

|

Requests to permit only intrinsic long values.

**Windows 7**: **JET_bitTTIntrinsicLVsOnly** is introduced in Windows 7.

|

*ptableid*

The output buffer that will receive the new cursor opened on the newly created temporary table.

*prgcolumnid*

The output buffer that will receive the array of column IDs generated during the creation of the temporary table.

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

**JetOpenTempTable3** failed because JET_bitTTForwardOnly was specified and the temporary table as specified could not be created using the forward-only optimization. This error will only be returned by Windows Server 2003 and later releases.

|
|

JET_errClientRequestToStopJetService

|

It is not possible to complete the operation because all activity on the instance associated with the session has ceased as a result of a call to [JetStopService](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269240(v=exchg.10).md).

|
|

JET_errIndexInvalidDef

|

The index could not be created because an invalid index definition was specified. **JetOpenTempTable3** will return this error when:

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

The **cp** member of the [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294130(v=exchg.10).md) structure was not set to a valid code page. The only valid values for text columns are English (1252) and Unicode (1200). A value of 0 means the default will be used (English, 1252).

|
|

JET_errInvalidColumnType

|

The **coltyp** member of the [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294130(v=exchg.10).md) structure was not set to a valid column type.

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

The session handle is invalid or refers to a closed session. This error is not returned under all circumstances. Handles are validated on a best effort basis only.

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

**JetOpenTempTable3** can return JET_errOutOfMemory if the address space of the host process becomes too fragmented. The temporary table manager will always allocate a 1MB chunk of address space for every temporary table created regardless of the amount of data to be stored.

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

[Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors)
[Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters)
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
[JetOpenTempTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentemptable-function)
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)
[JetSeek](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetseek-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[System Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-system-parameters)