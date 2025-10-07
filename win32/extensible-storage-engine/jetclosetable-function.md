# JetCloseTable Function

_**Applies to:** Windows | Windows Server_

## JetCloseTable Function

The **JetCloseTable** function closes an open table in a database. The table may be a temporary table or a normal table.

```cpp
JET_ERR JET_API JetCloseTable(
  __in          JET_SESID sesid,
  __in          JET_TABLEID tableid
);
```

### Parameters

*sesid*

Identifies the database session context that will be used for the API call.

*tableid*

Identifies the table to be closed.

Set *tableid* to JET_tableidNil to release memory.

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

#### Remarks

This function must be called on all tables opened with [JetOpenTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentable-function).

The exception to this rule happens when [JetOpenTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentable-function) is called in a transaction and the transaction is rolled back (with [JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)). When rolling back a transaction, the table is automatically closed. In this case, it is an error to close the table with **JetCloseTable**.

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
[JetOpenTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetopentable-function)
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)