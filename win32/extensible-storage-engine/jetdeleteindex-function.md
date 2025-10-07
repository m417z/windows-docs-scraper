# JetDeleteIndex Function

_**Applies to:** Windows | Windows Server_

## JetDeleteIndex Function

The **JetDeleteIndex** function deletes an index from a table.

```cpp
    JET_ERR JET_API JetDeleteIndex(
      __in          JET_SESID sesid,
      __in          JET_TABLEID tableid,
      __in          JET_PCSTR szIndexName
    );
```

### Parameters

*sesid*

The database session context to use for the API call.

*tableid*

The table that contains the column that is to be deleted.

*szIndexName*

The name of the index to be deleted.

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

JET_errFixedDDL

|

An attempt was made to delete an index from a fixed table (for example, one created with JET_bitTableCreateFixedDDL).

|
|

JET_errFixedInheritedDDL

|

An attempt was made to delete an index from a template table. A template table has fixed DDL.

|
|

JET_errIndexNotFound

|

The index named in *szIndexName* was not found.

|
|

JET_errPermissionDenied

|

The table cannot be updated because it was opened read-only.

|
|

JET_errSessionSharingViolation

|

Multiple threads attempted to use the same database session.

|
|

JET_errTransReadOnly

|

The transaction was opened as a read-only transaction.

|

#### Remarks

When successful, the index is deleted and therefore cannot be used subsequently. There must not be any active transaction using the index.

On success, the currency is set before the first record.

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

Implemented as **JetDeleteIndexW** (Unicode) and **JetDeleteIndexA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetCreateIndex](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex-function)
[JetCreateIndex2](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetcreateindex2-function)