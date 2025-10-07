# JetGetTableInfo Function

_**Applies to:** Windows | Windows Server_

## JetGetTableInfo Function

The **JetGetTableInfo** function retrieves various pieces of information about a table in a database.

```cpp
    JET_ERR JET_API JetGetTableInfo(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __out         void* pvResult,
      __in          unsigned long cbMax,
      __in          unsigned long InfoLevel
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*tableid*

The table that the information applies to.

*pvResult*

Pointer to a buffer that will receive the information. The type of the buffer is dependent on *InfoLevel*. It is the responsibility of the caller to align the buffer appropriately.

*cbMax*

The size, in bytes, of the buffer that was passed in *pvResult*.

*InfoLevel*

The type of information that will be retrieved for the table that is specified by *tableid*. The format of the data that is stored in *pvResult* is dependent on *InfoLevel*.

The following options can be set for this parameter:

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_TblInfo

|

*pvResult* is interpreted as a [JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269353(v=exchg.10).md) structure. If the method succeeds, the [JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269353(v=exchg.10).md) structure is filled in with the appropriate data. If it fails, the contents are undefined.

|
|

JET_TblInfoDbid

|

*pvResult* is treated as an array of two [JET_DBID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269248(v=exchg.10).md) objects. The database identifier of the database that owns the table is stored in this array twice.

|
|

JET_TblInfoDumpTable

|

JET_TblInfoDumpTable is deprecated. The API will return JET_errFeatureNotAvailable.

|
|

JET_TblInfoName

|

JET_TblInfoName retrieves the name of the table and stores it in *pvResult*. If the buffer is too small, the behavior is undefined.

|
|

JET_TblInfoMostMany

|

JET_TblInfoMostMany retrieves the name of the table and stores it in *pvResult*. If the buffer is too small, the behavior is undefined.

|
|

JET_TblInfoOLC

|

JET_TblInfoOLC is deprecated. The API will return JET_errFeatureNotAvailable.

|
|

JET_TblInfoRvt

|

JET_TblInfoRvt is deprecated. The API will return JET_errQueryNotSupported.

|
|

JET_TblInfoResetOLC

|

JET_TblInfoResetOLC is deprecated. The API will return JET_errFeatureNotAvailable.

|
|

JET_TblInfoSpaceAlloc

|

*pvResult* is interpreted as an array of two ULONGs:

* The first **ULONG** is the number of pages in the table.
* The second **ULONG** is the target density of pages for the table.

|
|

JET_TblInfoSpaceAvailable

|

*pvResult* is interpreted as a **ULONG**. The **ULONG** is the sum of the number of pages that are available in the table, its indexes, and the long value tree.

|
|

JET_TblInfoSpaceOwned

|

*pvResult* is interpreted as a **ULONG**. The **ULONG** is the sum of the number of pages that are owned by the table (including its indexes, and the long value tree and any available pages therein).

|
|

JET_TblInfoSpaceUsage

|

The behavior of the API depends on how large the buffer that is passed to the API is. Two *cbMax* values must be at least ( 2 * sizeof( ULONG ) ).

* If *cbMax* is ( 2 * sizeof( ULONG ) ), *pvResult* is interpreted as an array of two ULONGs:

  + The first **ULONG** is the number of Owned Extents of the table.
  + The second **ULONG** is the number of Available Extents of the table.
* *pvResult* is interpreted as an array of:

  + The first **ULONG** is the number of Owned Extents of the table.
  + The second **ULONG** is the number of Available Extents of the table.

|
|

JET_TblInfoTemplateTableName

|

*pvResult* is interpreted as a string buffer. The buffer must be at least JET_cbNameMost + 1, including the terminating **NULL**. If the table is a derived table, the buffer will be filled in with the name of the table from which the derived table inherited its DDL. If the table is not a derived table, the buffer will an empty string.

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

|
|

JET_errBufferTooSmall

|

The buffer was too small.

|
|

JET_errFeatureNotAvailable

|

A deprecated *InfoLevel* was specified.

|
|

JET_errInvalidBufferSize

|

The buffer was not the right size.

|
|

JET_errInvalidOperation

|

The table that was passed in was a temporary table, and the requested *InfoLevel* cannot be retrieved for a temporary table.

|
|

JET_errObjectNotFound

|

The table that was passed in was a temporary table, and the requested *InfoLevel* cannot be retrieved for a temporary table.

|
|

JET_errQueryNotSupported

|

The *InfoLevel* is not supported.

|
|

JET_errTableInUse

|

The table is being used by another database operation.

|
|

JET_errTableLocked

|

The table is locked by another database operation.

|
|

JET_wrnTableInUseBySystem

|

The table is being used by the system. This warning is nonfatal.

|

#### Remarks

Some pieces of information are not valid for temporary tables (See [JetOpenTempTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentemptable-function)).

The table statistics include the number of records and the number of pages in the clustered index (that is, the index containing the record data). The index statistics are accessed separately by name, using [JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function) or [JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function).

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

Implemented as **JetGetTableInfoW** (Unicode) and **JetGetTableInfoA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JET_OBJECTINFO](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-objectinfo-structure)
[JetGetIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetindexinfo-function)
[JetGetObjectInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetobjectinfo-function)
[JetGetTableIndexInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgettableindexinfo-function)
[JetOpenTempTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentemptable-function)