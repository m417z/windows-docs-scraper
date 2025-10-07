# JetGetTableColumnInfo Function

_**Applies to:** Windows | Windows Server_

## JetGetTableColumnInfo Function

The **JetGetTableColumnInfo** function retrieves information about a table column.

```cpp
JET_ERR JET_API JetGetTableColumnInfo(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid,
  __in          const tchar* szColumnName,
  __out         void* pvResult,
  __in          unsigned long cbMax,
  __in          unsigned long InfoLevel
);
```

### Parameters

*sesid*

The database session context to use for the API call.

*tableid*

The table that contains the column to fetch information for.

*szColumnName*

The name of the column to fetch information for.

*pvResult*

Pointer to a buffer that will receive the information. The type of the buffer is dependent on *InfoLevel*. The caller must be configured to align the buffer appropriately.

*cbMax*

The size, in bytes, of the buffer that was passed in *pvResult*.

*InfoLevel*

The type of information that will be retrieved for the column that is specified by *szColumnName*. The format of the data that is stored in *pvResult* is dependent on *InfoLevel*. For the schema of the temporary table, see [JET_COLUMNLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnlist-structure).

  - JET_ColInfoListSortColumnid will sort the temporary table by *columnid*.

  - JET_ColInfoListCompact will compact the output. For more information about the compact output, see [JET_COLUMNLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnlist-structure).

The following options can be set for this parameter:

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_ColInfo

|

*pvResult* is interpreted as a [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294130(v=exchg.10).md), and the fields of the [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294130(v=exchg.10).md) structure are filled in appropriately. JET_ColInfo and JET_ColInfoByColid both retrieve the same information.

|
|

JET_ColInfoBase

|

*pvResult* is interpreted as a [JET_COLUMNBASE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269194(v=exchg.10).md) structure. This is similar to a [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294130(v=exchg.10).md) structure. If this function succeeds, the structure is populated with appropriate values. If this function fails, the structure contains undefined data.

|
|

JET_ColInfoByColid

|

*pvResult* is interpreted as a [JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294130(v=exchg.10).md), except this *InfoLevel* indicates that the requested column (*szColumName*) is not the string column name, but a pointer to a [JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294104(v=exchg.10).md). JET_ColInfo and JET_ColInfoByColid both retrieve the same information.

|
|

JET_ColInfoList

|

*pvResult* is interpreted as a [JET_COLUMNLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269228(v=exchg.10).md) structure. If this function succeeds, the structure is populated with appropriate values. A temporary table is opened and is identified by the *tableid* member of [JET_COLUMNLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269228(v=exchg.10).md). The table must be closed with [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294087(v=exchg.10).md). If this function fails, the structure contains undefined data.

|
|

JET_ColInfoListCompact

|

*pvResult* is interpreted as a [JET_COLUMNLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269228(v=exchg.10).md) structure. If this function succeeds, the structure is populated with appropriate values. A temporary table is opened and is identified by the *tableid* member of [JET_COLUMNLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269228(v=exchg.10).md). The table must be closed with [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294087(v=exchg.10).md). If this function fails, the structure contains undefined data.

|
|

JET_ColInfoListSortColumnid

|

Same as JET_ColInfoList, however the resulting table is sorted by *columnid*, instead of column name.

|
|

JET_ColInfoSysTabCursor

|

JET_ColInfoSysTabCursor is deprecated, and use of it will return JET_errFeatureNotAvailable.

|
|

JET_ColInfoBaseByColId

|

Same as JET_ColInfoBase, *pvResult* is interpreted as a [JET_COLUMNBASE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269194(v=exchg.10).md), except this *InfoLevel* indicates that requested column (*szColumName*) is not the string column name, but a pointer to a [JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294104(v=exchg.10).md).

**Windows Vista:** This is available in Windows Vista and later.

|
|

JET_ColInfoGrbitNonDerivedColumnsOnly

|

Only return non-derived columns (if the table is derived from a template).

This value can be logically or'd into the *InfoLevel*, when the base *InfoLevel* is JET_ColInfoList.

**Windows Vista:** This value is introduced in Windows Vista.

|
|

JET_ColInfoGrbitMinimalInfo

|

Only return the column name and columnid of each column.

This value can be logically or'd into the *InfoLevel*, when the base *InfoLevel* is JET_ColInfoList.

**Windows Vista:** This value is introduced in Windows Vista.

|
|

JET_ColInfoGrbitSortByColumnid

|

Sort returned column list by columnid (default is to sort list by column name).

This value can be logically or'd into the *InfoLevel*, when the base *InfoLevel* is JET_ColInfoList.

**Windows Vista:** This value is introduced in Windows Vista.

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

JET_errColumnNotFound

|

The column named *szColumnName* was not found in the table.

|
|

JET_errFeatureNotAvailable

|

A bad *InfoLevel* was specified.

|
|

JET_errInvalidName

|

This error can be returned if:

* A bad name for *szTableName* was given.
* A bad name for *szColumnName* was given.

|
|

JET_errInvalidParameter

|

This error can be returned if:

* A bad *InfoLevel* was specified.
* A NULL *szTableName* was passed in.
* The buffer is too small.

|

#### Remarks

**JetGetTableColumnInfo** and [JetGetColumnInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetcolumninfo-function) both retrieve information about a column. The difference between them is how the table is identified:

  - **JetGetTableColumnInfo** identifies a table by *tableid*.

  - [JetGetColumnInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetcolumninfo-function) identifies a table by *dbid* and *szTableName* combination.

When retrieving data with JET_ColInfoList, JET_ColInfoListSortColumnid, or JET_ColInfoListCompact, a temporary table will be opened. The temporary table contains data, and the [JET_COLUMNLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnlist-structure) structure contains sufficient information to traverse the temporary table. The temporary table must be closed with [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function).

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

Implemented as **JetGetTableColumnInfoW** (Unicode) and **JetGetTableColumnInfoA** (ANSI).

|

#### See Also

[Extensible Storage Engine Errors](https://learn.microsoft.com/windows/win32/extensible-storage-engine/extensible-storage-engine-errors)
[Error Handling Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/error-handling-parameters)
[JET_COLUMNBASE](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnbase-structure)
[JET_COLUMNDEF](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columndef-structure)
[JET_COLUMNID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnid)
[JET_COLUMNLIST](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-columnlist-structure)
[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function)
[JetGetColumnInfo](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetgetcolumninfo-function)
[JetGetTableColumnInfo]()