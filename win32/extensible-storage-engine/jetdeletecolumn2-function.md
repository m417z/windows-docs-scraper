# JetDeleteColumn2 Function

_**Applies to:** Windows | Windows Server_

## JetDeleteColumn2 Function

The **JetDeleteColumn2** function deletes a column from an ESE database table and enables a *grbit* option to be set.

**Windows XP: JetDeleteColumn2** is introduced in Windows XP.

```cpp
    JET_ERR JET_API JetDeleteColumn2(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          const tchar* szColumnName,
      __in          const JET_GRBIT grbit
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*tableid*

The table that contains the column to be deleted.

*szColumnName*

The name of the column to be deleted.

*grbit*

A group of bits specifying zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitDeleteColumnIgnoreTemplateColumns

|

Setting JET_bitDeleteColumIgnoreTemplateColumns will cause the API to only attempt to delete columns in the derived table. If a column of that name exists in the base table it will be ignored.

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

Calling [JetDeleteColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdeletecolumn-function) is identical to calling **JetDeleteColumn2** with *grbit* set to zero (0).

#### Requirements

| Requirement | Value |
|------------|----------|
|

**Client**

|

Requires Windows Vista or Windows XP.

|
|

**Server**

|

Requires Windows Server 2008 or Windows Server 2003.

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

Implemented as **JetDeleteColumn2W** (Unicode) and **JetDeleteColumn2A** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetDeleteColumn](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdeletecolumn-function)