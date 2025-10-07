# JetDeleteTable Function

_**Applies to:** Windows | Windows Server_

## JetDeleteTable Function

The **JetDeleteTable** function deletes a table in an ESE database.

```cpp
    JET_ERR JET_API JetDeleteTable(
      __in          JET_SESID sesid,
      __in          JET_DBID dbid,
      __in          const tchar* szTableName
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*dbid*

The database identifier to use for the API call.

*szTableName*

The name of the table to delete.

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

JET_errTableInUse

|

An attempt was made to delete a table while another session has an open table ID ([JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269182(v=exchg.10).md)) with [JetOpenTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294118(v=exchg.10).md) or [JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269193(v=exchg.10).md).

|
|

JET_errCannotDeletetemporary table

|

An attempt was made to delete a temporary table. A temporary table is automatically deleted when it is closed with [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg294087(v=exchg.10).md).

|
|

JET_errCannotDeleteTemplateTable

|

An attempt was made to delete a template table, that is, a table from which DDL can be inherited.

|

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

Implemented as **JetDeleteTableW** (Unicode) and **JetDeleteTableA** (ANSI).

|

#### See Also

[JET_DBID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-dbid)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function)