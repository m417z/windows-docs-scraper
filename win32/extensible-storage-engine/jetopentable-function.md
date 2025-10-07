# JetOpenTable Function

_**Applies to:** Windows | Windows Server_

## JetOpenTable Function

The **JetOpenTable** function opens a cursor on a previously created table.

```cpp
    JET_ERR JET_API JetOpenTable(
      __in          JET_SESID sesid,
      __in          JET_DBID dbid,
      __in          const tchar* szTableName,
      __in_opt      const void* pvParameters,
      __in          unsigned long cbParameters,
      __in          JET_GRBIT grbit,
      __out         JET_TABLEID* ptableid
    );
```

### Parameters

*sesid*

The database session context to use.

*dbid*

The database identifier to use to find the table.

*szTableName*

The name of the table to open.

*pvParameters*

Deprecated. Set to **NULL**.

*cbParameters*

Deprecated. Set to 0 (zero).

*grbit*

A group of bits specifying zero or more of the following options.

|

Value

|

Meaning

|
|--------------|----------------|
|

JET_bitTableDenyRead

|

The table cannot be opened for read-access by another database session.

|
|

JET_bitTableDenyWrite

|

The table cannot be opened for write-access by another database session.

|
|

JET_bitTableNoCache

|

Do not cache the pages for this table.

|
|

JET_bitTablePermitDDL

|

Allows DDL modification on tables flagged as FixedDDL. This option must be used with the JET_bitTableDenyRead option.

|
|

JET_bitTablePreread

|

Provides a hint that the table is probably not in the buffer cache, and that pre-reading may be beneficial to performance.

|
|

JET_bitTableReadOnly

|

Requests read-only access to the table.

|
|

JET_bitTableSequential

|

The table should be very aggressively prefetched from disk because the application will be scanning it sequentially.

|
|

JET_bitTableUpdatable

|

Requests write-access to the table.

|

*ptableid*

On success, points to the identifier of the table. On failure, the contents for *ptableid* are undefined.

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

JET_errInvalidDatabaseId

|

*dbid* is not a valid database identifier.

|
|

JET_errInvalidgrbit

|

A bad combination of *grbit* was passed in.

|
|

JET_errInvalidName

|

The name given in *szTableName* is invalid.

For more information about valid table names, see the *szTableName* parameter in [JetCreateTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/gg269210(v=exchg.10).md).

|
|

JET_errObjectNotFound

|

An attempt was made to open a table that does not exist in the database.

|
|

JET_errOutOfCursors

|

The operation failed because the engine cannot allocate the resources required to open a new cursor. See the Remarks section.

|
|

JET_errTableInUse

|

The table is being used by another database operation.

|
|

JET_wrnTableInUseBySystem

|

A nonfatal warning indicating that the table is being used by the system.

|
|

JET_errTableLocked

|

The table is locked by another database operation.

|
|

JET_errTooManyOpenTables

|

An attempt was made to open too many unique tables at once. See the Remarks section.

|

#### Remarks

Tables opened with **JetOpenTable** should usually be closed with [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function). The exception to this rule happens when **JetOpenTable** is called in a transaction and the transaction is rolled back (with [JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)). When rolling back a transaction, the table is automatically closed. In this case, it is an error to close the table with [JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function).

It is legal to open system tables with **JetOpenTable** (for example, MSysObjects, MSysUnicodeFixup). The schema of the system tables may change, so accessing system tables is discouraged. The number of unique tables that can be opened simultaneously is affected directly by *JET_paramMaxOpenTables*. If the table is currently open then a new cursor will be created on the table. Cursor resources are configured using [JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function) with *JET_paramMaxCursors*. Also see [JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupcursor-function).

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

Implemented as **JetOpenTableW** (Unicode) and **JetOpenTableA** (ANSI).

|

#### See Also

[JET_ERR](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-err)
[JET_GRBIT](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-grbit)
[JET_SESID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-sesid)
[JET_TABLEID](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jet-tableid)
[JetCloseTable](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetclosetable-function)
[JetDupCursor](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetdupcursor-function)
[JetRollback](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetrollback-function)
[JetSetSystemParameter](https://learn.microsoft.com/windows/win32/extensible-storage-engine/jetsetsystemparameter-function)
[Resource Parameters](https://learn.microsoft.com/windows/win32/extensible-storage-engine/resource-parameters)