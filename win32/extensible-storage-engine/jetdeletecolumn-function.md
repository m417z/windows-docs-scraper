# JetDeleteColumn Function

_**Applies to:** Windows | Windows Server_

## JetDeleteColumn Function

The **JetDeleteColumn** function deletes a column from an ESE database table.

```cpp
JET_ERR JET_API JetDeleteColumn(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid,
  __in          const tchar* szColumnName
);
```

### Parameters

*sesid*

The database session context to use for the API call.

*tableid*

The table from which to delete the column.

*szColumnName*

The name of the column to be deleted.

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

JET_errColumnInUse

|

The column is currently in use. It may be currently used by an index.

|
|

JET_errFixedDDL

|

An attempt was made to modify the fixed DDL.

|
|

JET_errFixedInheritedDDL

|

The column named in *szColumnName* exists in the template table, and the DDL of a template table cannot be modified.

|
|

JET_errInvalidName

|

This may be returned if a bad name for *szColumnName* was given.

|
|

JET_errPermissionDenied

|

The table is not writable. This may get returned if the database was opened in read-only mode.

|
|

JET_errTransReadOnly

|

The transaction is a read-only transaction.

|

#### Remarks

Calling **JetDeleteColumn** is identical to calling [JetDeleteColumn2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdeletecolumn2-function) with *grbit* set to zero (0).

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

Implemented as **JetDeleteColumnW** (Unicode) and **JetDeleteColumnA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetDeleteColumn2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdeletecolumn2-function)